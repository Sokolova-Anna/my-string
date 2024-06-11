#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

unsigned int MyString::string_length(const char* str) const
{
	int i = 0;
	if (str == nullptr) return 0;
	while (str[i] != '\0') ++i;
	return i;
}

void MyString::str_copy(char* destptr, const char* srcptr)
{
	int i = 0;
	while (srcptr[i] != '\0')
	{
		destptr[i] = srcptr[i];
		i++;
	}
	destptr[i] = '\0';
}

void MyString::init(unsigned int len)
{
	str_length = len;
	str_capacity = len + 1;
	str = new char[str_capacity];
}

char* MyString::str_concat(const char* string1, const char* string2)
{
	char* res = new char[string_length(string1) + string_length(string2)];
	str_copy(res, string1);
	int i = string_length(string1), j = 0;
	while (string2[j] != '\0')
	{
		res[i] = string2[j];
		++i;
		++j;
	}
	res[i] = '\0';
	return res;
}

//Constructors

MyString::MyString()
{
	init(0);
	str[0] = '\0';
}

MyString::MyString(const char* string)
{

	init(string_length(string));
	str_copy(str, string);
}

MyString::MyString(const std::initializer_list<char>& string)
{
	init(string.size());
	int i = 0;
	for (auto& element_str : string)
	{
		str[i] = element_str;
		++i;
	}
	str[i] = '\0';
}

MyString::MyString(const std::string& string)
{
	init(string.size());
	str_copy(str, string.c_str());
}

MyString::MyString(const char* string, unsigned int count)
{
	init(count);
	int i;
	for (i = 0; i < count && string[i] != '\0'; ++i)
	{
		str[i] = string[i];
	}
	str[i] = '\0';
}

MyString::MyString(unsigned int count, char ch)
{
	init(count);
	memset(str, ch, count);
	str[count] = '\0';
}

MyString::MyString(const MyString& cpy_str)
{
	init(cpy_str.str_length);
	str_copy(str, cpy_str.str);
}

MyString::~MyString()
{
	delete[] str;
}

//Operators

MyString& MyString::operator+(MyString& string) const
{
	MyString* res_obj = new MyString(str);
	res_obj->insert(str_length, string.str, string.str_length);
	return *res_obj;
}

MyString& MyString::operator+(const char* char_string) const
{
	MyString* res_obj = new MyString(str);
	res_obj->insert(str_length, char_string, string_length(char_string));
	return *res_obj;
}

MyString& MyString::operator+(const std::string& std_string) const
{
	MyString* res_obj = new MyString(str);
	res_obj->insert(str_length, std_string.c_str(), string_length(std_string.c_str()));
	return *res_obj;
}

MyString MyString::operator+=(const MyString& string)
{
	this->insert(str_length, string.str, string.str_length);
	return *this;
}

MyString MyString::operator+=(const char* char_string)
{
	this->insert(str_length, char_string, string_length(char_string));
	return *this;
}

MyString MyString::operator+=(const std::string& string)
{
	this->insert(str_length, string.c_str(), string_length(string.c_str()));
	return *this;
}

MyString MyString::operator=(const char* char_string)
{
	this->erase(0, str_length);
	this->insert(0, char_string, string_length(char_string));
	return *this;
}

MyString MyString::operator=(const std::string& std_string)
{
	this->erase(0, str_length);
	this->insert(0, std_string.c_str(), string_length(std_string.c_str()));
	return *this;
}

MyString MyString::operator=(const char ch)
{
	if (str_capacity < 2)
	{
		delete[] str;
		init(2);
	}
	clear();
	str_length = 1;
	str[0] = ch;
	str[1] = '\0';
	return *this;
}

char MyString::operator[](int index) const
{
	if (index >= 0 && index <= str_length - 1)
		return str[index];
	else return -1;
}

bool MyString::operator==(const MyString& string) const
{
	if (str_length != string.str_length)
		return false;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != string.str[i]) return false;
		++i;
	}
	return true;
}

bool MyString::operator!=(const MyString& string) const
{
	return !(*this == string);
}

bool MyString::operator>(const MyString& string) const
{
	int i = 0;
	while (str[i] == string.str[i] && str[i] != '\0' && string.str[i] != '\0')
		++i;
	if (str[i] != '\0')
		return (str[i] > string.str[i]);
	else return false;
}

bool MyString::operator<(const MyString& string) const
{
	return !(*this == string || *this > string);
}

bool MyString::operator>=(const MyString& string) const
{
	return (*this == string || *this > string);
}

bool MyString::operator<=(const MyString& string) const
{
	return (*this == string || *this < string);
}

char* MyString::c_str() const
{
	return str;
}

char* MyString::data() const
{
	return str;
}

unsigned int MyString::size() const
{
	return str_length;
}

unsigned int MyString::length() const
{
	return str_length;
}

bool MyString::empty() const
{
	return (str_length == 0);
}

unsigned int MyString::capacity() const
{
	return str_capacity;
}

void MyString::shrink_to_fit()
{
	if (str_capacity == str_length + 1)
		return;
	char* str_cpy = new char[str_length + 1];
	str_copy(str_cpy, str);
	delete[] str;
	init(str_length);
	str_copy(str, str_cpy);
	delete[] str_cpy;
}

void MyString::clear()
{
	erase(0, str_length);
}

std::ostream& operator<<(std::ostream& out, MyString& str_obj)
{
	out << str_obj.str;
	return out;
}

std::istream& operator>>(std::istream& in, MyString& str_obj)
{
	char ch = 0;
	while (ch != '\n' && ch != -1) {
		ch = in.get();
		str_obj.insert(str_obj.size(), 1, ch);
	}
	return in;
}

//Insert

void MyString::insert(int index, const char* string, int count)
{
	if (index < 0 || index > str_length || count <= 0) return;

	char* old_str = new char[str_capacity];
	str_copy(old_str, str);

	char* old_str_1 = new char[index + 1];
	int i;
	for (i = 0; i < index; ++i)
		old_str_1[i] = old_str[i];
	old_str_1[i] = '\0';

	char* old_str_2 = new char[string_length(old_str) - index + 1];
	for (i = index; i < string_length(old_str); ++i)
		old_str_2[i - index] = old_str[i];
	old_str_2[i - index] = '\0';

	char* string_cut = new char[string_length(string) + 1];
	str_copy(string_cut, string);
	string_cut[count] = '\0';

	char* res_str_1 = str_concat(old_str_1, string_cut);
	char* res_str = str_concat(res_str_1, old_str_2);

	if (str_length + count >= str_capacity)
	{
		delete[] str;
		init(str_length + count);
	}
	else
		str_length = str_length + count;

	str_copy(str, res_str);

	delete[] old_str;
	delete[] old_str_1;
	delete[] old_str_2;
	delete[] string_cut;
}

void MyString::insert(int index, int count, char ch)
{
	if (count <= 0) return;
	char* string = new char[count];
	memset(string, ch, count);
	insert(index, string, count);
}

void MyString::insert(int index, const char* string)
{
	this->insert(index, string, string_length(string));
}

void MyString::insert(int index, const std::string& std_string)
{
	this->insert(index, std_string.c_str(), string_length(std_string.c_str()));
}

void MyString::insert(int index, const std::string& std_string, int count)
{
	this->insert(index, std_string.c_str(), count);
}

//Erase

void MyString::erase(int index, int count)
{
	int i;
	if (index >= str_length || count <= 0) return;

	for (i = index; i + count < str_length; ++i)
		str[i] = str[i + count];
	str[i] = '\0';
	str_length = string_length(str);
}

//Append

void MyString::append(int count, char ch)
{
	this->insert(str_length, count, ch);
}

void MyString::append(const char* string)
{
	this->insert(str_length, string);
}

void MyString::append(const char* string, int index, int count)
{
	char* str_cpy = new char[str_length + 1];
	str_copy(str_cpy, str);
	this->clear();
	this->append(string);
	this->erase(0, index);
	this->erase(count, str_length - count);
	this->insert(0, str_cpy);
	delete[] str_cpy;
}

void MyString::append(const std::string& std_string)
{
	this->insert(str_length, std_string);
}

void MyString::append(const std::string& std_string, int index, int count)
{
	this->append(std_string.c_str(), index, count);
}

//Replace

void MyString::replace(int index, int count, const char* string)
{
	this->erase(index, count);
	this->insert(index, string);
}

void MyString::replace(int index, int count, const std::string& std_string)
{
	this->replace(index, count, std_string.c_str());
}

//Substr

MyString& MyString::substr(int index) const
{
	MyString* res = new MyString(str);
	res->erase(0, index);
	return *res;
}

MyString& MyString::substr(int index, int count) const
{
	MyString* res = new MyString;
	res->append(str, index, count);
	return *res;
}

//Find

int MyString::find(const char* string) const
{
	return find(string, 0);
}

int MyString::find(const char* string, int index) const
{
	if (index < 0 || index >= str_length) return -1;

	int i, j;
	for (i = index; i <= str_length - string_length(string); ++i)
	{
		j = 0;
		while (str[i + j] == string[j] && string[j] != '\0')
			++j;
		if (string[j] == '\0') return i;
	}
	return -1;
}

int MyString::find(const std::string& std_string) const
{
	return find(std_string.c_str(), 0);
}

int MyString::find(const std::string& std_string, int index) const
{
	return find(std_string.c_str(), index);
}