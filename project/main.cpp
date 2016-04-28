#include <iostream>
#include <Windows.h>
#include <iostream>
#include "frame.h"
#include <stdlib.h>
#include "generate.h"

int main(){

	system("CLS");
	char grid3[width][height] = 
	  {
        {'*',' ',' ','#'},
        {' ',' ',' ','#'},
		{'*',' ',' ',' '},
        {' ','*',' ',' '}
    };
	Frame* f = generate();
	f->printFrame();
	f->simulate();

	f->animate();
}
