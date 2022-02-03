#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <string>

namespace Prog3_2 {

	class Array {
	private:
		static const int i = 3, j = 3;
		char ar[i][j];
		int k; //���-�� �������
	public:
		Array();
		Array(char* word);
		Array(int num_word, char** words);

		int getK() const { return k; }
		int getI() const { return i; }

		void init_array();
		friend std::istream& operator >>(std::istream& s, Array& arr); // ���� ����������� ������ �� �������� ������ 
		friend std::ostream& operator <<(std::ostream& s, const Array& arr); // ����� � �������� �����
		Array & operator+ (std::string word);  //���������� ����� � ������� ����
		int find(std::string word);  //����� ����� � �������(��� / ����), ��� ���������� ������� ������� � ������� ����
		std::string get_by_num(int num); //��������� ����� �� ��� ������ � �������
		Array& operator^=(char symbol); //������������ ������� ����, ������������ �� �������� ������ ��� ����� ��������
		Array& operator~();//������������ ���� � ������� �� �������� 
		std::string operator[](const int);
	};
}
#endif
