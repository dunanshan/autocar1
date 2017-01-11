//
// autocar project communication
//
// 2017.01.08
//
// Author: dunanshan@163.com (DU Nanshan)
//
// generate a grid map for autocar project.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[])
{
	if ((argc != 2) && (argc != 5))
	{
                cout << "error!!!" << endl;
		cout << "Usage: genMap mapfilename [lenX lenY unitLength]" << endl;
		return 0;
	}

        // default value
	long lenX = 1000;
        long lenY = 1500;
        double unitLength = 0.2;
	if (argc == 5)
	{
		lenX = stol(argv[2]);
		lenY = stol(argv[3]);
                unitLength = stod(argv[4]);
	} 

	char* grid = new char[lenX * lenY];
	srand(time(NULL));
	for (long i = 0; i < lenX; i++)
		for (long j = 0; j < lenY; j++)
		{
			grid[i*lenX + j] = rand() % 10;
		}


	for (long i = lenX / 4; i < lenX - lenX / 4; i++)
		for (long j = lenY / 4; j < lenY - lenY / 4; j++)
		{
			grid[i*lenX + j] = 0;
		}

	ofstream of(argv[1]);
        cout << "sizeof(lenX) = " << sizeof(lenX) << endl;
        cout << "sizeof(lenY) = " << sizeof(lenY) << endl;
        cout << "sizeof(unitLength) = " << sizeof(unitLength) << endl;
        cout << "contents(\"|\" not in file): lenX|lenY|unitLength|char[lenX*lenY]" << endl;
	of.write((const char*)&lenX, sizeof(lenX));
	of.write((const char*)&lenY, sizeof(lenY));
        of.write((const char*)&unitLength, sizeof(unitLength));
	of.write(grid, lenX * lenY);

        delete [] grid;

	return 0;
}

