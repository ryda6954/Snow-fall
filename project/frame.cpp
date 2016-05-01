#include "frame.h"
#include <iostream>
#include "generate.h"
#include<windows.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>


static inline uint64_t getCycles() //counts computer processes to be used as seed for random
{
  uint64_t t;
  __asm__ __volatile__ ("rdtsc" : "=A"(t));
  return t;
}


Frame::Frame(char grid2[width][height]) { //initializes Frame with a grid array
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			grid[i][j] = grid2[i][j];
		}
	}
	next = NULL;
};




void Frame::printFrame(){ //prints out the frame
	Sleep(800);  //slows process by 800 ms
 	system("CLS"); //clears screen for next frame
	for(int j = 0; j < height; j++){ //iterates through and prints grid
		for(int i = 0; i < width; i++){
			std::cout<<grid[i][j];
		}
		std::cout<<(char)10; //10 is ascii for new line
	}
}

int Frame::snowFall() { //this moves the "snow" (*)
	snow();
	
	int c = 0;
	for(int i = 0; i < width; i++){
		for(int j = height-1; j >= 0; j--){
			if(grid[i][j] == '*' && (grid[i][j+1] == ' ' || j == height-1)){ //if there is an empty space under * then * is moved and the space it left is empty
				if(j != height-1){
					grid[i][j+1] = '*';
				}
				grid[i][j] = ' ';
				c++; //keeps from crashing by making sure snow is still moving
			}
		}
	}
	return c;
}

void Frame::createNextFrame(){ //makes the next frame
	next = new Frame(grid);
}

void Frame::simulate(){ //creates linked list of frames
	if(snowFall() != 0){
		createNextFrame();
	}
	//else{
		//clearSnow();
		//createNextFrame();  //working on this
	//}
	if(next != NULL)
		next->simulate();
}

void Frame::animate(){  //actually animates all of the frames together
	printFrame();  //prints current frame
	if(next != NULL){ //prints next frame
		next->animate();
	}
}
void Frame::snow(){ //makes snow
	for(int i = 0; i < width; i++){  //snow is created in the top row of the grid
		srand(getCycles());  //random seed
		int y = (rand() % 30); 
		if(y <= 1){  //chances of snow appearing
		grid[i][0] = '*';
		}
	}
}

void Frame::clearSnow(){  //work in progress pay no mind
	for(int i = 0; i < width; i++){
		srand(getCycles());
		int y = (rand() % 30);
		if(y <= 1){
			grid[i][0] = 'v';
		}
	}	
}
