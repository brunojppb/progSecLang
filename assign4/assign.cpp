//
//  main.cpp
//  Image
//
//  Created by Bruno Paulino on 9/30/14.
//  Copyright (c) 2014 Bruno Paulino. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

//CONSTANTS
//const unsigned int HEIGHT = 418;
//const unsigned int WIDTH  = 312;
//const unsigned int MAX_VALUES = 130416;

const unsigned int HEIGHT = 10;
const unsigned int WIDTH  = 10;
const unsigned int MAX_VALUES = 100;

//==============================================
//STRUCTS
//==============================================
struct Image{
    string fileName;
    unsigned int pixelmap[HEIGHT][WIDTH];
    unsigned int width;
    unsigned int height;
};

struct AverageImage{
    string fileName;
    double pixelmap[HEIGHT][WIDTH];
    unsigned int width;
    unsigned int height;  
};

struct Frame{
    Image *image;
    struct Frame *next;
};

//Head
Frame *head = NULL;


//===============================================
//PROTOTYPES
//===============================================

bool isEmpty(Frame *head);
void showFrameList(Frame *head);
Frame* createNewFrame(const unsigned int imageHeight,
                      const unsigned int imageWidth,
                      const string fileName,
                      Frame **head);

int showMenu();
void loadVideo();
int intLength(int number);
void trim(string &str);
void calculateAverage(Frame *head);

//===============================================
//MAIN
//===============================================
int main() {
    
    int option = showMenu();
    
    switch (option) {
        case 1:
            loadVideo();
            //showFrameList(head);
            calculateAverage(head);
            break;
            
        default:
            break;
    }
    
    
    return 0;
}


//===============================================
//FUNCTIONS
//===============================================

bool isEmpty(Frame *head){
    if (head == NULL)
        return true;
    else
        return false;
}

Frame* createNewFrame(const unsigned int imageHeight,
                 const unsigned int imageWidth,
                 const string fileName,
                 Frame **head){
    
    Frame *newFrame = new Frame;

    if(isEmpty(*head)){
        cout << "Is Empty!!!\n\n";
        newFrame->image = new Image;
        newFrame->image->height = imageHeight;
        newFrame->image->width = imageWidth;
        newFrame->image->fileName = fileName;
        newFrame->next = NULL;
        *head = newFrame;
    }
    else{
        cout << "One more!!!\n\n";
        Frame *currentNode = *head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        newFrame->image = new Image;
        newFrame->image->height = imageHeight;
        newFrame->image->width = imageWidth;
        newFrame->image->fileName = fileName;
        newFrame->next = NULL;
        currentNode->next = newFrame;
    }
    return newFrame;
}

void showFrameList(Frame *head){
    Frame *headCopy = head;
    
    if (head == NULL) {
        cout << "HEAD NULL\n";
    }
    
    while (headCopy != NULL) {
        cout << "Filename: " << headCopy->image->fileName << endl;
        cout << "Memory Address: " << headCopy << endl;
        cout << "pixelmap:\n";
        //output the matrix (debug)
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                cout << headCopy->image->pixelmap[i][j] << " ";
            }
            cout << endl;
        }
        headCopy = headCopy->next;

    }
}

int showMenu(){
    
    int choice;
    cout << "1. Load video" << endl;
    cout << "2. Save video" << endl;
    cout << "3. Save an image frame" << endl;
    cout << "4. Delete a image frame" << endl;
    cout << "5. Calculate the average image frame" << endl;
    cin >> choice;
    return choice;
}

void loadVideo(){
        
    ifstream imageFile;

    for (int imageIndex = 0; imageIndex < 5; imageIndex++) {
        string folder = "test/";
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
        filename += ".pgm";
        imageFile.open(folder + filename);
        
        //try to open the file
        if (imageFile.is_open()) {
            cout << "file: " << filename << " ok" << endl;
            string line;
            string stream = "";
            //Jump the P2 (magic number)
            getline(imageFile, line);
            //jump the height and width of the matrix
            getline(imageFile, line);
            //jump the higher pixel
            getline(imageFile, line);

            //temporary array to store the numbers
            int temp[MAX_VALUES];

            //reading each line and converts the string to numbers
            stringstream ss;
            //count how many number are in the file
            int count = 0;
            while(getline(imageFile, line)){
                trim(line);
                ss << line;
                while(ss.good()){
                    int num;
                    ss >> num;
                    //cout << num << " ";
                    temp[count] = num;
                    count++;
                }
                //cout << endl;
                ss.clear();
            }

            //fill up the pixelmap matrix
            count = 0;
            Frame *frame = createNewFrame(HEIGHT, WIDTH, filename, &head);
            for(int i = 0; i < HEIGHT; i++){
                for(int j = 0; j < WIDTH; j++){
                    frame->image->pixelmap[i][j] = temp[count];
                    count++;
                }
            }
            //output the matrix (debug)
            for(int i = 0; i < HEIGHT; i++){
                for(int j = 0; j < WIDTH; j++){
                    cout << frame->image->pixelmap[i][j] << " ";
                }
                cout << endl;
            }   

            //close the file         
            imageFile.close();
        }
        else{
            cout << "Error: could not open the file" << endl;
        }
    }
    
}

//calculates how many decimal places a integer number has
int intLength(int number){
    int len = 1;
    
    if(number > 0){
        for(len = 0; number > 0; len++)
            number = number/10;
    }
    
    return len;
}

//remove the spaces before and after the string
void trim(string &str){
    string::size_type pos1 = str.find_first_not_of(' ');
    string::size_type pos2 = str.find_last_not_of(' ');
    str = str.substr(pos1 == string::npos ? 0 : pos1, 
    pos2 == string::npos ? str.length() - 1 : pos2 - pos1 + 1);
}

void calculateAverage(Frame *head){
    AverageImage *avg = new AverageImage;
    avg->fileName = "average_image.pgm";
    avg->width = WIDTH;
    avg->height = HEIGHT;

    //fill up the pixelmap with 0
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            avg->pixelmap[i][j] = 0;
        }
    }

    //sum the matrices and calculates how many nodes there are inside the list
    int nodeCount = 0;
    Frame *currentNode = head;
    while(currentNode != NULL){
        cout << "pass through the list...\n";
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                avg->pixelmap[i][j] += currentNode->image->pixelmap[i][j];
            }
        }
        nodeCount++;
        currentNode = currentNode->next;
    }

    //show the avg matrix before the avg calc.
    cout << "Avg matrix before the avg calc.\n";
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            cout << avg->pixelmap[i][j] << " ";
        }
        cout << endl;
    }

    //divide each element by the matrices quantity
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            avg->pixelmap[i][j] = static_cast<double>(avg->pixelmap[i][j]) / nodeCount;
        }
    }

    //show the avg image
    cout << "Avg matrix:\n";
    cout << fixed << setprecision(4);
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            cout << setw(8) << avg->pixelmap[i][j] << " ";
        }
        cout << endl;
    }

}





















