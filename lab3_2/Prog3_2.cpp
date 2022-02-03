#include <iostream>
#include <string>
#include "array.h"
#include "vld.h"

using namespace Prog3_2;

int main() {
	int c, t, cnt;
	Array ar;
	std::string word=ar[0]; 
	char s;

	ar.init_array();

	do {
		std::cout << "0. Exit" << std::endl;
		std::cout << "1. Input array" << std::endl;
		std::cout << "2. Output array" << std::endl;
		std::cout << "3. Add element" << std::endl;
		std::cout << "4. Find word" << std::endl;
		std::cout << "5. Print by num" << std::endl;
		std::cout << "6. Sort" << std::endl;
		std::cout << "7. Create new array" << std::endl;

		std::cin >> c;
		switch (c) {
		case 0:
			break;

		case 1:
			try {
				std::cin >> ar;
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;

		case 2:
			try {
				std::cout << ar <<std::endl;

			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;

		case 3:
			std::cout << "Enter the word: " << std::endl;
			std::cin >> word;
			try {
				ar+word;
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;

		case 4:
			std::cout << "Enter the word:" << std::endl;
			std::cin >> word;
			if (std::cin.good()) {
				t = ar.find(word);
				if (ar.find(word) != (-1)) {
					std::cout << "This word is found: [" << t << "] " << " " << word << std::endl;
				}
				else {
					std::cout << "[ERROR] This word isn't found" << std::endl;
				}
			}
			break;

		case 5:
			std::cout << "Enter the number: " << std::endl;
			std::cin >> t;
			if (std::cin.good()) {
				try {
					std::cout << "This word is found: [" << t << "] " << " " << ar.get_by_num(t) << std::endl;
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			}
			break;

		case 6:
			std::cout << ar.operator~() << std::endl;
			break;

		case 7:
			std::cout << "Enter the symbol: " << std::endl;
			std::cin >> s;
			if (std::cin.good()) {
				ar ^= s;
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
