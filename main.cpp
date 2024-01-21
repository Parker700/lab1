#include <iostream>
#include "program1.h"

int main() {
    using namespace program1;
    using std::endl;
    using std::cout;

    Matrix matrix; //our matrix
    Matrix nmatrix; //resulting matrix

    try
    {
        matrix = create_matrix (); //creating the matrix
        cout << "That is your matrix: \n";
        output (matrix); //outputting the matrix
        nmatrix = process_the_matrix (matrix);//transforming the matrix
        cout << "That is the resulting matrix: \n";
        output (nmatrix); //outputting it again with transformations
        erase (matrix); //erasing the matrix
        erase (nmatrix); //erasing the matrix
    }
    catch(const std::bad_alloc& ba)
    {
        std::cerr << "A problem with allocation\n";
        erase (matrix);
        return 1;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
        erase (matrix);
        return 1;
    }
    cout << "->Well done!";
    return 0;
}
