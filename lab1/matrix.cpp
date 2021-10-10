#include "matrix.h"
#include <iostream>

namespace Prog1 {

	int madeBack(int num) {
		int rem, reverse = 0;
		while (num > 0) {
			rem = num % 10;
			reverse = reverse * 10 + rem;
			num /= 10;
		}
		return reverse;
	}

	void madeRes(struct matrix* a, int m) {
		for (int i = 0; i < a->rows; i++) {
			for (int j = 0; j < a->columns; j++) {
				for (int n = 0; n < a->n; n++) {
					if ((a->elements[n].i == i) && (a->elements[n].j == j)) {
						a->elements[n].num = madeBack(a->elements[n].num);
					}
				}
			}
		}
	}


	void eraseMatrix(struct matrix* matr) {
			delete matr; 
			matr = nullptr;
	}

	void printMatrix(matrix* a) {
		for (int i = 0; i < a->rows; i++) {
			for (int j = 0; j < a->columns; j++) {
				for (int n = 0; n < a->n; n++) {
					if ((a->elements[n].i == i) && (a->elements[n].j == j)) {
						std::cout << a->elements[n].num << " ";
						break;
					}
					if (n == a->n - 1) {
						std::cout << "0 ";
					}
				}
			}
			std::cout << std::endl;
		}
	}

	void printRes(matrix* a) {
		for (int i = 0; i < a->rows; i++) {
			for (int j = 0; j < a->columns; j++) {
				for (int n = 0; n < a->n; n++) {
					if ((a->elements[n].i == i) && (a->elements[n].j == j)) {
						std::cout << a->elements[n].num << " ";
						break;
					}
					if (n == a->n - 1) {
						std::cout << "0 ";
					}
				}
			}
			std::cout << std::endl;
		}
	}
}
