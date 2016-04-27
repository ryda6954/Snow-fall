#ifndef FRAME_H
#define FRAME_H

const int width = 4;
const int height = 4;

class Frame{
public:
	char grid[width][height];
	int snowFall();
	Frame* next;	
	Frame(char grid[width][height]);
	void printFrame();
	void createNextFrame();
	void simulate();
	void animate();
};


#endif