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

void PushandMerge_RightLeft(int num, int (&grid)[SIZE][SIZE]);
void PushandMerge_UpDown(int num, int (&grid)[SIZE][SIZE]);
void PrintGrid(int (&grid)[SIZE][SIZE]);

int main() {
	//Open inputconf.txt
	ifstream infile;
	infile.open("inputconf4.txt");
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
				grid[rowind][colind] = temp;
			}
		}
	}

	infile.close();
	string command;
	PrintGrid(grid);
	cin >> command;

	if(command == "w") {
		PushandMerge_UpDown(0, grid);
	}
	else if(command == "s") {
		PushandMerge_UpDown(3, grid);
	}
	else if(command == "a") {
		PushandMerge_RightLeft(0, grid);
	}
	else if(command == "d") {
		PushandMerge_RightLeft(3, grid);
	}
	PrintGrid(grid);
	



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

void PushandMerge_RightLeft(int num, int (&grid)[SIZE][SIZE]) {
	for(int rowind = 0; rowind < SIZE; rowind++) {
		int a = num;
		int b = num;
		int noofadvances = 0;
		int zeronum = 0;
		bool achange = false;
		bool advance = false;

		while (noofadvances <= 3){
			advance = true;
			achange = false;
			if(grid[rowind][b] == 0 ) {
				zeronum++;
				advance = true;
			}
			else if(a == b) {
				advance = true;
			}
			else if(grid[rowind][a] == 0) {
				grid[rowind][a] = grid[rowind][b];
				grid[rowind][b]	= 0;
				advance = false;
			}
			else if(a != b) {
				if (grid[rowind][a] == grid[rowind][b]) {
					grid[rowind][a] = 2*grid[rowind][a];
					grid[rowind][b]	= 0;
					zeronum++;
					advance = true;
				}
				else {
					achange = true;
					advance = false;
				}
			}

			if(achange) {
				if(num == 0) {
					a++;
				}
				else if(num == 3) {
					a--;
				}
			}
			else if(advance) {
				if(noofadvances != 3) {
                    			if(num == 0) {
                        			b++;
                    			}
                    			else if(num == 3) {
                        			b--;
                    			}
				}
				noofadvances++;
			}

		}
	}
}

void PushandMerge_UpDown(int num, int (&grid)[SIZE][SIZE]) {
	for(int colind = 0; colind < SIZE; colind++) {
		int a = num;
		int b = num;
		int noofadvances = 0;
		bool achange = false;
		bool advance = false;

		while (noofadvances <= 3){
			advance = true;
			achange = false;
			if(grid[b][colind] == 0 || a == b) {
				advance = true;
			}
			else if(grid[a][colind] == 0) {
				grid[a][colind] = grid[b][colind];
				grid[b][colind]	= 0;
				advance = false;
			}
			else if(a != b) {
				if (grid[a][colind] == grid[b][colind]) {
					grid[a][colind] = 2*grid[a][colind];
					grid[b][colind]	= 0;
					advance = true;
				}
				else {
					achange = true;
					advance = false;
				}
			}

			if(achange) {
				if(num == 0) {
					a++;
				}
				else if(num == 3) {
					a--;
				}
			}
			else if(advance) {
				if(noofadvances != 3) {
                    			if(num == 0) {
                        			b++;
                    			}
                    			else if(num == 3) {
                        			b--;
                    			}
				}
				noofadvances++;
			}

		}
	}
}


void PrintGrid(int (&grid)[SIZE][SIZE]) {
	for(int rowind = 0; rowind < SIZE; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			cout << grid[rowind][colind] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}






