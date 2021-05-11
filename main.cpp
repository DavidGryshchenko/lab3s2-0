#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


int** getmat(string fname) {
	int** A = 0;
	A = new int* [4];
	ifstream f(fname);
	for (int i = 0; i < 4; i++) {
		A[i] = new int[4];
		for (int j = 0; j < 4;j++) {
			f >> A[i][j];
		}
	}
	return A;
}
void printmat(int** A) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			cout << A[i][j] << " ";
		}
		cout << "\n";
	}
}
void addmat(int** A, int** B) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << A[i][j] + B[i][j] << " ";
		}
		cout << "\n";
	}
}
void mulmat(int** A, int** B) {
	int i, j, k;
	int res[4][4];
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			res[i][j] = 0;
			for (k = 0; k < 4; k++) {
				res[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}

}
void minmat(int** A) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (A[i][j] != 0) {


				cout << "Val: " << A[i][j] << "; " << "Row: " << i << "; " << "Col: " << j << endl;
			}
		}
	}
}



int main() {
	

	int** A = getmat("matrix.txt");
	int** B = getmat("matrix1.txt");

	

	cout << "Mat1: " << endl;
	printmat(A);
	cout << "\n";

	cout << "Mat2: " << endl;
	printmat(B);
	cout << "\n";

	cout << "Sum: " << endl;
	addmat(A, B);
	cout << "\n";

	cout << "Mul: " << endl;
	mulmat(A, B);
	cout << "\n";

	cout << "Min: " << endl;
	minmat(B);
	cout << "\n";



	return 0;
} 
