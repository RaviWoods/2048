#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#define SIZE 4


using namespace std;

struct element {
   int rowind;
   int colind;
};

bool PushandMerge_RightLeft(int num, int (&grid)[SIZE][SIZE]);
bool PushandMerge_UpDown(int num, int (&grid)[SIZE][SIZE]);
void FindEmptyElements (int (grid)[SIZE][SIZE], vector<element>& emptyelements);
void AddRandomTwo(int (&grid)[SIZE][SIZE], const vector<element>& emptyelements);
bool CheckGameOver(int (grid)[SIZE][SIZE]) ;
void PrintGrid(int (grid)[SIZE][SIZE]);

int main() {
	//Open input file
	cout << "enter initial configuration file name:" << endl;
	string filename;
	cin >> filename;
	ifstream infile;
	infile.open(filename.c_str());
	int grid[SIZE][SIZE]={0};
	int temp;

	//If file not found, read default start config into array
	if(!infile.is_open()) {
		cout << "file not found, using default start configuration" << endl;
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

    bool gameover = false;
    PrintGrid(grid);
	gameover = CheckGameOver(grid);
	if(gameover) {
		cout << "game over" << endl;
		return 0;
	}
	srand((unsigned)time(0));
	while (!gameover) {
	//While game over condition false

		//Change array according to user command, and Print
		string command;
        cin >> command;
		bool changed;

        if(command == "w") {
            changed = PushandMerge_UpDown(0, grid);
        }
        else if(command == "s") {
            changed = PushandMerge_UpDown(3, grid);
        }
        else if(command == "a") {
            changed = PushandMerge_RightLeft(0, grid);
        }
        else if(command == "d") {
            changed = PushandMerge_RightLeft(3, grid);
        }
        else {
            changed = false;
        }

		vector<element> emptyelements;
		FindEmptyElements(grid, emptyelements);
		if(changed) {
			if(emptyelements.size() == 0) {
				gameover = CheckGameOver(grid);
				//If no of empty elements = 0; just check for game over
			}
			else if(emptyelements.size() == 1) {
				AddRandomTwo(grid,emptyelements);
				gameover = CheckGameOver(grid);
				//If no of empty elements = 1; add a two, then check for game over
			}
			else {
				AddRandomTwo(grid,emptyelements);
				//If no of empty elements > 1, just add a two
			}
			//Print grid
			PrintGrid(grid);
		}

		//If game over condition true, print message and return
		if(gameover) {
			cout << "game over" << endl;
		}
	}
	return 0;
}

bool PushandMerge_RightLeft(int num, int (&grid)[SIZE][SIZE]) {
	bool changed = false;
	for(int rowind = 0; rowind < SIZE; rowind++) {
		int a = num;
		int b = num;
		int noofbchanges = 0;
		bool achange = false;
		bool bchange = false;

		while (noofbchanges <= 3){
			bchange = true;
			achange = false;
			
			if(grid[rowind][b] == 0 | a == b) {
				bchange = true;
			}
			//If Index A (Back index) is zero, swap Element A and Element B, so line is "pushed" in correct direction.
			else if(grid[rowind][a] == 0) {
				grid[rowind][a] = grid[rowind][b];
				grid[rowind][b]	= 0;
				bchange = false;
				changed = true;
			}
			else {
				//If Element A and Element B are equal, multiply Element A by 2, and make Element B zero.
				if (grid[rowind][a] == grid[rowind][b]) {
					grid[rowind][a] = 2*grid[rowind][a];
					grid[rowind][b]	= 0;
					bchange = true;
					changed = true;
				}
				//If Element A doesn't equal Element B, only move Index A forward.
				else {
					achange = true;
					bchange = false;
				}
			}
			
			//Move Index A forward if necessary (with "forward" being increment or decrement depending
			if(achange) {
				if(num == 0) {
					a++;
				}
				else if(num == 3) {
					a--;
				}
			}
			else if(bchange) {
				//Move Index B forward if necessary, but do not if it would put it out of range of the array.
				if(noofbchanges != 3) {
					if(num == 0) {
                       	b++;
                    }
                    else if(num == 3) {
                       	b--;
                    }
				}
				noofbchanges++;
			}
		}
	}
	return changed;
}

//Same Function as above, but for the Up & Down pair.
bool PushandMerge_UpDown(int num, int (&grid)[SIZE][SIZE]) {
	bool changed = false;
	for(int colind = 0; colind < SIZE; colind++) {
		int a = num;
		int b = num;
		int noofbchanges = 0;
		bool achange = false;
		bool bchange = false;

		while (noofbchanges <= 3){
			bchange = true;
			achange = false;
			if(grid[b][colind] == 0 || a == b) {
				bchange = true;
			}
			else if(grid[a][colind] == 0) {
				grid[a][colind] = grid[b][colind];
				grid[b][colind]	= 0;
				bchange = false;
				changed = true;
			}
			else if(a != b) {
				if (grid[a][colind] == grid[b][colind]) {
					grid[a][colind] = 2*grid[a][colind];
					grid[b][colind]	= 0;
					bchange = true;
					changed = true;
				}
				else {
					achange = true;
					bchange = false;
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
			else if(bchange) {
				if(noofbchanges != 3) {
                    			if(num == 0) {
                        			b++;
                    			}
                    			else if(num == 3) {
                        			b--;
                    			}
				}
				noofbchanges++;
			}

		}
	}
	return changed;
}

void AddRandomTwo(int (&grid)[SIZE][SIZE],const vector<element>& emptyelements) {
	//Sets a random index [between 0 and (the number of empty elements - 1)] to 2.
	int randomindex = int((emptyelements.size())*rand()/(RAND_MAX));
	grid[emptyelements[randomindex].rowind][emptyelements[randomindex].colind] = 2;
	return;
}

bool CheckGameOver(int (grid)[SIZE][SIZE]) {
	//If every element is different to its adjacent ones (not diagonal), return true.
	bool gameover = true;
	for(int rowind = 0; rowind < SIZE; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			//For the first three rows, it checks whether the element is different to the one below.
			if(rowind != 3) {
				if(grid[rowind][colind] == grid[rowind+1][colind]) {
					gameover = false;
				}
			}
			//For the first three columns, it checks whether the element is different to the one to the right.
			if(colind != 3) {
				if(grid[rowind][colind] == grid[rowind][colind+1]) {
					gameover = false;
				}
			}
		}
	}
	
	return gameover;
}

void FindEmptyElements (int (grid)[SIZE][SIZE], vector<element>& emptyelements) {
	//Finds the index of each elements through simply traversing the grid.
	for(int rowind = 0; rowind < SIZE; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			if(grid[rowind][colind] == 0) {
				element temp;
				temp.rowind = rowind;
				temp.colind = colind;
				emptyelements.push_back(temp);
			}
		}
	}
	return;
}


void PrintGrid(int (grid)[SIZE][SIZE]) {
	//Print the grid by tabbing at each column interval, and ending the line at the end of a row.
	for(int rowind = 0; rowind < SIZE; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			cout << grid[rowind][colind] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	return;
}








