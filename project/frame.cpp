#include "frame.h"
#include <iostream>
#include "generate.h"
#include<windows.h>
#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>


static inline uint64_t getCycles()
{
  uint64_t t;
  __asm__ __volatile__ ("rdtsc" : "=A"(t));
  return t;
}


Frame::Frame(char grid2[width][height]) {
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			grid[i][j] = grid2[i][j];
		}
	}
	next = NULL;
};




void Frame::printFrame(){
	Sleep(800);
	system("CLS");
	for(int j = 0; j < height; j++){
		for(int i = 0; i < width; i++){
			std::cout<<grid[i][j];
		}
		std::cout<<(char)10;
	}
}

int Frame::snowFall(){
	snow();
	int c = 0;
	for(int i = 0; i < width; i++){
		for(int j = height-1; j >= 0; j--){
			if(grid[i][j] == '*' && (grid[i][j+1] == ' ' || j == height-1)){
				if(j != height-1){
					grid[i][j+1] = '*';
				}
				grid[i][j] = ' ';
				c++;
			}
		}
	}
	return c;
}

void Frame::createNextFrame(){
	next = new Frame(grid);
}

void Frame::simulate(){
	if(snowFall() != 0){
		createNextFrame();
	}
	if(next != NULL)
		next->simulate();
}

void Frame::animate(){
	printFrame();
	if(next != NULL){
		next->animate();
	}
}
void Frame::snow(){
	for(int i = 0; i < width; i++){
		srand(getCycles());
		int y = (rand() % 30);
		if(y <= 1){
		grid[i][0] = '*';
		}
	}
}





