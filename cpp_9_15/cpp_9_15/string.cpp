#include "string.h"



yyh::string::string(const char* str)
	: _size(strlen(str))
	, _capacity(_size)
{
	_str = new char[_capacity + 1];// _capacity表示有效字符个数
	strcpy(_str, str);
}

yyh::string::~string()
{
	delete[]_str;
	_str = nullptr;
	_size = _capacity = 0;
}

yyh::string::string(const string& s)
	: _size(strlen(s._str))
	, _capacity(s._size)
{
	_str = new char[_capacity + 1];
	strcpy(_str, s._str);
}

// 现代写法
//yyh::string::string(const string& s)
//	: _str(nullptr)
//{
//	yyh::string tmp(s._str);
//	swap(_str, tmp._str);
//}

yyh::string& yyh::string::operator=(const string & s)
{
	if (this != &s)
	{
		char* tmp = new char[strlen(s._str) + 1];
		strcpy(tmp, s._str);
		delete[]_str;
		_str = tmp;
		_size = s._size;
		_capacity = s._capacity;
	}
	return *this;
}

// 现代写法
yyh::string& yyh::string::operator=(const string& s)
{
	if (this != &s)
	{
		_str = nullptr;
		yyh::string tmp(s);
		swap(tmp._str, _str);
	}
	return *this;
}

// 更简洁
//yyh::string& yyh::string::operator=(string s)
//{
//	swap(s._str, _str);
//	return *this;
//}

char* yyh::string::c_str() const
{
	return _str;
}

size_t yyh::string::size() const
{
	return _size;
}

char& yyh::string::operator[](size_t pos)
{
	assert(pos < _size);
	return _str[pos];
}

const char& yyh::string::operator[](size_t pos) const
{
	return _str[pos];
}

yyh::string::iterator yyh::string::begin()
{
	return _str;
}

yyh::string::iterator yyh::string::end()
{
	return _str + _size;
}

yyh::string::const_iterator yyh::string::begin() const
{
	return _str;
}

yyh::string::const_iterator yyh::string::end() const
{
	return _str + _size;
}

void yyh::string::push_back(const char ch)
{
	if (_size == _capacity)
	{
		//扩容
		_capacity *= 2;
		char* tmp = new char[_capacity + 1];
		strcpy(tmp, _str);
		delete[]_str;
		_str = tmp;
	}
	_str[_size] = ch;
	_str[_size + 1] = '\0';
	_size++;
}

void yyh::string::append(const char* str)
{
	size_t sz = strlen(str);
	if (_size + sz > _capacity)
	{
		//扩容
		while (_capacity >= _size + sz)
		{
			_capacity *= 2;
		}
		char* tmp = new char[_capacity + 1];
		strcpy(tmp, _str);
		delete[]_str;
		_str = tmp;
	}
	strcpy(_str + _size, str);
	_size += sz;
	_str[_size] = '\0';
}