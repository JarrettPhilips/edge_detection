//Jarrett Philips
//December 7th

#include <iostream>
#include <string>
#include <vector>

#include "Writer.h"
//#define cimg_use_jpeg
#include "CImg.h"

using namespace cimg_library;

//Constructors
Writer::Writer(){

}

Writer::Writer(std::string filename, std::string destinationName){
	this->filename = filename;
	this->destinationName = destinationName;
}

//Functions
//Write a new image
void Writer::writePhoto(std::vector<std::vector<int> > finalVector){
	CImg<float> original(filename.c_str());
	CImg<float> image = original;
	for(int i = image.height() - 1; i >= 0; i --){
		for(int j = image.width() - 1; j >= 0; j --){
			image(j, i, 0) = finalVector[j][i];
			image(j, i, 1) = finalVector[j][i];
			image(j, i, 2) = finalVector[j][i];
		}
	}

	image.save(destinationName.c_str());
}

//Reads in an image
std::vector<std::vector<int> > Writer::readPhoto(std::string filename){
	const CImg<float> image(filename.c_str());

	//Creates a grey-scale array of the image
	std::vector<std::vector<int> > greyVector(image.width(), std::vector<int>(image.height()));

	for(int i = image.height() - 1; i >= 0; i --){
		for(int j = image.width() - 1; j >= 0; j --){
			int grey = (image(j, i, 0) + image(j, i, 1) + image(j, i, 2)) / 3; 
			greyVector[j][i] = grey;
		}
	}


	return greyVector;
}