#include <iostream>
#include <string>
#include "array.h"
#include "vld.h"

using namespace Prog3_1;

int main() {  
	int c,t,l,d;
	Array ar;
	std::string word;
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
				ar.input();
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;

		case 2:
			try {
				std::cout<<ar.output();
				
			}
			catch (std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
			break;

		case 3:
			std::cout << "Enter the num of element: " << std::endl;
			std::cin >> d;
			std::cout <<"Enter the word: " << std::endl;
			std::cin >> word;
			try {
				ar.add(word, d);
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
			std::cin >> l;
			if (std::cin.good()) {
				try {
					ar.print_by_num(l);
				}
				catch (std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			}
			break;

		case 6:
			ar.sort();
			std::cout<<ar.output();
			break;

		case 7:
			std::cout << "Enter the symbol: " << std::endl;
			std::cin >> s;
			if (std::cin.good()) {
				ar.new_array(s);
				std::cout << ar.new_array(s);
			}
			break;

		default:
			std::cout << "You are wrong! Try again" << std::endl;
			break;
		}
	} while (c != 0);
	return 0;
}
