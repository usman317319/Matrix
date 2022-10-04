#include<iostream>
using namespace std;

int main()
{
	int nr, nc; //nr: RowNumber, nc: ColumnNumber

	cout << "Enter number of rows: "; cin >> nr;
	cout << "Enter numner of columns: "; cin >> nc;

	int matrix[nc][nr];
	/* Following format
	{
	{* * * *},
        {* * * *},
	{* * * *}
	}
	*/

	cout << "Enter elements of rows (seperate them with a space)\nPress Enter before writing elements of next row." << endl;

	for(int i=1; i<=nr; ++i){
		for(int j=1; j<=nc; ++j){
			cin >> matrix[i][j];
		}
		if (i != nr ) cout << "Row " << i << " completed\nEnter the elements for row" << i+1 << endl;
	}
	cout << endl << endl;
	// Displaying the matrix
	cout << "[";
	for (int i=1; i<= nr; ++i){
		for(int j=1; j<= nc; ++j){
			if (j != nc)cout << matrix[i][j] << " ";
			if (j == nc)cout << matrix[i][j];
		}
		if (i != nr) cout << endl << " ";
		if (i == nr) cout << "]";
	}


	return 0;
}
