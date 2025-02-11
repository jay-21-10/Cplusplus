#include "string.h"

namespace myStr
{
	const size_t string::npos = -1;
	void string::reserve(size_t n)
	{
		if (n > _capacity)
		{
			cout << " reserve:" << n << endl;
			char* tmp = new char[n + 1];
			strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
		}
	}

	void string::push_back(char ch)
	{
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4: 2 * _capacity);
		}
		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	void string::append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len >_capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		strcpy(_str + _size, str);
		_size += len;
	}

	string& string::operator+= (char ch)
	{
		push_back(ch);
		return *this;
	}
	string& string::operator+= (const char* str)
	{
		append(str);
		return *this;
	}

	void string::insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			reserve(_capacity == 0 ? 4 : 2 * _capacity);
		}
		memmove(_str + pos + 1, _str + pos, _size - pos + 1);
		_str[pos] = ch;
		++_size;
	}
	void string::insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len > 2 * _capacity ? _size + len : 2 * _capacity);
		}
		memmove(_str + pos + len, _str + pos, _size - pos + 1);
		memmove(_str + pos, str, len);
	}
	void string::erase(size_t pos, size_t len)
	{
		assert(pos <= _size);
		if (len >= _size - pos)
		{
			_str[pos] = '\0';
			_size = pos;
		}
		else
		{
			for (size_t i = pos + len; i <= _size; i++)
			{
				_str[i - len] = _str[i];
			}
			_size -= len;
		}
	}

	void string::clear()
	{
		_str[0] = '\0';
		_size = 0;
	}

	size_t string::find(char ch, size_t pos) const
	{
		assert(pos < _size);
		for (size_t i = pos; i < _size; ++i)
		{
			if (_str[i] == ch) return i;
		}
		return npos;
	}
	size_t string::find(const char* str, size_t pos) const
	{
		assert(pos < _size);
		const char* ptr = strstr(_str + pos, str);

		if (ptr == nullptr) return npos;
		return ptr - _str;
	}
	string string::substr(size_t pos, size_t len)const
	{
		assert(pos < _size);
		if (len > _size - pos) len = _size - pos;

		string sub;
		sub.reserve(len);
		for (size_t i = 0; i < len; ++i)
		{
			sub += _str[pos + i];
		}
		return sub;
	}

	string& string::operator=(const string& str)
	{
		if (this == &str) return *this;

		//使用拷贝构造去深拷贝
		string tmp(str._str);
		swap(tmp);

		/*delete[] _str;
		_str = new char[str._capacity + 1];
		strcpy(_str, str._str);
		_size = str._size;
		_capacity = str._capacity;*/

		return *this;
	}

	bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}
	bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}
	bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}
	bool operator>=(const string& s1, const string& s2)
	{
		return s1 > s2 || s1 == s2;
	}
	bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}
	bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
}
