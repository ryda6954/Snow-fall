#include "frame.h"
#include "generate.h"
#include <iostream>
#include <Windows.h>
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



 Frame* generate(){
	char g[width][height];
	for(int j = 0; j < height; j++){
		for(int i = 0; i < width; i++){
			srand(getCycles());			
			int r = (rand() % (int)(1100 - ((1000*(float)j)/(float)(height-1))) + 1);
			if((r > 100 && r < 1099) || (r > 45 && r < 95)){
				g[i][j] = ' ';
			}
			else{
				g[i][j] = '^';
			}
		}
	}
	
	
	return new Frame(g);

}