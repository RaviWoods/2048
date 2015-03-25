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

void PushandMerge_RightLeft(int num, int (&grid)[SIZE][SIZE]);
void PushandMerge_UpDown(int num, int (&grid)[SIZE][SIZE]);
void FindEmptyElements (int (grid)[SIZE][SIZE], vector<element>& emptyelements);
void AddRandomTwo(int (&grid)[SIZE][SIZE], const vector<element>& emptyelements);
bool CheckGameOver(int (grid)[SIZE][SIZE]) ;
void PrintGrid(int (grid)[SIZE][SIZE]);

int main() {
	//Open inputconf.txt
	ifstream infile;
	infile.open("inputconf3.txt");
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

    PrintGrid(grid);
	bool gameover = false;
	srand((unsigned)time(0));
	while (!gameover) {
	//While game over condition false

		//Change array according to user command, and Print
		string command;
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

		vector<element> emptyelements;
		FindEmptyElements(grid, emptyelements);
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

		//If game over condition true, print message and return
		if(gameover) {
			cout << "game over" << endl;
		}

	}
}

void PushandMerge_RightLeft(int num, int (&grid)[SIZE][SIZE]) {
	for(int rowind = 0; rowind < SIZE; rowind++) {
		int a = num;
		int b = num;
		int noofadvances = 0;
		bool achange = false;
		bool advance = false;

		while (noofadvances <= 3){
			advance = true;
			achange = false;
			if(grid[rowind][b] == 0 ) {
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

void AddRandomTwo(int (&grid)[SIZE][SIZE],const vector<element>& emptyelements) {
	int randomindex = int((emptyelements.size())*rand()/(RAND_MAX));
	grid[emptyelements[randomindex].rowind][emptyelements[randomindex].colind] = 2;
	return;
}

bool CheckGameOver(int (grid)[SIZE][SIZE]) {
	bool gameover = true;
	for(int rowind = 0; rowind < SIZE; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			if(rowind != 3) {
				if(grid[rowind][colind] == grid[rowind+1][colind]) {
					gameover = false;
				}
			}
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
	for(int rowind = 0; rowind < SIZE; rowind++) {
		for(int colind = 0; colind < SIZE; colind ++) {
			cout << grid[rowind][colind] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	return;
}








