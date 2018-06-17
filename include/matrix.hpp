#ifndef LAB_5
#define LAB_5
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

class Matrix{
private:
    int **arr;
    int rows;
    int columns;
public:
    Matrix();
    Matrix(int row, int cols);
    ~Matrix();
    int Rows();
    int Columns();
    int Element(int i, int j);
    void Read(string filename);
    void Print();
    Matrix operator+(Matrix& other)const;
    Matrix operator-(Matrix& other)const;
    Matrix operator*(Matrix& other)const;
    Matrix Transp()const ;
    Matrix operator=(Matrix& other)const;
    bool operator==(Matrix& other)const;
    friend ostream& operator<<(ostream& os,const Matrix& other);
    friend istream& operator>>(istream& is, Matrix& other);
};
#endif LAB_5
