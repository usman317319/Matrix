#include <iostream>
using namespace std;

int main()
{
    int matrix[5][5][5] = {0};
    while(1){
        int cho =0, mat=0;  //choice, mat is the matrix number like matrixA (mat=0)
        cout << "SELECT\n1)Define Matrix\n2)Display Matrix\n3)Scalar Multiplication\n4)Matrix Multiplication\n: ";
        cin >> cho;        

        switch (cho)
        {
            case 1:
                mat=0;
                cout << "SELECT (Enter -1 to go back)Matrix\n1)MatrixA\n2)MatrixB\n3)MatrixC\n4)MatrixD\n5)MatrixE\n";
                cin >> mat;
                mat -= 1;
                while(mat!=-2){
                        int r=0,c=0;
                        cout << "Enter number of rows: "; cin >> r;
                        cout << "Enter number of columns: "; cin >> c;
                        //Metadata of a matrix
                        matrix[mat][0][0] = r; //stores the number of rows
                        matrix[mat][0][1] = c; //stores the number of columns
                        matrix[mat][0][2]=1; //stores the length of the biggest number present in the matrix
                        matrix[mat][0][3]= 1; // Stores whether matrix is defined or not (1 means matrix is defined and not defined for all other values)

                        int temp= 0, dig_len=1;
                        cout << "Enter enteries of row (Sperate them with a space)\n";
                        for (int i=1; i<=r; ++i){
                            for (int j=0; j<c; ++j){
                                dig_len= 1;
                                cin >> matrix[mat][i][j];
                                temp = matrix[mat][i][j];
                                while (temp > 9 || temp < -9){ temp /= 10; dig_len += 1; }
                                if (matrix[mat][0][2] < dig_len) matrix[mat][0][2] = dig_len;
                            }
                            if (i!= r) cout << "Row " << i << " completed, Enter the next row\n";
                        }
                    
                    cout << "Matrix " << mat+1 << " completed\nSELECT (Enter -1 to go back)\n1)MatrixA\n2)MatrixB\n3)MatrixC\n4)MatrixD\n5)MatrixD\n";
                    cin >> mat;
                    mat -= 1;
                }
                if (mat == -2) continue;

            case 2:
                mat=0;
                cout << "SELECT Matrix to be displayed\n1)MatrixA    2)MatrixB\n3)MatrixC    4)MatrixD\n5)MatrixE\n: ";
                cin >> mat;
                mat -= 1;
                while (mat != -2){
                    int temp=0, sp=0;
                    if (matrix[mat][0][3] == 1){
                        cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl << endl << endl;
                        for (int i=1; i<=matrix[mat][0][0]; ++i){
                            for (int j=0; j<matrix[mat][0][1]; ++j){
                                temp = matrix[mat][i][j];
                                while (temp > 9 || temp < -9) { temp /= 10; sp += 1;}
                                for (int k=0; k<= matrix[mat][0][2] - sp; ++k)
                                    cout << " ";
                                sp = 0;
                                cout << matrix[mat][i][j];
                            }
                            cout << endl;
                        }
                        cout << endl << endl << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
                        cout << "SELECT Matrix to be displayed\n1)MatrixA    2)MatrixB\n3)MatrixC    4)MatrixD\n5)MatrixD\n: ";
                        cin >> mat;
                        mat -= 1;
                    }
                    else if (matrix[mat][0][3] == 0) {
                        cout << "Please first define the matrix to use it\n"; break;
                    }
                    else if (mat == -2) break;
                }
                break;
            
            case 3:
                mat=0;
                cout << "SELECT Matrix to multiply matrix with(-1 to go back)\n1)MatrixA    2)MatrixB\n3)MatrixC    4)MatrixD\n5)MatrixE\n: ";
                cin >> mat;
                mat -= 1;
                if (matrix[mat][0][3] == 1){
                    while (mat != -2){
                        
                        //SHOWS WHICH MATRIX IS SELECTED
                        cout << "Matrix";
                        switch (mat){
                        case 1:
                            cout << "A";
                            break;
                        case 2:
                            cout << "B";
                            break;
                        case 3:
                            cout << "C";
                            break;
                        case 4:
                            cout << "D";
                            break;
                        case 5:
                            cout << "E";
                            break;
                        }
                        cout << " selected." << endl;

                        //INITIALIZING A VARIABLE THAT WILL HOLD THE VALUE OF THE SCALAR THAT USER INPUTS
                        int scalar=0;
                        //INITIALIZING A MATRIX THAT WILL TEMPORARYLY STORE THE RESULT OF SCALAR MULTIPLICATION
                        const int r = matrix[mat][0][0];
                        const int c = matrix[mat][0][1];
                        int scalarmatrix[r][c];
                        int temp=0, dig_len=1 , max_dig_len=1;  //stores the maxiumum digit length after scalar multiplication
                        cout << "Enter the scalar: ";
                        cin >> scalar;
                        //SELECTS ROW AND GOES OVER COLUMNS
                        for (int i=1; i <= matrix[mat][0][0]; ++i)
                            for (int j=0; j< matrix[mat][0][1]; ++j){
                                scalarmatrix[i][j] = scalar * matrix[mat][i][j];
                                temp = scalarmatrix[i][j];
                                while (temp > 9 || temp < -9) {temp /= 10 ; dig_len += 1;}
                                if (max_dig_len < dig_len) max_dig_len = dig_len;
                                dig_len= 0;
                            }

                        //Displaying the output of scalar multiplication
                        int sp= 0;
                        temp = 0;
                        cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl << endl << endl;
                        for (int i=1; i<=r; ++i){
                            for (int j=0; j<c; ++j){
                                temp = scalarmatrix[i][j];
                                while (temp > 9 || temp < -9) { temp /= 10; sp += 1;}
                                for (int k=0; k<= max_dig_len - sp; ++k)
                                    cout << " ";
                                sp = 0;
                                cout << scalarmatrix[i][j];
                            }
                            cout << endl;
                        }
                        cout << endl << endl << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

                        //UNDER WORK
                        short int yesno = 0;
                        cout << "Do you want to save it or not\n1)Yes     2)No\n:";
                        cin >> yesno;
                        if (yesno == 1){
                            mat=0;
                            int temp= 0, dig_len=1;
                            cout << "SELECT Matrix to store updated values(-1 to go back)\n1)MatrixA    2)MatrixB\n3)MatrixC    4)MatrixD\n5)MatrixE\n: ";
                            cin >> mat;
                            mat -= 1;
                            //Providing the metadata of matrix stored in the main 3d matrix array
                            matrix[mat][0][0] = r;    //updating the row value to metadata
                            matrix[mat][0][1] = c;    //updating the column value to metadata
                            //No need to update the maximum digit length
                            matrix[mat][0][3] = 1;    //updating flag indicator that value is updated
                            //SHOWS WHICH MATRIX IS SELECTED
                            cout << "Matrix";
                            switch (mat){
                            case 1:
                                cout << "A";
                                break;
                            case 2:
                                cout << "B";
                                break;
                            case 3:
                                cout << "C";
                                break;
                            case 4:
                                cout << "D";
                                break;
                            case 5:
                                cout << "E";
                                break;
                            }
                            cout << " selected being UPDATED" << endl;
                            for (int i=1; i <= matrix[mat][0][0]; ++i){
                                for (int j=0; j< matrix[mat][0][1]; ++j){
                                    matrix[mat][i][j] = scalarmatrix[i][j];
                                    temp = scalarmatrix[i][j];
                                    while (temp > 9 || temp < -9) {
                                        temp /= 10;
                                        dig_len += 1;
                                    }
                                    if (matrix[mat][0][2] < dig_len) matrix[mat][0][2] = dig_len;
                                    dig_len= 1;
                                }
                            }
                            cout << "UPDATE COMPLETE" << endl;
                        }
                        cout << "SELECT Matrix to multiply matrix with(-1 to go back)\n1)MatrixA    2)MatrixB\n3)MatrixC    4)MatrixD\n5)MatrixE\n: ";
                        cin >> mat;
                        mat -= 1;
                    }
                }
                else if (matrix[mat][0][3] == 0){
                    cout << "Please first define the matrix to use it\n"; continue;
                }
                break;

            
            case 4:
                int mat1=0, mat2=0;
                cout << "Select any two matrixes to be multiplied(Press -1 to go back)\n1st: ";
                cin >> mat1;
                mat1 -= 1;
                if (matrix[mat1][0][3] == 1){
                    while (mat1 != -2 || mat2 != -2){
                        cout << "Matrix ";
                        switch (mat1){
                            case 0:
                                cout << "A";
                                break;
                            case 1:
                                cout << "B";
                                break;
                            case 2:
                                cout << "C";
                                break;
                            case 3:
                                cout << "D";
                                break;
                            case 4:
                                cout << "E";
                                break;
                            }
                        cout << " selected\n";
                        cout << "2nd: ";
                        cin >> mat2;
                        mat2 -= 1;
                        if (mat2 == -2) break;
                        if (matrix[mat2][0][3] != 1) { cout << "Matrix not defined\n"; break;}
                        switch (mat2){
                            case 0:
                                cout << "A";
                                break;
                            case 1:
                                cout << "B";
                                break;
                            case 2:
                                cout << "C";
                                break;
                            case 3:
                                cout << "D";
                                break;
                            case 4:
                                cout << "E";
                                break;
                            }
                        cout << " selected.\n";
                        

                        //Matrix Multiplication
                        //condition checks either the two selected matrixes are capable of matrix multiplication or not
                        if (matrix[mat1][0][1] == matrix[mat2][0][0]){
                            //Stores number of rows and colums for the resulting matrix after multiplication
                            const int r= matrix[mat1][0][0], c= matrix[mat2][0][1];
                            //Temporary Matrix for storing results for multiplication
                            int R[r][c];
                            int temp=0, dig_len=1, max_dig_len=1;
                            int x=0, pre= 0;
                            for (int i=1; i<=matrix[mat1][0][0]; ++i){
                                for (int j=0; j<matrix[mat2][0][1];  ++j){
                                    for (int k=1; k<=matrix[mat2][0][0]; ++k){
                                        R[i][j] = pre + (matrix[mat1][i][x]*matrix[mat2][x+1][j]);
                                        pre = R[i][j];
                                        x=1;
                                        temp = R[i][j];
                                        while (temp > 9 || temp < -9) {temp /= 10; dig_len += 1;}
                                        if (max_dig_len<dig_len) max_dig_len=dig_len;
                                        dig_len=0;
                                    }
                                pre=0, x=0;
                                }
                            }

                            //Displaying the output of scalar multiplication
                            int sp= 0;
                            temp = 0;
                            cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl << endl << endl;
                            for (int i=1; i<=r; ++i){
                                for (int j=0; j<c; ++j){
                                    temp = R[i][j];
                                    while (temp > 9 || temp < -9) { temp /= 10; sp += 1;}
                                    for (int k=0; k<= max_dig_len - sp; ++k)
                                        cout << " ";
                                    sp = 0;
                                    cout << R[i][j];
                                }
                                cout << endl;
                            }
                            cout << endl << endl << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;


                            //Asking user if he wants to update the value or not
                            short int yesno = 0;
                            cout << "Do you want to save it or not\n1)Yes     2)No\n:";
                            cin >> yesno;
                            if (yesno == 1){
                                mat=0;
                                int temp= 0, dig_len=1;
                                cout << "SELECT Matrix to store updated values(-1 to go back)\n1)MatrixA    2)MatrixB\n3)MatrixC    4)MatrixD\n5)MatrixE\n: ";
                                cin >> mat;
                                mat -= 1;
                                //Providing the metadata of matrix stored in the main 3d matrix array
                                matrix[mat][0][0] = r;    //updating the row value to metadata
                                matrix[mat][0][1] = c;    //updating the column value to metadata
                                //No need to update the maximum digit length
                                matrix[mat][0][3] = 1;    //updating flag indicator that value is updated
                                //SHOWS WHICH MATRIX IS SELECTED
                                cout << "Matrix";
                                switch (mat){
                                    case 1:
                                        cout << "A";
                                        break;
                                    case 2:
                                        cout << "B";
                                        break;
                                    case 3:
                                        cout << "C";
                                        break;
                                    case 4:
                                        cout << "D";
                                        break;
                                    case 5:
                                        cout << "E";
                                        break;
                                }
                                cout << " selected being UPDATED" << endl;
                                for (int i=1; i <= matrix[mat][0][0]; ++i){
                                    for (int j=0; j< matrix[mat][0][1]; ++j){
                                        matrix[mat][i][j] = R[i][j];
                                        temp = R[i][j];
                                        while (temp > 9 || temp < -9) {
                                            temp /= 10;
                                            dig_len += 1;
                                        }
                                        if (matrix[mat][0][2] < dig_len) matrix[mat][0][2] = dig_len;
                                        dig_len= 1;
                                    }
                                }
                                cout << "UPDATE COMPLETE\n" << endl;
                            }
                        }
                        cout << "Select any two matrixes to be multiplied(Press -1 to go back)\n1st: ";
                        cin >> mat1;
                        mat1 -= 1;
                        if (mat1 == -2) break;
                        if (matrix[mat1][0][3] != 1) { cout << "Matrix not defined\n"; break;}
                        cout << "Matrix ";
                        switch (mat1){
                            case 0:
                                cout << "A";
                                break;
                            case 1:
                                cout << "B";
                                break;
                            case 2:
                                cout << "C";
                                break;
                            case 3:
                                cout << "D";
                                break;
                            case 4:
                                cout << "E";
                                break;
                            }
                        cout << " selected\n";
                        cout << "2nd: ";
                        cin >> mat2;
                        mat2 -= 1;
                        if (mat2 == -2) break;
                        if (matrix[mat1][0][3] != 1) { cout << "Matrix not defined\n"; break;}
                        switch (mat2){
                            case 0:
                                cout << "A";
                                break;
                            case 1:
                                cout << "B";
                                break;
                            case 2:
                                cout << "C";
                                break;
                            case 3:
                                cout << "D";
                                break;
                            case 4:
                                cout << "E";
                                break;
                            }
                        cout << " selected.\n";
                    }
                }
                else{
                    cout << "Matrix not defined\n"; continue;
                }
        

            case 5:
                short int op=0;
                cout << "Choose Operation\n1)Addition (+)        2)Subtraction (-)\n3)Multiplication (x)        4)Division (/)\n: ";
                cin >> op;
                switch(op){
                    case 1:
                        int mats[5] = {0};
                        cout << "Select Matrixes for addition\n1)MatrixA    2)MatrixB\n3)MatrixC    4)MatrixD\n5)MatrixE\n: ";
                        cin >> mats[0];
                        mats[0] -= 1;
                        if (matrix[mats[0]][0][3] == 1){
                            for (int i=1; i<5 ,++i){
                                cout << "Select Matrixes for addition\n1)MatrixA    2)MatrixB\n3)MatrixC    4)MatrixD\n5)MatrixE\n: ";
                                cin >> mats[i];
                                if (matrix[mats[i]][0][3] == ) cout << "Matrix not defined\nSelect another\n: "; --i;
                            }
                        }
                }





        
        }
    }
}
