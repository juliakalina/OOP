#include "vld.h"
#include <iostream>
#include "matrix.h"

using namespace Prog1;

int main() {
        matrix* a = new matrix;
        int m, n; 
        int amount;

        std::cout << "Enter number of rows [m]: ";
        getNum(m);

        std::cout << "Enter number of columns [n]: ";
        getNum(n);

        std::cout << "Enter number of not null items: ";
        getNum(amount);
        if (amount >= (m * n)/2) {
            std::cout << "[ERROR]"<< "\n" << "Not sparse matrix!" << std::endl;
            eraseMatrix(a);
            return 0;
        }

        a->rows = m;
        a->columns = n;
        a->elements = new notNull[amount];

        std::cout << "--- now input values ---" << std::endl;
        int input;
        for (a->n = 0; a->n < amount; a->n++) {
            std::cout << a->n + 1 << ")\titem: " << std::endl;
            std::cout << "\tEnter value: ";

            getNum(a->elements[a->n].num);

            std::cout << "\tEnter row:";
            getNum(a->elements[a->n].i);
            if (a->elements[a->n].i > a->rows - 1) {
                std::cout << "[ERROR]" << std::endl;
                delete a->elements;
                a->elements = nullptr;
                eraseMatrix(a);
                return 1;
            }
            std::cout << "\tEnter column:";
            getNum(a->elements[a->n].j);
            if (a->elements[a->n].j > a->columns - 1) {
                std::cout << "[ERROR]" << std::endl;
                delete a->elements;
                a->elements = nullptr;
                eraseMatrix(a);
                return 1;
            }
        }
        std::cout << "\n" << std::endl;
        std::cout << "Matrix: " << "\n" << std::endl;

        printMatrix(a);
        madeRes(a, m);
        
        std::cout << "Result: "<<"\n" << std::endl;
        printRes(a);
        delete a->elements;
        a->elements = nullptr;
        eraseMatrix(a);
        return 0;
    }
