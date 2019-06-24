#include "Header.h"
#include "iostream"

using namespace std;

void math(int* pointer)
{
(*pointer) = (*pointer) * 2;
}


int main()
{
	int pointer = 49;
	math(&pointer);
	cout << pointer << endl;


}


//tetris planning
//need to have a random generator to generate the blocks
// have a function for the blocks to fall
// have the falling speed up slowly
// have the blocks dissapear after thr row is full
