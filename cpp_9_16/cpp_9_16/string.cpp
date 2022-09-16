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
//	swap(_size, tmp._size);
//	swap(_capacity, tmp._capacity);
//}

yyh::string& yyh::string::operator=(const string& s)
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
//yyh::string& yyh::string::operator=(const string& s)
//{
//	if (this != &s)
//	{
//		_str = nullptr;
//		yyh::string tmp(s);
//		swap(tmp._str, _str);
//		swap(tmp._capacity, _capacity);
//		swap(tmp._size, _size);
//	}
//	return *this;
//}

// 更简洁
//yyh::string& yyh::string::operator=(string s)
//{
//	swap(s._str, _str);
//	swap(s._size, _size);
//	swap(s._capacity, _capacity);
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
		if (_capacity == 0)
		{
			_capacity = 4;
		}
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
		if (_capacity == 0)
		{
			_capacity = 4;
		}
		while (_capacity < _size + sz)
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
}

yyh::string& yyh::string::operator+=(const char ch)
{
	push_back(ch);// 复用
	return *this;
}

yyh::string& yyh::string::operator+=(const char* str)
{
	append(str);
	return *this;
}

void yyh::string::resize(size_t n, char ch)
{
	if (n < _size)
	{
		_str[n] = '\0';
		_size = n;
	}
	if (n > _size)
	{
		if (n > _capacity)
		{
			//扩容
			if (_capacity == 0)
			{
				_capacity = 4;
			}
			while (_capacity <= n)
			{
				_capacity *= 2;
			}
			char* tmp = new char[_capacity + 1];
			strcpy(tmp, _str);
			delete[]_str;
			_str = tmp;
		}
		for (int i = _size; i < n; i++)
		{
			_str[i] = ch;
		}
		_size = n;
	}
}


size_t yyh::string::find(const char ch)
{
	size_t i = 0;
	while (i < _size)
	{
		if (_str[i] == ch)
		{
			return i;
		}
	}
	return -1;// npos
}

size_t yyh::string::find(const char* str, size_t pos)
{
	const char* p = strstr(_str + pos, str);
	if (p == nullptr)// 没找到
		return -1;
	return (p - _str);
}

yyh::string& yyh::string::insert(size_t pos, const char ch)
{
	assert(pos <= _size);
	if (_size + 1 > _capacity)
	{
		//扩容
		size_t tmp = _size + 1;
		resize(tmp);
	}
	size_t end = _size + 1;
	while (end > pos)
	{
		_str[end] = _str[end - 1];
		end--;
	}
	_str[pos] = ch;
	_size++;
	return *this;
}

yyh::string& yyh::string::insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	size_t sz = strlen(str);
	if (_size + sz > _capacity)
	{
		// 扩容
		size_t tmp = _size + sz;
		resize(tmp);
		/*if (_capacity == 0)
		{
			_capacity = 4;
		}
		while (_capacity < _size + sz)
		{
			_capacity *= 2;
		}
		char* tmp = new char[_capacity + 1];
		strcpy(tmp, _str);
		delete[]_str;
		_str = tmp;*/
	}
	size_t end = _size + sz;
	while (end >= pos + sz)
	{
		_str[end] = _str[end - sz];
		end--;
	}
	for (size_t i = pos; i < sz; i++)
	{
		_str[i] = *str;
		str++;
	}
	_size += sz;
	return *this;
}

yyh::string& yyh::string::erase(size_t pos, size_t len)
{
	assert(pos < _size);
	if (pos + len >= _size)
	{
		_size = pos;
		_str[_size] = '\0';
	}
	else
	{
		strcpy(_str + pos, _str + pos + len);
		_size -= len;
	}
	return *this;
}

ostream& operator<<(ostream& out, yyh::string& s)
{
	for (auto e : s)// 不能用c_str()
	{
		out << e;
	}
	return out;
}

istream& operator>>(istream& in, yyh::string& s)
{
	char ch = in.get();
	while (ch != '\n' && ch != ' ')
	{
		s += ch;
		ch = in.get();
	}
	return in;
}