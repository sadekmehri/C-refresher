#include <iostream>
#include "matrix_impl.h"

using namespace std;

int main()
{
    Matrix<int> matrix(2,2);
    cout << "Matrix of size rows = " << matrix.getRows() << " columns =  " << matrix.getColumns() << " ." << endl;
    matrix.fill();
    Matrix<int> matrix1(2,5);
    Matrix<int> matrix2;

    try{
        matrix1 = matrix + matrix;
        matrix1.display();
        matrix1 = matrix1 * 2;
        matrix1.display();
    }
    catch(const runtime_error &ex){
        cerr << ex.what();
    }

    return 0;
}
