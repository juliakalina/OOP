#include "pch.h"
#include "gtest\gtest.h"
#include <iostream>
#include <Windows.h>
#include "C:\Users\yul20\Desktop\labs\3sem\lab3_3\lab3_3\array.h"
#include "C:\Users\yul20\Desktop\labs\3sem\lab3_3\lab3_3\array.cpp"

TEST(Methods, GetK)
{
	Prog3_3::Array a1;
	a1.setK(2);
	ASSERT_EQ(2, a1.getK());
}

TEST(Methods, GetI)
{
	Prog3_3::Array a1;
	a1.setI(3);
	ASSERT_EQ(3, a1.getI());
}

/*TEST(Methods, Setters) {
	Prog3_3::Array a1;
	a1.setI(2);
	a1.setK(2);
	ASSERT_EQ(2, a1.getI());
	ASSERT_EQ(2, a1.getK());
	ASSERT_ANY_THROW(a1.setK(-4));
	ASSERT_ANY_THROW(a1.setI(-4));
}*/


/*TEST(Methods, SquareBrackets)
{
	Prog3_3::Array a1;

}*/

TEST(Methods, Plus)
{
	Prog3_3::Array a1;
	std::string massiv;
	a1 = a1 + "qwe";
	massiv = massiv + a1[0] + " ";
	a1 = a1 + "zxc";
	massiv = massiv + a1[1] + " ";
	ASSERT_EQ("qwe zxc ", massiv);
	a1 = a1 + "asd";
	massiv = massiv + a1[2] + " ";
	ASSERT_EQ("qwe zxc asd ", massiv);
}

TEST(Methods, Find)
{
	Prog3_3::Array a1;
	a1.init_array();
	a1 = a1 + "asd";
	a1 = a1 + "qwe";
	a1 = a1 + "zxc";
	ASSERT_EQ(0, a1.find("asd"));
	ASSERT_EQ(2, a1.find("zxc"));
	ASSERT_EQ(1, a1.find("qwe"));
}

TEST(Methods, Tilda)
{
	Prog3_3::Array a1, a2;
	std::string massiv1, massiv2;
	a1.init_array();
	a1 = a1 + "asd";
	a1 = a1 + "zxc";
	a1 = a1 + "qwe";
	massiv1 = massiv1 + a1[0];
	massiv1 = massiv1 + a1[2];
	massiv1 = massiv1 + a1[1];
	a1.operator~();
	ASSERT_EQ("asdqwezxc", massiv1);
	a2.init_array();
	a2 = a2 + "abc";
	a2 = a2 + "qwe";
	a2 = a2 + "asd";
	massiv2 = massiv2 + a2[0];
	massiv2 = massiv2 + a2[2];
	massiv2 = massiv2 + a2[1];
	a2.operator~();
	ASSERT_EQ("abcasdqwe", massiv2);
}

TEST(Methods, GetByNum)
{
	Prog3_3::Array a1, a2;
	a1.init_array();
	a1 = a1 + "qwe";
	a1 = a1 + "zxc";
	a1 = a1 + "asd";
	ASSERT_EQ("qwe", a1[0]);
	ASSERT_EQ("zxc", a1[1]);
	ASSERT_EQ("asd", a1[2]);
	ASSERT_ANY_THROW(a1[4]);
}

int _tmain(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
