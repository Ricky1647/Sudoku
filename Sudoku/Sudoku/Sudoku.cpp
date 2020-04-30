// Sudoku.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Sudoku {
public:
	
	static const int length = 9;
	static const int SudokuSize = 81;
	// solve
	void solve(int count);
	bool isValid(int, int, int);
	bool back(int x);
	int inputcell[length][length];
private:
	int map[SudokuSize];
	int cell[length][length];
	bool complete = false;
	bool moreThanOne = false;
};

int main()
{
	cout << "輸入數獨" << endl;
	int a = 0;
	Sudoku su;
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<9; j++) {
			cin >> su.inputcell[i][j];
		}
	}
	for (int i = 0; i<9; i++)
		for (int j = 0; j<9; j++) {
			if (su.inputcell[i][j] != 0)
				a++;
		}
	if (a<17) {
		cout << "有多解" << endl;
		exit(1);
	}
	su.solve(0);
	cout << "無解" << endl;
    return 0;
}

//This is solve
bool Sudoku::back(int x) {
	if (x == 0)
		return complete;
	if (x == 1)
		return moreThanOne;
}


bool Sudoku::isValid(int i, int j, int n) {
	for (int k = 0; k<9; k++)
		if (inputcell[i][k] == n || inputcell[k][j] == n)
			return false;
	//int a=i/3*3,b=j/3*3;
	int a, b = 0;
	if (0 <= i&&i <= 2)a = 0;
	else if (2<i&&i <= 5)a = 3;
	else a = 6;

	if (0 <= j&&j <= 2)b = 0;
	else if (2<j&&j <= 5)b = 3;
	else b = 6;

	for (int k = 0; k<3; k++)
		for (int l = 0; l<3; l++)
			if (inputcell[a + k][b + l] == n)
				return false;
	return true;
}

void Sudoku::solve(int count) {
	int a = 0;
	if (a == 1)return;
	int row = 0;
	if (count >= 0 && count <= 8)row = 0;
	else if (count > 8 && count <= 17)row = 1;
	else if (count > 17 && count <= 26)row = 2;
	else if (count > 26 && count <= 35)row = 3;
	else if (count > 35 && count <= 44)row = 4;
	else if (count > 44 && count <= 53)row = 5;
	else if (count > 53 && count <= 62)row = 6;
	else if (count > 62 && count <= 71)row = 7;
	else if (count > 71 && count <= 80)row = 8;
	int col = count % 9;
	if ((count == 81) && (complete == false)) {
		complete = true;
		a = 1;
		cout << "有唯一解" << endl;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (j == 8)cout << inputcell[i][j];
				else cout << inputcell[i][j] << " ";
				//cell[i][j] = inputcell[i][j];
			}
			cout << endl;
		}
		exit(1);

	}
	else if (count == 81 && complete == true) {
		moreThanOne = true;
		return;
	}
	if (inputcell[row][col] == 0) {
		for (int i = 1; i <= 9; ++i) {
			if (isValid(row, col, i)) {
				inputcell[row][col] = i;
				solve(count + 1);
				if (a == 1)return;
				if (complete && moreThanOne)
					return;
				inputcell[row][col] = 0;
			}
		}
		return;
	}
	else {
		solve(count + 1);
		if (a == 1) return;
	}
}


