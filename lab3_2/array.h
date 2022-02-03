#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <string>

namespace Prog3_2 {

	class Array {
	private:
		static const int i = 3, j = 3;
		char ar[i][j];
		int k; //кол-во зан€тых
	public:
		Array();
		Array(char* word);
		Array(int num_word, char** words);

		int getK() const { return k; }
		int getI() const { return i; }

		void init_array();
		friend std::istream& operator >>(std::istream& s, Array& arr); // ввод экземпл€ров класса из входного потока 
		friend std::ostream& operator <<(std::ostream& s, const Array& arr); // вывод в выходной поток
		Array & operator+ (std::string word);  //добавление слова к массиву слов
		int find(std::string word);  //поиск слова в массиве(нет / есть), при совпадении указать позицию в массиве слов
		std::string get_by_num(int num); //выделение слова по его номеру в массиве
		Array& operator^=(char symbol); //формирование массива слов, начинающихс€ на заданный символ без учета регистра
		Array& operator~();//упор€дочение слов в массиве по алфавиту 
		std::string operator[](const int);
	};
}
#endif
