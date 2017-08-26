//Jarrett Philips
//December 7th, 2015

#include <iostream>
#include <string>
#include <vector>

#ifndef Writer_h
#define Writer_h

class Writer{
	private:
		//Variables
		std::string filename;
		std::string destinationName;
	public:
		//Public functions
		Writer();
		Writer(std::string filename, std::string destinationName);
		void writePhoto(std::vector<std::vector<int> > finalVector);
		std::vector<std::vector<int> > readPhoto(std::string filename);
};	

#endif