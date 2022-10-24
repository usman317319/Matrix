#include<iostream>
using namespace std;


int main(){
    int r,c;
    cout << "Enter number of rows: "; cin >> r;
    cout << "Enter number of columns: "; cin >> c;

    int matrix[r][c];

    int temp= 0, max_dig_len= 1;
    cout << "Enter enteries of row (Sperate them with a space)\n";
    for (int i=1; i<=r; ++i){
        for (int j=1; j<=c; ++j){
		cin >> matrix[i][j];
		temp = matrix[i][j];
		    while (temp > 9 || temp < -9){ temp /= 10; max_dig_len += 1;} 
		}
	  if (i!= r) cout << "Row " << i << " completed, Enter the next row\n";
    }


    int sp=0;
    for (int i=1; i<=r; ++i){
        for (int j=1; j<=c; ++j){
		    temp = matrix[i][j];
		    while (temp > 9 || temp < -9) { temp /= 10; sp += 1;}
		    for (int k=1; k<= max_dig_len - sp; ++k)
		        cout << " ";
		sp = 0;
		cout << matrix[i][j];
	  }
        cout << endl;
    }

    return 0;
}
