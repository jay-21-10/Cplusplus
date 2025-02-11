#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

namespace myStr
{
	
	class string
	{
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

/*
 *		手动深拷贝
 		string(const string& str)
		{
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
			_size = str._size;
			_capacity = str._capacity;
		}
	*/ 
		//利用拷贝构造去深拷贝
		void swap(string& str)
		{
			std::swap(_str, str._str);
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
		}
		string(const string& str)
		{
			string tmp(str._str);
			swap(tmp);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		
		char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		typedef char* iterator;
		iterator begin() const
		{
			return _str;
		}
		iterator end() const
		{
			return _str + _size;
		}

		void reserve(size_t n);
		void push_back(char ch);
		void append(const char* str);
		string& operator+= (char ch);
		string& operator+= (const char* str);
		void insert(size_t pos, char ch);
		void insert(size_t pos, const char* str);
		void erase(size_t pos = 0, size_t len = npos);
		void clear();
		size_t find(char ch, size_t pos = 0)const;
		size_t find(const char* str, size_t pos = 0)const;
		string substr(size_t pos = 0, size_t len = npos)const;

		string& operator=(string str);

	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0;

		//static const size_t npos = -1;
		static const size_t npos;
	};

	bool operator<(const string& s1, const string& s2);
	bool operator<=(const string& s1, const string& s2);
	bool operator>(const string& s1, const string& s2);
	bool operator>=(const string& s1, const string& s2);
	bool operator==(const string& s1, const string& s2);
	bool operator!=(const string& s1, const string& s2);

	inline ostream& operator<<(ostream& cout, const string& str)
	{
		for (auto ch : str)
		{
			cout << ch;
		}
		return cout;
	}

	inline istream& operator>>(istream& cin, string& str)
	{
		str.clear();

		//设置缓存区，优化扩容问题
		const int N = 256;
		char buff[N];
		int i = 0;

		char ch = cin.get();
		while (ch != ' ' && ch != '\n')
		{
			buff[i++] = ch;
			if (i == N - 1)
			{
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			//str += ch;
			ch = cin.get();
		}
		if (i > 0) 
		{
			buff[i] = '\0';
			str += buff;
		}
		return cin;
	}
}
