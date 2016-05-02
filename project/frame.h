#ifndef FRAME_H
#define FRAME_H

const int width = 30;
const int height = 10;

class Frame{
public:
    char precip;
	char grid[width][height];
	int snowFall();
	Frame* next;
	Frame(char grid[width][height], char in_precip);
	void printFrame();
	void createNextFrame();
	void simulate();
	void animate();
	void random();
	void snow();
	void clearSnow();
};


#endif
