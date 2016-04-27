#include "frame.h"
#include <iostream>


Frame::Frame(char grid2[4][4]) {
	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			grid[i][j] = grid2[i][j];
		}
	}
	next = NULL;
};


void Frame::printFrame(){
	for(int j = 0; j < height; j++){
		for(int i = 0; i < width; i++){
			std::cout<<grid[i][j];
		}
		std::cout<<'\n';
	}
}

int Frame::snowFall(){
	int c = 0;
	for(int i = 0; i < width; i++){
		for(int j = height-1; j >= 0; j--){
			if(grid[i][j] == '*' && grid[i][j+1] == ' '){
				grid[i][j+1] = '*';
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
	int t = 0;
	int w = height*(width + 1);
	while(t != w){
		std::cout<<'\b'<<(char)127;
		t++;
	}
	printFrame();
	if(next != NULL){
		next->animate();
	}
}

















