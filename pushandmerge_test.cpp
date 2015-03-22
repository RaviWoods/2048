#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#define SIZE 4
#define SIZE2 5

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

void PushandMerge(int num, int (&grid)[SIZE2][SIZE]);

int main() {
	//Open inputconf.txt
	ifstream infile;
	infile.open("inputconf4.txt");
	int grid[SIZE2][SIZE]={0};
	int temp;

	//If file not found, read default start config into array
	if(!infile.is_open()) {
		grid[SIZE2-1][SIZE-1] = 2;
	}

	//Else, read file into array and close file.
	else {
		for(int rowind = 0; rowind < SIZE2; rowind++) {
			for(int colind = 0; colind < SIZE; colind ++) {
				infile >> temp;
				grid[rowind][colind] = temp;
			}
		}
	}

	infile.close();

	/*
	for(int rowind = 0; rowind < SIZE2; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			cout << grid[rowind][colind] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	*/

	PushandMerge(3, grid);

	for(int rowind = 0; rowind < SIZE2; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			cout << grid[rowind][colind] << " , " << "\t";
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

void PushandMerge(int num, int (&grid)[SIZE2][SIZE]) {
	for(int rowind = 0; rowind < SIZE2; rowind++) {
		int a = num;
		int b = num;
		int j = 0;
		bool i = false;
		bool advance = false;

		//two = grid[rowind][b]
		//one = grid[rowind][a]

		while (j <= 3){
			advance = true;
			i = false;
			if(grid[rowind][b] == 0 || a == b) {
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
					advance = true;
				}
				else {
					i = true;
					advance = false;
				}
			}

			if(i) {
				if(num == 0) {
					a++;
				}
				else if(num == 3) {
					a--;
				}
			}
			else if(advance) {
				if(j != 3) {
                    if(num == 0) {
                        b++;
                    }
                    else if(num == 3) {
                        b--;
                    }
				}
				j++;
			}
			/*
			for(int colind = 0; colind < SIZE; colind ++) {
                cout << grid[colind][rowind] << "\t";
            }
            cout << "a = " << a << "b = " << b << endl;
            cout << endl;
            */
		}
		//cout << endl;
	}
}



