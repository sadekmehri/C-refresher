#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int randomInt(int low, int high);
void fill(int **p, int rowSize, int columnSize);
void print(int **p, int rowSize, int columnSize);
void deallocate(int **p, int rowSize);

int main()
{
    srand((unsigned int )time(nullptr));
    int **board = nullptr;
    int rows = 0;
    int columns = 0;

    cout << "Enter the number of rows " << "and columns: ";
    cin >> rows >> columns;
    cout << endl;

    board = new int* [rows];
    for (int row = 0; row < rows; row++)
        board[row] = new int[columns];

    fill(board, rows, columns);

    cout << "Board:" << endl;

    print(board, rows, columns);
    deallocate(board, rows);

    delete [] board;
    board = nullptr;

    return 0;
}


int randomInt(int low, int high)
{
    return low + rand() % ( high - low );
}

void fill(int **p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < columnSize; col++)
            p[row][col] = randomInt(0, 5);

        cout << endl;
    }
}

void print(int **p, int rowSize, int columnSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        for (int col = 0; col < columnSize; col++)
            cout << setw(5) << p[row][col];

        cout << endl;
    }
}

void deallocate(int **p, int rowSize)
{
    for (int row = 0; row < rowSize; row++)
    {
        delete [] p[row];
        p[row] = nullptr;
    }
}

