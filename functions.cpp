#include <iostream>
#include "program1.h"

#include <string>
#include <limits>
#include <cstring>

using namespace std;

namespace program1 {//namespace program1
    int get_num (){ //getting number
        int num;
        while(true)
        {
            cin >> num;
            if(cin.eof())
            {
                throw runtime_error("EOF occurred");
            }
            else if(cin.bad())
            {
                throw runtime_error(string("Couldn't read number: ") + strerror(errno));
            }
            else if(cin.fail() || num < numeric_limits<int>::lowest() || num > numeric_limits<int>::max())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "That was wrong, you might be using non integer type!\n";
            }
            else if(num <= 0)
            {
                cout << "Please enter a positive number!\nHere: ";
            }
            else  //exiting from the loop
            {
                return num;
            }
        }
    }

    Matrix create_matrix () //create() - creates a matrix by input stream
    {
        Matrix matrix;
        int n;//amount of rows and columns
        try
        {
            cout << "Print a number of rows and columns of the matrix:";
            n = get_num ();
            matrix.n = n;
            int sym = 0;//for symmetry of the matrix
            int temp;
            matrix.line = new Line[n]();
            for(int i = 0; i < matrix.n; i++)
            {
                matrix.line[i].n = n;
                matrix.line[i].a = new int[n]();
            }
            for(int i = 0; i < matrix.n; i++)
            {
                cout << "Now, print only <" << n - sym  << "> values of the row number - " << i+1 << ":" << endl;
                for(int j = sym; j < matrix.line[i].n; j++)
                {
                    temp = get_num ();
                    matrix.line[i].a[j] = temp;
                    if(j != i)
                    {
                        matrix.line[j].a[i] = temp;
                    }
                }
                sym++;
            }
        }
        catch(...)
        {
            erase (matrix);
            throw;
        }
        return matrix;
    }

    int findmin_index (Line &list) //finding the minimal index of the row
    {
        if(list.a != nullptr)
        {
            int temp = list.a[0];
            int ind = 0;
            for (int i = 1; i < list.n; i++)
            {
                if (list.a[i] < temp)
                {
                    temp = list.a[i];
                    ind = i;
                }
            }
            return ind;
        }
        else
        {
            cerr << "the array is empty!" << endl;
            return -1;
        }
    }

    Matrix& process_the_matrix (Matrix& old_matrix) //Our general function
    {
        Matrix new_matrix;
        int min;
        int new_ind;
        try {
            new_matrix.n = old_matrix.n;
            new_matrix.line = new Line[old_matrix.n];
            for (int i = 0; i < new_matrix.n; i++) {
                min = findmin_index(old_matrix.line[i]);
                new_matrix.line[i].n = old_matrix.n - min;
                new_matrix.line[i].a = new int[new_matrix.line[i].n]();
                new_ind = 0;
                for (int j = min; j < old_matrix.n; j++) {
                    new_matrix.line[i].a[new_ind] = old_matrix.line[i].a[j];
                    new_ind++;
                }
            }
        }
        catch(...)
        {
            erase (new_matrix);
            throw;
        }
       return new_matrix;
    }

    void output (const Matrix &matrix)//function for outputting a matrix
    {
        Line line;//
        for(int i = 0; i < matrix.n; i++) //rows
        {
            line = matrix.line[i];
            for(int j = 0; j < line.n; j++) //columns
            {
                cout << line.a[j] << " ";
            }
                cout << '\n';
        }
    }

    void erase (Matrix &matrix)   //function to free a matrix
    {    //erasing each row of matrix
        for(int i = 0; i < matrix.n; i++)
        {
            delete[] matrix.line[i].a;
        }
        delete[] matrix.line;   //erasing space for container of rows
        matrix.line = nullptr;
        matrix.n = 0;
    }
}