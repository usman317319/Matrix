#include <iostream>
using namespace std;

int main()
{
    while(1){
        int cho=0;  //choice
        cout << "SELECT\n1)Define Matrix\n2)Display Matrix\n3)Matrix Multiplication\n: "; cin >> cho;

        switch (cho)
        {
            case 1:
                int mat=0;
                cout << "SELECT (Enter -1 to go back)Matrix\n1)MatrixA\n2)MatrixB\n3)MatrixC\n4)MatrixD\n5)MatrixE\n"; cin >> mat;
                while(mat!=-1){
                        int r=0,c=0;
                        cout << "Enter number of rows: "; cin >> r;
                        cout << "Enter number of columns: "; cin >> c;
                        int matrix[mat-1][r][c];
                        matrix[mat-1][0][0] = r; matrix[mat-1][0][1] = c; matrix[mat-1][0][2]=1;

                        int temp= 0, dig_len=1;
                        cout << "Enter enteries of row (Sperate them with a space)\n";
                        for (int i=1; i<=r; ++i){
                            for (int j=0; j<c; ++j){
                                cin >> matrix[mat-1][i][j];
                                temp = matrix[mat-1][i][j];
                                while (temp > 9 || temp < -9){ temp /= 10; dig_len += 1;}
                                if (matrix[mat][0][2]<dig_len) matrix[mat-1][0][2] = dig_len;
                                dig_len= 0;
                            }
                            if (i!= r) cout << "Row " << i << " completed, Enter the next row\n";
                        }
                    
                    cout << "Matrix " << mat << " completed\nSELECT (Enter -1 to go back)\n1)MatrixA\n2)MatrixB\n3)MatrixC\n4)MatrixD\n5)MatrixD\n";
                    cin >> mat;
                }
        /*
            case 2:
                mat= 0;
                temp=0;
                int sp=0;
                cout << "Select Matrix to be displayed\n1)MatrixA\n2)MatrixB\n3)MatrixC\n4)MatrixD\n5)MatrixE\n: "; cin >> mat;

                for(int i=1; i<= matrix[mat-1][0][0]; ++i)
                    for (int j=0; j< matrix[mat-1][0][1]; ++i){
                        temp = matrix[mat-1][i][j];
                        while (temp > 9 || temp < -9) { temp /= 10; sp += 1;}
                        for (int k=1; k <= matrix[mat-1][0][2] - sp; ++k)
                            cout << " ";
                        sp = 0;
                        cout << matrix[mat -1 ][i][j];
                    }
        */
        }
    }
}
