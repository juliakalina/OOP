#include <iostream>
#include <string>
#include "array.h"
#include "vld.h"

using namespace Prog3_3;

int main() {
	int c, t, cnt;
	int row,d;
	std::string word;
	char s;
	//ar.init_array();

	std::cout << "Enter the number of rows" << std::endl;
	std::cin >> row;
	Array ar(row); 
	//ar.init_array();
	//Array a2(ar); 

	for (int l = 0; l < row; l++) {
		try {
			std::cin >> ar;
		}
		catch (std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}
	}

	do {
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. Output array" << std::endl;
		std::cout << "2. Add element" << std::endl;
		std::cout << "3. Find word" << std::endl;
		std::cout << "4. Print by num" << std::endl;
		std::cout << "5. Sort" << std::endl;
		std::cout << "6. Create new array" << std::endl;

		std::cin >> c;
		switch (c) {
		case 0:
			break;

		case 1:
			try {
				std::cout << ar <<std::endl;

			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;

		case 2:
			std::cout << "Enter the word: " << std::endl;
			std::cin >> word;
			try {
				ar=ar+word;
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;

		case 3:
			std::cout << "Enter the word:" << std::endl;
			std::cin >> word;
			if (std::cin.good()) {
				t = ar.find(word);
				if (t != (-1)) {
					std::cout << "This word is found: [" << t << "] " << " " << word << std::endl;
				}
				else {
					std::cout << "[ERROR] This word isn't found" << std::endl;
				}
			}
			break;

		case 4:
			std::cout << "Enter the number: " << std::endl;
			std::cin >> t;
			if (std::cin.good()) { 
				try {
					std::cout << "This word is found: [" << t << "] " << " " << ar[t] << std::endl;
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			}
			break;

		case 5:
			std::cout << ar.operator~() << std::endl;
			break;

		case 6:
			std::cout << "Enter the symbol: " << std::endl;
			std::cin >> s;
			if (std::cin.good()) {
				ar^=s;
				std::cout << ar << std::endl;
			}
			break;

		default:
			std::cout << "You are wrong! Try again" << std::endl;
			break;
		}
	} while (c != 0);
	return 0; 
}
