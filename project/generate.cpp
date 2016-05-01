#include "generate.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>


static inline uint64_t getCycles() //counts computer process to be used as random seeder.
{
  uint64_t t;
  __asm__ __volatile__ ("rdtsc" : "=A"(t));
  return t;
}



Frame* generate(){ 
	char g[width][height];
	for(int j = 0; j < height; j++){
		for(int i = 0; i < width; i++){
			srand(getCycles());			 //seed for random
			int r = (rand() % (int)(1100 - ((1000*(float)j)/(float)(height-1))) + 1); //creates 'randomly' generated grid
			if((r > 100 && r < 1099) || (r > 45 && r < 95)){ //chances for an empty space to occupy spot in grid
				g[i][j] = ' '; //where the empty spot if put into the array
			}
			else{
				g[i][j] = '^'; //where the mountains are put in the array
			}
		}
	}
	
	
	return new Frame(g); //returns the newly generated grid

}
