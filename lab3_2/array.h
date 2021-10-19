#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <string>

namespace Prog3_1 {

	class Array {
	private:
		static const int i=3, j=3;
		char ar[i][j];
		int k; //кол-во занятых
	public:
		Array();
		Array(char* word);
		Array(int num_word, char** words);

		void init_array();
		void input(); // ввод экземпляров класса из входного потока 
		std::string output(); // вывод в выходной поток
		void add(std::string word, int d);  //добавление слова к массиву слов
		int find(std::string word);  //поиск слова в массиве(нет / есть), при совпадении указать позицию в массиве слов
		void print_by_num(int num); //выделение слова по его номеру в массиве
		std::string new_array(char symbol); //формирование массива слов, начинающихся на заданный символ без учета регистра
		void sort();//упорядочение слов в массиве по алфавиту
		
	};
}
#endif
