#include <iostream>
#include <Windows.h>
#include <iostream>
#include "frame.h"
#include <stdlib.h>
#include "generate.h"
#include <istream>

using namespace std;

int main(){
    ///////////////////////////////////
    char precip;
    string temp;
    cout<<"Enter any type of punctuation for the style of precipitation:"<<endl;
    getline(cin,temp);
    temp.c_str();
    precip = temp[0];
    ///////////////////////////////////

	system("CLS");
	char grid3[width][height] =
	  {
        {'*',' ',' ','#'},
        {' ',' ',' ','#'},
		{'*',' ',' ',' '},
        {' ','*',' ',' '}
    };
	Frame* f = generate(precip);
	f->printFrame();
	f->simulate();

	f->animate();
}
