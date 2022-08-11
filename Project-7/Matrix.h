#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#define ROWS 5
#define COLUMNS 5
#include <iostream>

using namespace std;

template<class T>
class Matrix {
    private:
        int rows;
        int columns;
        T **board;
    public:
        Matrix(int rows = ROWS, int columns = COLUMNS);
        Matrix(const Matrix& otherMatrix);
        void display() const;
        void fill();
        int getRows() const;
        int getColumns() const;
        const Matrix<T>& operator=(const Matrix<T>& otherMatrix);
        Matrix<T>& operator+(const Matrix<T>& otherMatrix);
        Matrix<T>& operator-(const Matrix<T>& otherMatrix);
        Matrix<T>& operator*(const int number);
        ~Matrix();
};

#endif // MATRIX_H_INCLUDED
