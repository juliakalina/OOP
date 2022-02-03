#include "array.h"
#include <iostream>
#include <ostream>
#include <string>
#include <cstring>


namespace Prog3_3 {

	Array::Array() {
		ar = new char* [1];

		for (int n = 0; n < 1; n++)
		{
			ar[n] = new char[2];
		}
		k = 0;
		i = 1;
	}

	Array::Array(char* word) {
		ar = new char* [1];
		k = 1;
		i = 1;
		ar[0] = new char(strlen(word));
		for (int m = 0; m < strlen(word); m++) {
			ar[0][m] = word[m];
		}
	}

	Array::Array(int num_word, char** words) {
		ar = new char* [num_word];
		k = num_word;
		i = num_word;
		for (int n = 0; n < num_word; n++) {
			ar[n] = new char[sizeof(words[n])+1]{ '\0' };
			//char** ar = new char* [m];
			for (int m = 0; m < sizeof(words[n]); m++) {
				ar[n][m] = words[n][m];
			}
			ar[n][sizeof(words[n])] = '\0';

		/*for (int n = 0; n < num_word; n++) {
			ar[n] = new char [sizeof(words[n])];
			for (int m = 0; m < sizeof(words[n]); m++) {
				ar[n][m] = words[n][m];
				std::copy(ar[n], ar[n] + sizeof(words[n]), words[n]);
			}*/
		} 
	}

	Array::Array(int d) {
		ar = new char* [d];
		/*for (int n = 0; n < d; n++) {
			ar[n] = new char[0];
		}*/
		k = 0;
		i = d;
	}

	Array& Array::setK(int k0)
	{
		if (k0 < 0)
			throw std::exception("invalid radius");
		k = k0;
		return *this;
	}

	Array& Array::setI(int i0)
	{
		if (i0 < 0)
			throw std::exception("invalid radius");
		i = i0;
		return *this;
	}

	Array& Array::operator =(Array&& mas)
	{
		k = mas.k;
		i = mas.i;
		ar = mas.ar;
		mas.ar = nullptr;
		return *this;
	}

	Array& Array::operator =(const Array& mas)
	{
		if (this != &mas) {
			i = mas.i;
			k = mas.k;

			delete[] ar; 

			ar = new char* [k];

			for (int n = 0; n < k; n++) {
				ar[n] = new char[sizeof(mas.ar[n]) + 1]{ '\0' };
				for (int m = 0; m < sizeof(mas.ar[n]); m++) {
					ar[n][m] = mas.ar[n][m];
				}
				ar[n][sizeof(mas.ar[n])] = '\0'; 
			}

				//std::copy(ar[n], ar[n] + sizeof(mas.ar[n]), mas.ar[n]);
		}
		return *this;
	}

	Array::Array(Array&& mas) :i(mas.i), k(mas.k), ar(mas.ar)
	{
		mas.ar = nullptr;
	}

	Array::Array(const Array& mas) : i(mas.i), k(mas.k)
	{
		ar = new char* [k];
		for (int m = 0; m < k; m++)
		{
			std::copy(ar[m], ar[m] + strlen(mas.ar[m]), mas.ar[m]);
		}
	}

	Array::~Array()
	{
		for (int n = 0; n < i; n++) {
			delete[] ar[n];
		}
		//std::cout << "~Array" << std::endl;
		delete[] ar;
	}

	std::string  Array::operator [] (const int l) {
		std::string elem;
		if (l < k) {
			//std::copy(elem.c_str(), elem.c_str() + strlen(ar[l]), ar[l]);
			for (int m = 0; m < strlen(ar[l]); m++) { //+1 (?)
				if (ar[l]) {
					elem += ar[l][m];
				}
			}
			return elem.c_str();
		}
		else throw std::exception("This element is excisted!");
	}

	void Array::init_array() {
		for (int n = 0; n < i; n++) {
			*ar[n] = char(32);
		}
	}

	std::ostream& operator <<(std::ostream& s, const Array& arr) {
		if (arr.k == 0)
			s << "Array is empty";
		else
			for (int n = 0; n < arr.k; n++) {
				s << "[" << char('0' + n) << "]:";
				char* l = new char[strlen(arr.ar[n])+1];
				//std::copy(l, l + strlen(arr.ar[n])+1, arr.ar[n]); 
				strcpy_s(l, strlen(arr.ar[n])+1, arr.ar[n]);
				/*for (int m = 0; m < strlen(arr.ar[n]) + 1; m++) {
					if (arr.ar[n] && ((arr.ar[n][m] | 32) >= 'a' && (arr.ar[n][m] | 32) >= 'A')) {
						s << arr.ar[n][m];
					}
					if (((arr.ar[n][m+1] | 32) >= 'a' && (arr.ar[n][m+1] | 32) >= 'A'))
						continue;
				} */

				s << l << std::endl;
				delete[] l;
			}
		return s;
	}

	std::istream& operator>>(std::istream& s, Array& arr) {
			std::string word;
			int n;
			std::cout << "Enter the num of element: " << std::endl;
			s >> n;
			std::cout << "Enter the element: " << std::endl;
			s >> word;
			if (arr.find(word) == -1) {
				arr.ar[n] = new char [word.size() + 1]{'\0'};
				//char** ar = new char* [m];
				for (int m = 0; m < word.size(); m++) {
					arr.ar[n][m] = word[m];
				}
				arr.ar[n][word.size()] = '\0';
				arr.k++;
			}
			else
			{
				throw std::exception("This element is excisted!");
			}
			return s;
		}
		/*char* p = new char[word.size()];
		for (int a = 0; a < word.size(); a++) {
			p[a] = word.c_str()[a]; 
		}
		//p = (word);
		if (arr.find(word) == -1){
			arr.ar[n] = new char[strlen(word.c_str())];
			std::copy(arr.ar[n], arr.ar[n] + strlen(word.c_str()), p);
		/*
			//for (int j = 0; j < arr.i; j++) {
				//arr.ar[j] = new char[strlen(word.c_str())];
				//std::copy(arr.ar[j], arr.ar[j] + strlen(word.c_str()), &word);
			for ( int j = 0; j < strlen(word.c_str()); j++){
				arr.ar[j] = new char[strlen(word.c_str())];
				arr.ar[n][j] = word.c_str()[j];
			}
			//arr.ar[n][word.size()] = '\0';
			arr.k++;
			//arr.i++; 
		}
		else 
		{
			throw std::exception("This element is excisted!");
		}
		return s;*/

	Array& Array::operator+(std::string word) { 
		if (find(word) == -1) {
			Array hl(1+k);
			for (int n = 0; n < k; n++) {
				hl.ar[n] = new char[strlen(ar[n])+1]{ '\0' }; //+1
				for (int m = 0; m < strlen(ar[n])+1; m++) {
					hl.ar[n][m] = ar[n][m];
				}
				hl.ar[n][strlen(hl.ar[n])] = '\0';
				hl.k++;
			}
			
			hl.ar[k] = new char[word.size()+1]{ '\0' }; //+1
			for (int m = 0; m < word.size(); m++) {
				hl.ar[k][m] = word[m];
			}
			hl.ar[k][word.size()] = '\0';
			hl.k++;

			//delete[] ar;
			
			for (int n = 0; n < i; n++) {
				delete[](ar[n]);
			}
			//std::cout << "~Array" << std::endl;
			delete[] ar;

			ar = new char* [hl.k]; 
			for (int n = 0; n < hl.k; n++) {
				ar[n] = new char [sizeof(hl[n])]{ '\0' };
				for (int m = 0; m < sizeof(hl[n]); m++) {
					ar[n][m] = hl.ar[n][m]; 
				}
				//this[n][sizeof(hl.ar[n])] = '\0';
			}
			k = hl.k;
			i = k;
			return *this;
	}
	else throw std::exception("Can't add word!");
	}
		/*if (find(word) == -1) { 
			Array hl(k+1);  
			for (int n = 0; n < k; n++) {
				hl.ar[n] = new char[strlen((*this).ar[n])]{ '\0' }; //+1
				for (int m = 0; m < strlen((*this).ar[n]); m++) {
					hl.ar[n][m] = ar[n][m];
				}
				//hl.ar[n][(*this)[n].size()] = '\0';
				hl.k++;
			}
			
			hl.ar[k] = new char[word.size()]{ '\0' }; //+1
			for (int m = 0; m < word.size(); m++) {
					hl.ar[k][m] = word.c_str()[m];
			}
			//hl.ar[k][word.size()] = '\0';
			hl.k++; 
				/// /// ///

			delete[] ar;
		
			ar = new char* [k + 1]; /// 


			for (int n = 0; n < hl.k; n++) {
				ar[n] = new char[hl[n].size()]{ '\0' };
				for (int m = 0; m < hl[n].size(); m++) {
					ar[n][m] = hl.ar[n][m];
				}
				//this[n][hl[n].size()] = '\0';
			}
			k = hl.k;
			i = k;
			/// /// /// 
			//hl[5].
			//hl.i++;
			//*this = hl;
			//(*this).ar=hl.ar;
			//(*this).i = hl.i;
			//(*this).k = hl.k;
			//delete[] hl.ar;
			
			return *this;
		}
		throw std::exception("Can't add word!");
	}*/

	int Array::find(std::string word) {
		//std::cout << (*this)[1] << std::endl << std::endl;
		//std::cout << ar[1] << std::endl << std::endl;
		for (int n = 0; n < k; n++) {
			if ((*this)[n] == word) { // word + '\0' = word.c_str()
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

	/*std::string Array::get_by_num(int num) {
		std::string elem;
		int n = 0; 
		while (n != num && n < i) {
			n++;
		}
		if (n == num) {
			for (int m = 0; m < elem.size(); m++) {
				elem = elem + ar[n][m];
			}
			return elem;
		}
		else
			throw std::exception("[ERROR] This word isn't excisted");
	}*/

	Array& Array::operator^=(char symbol) {
		char** s = new char* [k];
		int cnt = 0;
		
		for (int n = 0; n < k; n++) {
			if (((ar[n][0] | 32) >= 'a' && (ar[n][0] | 32) <= 'z') && ((ar[n][0] | 32) == (symbol | 32))) {
				s[cnt] = new char[sizeof(ar[n])];
				for (int m = 0; m < sizeof(ar[n]); m++) {
					s[cnt][m] = ar[n][m];
				}
				cnt++;
			}
		} 
		
		Array nov(cnt, s);

		for (int m = 0; m < cnt; m++) {
			delete[] s[m]; 
		}
		delete[] s; 

		*this = nov; 
		
		return *this;
	}
	
}




