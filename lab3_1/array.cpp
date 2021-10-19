#include "array.h"
#include <iostream>
#include <ostream>
#include <string>
#include <cstring>


namespace Prog3_1 {

	Array::Array() {
		char ar[i][j];
		k = 0;
	}

	Array::Array(char* word) {
		char ar[i][j];
		k = 1;
		for (int n = 0; n < j; n++) {
			ar[0][n] = word[n];
		}
	}

	Array::Array(int num_word, char** words) {
		char ar[i][j];
		k = num_word;
		for (int n = 0; n < num_word; n++) {
			for (int m = 0; m < j; m++) {
				ar[n][m] = words[n][m];
			}
		}
	}

	void Array::init_array() {
		for (int n = 0; n < i; n++) {
			for (int m = 0; m < j; m++) {
				ar[n][m] = char(32);
			}
		}
	}

	void Array::input() {
		std::string word;
		int n, cnt;
		std::cout << "Enter the number of elements" << std::endl;
		std::cin >> cnt;
		while (k < cnt) {
			std::cout << "Enter the num of element: " << std::endl;
			std::cin >> n;
			std::cout << "Enter the element: " << std::endl;
			std::cin >> word;

			if (find(word) == -1) {
				for (int m = 0; m < word.size(); m++) {
					ar[n][m] = word[m];
				}
			}
			else
			{
				throw std::exception("This element is excisted!");
			}
			k++;
		}
	}

	std::string Array::output() {
		std::string massiv;
		if (ar != 0) { 
			massiv += "ARRAY\n";
			for (int n = 0; n < i; n++) {
				massiv = massiv + "[" + char('0'+n) + "]:";
				for (int m = 0; m < j; m++) {
					massiv+= ar[n][m];
				}
				massiv += "\n";
			}
			return massiv;
		}
		else throw std::exception("Array is empty!");
		//return massiv;
	}

	void Array::add(std::string word, int d) {
		if (k != i && find(word) == -1 && d < i) {
			for (int m = 0; m < word.size(); m++) {
				ar[d][m] = word[m];
			}
			k++;
		}
		else throw std::exception("[ERROR] Can't add word!");
	}

	int Array::find(std::string word) {
		int n;
		bool f_is = false;
		for (n = 0; n < i; n++) {
			int r = 0;
			for (int m = 0; m < word.size(); m++) {
				if (ar[n][m] == word[m]) {
					f_is = true;
					r++;
					if (r == word.size() && !((ar[n][m + 1] < 'z' && ar[n][m + 1] > 'a') || (ar[n][m + 1] < 'Z' && ar[n][m + 1] > 'A')))

						return n;
				}
				else
					f_is = false;
			}

		}
		return -1;
	}

	void Array::sort() {
		std::string massiv;
		char hl;
		for (int n = 0; n < i; n++) {
			for (int l = 0; l < i - 1; l++) {

				if (ar[l][0] > ar[l + 1][0]) {
					for (int m = 0; m < j; m++) {
						std::swap(ar[l][m], ar[l + 1][m]); 
					}
				}
			}
		}
	}
			

	void Array::print_by_num(int num) {
		int n = 0;
		while (n != num && n < i) {
			n++;
		}
		if (n == num) {
			for (int m = 0; m < j; m++) {
				std::cout << ar[n][m];
			}
			std::cout << std::endl;
		}
		else
			throw std::exception("[ERROR] This word isn't excisted");
	}

	std::string Array::new_array(char symbol) {
		Array nov;
		nov.init_array();
		for (int n = 0; n < i; n++) {
			for (int m = 0; m < j; m++) {
				{
					if (((ar[n][0] | 32) >= 'a' && (ar[n][0] | 32) <= 'z') && ((ar[n][0] | 32) == (symbol | 32))) {
						nov.ar[n][m] = ar[n][m];
					}
					else nov.ar[n][m] = char(32); 
				}
			}
		}
		return nov.output();
	}


}




