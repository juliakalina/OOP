#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <string>

using namespace std;

namespace Prog3_3 {

	class Array {
	private:
		//static const int step = 5;
		int i; //кол-во строк всего
		char** ar;
		int k; //кол-во зан€тых
	public:
		Array();
		Array(char* word);
		Array(int num_word, char** words);
		Array(int d);
		Array(const Array&); // копирующий конструктор 
		Array(Array&&);

		int getK() const { return k; }
		int getI() const { return i; }
		Array& setK(int k0);
		Array& setI(int i0);
		Array& operator =(Array&& mas);
		Array& operator =(const Array& mas); 

		~Array();//деструктор
		
		void init_array();
		friend std::istream& operator >>(std::istream& s, Array& arr); // ввод экземпл€ров класса из входного потока 
		friend std::ostream& operator <<(std::ostream& s, const Array& arr); // вывод в выходной поток
		Array& operator+ (std::string word);  //добавление слова к массиву слов
		int find(std::string word);  //поиск слова в массиве(нет / есть), при совпадении указать позицию в массиве слов
		//std::string get_by_num(int num); //выделение слова по его номеру в массиве
		Array& operator^=(char symbol); //формирование массива слов, начинающихс€ на заданный символ без учета регистра
		Array& operator~();//упор€дочение слов в массиве по алфавиту 
		std::string operator[](const int);
	};
}
#endif
