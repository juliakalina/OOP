#include <iostream>

namespace Prog1 {

    struct notNull {
        int num, i, j;
    };

    struct matrix {
        int rows, columns;
        notNull* elements;
        int n;
    };

    template <class T>
    int getNum(T& a) {
        std::cin >> a;
        if (!std::cin.good()) {
            return -1;
        }
        return 1;
    }

    int madeBack(int num);
    void printMatrix(matrix* a);
    void printRes(matrix* a);
    void madeRes(struct matrix* a, int m);
    void eraseMatrix(struct matrix* matr);
}
