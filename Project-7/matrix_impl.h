#ifndef MATRIX_IMPL_H_INCLUDED
#define MATRIX_IMPL_H_INCLUDED
#define ROWS 5
#define COLUMNS 5
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include "Matrix.h"

template<class T>
Matrix<T>::Matrix(int rows, int columns)
{
    if (rows < 0 || columns < 0)
    {
        cerr << "The matrix row and column must be positive. Creating "
            << "a matrix of size rows = " << ROWS << " columns =  " << COLUMNS << " ." << endl;

        this->rows = ROWS;
        this->columns = COLUMNS;
    }
    else {
        this->rows = rows;
        this->columns = columns;
    }

    board = new T*[rows];
    for (int row = 0; row < rows; row++)
        board[row] = new T[columns];

    assert(board != nullptr);
}

template<class T>
Matrix<T>::Matrix(const Matrix& otherMatrix)
{
    rows = otherMatrix.rows;
    columns = otherMatrix.columns;

    board = new T*[rows];
    for (int row = 0; row < rows; row++)
        board[row] = new T[columns];

    assert(board != nullptr);

    for (int row = 0; row < rows; row++)
        for (int column = 0; column < columns; column++)
            board[row][column] = otherMatrix.board[row][column];
}

template<class T>
const Matrix<T>& Matrix<T>::operator=(const Matrix<T>& otherMatrix)
{
    if (this != &otherMatrix)
    {
        for (int row = 0; row < rows; row++)
        {
            delete [] board[row];
            board[row] = nullptr;
        }

        delete[] board;
        board = nullptr;

        rows = otherMatrix.rows;
        columns = otherMatrix.columns;

        board = new T*[rows];
        for (int row = 0; row < rows; row++)
            board[row] = new T[columns];

        assert(board != nullptr);

        for (int row = 0; row < rows; row++)
            for (int column = 0; column < columns; column++)
                board[row][column] = otherMatrix.board[row][column];
    }

    return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator+(const Matrix<T>& otherMatrix)
{
    if (rows != otherMatrix.rows)
    {
        throw runtime_error("The matrix row and column must be equals. Returning the first argument.");
    }

    static Matrix<T> matrix(rows, columns);

    for (int row = 0; row < rows; row++)
        for (int column = 0; column < columns; column++)
            matrix.board[row][column] = board[row][column] + otherMatrix.board[row][column];

    return matrix;
}

template<class T>
Matrix<T>& Matrix<T>::operator-(const Matrix<T>& otherMatrix)
{
    if (rows != otherMatrix.rows)
    {
        throw runtime_error("The matrix row and column must be equals. Returning the first argument.");
    }

    static Matrix<T> matrix(rows, columns);

    for (int row = 0; row < rows; row++)
        for (int column = 0; column < columns; column++)
            matrix.board[row][column] = board[row][column] - otherMatrix.board[row][column];

    return matrix;
}

template<class T>
Matrix<T>& Matrix<T>::operator*(const int number)
{
    static Matrix<T> matrix(rows, columns);

    for (int row = 0; row < rows; row++)
        for (int column = 0; column < columns; column++)
            matrix.board[row][column] = board[row][column] * number;

    return matrix;
}

template<class T>
int Matrix<T>::getRows() const
{
    return rows;
}

template<class T>
int Matrix<T>::getColumns() const
{
    return columns;
}

template<class T>
void Matrix<T>::display() const
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
            cout << setw(5) << board[row][column];

        cout << endl;
    }
}

template<class T>
void Matrix<T>::fill()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cout << "T[" << row + 1 << "][" << column + 1 << "] = ";
            cin >> board[row][column];
        }

        cout << endl;
    }
}

template<class T>
Matrix<T>::~Matrix()
{
    for (int row = 0; row < rows; row++)
    {
        delete [] board[row];
        board[row] = nullptr;
    }

    delete[] board;
    board = nullptr;
}

#endif // MATRIX_IMPL_H_INCLUDED
