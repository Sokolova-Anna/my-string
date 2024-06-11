#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

void testConstructors()
{
	MyString a1;
	std::cout << a1 << " " << a1.size() << " " << a1.capacity() << std::endl;

	MyString a2("Hello world!");
	std::cout << a2 << " " << a2.size() << " " << a2.capacity() << std::endl;

	MyString a3({ 'h','e','l','l','o' });
	std::cout << a3 << " " << a3.size() << " " << a3.capacity() << std::endl;

	std::string s = "hello";
	MyString a4(s);
	std::cout << a4 << " " << a4.size() << " " << a4.capacity() << std::endl;

	MyString a5("hello", 4);
	std::cout << a5 << " " << a5.size() << " " << a5.capacity() << std::endl;

	MyString a6(5, '!');
	std::cout << a6 << " " << a6.size() << " " << a6.capacity() << std::endl;

	MyString a7("hello");
	MyString a8(a7);
	std::cout << a8 << " " << a8.size() << " " << a8.capacity() << std::endl;

}

void testConcatenate()
{
	std::cout << "//+" << std::endl;

	MyString a1("hel"), a2("lo"), a3;
	a3 = a1 + a2;
	std::cout << a1 << " " << a2 << " " << a3 << std::endl;

	MyString a4("hel"), a5;
	a5 = a4 + "lo";
	std::cout << a4 << " " << a5 << std::endl;

	MyString a6("hel"), a7;
	std::string s1 = "lo";
	a7 = a6 + s1;
	std::cout << a6 << " " << a7 << std::endl;

}

void testAssignmentConcatenate()
{
	std::cout << "//+=" << std::endl;

	MyString a1("hel"), a2("lo");
	a1 += a2;
	std::cout << a1 << " " << a2 << std::endl;

	MyString a3("hel");
	a3 += "lo";
	std::cout << a3 << std::endl;

	MyString a4("hel");
	std::string s1 = "lo";
	a4 += s1;
	std::cout << a4 << std::endl;
}

void testAssignment()
{
	std::cout << "//=" << std::endl;

	MyString a1;
	a1 = "hello";
	std::cout << a1 << std::endl;

	MyString a2;
	std::string s1 = "hello";
	a2 = s1;
	std::cout << a2 << std::endl;

	MyString a3;
	a3 = '!';
	std::cout << a3 << std::endl;
}

void testComparing()
{
	std::cout << "//comparing" << std::endl;
	MyString a, b;
	a = "abcd";
	b = "abce";
	std::cout << (a == b) << (a != b) << (a > b) << (a >= b) << (a < b) << (a <= b) << std::endl;

}

void testOperators()
{
	std::cout << "//" << std::endl;

	MyString a1("Hello world!");
	char* s1;
	s1 = a1.c_str();
	std::string s2;
	s2 = a1.data();
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;

	MyString a2("Hello world!");
	std::cout << a2.size() << std::endl;
	std::cout << a2.length() << std::endl;

	MyString a3("Hello world!");
	std::cout << a3.empty() << std::endl;

	MyString a4("Hello world!");
	std::cout << a4.capacity() << std::endl;

	MyString a5("Hello world!");
	a5.erase(5, 6);
	std::cout << a5 << " " << a5.size() << " " << a5.capacity() << std::endl;
	a5.shrink_to_fit();
	std::cout << a5 << " " << a5.size() << " " << a5.capacity() << std::endl;

	MyString a6("Hello world!");
	std::cout << a6 << std::endl;
	a6.clear();
	std::cout << a6 << std::endl;


}

void testInsert()
{
	MyString a1 = "aaaaa";
	a1.insert(0, 1, '!');
	std::cout << a1 << std::endl;
	a1.insert(3, 2, '@');
	std::cout << a1 << std::endl;

	MyString a2 = "aaaaa";
	a2.insert(1, "@@@@@");
	std::cout << a2 << std::endl;

	MyString a3 = "aaaaa";
	a3.insert(1, "@@@@@", 2);
	std::cout << a3 << std::endl;

	MyString a4 = "aaaaa";
	std::string s1 = "@@@@@";
	a4.insert(1, s1);
	std::cout << a4 << std::endl;

	MyString a5 = "aaaaa";
	std::string s2 = "@@@@@";
	a5.insert(1, s2, 2);
	std::cout << a5 << std::endl;
}

void testErase()
{
	MyString a1("Hello world!");
	a1.erase(5, 6);
	std::cout << a1 << std::endl;
}

void testAppend()
{
	MyString a1;
	a1.clear();
	a1.append(3, '!');
	std::cout << a1 << std::endl;
	a1.append(3, '@');
	std::cout << a1 << std::endl;

	MyString a2;
	a2.clear();
	a2.append("Hello ");
	std::cout << a2 << std::endl;
	a2.append("world");
	std::cout << a2 << std::endl;

	MyString a3;
	a3.clear();
	a3.append("Hello world", 0, 6);
	std::cout << a3 << std::endl;
	a3.append("Hello world", 6, 5);
	std::cout << a3 << std::endl;

	MyString a4;
	std::string s1 = "Hello ", s2 = "world";
	a4.clear();
	a4.append(s1);
	std::cout << a4 << std::endl;
	a4.append(s2);
	std::cout << a4 << std::endl;

	MyString a5;
	std::string s3 = "Hello world";
	a5.clear();
	a5.append(s3, 0, 6);
	std::cout << a5 << std::endl;
	a5.append(s3, 6, 5);
	std::cout << a5 << std::endl;

}

void testReplace()
{
	MyString a1 = "hello amazing world";
	a1.replace(6, 7, "wonderful");
	std::cout << a1 << std::endl;

	MyString a2 = "hello amazing world";
	std::string s1 = "wonderful";
	a2.replace(6, 7, s1);
	std::cout << a2 << std::endl;

}

void testSubstr()
{
	MyString a1 = "hello amazing world", a2;
	a2 = a1.substr(6);
	std::cout << a2 << std::endl;

	MyString a3 = "hello amazing world", a4;
	a4 = a3.substr(6, 7);
	std::cout << a4 << std::endl;
}

void testFind()
{
	MyString a1 = "hello amazing world amazing";
	int i;
	i = a1.find("amazing");
	std::cout << i << std::endl;

	MyString a2 = "hello amazing world amazing";
	i = a2.find("amazing", 7);
	std::cout << i << std::endl;

	MyString a3 = "hello amazing world amazing";
	std::string s1 = "amazing";
	i = a3.find(s1);
	std::cout << i << std::endl;

	MyString a4 = "hello amazing world amazing";
	i = a4.find(s1, 7);
	std::cout << i << std::endl;
}

int main()
{

	MyString a1("jhsjadjhagsdhghsdhfghfsdfd");
	std::cout << a1 << " " << a1.capacity() << std::endl;
	a1 = "jhds";
	std::cout << a1 << " " << a1.capacity() << std::endl;
	std::cout << std::endl;

	MyString a2("ajshfijhwiuehf");
	std::cout << a2 << " " << a2.capacity() << std::endl;
	a2.erase(1, 10);
	std::cout << a2 << " " << a2.capacity() << std::endl;
	a2.insert(1, "hello");
	std::cout << a2 << " " << a2.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "_________Constructors_________" << std::endl;
	testConstructors();

	std::cout << "_________Operators_________" << std::endl;
	testConcatenate();
	testAssignmentConcatenate();
	testAssignment();
	std::cout << "//[]" << std::endl;
	MyString a4;
	a4 = "hello";
	std::cout << a4[2] << std::endl;
	testComparing();
	testOperators();

	std::cout << "_________Insert_________" << std::endl;
	testInsert();

	std::cout << "_________Erase_________" << std::endl;
	testErase();

	std::cout << "_________Append_________" << std::endl;
	testAppend();

	std::cout << "_________Replace_________" << std::endl;
	testReplace();

	std::cout << "_________Substr_________" << std::endl;
	testSubstr();

	std::cout << "_________Find_________" << std::endl;
	testFind();

	return 0;
}