//Jarrett Philips
//December 7th, 2015

#include <iostream>
#include <string>
#include <vector>

#ifndef Scanner_h
#define Scanner_h

class Scanner{
	private:
		//Variables
		std::vector<std::vector<int> > greyVector;
		int width;
		int height;
		int distance;
		bool removeNoiseBoolean;

		//Private functions
		int getDistance(int p1, int p2);
		std::vector<std::vector<bool> > fillBoolean();
		std::vector<std::vector<bool> > removeNoise(std::vector<std::vector<bool> > booleanVector);
		std::vector<std::vector<int> > assemble(std::vector<std::vector<bool> > booleanVector);
	public:
		//Public functions
		Scanner();
		Scanner(int distance, bool removeNoise, int width, int height);
		std::vector<std::vector<int> > buildEdge(std::vector<std::vector<int> > greyVector);
};

#endif