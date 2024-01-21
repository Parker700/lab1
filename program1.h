#ifndef LAB1_PROGRAM1_H
#define LAB1_PROGRAM1_H

#include <iostream>

namespace program1 {
    //Structures for defining a matrix
    struct Line {
        int n = 0;
        int *a = nullptr;
    };
    struct Matrix {
        int n = 0;
        Line *line = nullptr;
    };

    //prototypes of the useful functions
    int get_num ();
    Matrix create_matrix ();
    int findmin_index (Line &list);
    Matrix &process_the_matrix (Matrix& matrix);
    void output (const Matrix& matrix);
    void erase (Matrix &matrix);
}

#endif //LAB1_PROGRAM1_H
