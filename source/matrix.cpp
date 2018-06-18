#include <iostream>
#include "matrix.hpp"

Matrix::Matrix():rows(0), columns(0){}
Matrix::Matrix(int row, int cols): rows(row), columns(cols){
    arr = new int*[row];
    for(int i = 0; i < row; i++){
        arr[i] = new int[cols]{};
    }
}
Matrix::~Matrix(){
//        for(int i = 0; i < rows; i++){
//            delete[] arr[i];
//        }
//        delete[] arr;
}

int Matrix::Rows(){
    return rows;
}
int Matrix::Columns(){
    return columns;
}
int Matrix::Element(int i, int j) {
    if (i < rows && j < columns) {
        return arr[i][j];
    }else{
        return 1;
    }
}

void Matrix::Read(string filename) {//данный метод видоизменен, так как ввод матриц в файл при тестировании производится одной строкой и
	//число строк и столбцов в матрицах задается заранее с помощью конструкторов (соответственно не нужна первая строка с числом 
	//строк и столбцов в файлах).
    ifstream file(filename);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            file >> arr[i][j];
        }
    }
}

void Matrix::Print(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout.width(rows);
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
}

Matrix Matrix::operator+(Matrix& other)const{
    assert(rows == other.rows && columns == other.columns);
    Matrix result(other.rows, other.columns);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result.arr[i][j] = arr[i][j] + other.arr[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator-(Matrix& other)const{
    assert(rows == other.rows && columns == other.columns);
    Matrix result(other.rows, other.columns);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            result.arr[i][j] = arr[i][j] - other.arr[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator*(Matrix& other)const{
    assert(columns == other.rows);
    Matrix result(rows, other.columns);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < other.columns; j++){
            int tmp = 0;
            for(int t = 0; t < columns; t++){
                tmp += arr[i][t]*other.arr[t][j];
            }
            result.arr[i][j] = tmp;
        }
    }
    return result;
}
Matrix Matrix::Transp()const{
    Matrix result(columns, rows);
    for (int i = 0; i < rows; i++){
        for( int j = 0; j < columns; j++){
            result.arr[j][i] = arr[i][j];
        }
    }
    return result;
}
Matrix Matrix::operator=(Matrix& other)const{
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            arr[i][j] = other.arr[i][j];
        }
    }
    return *this;
}
bool Matrix::operator==(Matrix& other)const{
    if(rows != other.rows || columns != other.columns){
        return false;
    }else{
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if(arr[i][j] != other.arr[i][j]){
                    return false;
                }
            }
        }
    }
    return true;
}

ostream& operator<<(ostream& os,const Matrix& other){
    for (int i = 0; i < other.rows; i++){
        for (int j = 0; j < other.columns; j++){
            os.width(other.rows);
            os << other.arr[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

istream& operator>>(istream& is, Matrix& other) {

		for (int i = 0; i < other.rows; i++) {

			for (int j = 0; j < other.columns; j++) {

				cout << "arr[" << i << "][" << j << "] = ";

				is >> other.arr[i][j];

			}

		}

		return is;

	}
