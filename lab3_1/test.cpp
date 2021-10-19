#include "pch.h"
#include "gtest\gtest.h"
#include <iostream>
#include "C:\Users\yul20\Desktop\labs\3sem\lab3_1\array.h"
#include "C:\Users\yul20\Desktop\labs\3sem\lab3_1\array.cpp"

TEST(CircleMethods, Parameters)
{
	Prog3_1::Array a1,a2;
	a1.add("asd", 2);
	a1.add("qwe", 0);
	a1.add("zxc", 1);
	ASSERT_EQ("ARRAY\n[0]:qwe\n[1]:zxc\n[2]:asd\n", a1.output()); 
	ASSERT_EQ(2, a1.find("asd"));
	a1.sort();
	ASSERT_EQ("ARRAY\n[0]:asd\n[1]:qwe\n[2]:zxc\n", a1.output()); 
	ASSERT_EQ("ARRAY\n[0]:asd\n[1]:"+ "0" + "0" + "0" +"\n[2]:"+ "0" + "0" +"0"+"\n", a1.new_array('a'));
}

int _tmain(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
