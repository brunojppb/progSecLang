//
//
//  Created by Bruno Paulino on 9/30/14.
//  Copyright (c) 2014 Bruno Paulino. All rights reserved.
//
//This program loads a sequence of images and calculates the average image
//also save delete images from memory and save the images in the hard disk

//COMPILE COMMAND
//g++ -Wall image.cpp -lboost_thread -lboost_system -lboost_filesystem

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
using namespace std;


//VALUES DYNAMICALLY CALCULATED
int HEIGHT = 0;
int WIDTH  = 0;
int MAX_VALUES = 0;
int TIME = 0;
const string VIDEO_OUTPUT_FOLDER = "OUTPUT_VIDEO/";
const string AVG_OUTPUT_FOLDER = "OUTPUT_AVG/";


//===============================================
//FUNCTIONS PROTOTYPES
//===============================================

//MENU OPERATIONS
int showMenu();
void loadVideo();
void saveVideo();
void saveVideoInBackground(int id);
void calculateAvg();
void calcPartialAvgInBackground(int threadId, int matrixInitialIndex, int matrixFinalIndex, double* partialAvgMatrix);

//Auxiliar functions
int intLength(int number);
void trim(string &str);
string to_string(int number);

//Video (3D Matrix)
unsigned int *video = NULL;
// Mutual exclusion synchronization primitive to protect agains concurrent updates (i.e., race conditions).
boost::mutex mutex;


//===============================================
//MAIN FUNCTION
//===============================================
int main() {
    string filename;
    int option = 0;

    while(option != 4){

        option = showMenu();

        switch (option) {
        case 1:
            loadVideo();
            break;

        case 2:
            saveVideo();
            break;

        case 3:
            calculateAvg();
            break;

        case 4:
            cout << "Thank you...\n";
            break;

        default:
            cout << "Choose a valid option.\n";
            break;
        }

        option = 0;
    };
    
    
    return 0;
}


//===============================================
//FUNCTIONS
//===============================================

//===============================================================
//Show the main menu
//===============================================================
int showMenu(){
    
    int choice;
    cout << "1. Load video" << endl;
    cout << "2. Save video" << endl;
    cout << "3. Show video" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    return choice;
}

//===============================================================
//Load frames from the hard disk and store in the memory
//===============================================================
void loadVideo(){
    
    //save each frame in a single file(Image File)
    ifstream imageFile;

    string folder;
    cout << "Enter the name of the video: ";
    cin >> folder;

    boost::filesystem::path dir(folder);
    boost::filesystem::directory_iterator end;

    //Dynamically calculates the width, height and time
    for ( boost::filesystem::directory_iterator pos(dir); pos != end; ++pos ){
        if ( is_regular_file( *pos ) ){
            imageFile.open(pos->path().c_str());
            if(imageFile.is_open()){
                if(WIDTH == 0 && HEIGHT == 0){
                    string line;
                    //Jump the Magic number
                    getline(imageFile, line);
                    //get the width and height of the file
                    getline(imageFile, line);
                    //buffer to get the width and height values
                    stringstream ss;
                    //remove the spaces
                    trim(line);
                    //extract the content of the line variable
                    ss << line;
                    //while ss has content to be converted
                    //keep converting
                    while(ss.good()){
                        //extract and convert the string to int
                        ss >> WIDTH;
                        ss >> HEIGHT;
                    }
                    ss.clear();
                }
                imageFile.close();;
            }

            //Calculates how many frames the folder has
            TIME++;
            MAX_VALUES = WIDTH * HEIGHT;

            //std::cout << pos->path().filename() << " : " << boost::filesystem::file_size( pos->path() ) << "\n";
        }
    }


    //Alocate the 3D matrix DYNAMICALLY
    video = new unsigned int[WIDTH*HEIGHT*TIME];
    //3D Matrix Index
    int videoIndex = 0;

    //Read the files and store in memory
    for ( boost::filesystem::directory_iterator pos(dir); pos != end; ++pos ){
        if ( is_regular_file( *pos ) ){

            imageFile.open(pos->path().c_str());
            //try to open the file
            if (imageFile.is_open()) {
                cout << "file: " << pos->path().filename() << " ok" << endl;
                string line;
                string stream = "";
                //Jump the P2 (magic number)
                getline(imageFile, line);
                //jump the height and width of the matrix
                getline(imageFile, line);
                //jump the maximum pixel
                getline(imageFile, line);

                //temporary array to store the numbers
                int temp[MAX_VALUES];

                //to read each line of the file and converts the string to numbers
                //we have to extract each string from the stringstream
                stringstream ss;
                //count how many numbers are in the file
                int count = 0;
                while(getline(imageFile, line)){
                    //remove spaces before and after the string
                    trim(line);
                    //extract the content of the line variable
                    ss << line;
                    //while ss has content to be converted
                    //keep converting
                    while(ss.good()){
                        int num;
                        //extract and convert the string to int
                        ss >> num;
                        temp[count] = num;
                        count++;
                    }
                    ss.clear();
                }

                //fill up the video matrix
                count = 0;
                for(int i = 0; i < HEIGHT; i++){
                    for(int j = 0; j < WIDTH; j++){
                        video[videoIndex] = temp[count];
                        count++;
                        videoIndex++;
                    }
                }

                //close the file         
                imageFile.close();
            }
            //error trying to open the file
            else{
                cout << "Error: could not open the file" << endl;
            }
        }
    }   



    for (int imageIndex = 0; imageIndex < TIME; imageIndex++) {
        string filename = "";
        if (intLength(imageIndex) == 1) {
            filename += "00" + to_string(imageIndex);
        }
        else if(intLength(imageIndex) == 2){
            filename += "0" + to_string(imageIndex);
        }
        else{
            filename += to_string(imageIndex);
        }
        filename = folder + "/" + filename + ".pgm";
        imageFile.open(filename.c_str());
    }

    cout << "Width: " << WIDTH << endl << "Height: " << HEIGHT << endl;
    cout << "Time: " << TIME << endl;

    MAX_VALUES = WIDTH * HEIGHT * TIME;
    cout << "MAX_VALUES: " << MAX_VALUES << endl;
}

//================================================================================
//calculates how many decimal places a integer number has
//================================================================================
int intLength(int number){
    int len = 1;
    
    if(number > 0){
        for(len = 0; number > 0; len++)
            number = number/10;
    }
    
    return len;
}

//================================================================================
//remove the spaces before and after the string
//================================================================================
void trim(string &str){
    string::size_type pos1 = str.find_first_not_of(' ');
    string::size_type pos2 = str.find_last_not_of(' ');
    str = str.substr(pos1 == string::npos ? 0 : pos1, 
    pos2 == string::npos ? str.length() - 1 : pos2 - pos1 + 1);
}


void calculateAvg(){
    double  partial1[HEIGHT/4 * WIDTH/4], 
            partial2[HEIGHT/4 * WIDTH/4],
            partial3[HEIGHT/4 * WIDTH/4],
            partial4[HEIGHT/4 * WIDTH/4];
    
    // cout << "#1 index: " << 0 << " : " << MAX_VALUES/4 << endl;
    // cout << "#2 index: " << MAX_VALUES/4 << " : " << MAX_VALUES/2 << endl;
    // cout << "#3 index: " << MAX_VALUES/2 << " : " << MAX_VALUES/2 + (MAX_VALUES/4) << endl;
    // cout << "#4 index: " << MAX_VALUES/2 + MAX_VALUES/4 << " : " << MAX_VALUES << endl;


    boost::thread t1(calcPartialAvgInBackground, 2, 0, MAX_VALUES/4, partial1);
    boost::thread t2(calcPartialAvgInBackground, 3, (MAX_VALUES/4), MAX_VALUES/2, partial2);
    boost::thread t3(calcPartialAvgInBackground, 4, (MAX_VALUES/2), (MAX_VALUES/2) + (MAX_VALUES/4), partial3);
    boost::thread t4(calcPartialAvgInBackground, 5, (MAX_VALUES/2) + (MAX_VALUES/4), MAX_VALUES, partial4);
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    int index = 0;
    for(int i = 0; i < HEIGHT/4; i++){
        for(int j = 0; j < WIDTH/4; j++){
            if(j % 10 == 0)
                cout << "\n";
            cout << partial1[index] << " ";
            index++;
        }
        cout << "\n";
    }

    cout << "Average calculation ended...\n";

}


//================================================================================
//Calculates the partial average in Background (thread)
//================================================================================
void calcPartialAvgInBackground(int threadId, int matrixInitialIndex, int matrixFinalIndex, double* partialAvgMatrix){

    const int partialWidth = WIDTH / 4;
    const int partialHeight = HEIGHT / 4;

    //partialAvgMatrix = new double[partialWidth * partialHeight];

    //fill up the matrix with 0
    int tempIndex = 0;
    for(int i = 0; i < partialHeight; i++){
       for(int j = 0; j < partialWidth; j++){
            partialAvgMatrix[tempIndex] = 0.0;
        }
    }    

    //sum all pixels
    int tempInitialIndex = matrixInitialIndex;
    tempIndex = 0;
    for(int k = 0; k < TIME; k++){
        for(int i = 0; i < partialHeight; i++){
           for(int j = 0; j < partialWidth; j++){
                partialAvgMatrix[tempIndex] += video[tempInitialIndex];
                tempInitialIndex++;
                tempIndex++;
            }
        }
        tempIndex = 0;    
    }

    //calculates the average base on the time variable
    for(int i = 0; i < partialHeight; i++){
       for(int j = 0; j < partialWidth; j++){
            if(partialAvgMatrix[tempIndex] >= 1)
                partialAvgMatrix[tempIndex] /= TIME;
            tempIndex++;
        }
    }    

}

//===========================================================================================
// Save the video (all the frames stored in the 3D Matrix) in the folder named "OUTPUT_VIDEO"
//===========================================================================================
void saveVideo(){
    boost::thread t1(saveVideoInBackground, 1);
    t1.join();
    cout << "Video Saved...\n";
}

void saveVideoInBackground(int id){
    if(video != NULL){
        int videoIndex = 0;        

        for(int k = 0; k < TIME; k++){
            ofstream imageFile;
            string path = VIDEO_OUTPUT_FOLDER + to_string(k) + ".pgm";
            imageFile.open(path.c_str());
            if(imageFile.is_open()){

                //write the magic number
                imageFile << "P2\n";
                //write the width and height of the matrix
                imageFile << WIDTH << " " << HEIGHT << "\n";

                //we must have to calculate the Pixel Max
                int videoIndexMax = videoIndex;
                unsigned int pixelMax = 0;

                for(int i = 0; i < HEIGHT; i++){
                    for(int j = 0; j < WIDTH; j++){
                        if(video[videoIndexMax] > pixelMax)
                            pixelMax = video[videoIndexMax];
                        videoIndexMax++;
                    }
                }

                //write the maximum pixel
                imageFile << pixelMax << "\n";

                //write each pixel in the file
                for(int i = 0; i < HEIGHT; i++){
                    for(int j = 0; j < WIDTH; j++){
                        if(j % 10 == 0 && j != 0)
                            imageFile << "\n";
                        imageFile << video[videoIndex] << " ";
                        videoIndex++;
                    }
                    imageFile << "\n";
                }
                imageFile.close();
            }
        }
    }
    else{
        cout << "No video loaded... Please, load the video...\n";
    }
}


string to_string(int number){

    ostringstream convert;
    convert << number;
    return convert.str();
}