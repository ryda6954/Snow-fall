#include <iostream>
#include <Windows.h>
#include "frame.h"

int main(){
	char grid3[4][4] = 
	  {
        {'*','*',' ','#'},
        {'*',' ',' ','#'},
		{' ',' ',' ','#'},
        {' ','*',' ','#'}
    };
	Frame f(grid3);
	f.simulate();
	f.printFrame();
	f.animate();
}