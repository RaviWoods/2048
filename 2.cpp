#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#define SIZE 4

using namespace std;

/* Print
	for(int rowind = 0; rowind < SIZE; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			cout << grid[colind][rowind] << "\t";
		}
		cout << endl;
	}
	cout << endl;
*/

void PushandMerge(int num, int (&grid)[SIZE][SIZE]);

int main() {
	//Open inputconf.txt
	ifstream infile;
	infile.open("inputconf2.txt");
	int grid[SIZE][SIZE]={0};
	int temp;

	//If file not found, read default start config into array
	if(!infile.is_open()) {
		grid[SIZE-1][SIZE-1] = 2;
	}

	//Else, read file into array and close file.
	else {
		for(int rowind = 0; rowind < SIZE; rowind++) {
			for(int colind = 0; colind < SIZE; colind ++) {
				infile >> temp;
				grid[colind][rowind] = temp;
			}
		}
	}

	infile.close();
	
	for(int rowind = 0; rowind < SIZE; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			cout << grid[colind][rowind] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	PushandMerge(0, grid);
	
	for(int colind = 0; colind < SIZE; colind++) {
		for(int rowind = 0; rowind < SIZE; rowind ++) {
			cout << grid[rowind][colind] << "\t";
		}
		cout << endl;
	}
	cout << endl;	
	
	
	

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

void PushandMerge(int num, int (&grid)[SIZE][SIZE]) {
	for(int rowind = 0; rowind < SIZE; rowind++) {
		int a = num;
		int b = num;
		int j = 0;
		int temp = 0;
		bool i = false;

		//two = grid[b][rowind];	
		//one = grid[a][rowind];
		
		while (!i) {
			if(grid[b][rowind] == 0) {
				{};
			}
			else if(grid[a][rowind] == 0) {
				grid[a][rowind] = temp;
				grid[a][rowind] = grid[b][rowind]; 
				grid[b][rowind] = temp;
			}
			else {
				if(a==b) {
					{};
				}
				else if(grid[a][rowind] == grid[b][rowind]) {
					grid[a][rowind] = 2*grid[a][rowind];
					grid[b][rowind] = 0;
					a = b;

				}	
				else if((b-a)>1) {
					if (num == 0) {
						grid[a+1][rowind] = grid[b][rowind];
						grid[b][rowind] = 0;
						a++;
					}
					else {
						grid[a-1][rowind] = grid[b][rowind];
						grid[b][rowind] = 0;
						a--;
					}
					
				}
				else {		
					a = b;
				}
			}
			if(j == 3) {
				i = true;	
			}
			else if (num == 0) {
				b = b + 1;
				j++;
			}
			else if (num == 3) {
				b = b - 1;
				j++;
			}
		}
		
	}
}



