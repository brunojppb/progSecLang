//
//
//  Created by Bruno Paulino on 9/30/14.
//  Copyright (c) 2014 Bruno Paulino. All rights reserved.
//
//This program loads a sequence of images and calculates the average image
//also save delete images from memory and save the images in the hard disk

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

//TEST VALUES
// const unsigned int HEIGHT = 10;
// const unsigned int WIDTH  = 10;
// const unsigned int MAX_VALUES = 100;
// const unsigned int NUMBER_OF_FRAMES = 5;

//CONSTANTS
const unsigned int HEIGHT = 418;
const unsigned int WIDTH  = 312;
const unsigned int MAX_VALUES = HEIGHT * WIDTH;
const unsigned int NUMBER_OF_FRAMES = 109;
const string FRAME_OUTPUT_FOLDER = "OUTPUT_FRAME/";
const string VIDEO_OUTPUT_FOLDER = "OUTPUT_VIDEO/";
const string AVG_OUTPUT_FOLDER = "OUTPUT_AVG/";

//==============================================
//STRUCTS
//==============================================
struct Image{
    string fileName;
    unsigned int pixelmap[HEIGHT][WIDTH];
    unsigned int pixelMax;
    unsigned int width;
    unsigned int height;
};

//The average image needs to be a little bit diferent
//because the average is a float point number
struct AverageImage{
    string fileName;
    double pixelmap[HEIGHT][WIDTH];
    double pixelMax;
    unsigned int width;
    unsigned int height;  
};

struct Frame{
    Image *image;
    struct Frame *next;
};

//Head of the list of frames
Frame *head = NULL;


//===============================================
//FUNCTIONS PROTOTYPES
//===============================================

//LIST MANIPULATION
bool isEmpty(Frame *head);
void showFrameList(Frame *head);
Frame* createNewFrame(const unsigned int imageHeight,
                      const unsigned int imageWidth,
                      const string fileName,
                      Frame **head);
void deleteFrame(string filename, Frame **head);
void saveFrame(string filename, string folder, Frame *head);
void saveVideo(Frame *head);
int listLength(Frame *head);

//MENU OPERATIONS
int showMenu();
void loadVideo();
int intLength(int number);
void trim(string &str);
void calculateAverage(Frame *head);

//===============================================
//MAIN FUNCTION
//===============================================
int main() {
    string filename;
    int option = 0;

    while(option != 6){

        option = showMenu();

        switch (option) {
        case 1:
            loadVideo();
            break;

        case 2:
            saveVideo(head);
            break;
        
        case 3:
            if(isEmpty(head)){
                cout << "Please, load the video...\n";
                break;
            }
            cout << "enter the name of the frame (e.g. \"005.pgm\"): ";
            cin >> filename;
            saveFrame(filename, FRAME_OUTPUT_FOLDER, head);
            break;

        case 4:
            if(isEmpty(head)){
                cout << "Please, load the video...\n";
                break;
            }
            cout << "enter the name of the frame to be deleted (e.g. \"005.pgm\"): ";
            cin >> filename;
            deleteFrame(filename, &head);
            break;

        case 5:
            calculateAverage(head);
            break;

        case 6:
            cout << "Thank you...\n";
            break;

        default:
            cout << "Choose a valid option.\n";
            break;
        }
    };
    
    
    return 0;
}


//===============================================
//FUNCTIONS
//===============================================

//===============================================
//tests if the list is empty or not
//===============================================
bool isEmpty(Frame *head){
    if (head == NULL)
        return true;
    else
        return false;
}

//===============================================
//Create a new Frame and inserts in the list
//===============================================
Frame* createNewFrame(const unsigned int imageHeight,
                 const unsigned int imageWidth,
                 const string fileName,
                 Frame **head){
    try{

        Frame *newFrame = new Frame;

        //INSERT THE FIRST NODE OF THE LIST
        if(isEmpty(*head)){
            newFrame->image = new Image;
            newFrame->image->height = imageHeight;
            newFrame->image->width = imageWidth;
            newFrame->image->fileName = fileName;
            newFrame->next = NULL;
            *head = newFrame;
        }
        //INSERT THE NEW NODE AT THE END OF THE LIST
        else{
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
    catch(bad_alloc){
        cout << "Insufficient memory. Plese, close other programs or buy more memory\n";
        return NULL;
    }
}

//===============================================
//Shows the frames stored in the memory (List)
//===============================================
void showFrameList(Frame *head){
    Frame *headCopy = head;
    
    if (head == NULL) {
        cout << "The List is empty.\n";
    }
    
    while (headCopy != NULL) {
        cout << "Filename: " << headCopy->image->fileName << endl;
        cout << "Memory Address: " << headCopy << endl;
        headCopy = headCopy->next;

    }
}

//===============================================================
//Calculates the length of the list (How many frames in the list)
//===============================================================
int listLength(Frame *head){
    if (head == NULL)
    {
        return 0;
    }

    Frame *node = head;
    int count = 0;
    while(node != NULL){
        node = node->next;
        count++;
    }
    return count;
}

//===============================================================
//Show the main menu
//===============================================================
int showMenu(){
    
    int choice;
    cout << "1. Load video" << endl;
    cout << "2. Save video" << endl;
    cout << "3. Save an image frame" << endl;
    cout << "4. Delete an image frame" << endl;
    cout << "5. Calculate the average image frame" << endl;
    cout << "6. Exit"<< endl;
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

    for (int imageIndex = 0; imageIndex <= NUMBER_OF_FRAMES; imageIndex++) {
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
        imageFile.open(folder + "/" + filename);
        
        //try to open the file
        if (imageFile.is_open()) {
            cout << "file: " << filename << " ok" << endl;
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
            //store the max value of the matrix
            int pixelmax = 0;
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
                    //obtain the maximum value of the matrix (pixel)
                    if(num > pixelmax)
                        pixelmax = num;
                }
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

            frame->image->pixelMax = pixelmax;

            //close the file         
            imageFile.close();
        }
        //error trying to open the file
        else{
            cout << "Error: could not open the file" << endl;
        }
    }
    
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

//================================================================================
// Calculates the average image and save in the folder named "OUTPUT_AVG"
//================================================================================
void calculateAverage(Frame *head){
    if(isEmpty(head)){
        cout << "Please, load the video...\n";
        return;
    }
    AverageImage *avg = new AverageImage;
    avg->fileName = "average_image.pgm";
    avg->width = WIDTH;
    avg->height = HEIGHT;

    //fill up the pixelmap matrix with 0
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            avg->pixelmap[i][j] = 0;
        }
    }

    //sum the matrices and calculates how many nodes there are inside the list
    int nodeCount = 0;
    Frame *currentNode = head;
    while(currentNode != NULL){
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                avg->pixelmap[i][j] += currentNode->image->pixelmap[i][j];
            }
        }
        nodeCount++;
        currentNode = currentNode->next;
    }

    //divide each element of the matrix by the matrices number
    double avgPixelMax = 0;
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            avg->pixelmap[i][j] = static_cast<float>(avg->pixelmap[i][j]) / static_cast<float>(nodeCount);
            if(avg->pixelmap[i][j] > avgPixelMax)
                avgPixelMax = avg->pixelmap[i][j];
        }
    }
    //store the maximum pixel of the average image
    avg->pixelMax =avgPixelMax;

    ofstream imageFile;
    string path = AVG_OUTPUT_FOLDER + avg->fileName;
    imageFile.open(path);
    if(imageFile.is_open()){

        //write the magic number
        imageFile << "P2\n";
        //write the width and height of the matrix
        imageFile << WIDTH << " " << HEIGHT << "\n";
        //write the maximum pixel
        imageFile << avg->pixelMax << "\n";

        //write the matrix on the file following the pattern of the original file
        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                if(j % 10 == 0 && j != 0)
                    imageFile << "\n";
                imageFile << avg->pixelmap[i][j] << " ";
            }
            imageFile << "\n";
        }

        //close the file
        imageFile.close();
        cout << "Average Frame saved in the folder named \"OUTPUT_AVG\".\n";

    }
    else{
        cout << "Error: could not open the file...\n";
    }
}

//================================================================================
// Save a especific frame in the folder named "OUTPUT_FRAME"
//================================================================================
void saveFrame(string filename, string folder, Frame *head){
    if(isEmpty(head)){
        cout << "No video loaded... Please, load the video first...\n";
        return;
    }
    Frame *searchFrame = NULL;

    Frame *currentNode = head;
    while(currentNode != NULL){

        if(filename.compare(currentNode->image->fileName) == 0){
            searchFrame = currentNode;
            break;
        }

        currentNode = currentNode->next;
    }

    if (searchFrame == NULL){
        cout << "There is no frame named " << filename << endl;
        return;    
    }

    ofstream imageFile;
    string path = folder + "OUT_" + searchFrame->image->fileName;
    imageFile.open(path);
    if(imageFile.is_open()){

        imageFile << "P2\n";
        imageFile << WIDTH << " " << HEIGHT << "\n";
        imageFile << searchFrame->image->pixelMax << "\n";

        for(int i = 0; i < HEIGHT; i++){
            for(int j = 0; j < WIDTH; j++){
                if(j % 10 == 0 && j != 0)
                    imageFile << "\n";
                imageFile << searchFrame->image->pixelmap[i][j] << " ";
            }
            imageFile << "\n";
        }

        //close the file
        imageFile.close();


    }
    else{
        cout << "Error: could not open the file...\n";
    }
}


//========================================================================================
// Save the video (all the frames stored in the memory) in the folder named "OUTPUT_VIDEO"
//========================================================================================
void saveVideo(Frame *head){

    if(!isEmpty(head)){
        Frame *currentNode = head;
        cout << "saving video... please, wait...\n";
        while(currentNode != NULL){
            saveFrame(currentNode->image->fileName, VIDEO_OUTPUT_FOLDER, head);
            currentNode = currentNode->next;
        }
        cout << "Video saved in the folder named \"OUTPUT_VIDEO\".\n\n";
    }
    else{
        cout << "No video loaded... Please, load the video...\n";
    }
}

//========================================================================================
// Delete from the list an especific frame
//========================================================================================
void deleteFrame(string filename, Frame **head){
    if(isEmpty(*head)){
        cout << "No video loaded... Please, load the video...\n";
        return;
    }
    Frame *nodeToRemove = NULL;
    Frame *nodeBefore = NULL;
    Frame *nodeAfter = NULL;
    Frame *currentNode = *head;
    int index = 0;

    bool found = false;

    //To remove nodes from the single linked list we have 3 especific cases:
    //
    //    - Remove the first node of the list
    //    - Remove a node between two nodes
    //    - Remove the last node of the list
    //
    while(currentNode != NULL){
        index++;
        if(currentNode->image->fileName.compare(filename) == 0){
            found = true;
            nodeToRemove = currentNode;
            //===================================================
            //FIRST CASE
            //===================================================
            //We need to remove the first node of the list
            if(index == 1){
                *head = currentNode->next;
                delete nodeToRemove;
            }
            //===================================================
            //SECOND CASE
            //===================================================
            //we need to remove the last node of the list
            else if(index == listLength(*head)){
                nodeBefore = *head;
                //store the reference of the node before the node to remove
                while(nodeBefore->next->image->fileName.compare(nodeToRemove->image->fileName) != 0)
                    nodeBefore = nodeBefore->next;
                nodeBefore->next = NULL;
                delete nodeToRemove;
            }
            //===================================================
            //THIRD CASE
            //===================================================
            //we need to remove a node between two nodes
            else{
                nodeBefore = *head;
                //store the reference of the node before the node to remove
                while(nodeBefore->next->image->fileName.compare(nodeToRemove->image->fileName) != 0)
                    nodeBefore = nodeBefore->next;
                nodeAfter = nodeToRemove->next;
                delete nodeToRemove;
                nodeBefore->next = nodeAfter;
            }
            //stop the while loop
            break;
        }

        //jump to the next node
        currentNode = currentNode->next;
    };

    if(!found){
        cout << "There is no frame named " << filename << " inside the list.\n";
    }else{
        cout << "Frame " << filename << " deleted...\n\n";
    }
}