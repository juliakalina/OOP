#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <string>

using namespace std;

namespace Prog3_3 {

	class Array {
	private:
		//static const int step = 5;
		int i; //���-�� ����� �����
		char** ar;
		int k; //���-�� �������
	public:
		Array();
		Array(char* word);
		Array(int num_word, char** words);
		Array(int d);
		Array(const Array&); // ���������� ����������� 
		Array(Array&&);

		int getK() const { return k; }
		int getI() const { return i; }
		Array& setK(int k0);
		Array& setI(int i0);
		Array& operator =(Array&& mas);
		Array& operator =(const Array& mas); 

		~Array();//����������
		
		void init_array();
		friend std::istream& operator >>(std::istream& s, Array& arr); // ���� ����������� ������ �� �������� ������ 
		friend std::ostream& operator <<(std::ostream& s, const Array& arr); // ����� � �������� �����
		Array& operator+ (std::string word);  //���������� ����� � ������� ����
		int find(std::string word);  //����� ����� � �������(��� / ����), ��� ���������� ������� ������� � ������� ����
		//std::string get_by_num(int num); //��������� ����� �� ��� ������ � �������
		Array& operator^=(char symbol); //������������ ������� ����, ������������ �� �������� ������ ��� ����� ��������
		Array& operator~();//������������ ���� � ������� �� �������� 
		std::string operator[](const int);
	};
}
#endif
