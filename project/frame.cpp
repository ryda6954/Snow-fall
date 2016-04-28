#ifndef FRAME_H
#define FRAME_H

const int width = 30;
const int height = 10;

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
	void random();
	void snow();
};


#endif
