#pragma once
#include <iostream>

class MyString
{
private:
	char* str;
	unsigned int str_length;
	unsigned int str_capacity;
	unsigned int string_length(const char* str) const;
	void str_copy(char* destptr, const char* srcptr);
	void init(unsigned int len);
	char* str_concat(const char* string1, const char* string2);

public:
	MyString();															//default constructor
	MyString(const char* string);										//char array constructor
	MyString(const std::initializer_list<char>& str);					//initializer list constructor
	MyString(const std::string& string);								//std::string constructor
	MyString(const char* string, unsigned int count);					//init class with count characters of  “char string”
	MyString(unsigned int count, char ch);								//init class with count of characters
	MyString(const MyString& cpy_str);									//copy constructor
	~MyString();														//destructor

	MyString& operator+(MyString& string) const;						//concatenate with Mystring
	MyString& operator+(const char* char_string) const;					//concatenate with char array
	MyString& operator+(const std::string& std_string) const;			//concatenate with std::string
	MyString operator+=(const MyString& string);						//assignment concatenate with Mystring
	MyString operator+=(const char* char_string);						//assignment concatenate with char array
	MyString operator+=(const std::string& std_string);					//assignment concatenate with std::string
	MyString operator=(const char* char_string);						//char string assignment
	MyString operator=(const std::string& std_string);					//std::string assignment
	MyString operator=(const char ch);									//char assignment

	char operator[](int index) const;									//index operator

	//lexicographically comparing
	bool operator>(const MyString& string) const;
	bool operator<(const MyString& string) const;
	bool operator>=(const MyString& string) const;
	bool operator<=(const MyString& string) const;
	bool operator!=(const MyString& string) const;
	bool operator==(const MyString& string) const;
	char* c_str() const;												//return a pointer to null-terminated character array
	char* data() const;													//return a pointer to array data that not required to be null-terminated
	unsigned int size() const;											//return the number of char elements in string
	unsigned int length() const;										//same as size
	bool empty() const;													//true if string is empty
	unsigned int capacity() const;										//return the current amount of allocated memory for array
	void shrink_to_fit();												//reduce the capacity to size
	void clear();														//remove all char element in string
	friend std::ostream& operator<<(std::ostream& out, MyString& str_obj);
	friend std::istream& operator>>(std::istream& in, MyString& str_obj);

	void insert(int index, int count, char ch);							//insert count of char in index position
	void insert(int index, const char* string);							//insert null-terminated char string at index position
	void insert(int index, const char* string, int count);				//insert count of null-terminated char string at index position
	void insert(int index, const std::string& std_string);				//insert std::string at index position
	void insert(int index, const std::string& std_string, int count);	//insert count of std::string at index position

	void erase(int index, int count);									//erase count of char at index position

	void append(int count, char ch);									//append count of char
	void append(const char* string);									//append null-terminated char string
	void append(const char* string, int index, int count);				//append a count of null-terminated char string by index position
	void append(const std::string& std_string);							//append std:: string
	void append(const std::string& std_string, int index, int count);	//append a count of std:: string by index position

	void replace(int index, int count, const char* string);				//replace a count of char at index by “string”
	void replace(int index, int count, const std::string& std_string);	//replace a count of char at index by std::string

	MyString& substr(int index) const;									//return a substring starts with index position
	MyString& substr(int index, int count) const;						//return a count of substring’s char starts with index position

	int find(const char* string) const;									//if founded return the index of substring
	int find(const char* string, int index) const;						//same as find(“string”) but search starts from index position
	int find(const std::string& std_string) const;						//if founded return the index of substring
	int find(const std::string& std_string, int index) const;			//same as find(“string”) but search starts from index position

};
