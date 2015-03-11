#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#define SIZE 4

using namespace std;

/* Print
	for(int colind = 0; colind < SIZE; colind++) {
		for(int rowind = 0; rowind < SIZE; rowind ++) {
			cout << grid[rowind][colind] << "\t";
		}
		cout << endl;
	}
*/

int main() {
	//Open inputconf.txt
	ifstream infile;
	infile.open("inputconf.txt");

	int grid[SIZE][SIZE]={0};
	int temp;
	//If file not found, read default start config into array
	if(!infile.is_open()) {
		grid[SIZE-1][SIZE-1] = 2;
	}
		//Else, read file into array and close file.
	else {
		for(int colind = 0; colind < SIZE; colind++) {
			for(int rowind = 0; rowind < SIZE; rowind++) {
				infile >> temp;
				grid[rowind][colind] = temp;
			}
		}
	}


	
	
	infile.close();
	

	return 0;
	//While game over condition false
		//Read in user command
		//Change array according to command
		//If no of empty elements = 0
			//Check for game over
		//If no of empty elements = 1
			//Add a 2 in one of the empty elements
			//Check for game over
		//If no of empty elements > 1
			//Add a 2 in one of the empty elements
		//Print grid 
		//If game over condition true, print message and return 
	
}



