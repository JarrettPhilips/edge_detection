//Jarrett Philips
//December 7th, 2015

#include <iostream>
#include <string>
#include <vector>

#include "Scanner.h"
#include "Writer.h"

using namespace std;

int main(int argc, char *argv[]){
	//Collecting input from user
	string filename = argv[1];
	string destinationName = argv[2];
	int edgeDistance = stoi(argv[3]);

	//Reading in the image
	Writer writer = Writer(filename, destinationName);
	cout << "Reading image" << endl;
	vector<vector<int> > greyVector = writer.readPhoto(filename);

	//Processing the image
	cout << "Processing image" << endl;
	Scanner scanner = Scanner(edgeDistance, true, greyVector[0].size(), greyVector.size());
	vector<vector<int> > finalVector = scanner.buildEdge(greyVector);
	
	//Writing the new image
	cout << "Writing image" << endl;
	writer.writePhoto(finalVector);

	cout << "Done" << endl;
}