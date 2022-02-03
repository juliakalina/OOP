#include "array.h"
#include <iostream>
#include <ostream>
#include <string>
#include <cstring>


namespace Prog3_2 {

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

	std::string Array::operator [] (const int i)
	{
		std::string elem;
		for (int m = 0; m < j; m++) {
			if (ar[i][m] != char(32)) {
				elem += ar[i][m];
			}
		}
		return elem;
	}

	void Array::init_array() {
		for (int n = 0; n < i; n++) {
			for (int m = 0; m < j; m++) {
				ar[n][m] = char(32); 
			}
		}
	}

	std::ostream& operator <<(std::ostream& s, const Array& arr) {
		Array g=arr;
		if (arr.k == 0)
			s << "Array is empty";
		else
			for (int n = 0; n < arr.i; n++) {
				s << "[" << char('0' + n) << "]:";
				s << g[n]; 
				s << std::endl;
			}
		return s;
	}

	std::istream& operator>>(std::istream& s, Array& arr) {
		std::string word;
		int n, cnt;
		std::cout << "Enter the number of elements" << std::endl;
		s >> cnt;
		while (arr.k < cnt) {
			std::cout << "Enter the num of element: " << std::endl;
			s >> n;
			std::cout << "Enter the element: " << std::endl;
			s >> word;

			if (arr.find(word) == -1) {
				for (int m = 0; m < word.size(); m++) {
					arr.ar[n][m] = word[m];
				}
			}
			else
			{
				throw std::exception("This element is excisted!");
			}
			(arr.k)++;
		}
		return s;
	}

	Array& Array::operator+(std::string word) {
		int d;
		if (k != i && find(word) == -1) {
			for (int n = 0; n < i; n++) {
				if (ar[n][0] == char(32)){
					for (int m = 0; m < word.size(); m++) {
						ar[n][m] = word[m];
					}
					k++;
					return *this;
				}
			}
		}
		else throw std::exception("[ERROR] Can't add word!");
		return*this;
	}

	int Array::find(std::string word) {
			for (int n = 0; n < i; n++) {
				if ((*this)[n] == word) {
					return n;
				}
			}
			return -1;
	}

	Array& Array::operator~() {
		for (int n = 0; n < i; n++) {
			for (int l = 0; l < i - 1; l++) {
				if (strcmp(ar[l], ar[l + 1]) > 0) {
					std::swap(ar[l], ar[l + 1]);
				}
			}
		}
		return *this;
	}

	std::string Array::get_by_num(int num) {
		std::string elem;
		int n = 0;
		while (n != num && n < i) {
			n++;
		}
		if (n == num) {
			for (int m = 0; m < j; m++) {
				elem = elem + ar[n][m]; 
			}
			return elem; 
		}
		else
			throw std::exception("[ERROR] This word isn't excisted");
	}

	Array& Array::operator^=(char symbol) {
		Array nov;
		nov.init_array();
		for (int n = 0; n < i; n++) {
			for (int m = 0; m < j; m++) {
				{ 
					if (((ar[n][0] | 32) >= 'a' && (ar[n][0] | 32) <= 'z') && ((ar[n][0] | 32) == (symbol | 32))) {
						nov.ar[n][m] = ar[n][m];
					}
					//else nov.ar[n][m] = ''; â
				} 
			}
			nov.k++;
		}
		*this = nov;
		return *this;
	}


}




