//Jarrett Philips
//December 7th, 2015

#include <iostream>
#include <string>
#include <vector>

#include "Scanner.h"

using namespace std;

//Constructors
Scanner::Scanner(){

}

Scanner::Scanner(int distance, bool removeNoiseBoolean, int width, int height){
	this->distance = distance;
	this->removeNoiseBoolean = removeNoiseBoolean;
	this->width = width;
	this->height = height;
}

//Functions
//Controls the processing of the image
vector<vector<int> > Scanner::buildEdge(vector<vector<int> > greyVector){
	this->greyVector = greyVector;

	cout << "Filling boolean vector" << endl;
	vector<vector<bool> > unpolishedVector = fillBoolean();

	cout << "Removing noise" << endl;
	vector<vector<bool> > polishedVector = removeNoise(unpolishedVector);

	cout << "Assembling final vector" << endl;
	vector<vector<int> > finalVector(height, std::vector<int>(width));
	finalVector = assemble(polishedVector);
	
	cout << "Returning vector" << endl;
    return finalVector;
}

//Fills the boolean array
//Determines roughly where the edges are
vector<vector<bool> > Scanner::fillBoolean(){
	vector<vector<bool> > booleanVector;
    booleanVector.resize(height);
	for(int i = 0; i < booleanVector.size(); i ++){
		booleanVector[i].resize(width);
	}

    int row = 0;
    int col = 0;

    int centerPixel = 0;
    int bottomPixel = 0;
    int rightPixel = 0;

    for (int row = height - 1; row >= 0; row --){
        for (int col = width - 1; col >= 0; col --){
            //Establishes the two points the method uses to find edges.
            if(row > 0)
                bottomPixel = greyVector[row - 1][col];
            else
                bottomPixel = greyVector[row][col];
            
            if(col > 0)
                rightPixel = greyVector[row][col - 1];
            else
                rightPixel = greyVector[row][col];

            centerPixel = greyVector[row][col];

            //Decides that, should either pixel provide enough differentiation, it will mark that pixel true
            if (getDistance(centerPixel, bottomPixel) > distance || getDistance(centerPixel, bottomPixel) > distance)
                booleanVector[row][col] = true;
            else
                booleanVector[row][col] = false;

        }
    }

    return booleanVector;
}

//Removes some stray specks from the image
vector<vector<bool> > Scanner::removeNoise(vector<vector<bool> > booleanVector){
	//Cleans the distance array by removing outliers (removes noise)
    for(int row = height - 1; row >= 0; row --){
        for(int col = width - 1; col >= 0; col --){
            if(row > 0 && row < height - 1 && col > 0 && col < width - 1){
                //This if statements finds any black pixels surrounded by white, and makes that pixel white, reducing noise.
                if (booleanVector[row][col] == true && booleanVector[row + 1][col] == false && booleanVector[row - 1][col] == false && booleanVector[row + 1][col] == false && booleanVector[row][col - 1] == false)
                    booleanVector[row][col] = false;  
                //This if statements finds any white pixels surrounded by black, and makes that pixel black, reducing noise.
                if (booleanVector[row][col] == false && booleanVector[row + 1][col] == true && booleanVector[row - 1][col] == true && booleanVector[row + 1][col] == true && booleanVector[row][col - 1] == true)
                    booleanVector[row][col] = true;  
            }
        }
    }

    return booleanVector;
}

//Recompiles the boolean array back to rgb values
vector<vector<int> > Scanner::assemble(vector<vector<bool> > booleanVector){
	std::vector<std::vector<int> > finalVector(height, std::vector<int>(width));

    for(int row = height - 1; row >= 0; row --){
        for(int col = width - 1; col >= 0; col --){
            if (booleanVector[row][col] == true)
                finalVector[row][col] = 0;
            else
                finalVector[row][col] = 255;    
        }
    }

    return finalVector;
}

//Gets the difference between two points
int Scanner::getDistance(int p1, int p2){
    //Takes the absolute value of their difference
    int total = p1 - p2;
    if(total < 0)
        total = total * - 1;
        
    return total;
}