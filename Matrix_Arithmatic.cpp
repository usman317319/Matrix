#include <iostream>
#include <iomanip>
using namespace std;
class Matrix
{
    int Rows = 0;
    int Cols = 0;
    int **matrix = new int *[Rows];
    void alloc_Rows()
    {
        for (int i = 0; i < Rows; i++)
            matrix[i] = new int[Cols];
    }
    friend ostream &operator<<(ostream &out, Matrix m);
    friend istream &operator>>(istream &input, Matrix m);
    friend Matrix operator*(int x, Matrix &m);
    friend Matrix operator*(Matrix &m ,int x);
    inline int **get_matrix() { return matrix; }
    inline int get_rows() { return Rows; }
    inline int get_cols() { return Cols; }

public:
    Matrix()
    {
        Rows = 1;
        Cols = 1;
    }
    Matrix(int rows, int cols)
    {
        if (rows > 0 && cols > 0)
        {
            Rows = rows;
            Cols = cols;
            alloc_Rows();
        }
        else
            exit(1);
    }

    void find(int &lesser, int &grater)
    {
        grater = matrix[0][0];
        for (int i = 0; i < Rows; i++)
            for (int j = 0; j < Cols; j++)
                if (matrix[i][j] > grater)
                    grater = matrix[i][j];
                else
                    lesser = matrix[i][j];
    }
    // Matrix transpose(){

    // }
    Matrix operator+(Matrix &m2)
    {
        Matrix Sum(m2.get_rows(), m2.get_cols());
        if (Rows == m2.Rows && Cols == m2.Cols)
        {
            int **sum = Sum.get_matrix();
            int **op2 = m2.get_matrix();
            for (int i = 0; i < Rows; i++)
                for (int j = 0; j < Cols; j++)
                    sum[i][j] = matrix[i][j] + op2[i][j];
        }
        else
            exit(1);
        return Sum;
    }
    Matrix operator-(Matrix &m2)
    {
        Matrix Sub(m2.get_rows(), m2.get_cols());
        if (Rows == m2.Rows && Cols == m2.Cols)
        {
            int **sub = Sub.get_matrix();
            int **op2 = m2.get_matrix();
            for (int i = 0; i < Rows; i++)
                for (int j = 0; j < Cols; j++)
                    sub[i][j] = matrix[i][j] - op2[i][j];
        }
        else
            exit(1);
        return Sub;
    }
    Matrix operator*(Matrix &m2)
    {
        Matrix Mul(Rows, m2.get_cols());
        int **op2 = m2.get_matrix();
        int **mul = Mul.get_matrix();
        if (Cols == m2.Rows)
        {
            for (int i = 0; i < Rows /*R1*/; i++)
            {
                for (int j = 0; j < m2.get_cols() /*C2*/; j++)
                {
                    mul[i][j] = 0;
                    for (int k = 0; k < m2.get_rows() /*R2*/; k++)
                    {
                        mul[i][j] += matrix[i][k] * op2[k][j];
                    }
                }
            }
        }
        else
            exit(1);
        return Mul;
    }
};
// For left scaler
Matrix operator*(int x , Matrix &m)
{
    Matrix Mul(m.get_rows(),m.get_cols());
    int **mul=Mul.get_matrix();
    int **mat = m.get_matrix();
    for (int i = 0; i < m.get_rows(); i++)
        for (int j = 0; j < m.get_cols(); j++)
            mul[i][j] = x * mat[i][j];
    return Mul;
}
// For right scaler
Matrix operator*(Matrix &m ,int x)
{
    Matrix Mul(m.get_rows(),m.get_cols());
    int **mul=Mul.get_matrix();
    int **mat = m.get_matrix();
    for (int i = 0; i < m.get_rows(); i++)
        for (int j = 0; j < m.get_cols(); j++)
            mul[i][j] = x * mat[i][j];
    return Mul;
}


ostream &operator<<(ostream &out, Matrix m)
{
    int spaces = 6;
    int lesser, grater;
    m.find(lesser, grater);
    if (grater >= 1000)
        spaces *= 2;
    else if (lesser < 0)
        spaces++;
    for (int i = 0; i < m.Rows; i++)
    {
        for (int j = 0; j < m.Cols; j++)
            out << setw(spaces) << m.matrix[i][j];
        out << endl;
    }
    return out;
}

istream &operator>>(istream &input, Matrix m)
{
    for (int i = 0; i < m.Rows; i++)
    {
        cout << "Enter Row " << i + 1 << " elements" << endl;
        for (int j = 0; j < m.Cols; j++)
        {
        if_error:
            input >> m.matrix[i][j];
            if (!input)
            {
                input.clear();
                input.ignore();
                cout << "Invalid...(Enter again)\n";
                goto if_error;
            }
        }
    }
    return input;
}

int main()
{
    int rows, cols;
    cout << "Enter number of rows of Matrix A: ";
    cin >> rows;
    cout << "Enter number of columns of Matrix A: ";
    cin >> cols;
    Matrix m1(rows, cols);
    cout << "Enter number of rows of Matrix B: ";
    cin >> rows;
    cout << "Enter number of columns of Matrix B: ";
    cin >> cols;
    Matrix m2(rows, cols);
    Matrix result;
    cout << "Matrix 1" << endl;
    cin >> m1;
    cout << "Matrix 2" << endl;
    cin >> m2;
    cout << "Matrix 1" << endl;
    cout << m1 << endl;
    cout << "Matrix 2" << endl;
    cout << m2;
    result = m1 + m2;
    cout << "Sum" << endl;
    cout << result;
    cout << "Sub" << endl;
    result = m1 - m2;
    cout << result;
    cout << "Mul" << endl;
    result = m1 * m2;
    cout << result;
    //scaler to the left 
    result = 5 * m1;
    cout << result;
    //scaler to the right
    result = m1 * 2;
    cout << result;
    return 0;
}
