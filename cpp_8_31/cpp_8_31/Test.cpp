#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;

namespace yyh
{
	class string
	{
	public:
		typedef char* iterator;

		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		/*string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}*/

		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_capacity, s._capacity);
			::swap(_size, s._size);
		}

		string(const string& s)
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			/*swap(_str, tmp._str);
			swap(_capacity, tmp._capacity);
			swap(_size, tmp._size);*/
			//this->swap(tmp);
			swap(tmp);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		//pos之前
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t sz = strlen(str);
			if (sz + _size > _capacity)
			{
				reserve(sz + _size);
			}
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + sz] = _str[end];
				end--;
			}
			_size += sz;
			strncpy(_str + pos, str, sz);
		}

		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			//长度
			size_t leftlen = _size - pos;
			if (len >= leftlen)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t end = pos + len;
				while (end <= _size)
				{
					_str[pos++] = _str[end++];
				}
			}
			return *this;
		}

		size_t find(char ch, size_t pos = 0)
		{
			while (pos < _size)
			{
				if (_str[pos] == ch)
				{
					return pos;
				}
				pos++;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			//记录str
			const char* s = str;
			while (pos < _size)
			{
				if (_str[pos] == *s)
				{
					//判断后续是否相等
					size_t tmp = pos;
					while (s && tmp < _size)
					{
						if (_str[tmp] != *s)
						{
							break;
						}
						else
						{
							s++;
							tmp++;
						}
					}
					if (*s == '\0')
					{
						return pos;
					}
				}
				pos++;
			}
			return npos;
		}

		void insert(size_t pos, char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			//移动
			for (int i = _size; i >= (int)pos; i--)
			{
				_str[i + 1] = _str[i];
			}
			_str[pos] = ch;
		}

		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
		}*/

		string& operator=(string s)
		{
			/*swap(s._str, _str);
			swap(s._size, _size);
			swap(s._capacity, _capacity);*/
			//this->swap(s);
			swap(s);
			return *this;
		}

		size_t size() const
		{
			return _size;
		}

		string& operator+=(const char str)
		{
			PushBack(str);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strncpy(tmp, _str, _size + 1);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char val = '\0')
		{
			if (n < _size)
			{
				_str[n] = '\0';
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				for (int i = _size; i < n; i++)
				{
					_str[i] = val;
				}
				_str[n] = '\0';
				_size = n;
			}
		}

		void PushBack(const char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			_size++;
		}

		void append(const char* str)
		{
			size_t len = strlen(str) + _size;
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size&& pos >= 0);
			return _str[pos];
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size&& pos >= 0);
			return _str[pos];
		}

		const char* c_str()
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const int npos;
	};
	const int string::npos = -1;

	ostream& operator<<(ostream& out, string& s)
	{
		out << s.c_str();
		return out;
	}

	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		in.get(ch);
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			in.get(ch);
		}
		return in;
	}

	void test_string()
	{
		string s1("hello world");
		string s2(s1);
		cout << s2.c_str() << endl;
		string s3;
		s3 = s2;
	}

	void test2()
	{
		string s1("hello world");
		cout << s1[1] << endl;
		//s1[2] = 's';
		cout << s1.c_str() << endl;
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
	}

	void test3()
	{
		string s3("hello world");
		string::iterator it = s3.begin();
		while (it != s3.end())
		{
			cout << *it << " ";
			it++;
		}
	}

	void test4()
	{
		string s4("aadfghnsefg");
		for (auto e : s4)
		{
			cout << e << " ";
		}
	}

	void test5()
	{
		string s4("aaaaaaaa");
		s4 += 'f';
		s4 += "ccc";
		s4 += 'w';
		cout << s4.c_str() << endl;
	}

	void test6()
	{
		string s6("abcdef");
		s6.resize(s6.size() + 3, 'w');
		cout << s6.c_str() << endl;
		char str[] = "sssssssssss";
		s6.insert(0, str);
		cout << s6.c_str() << endl;
	}

	void test7()
	{
		string s7("abcdefg");
		s7.erase(2, 8);
		cout << s7.c_str() << endl;
	}

	void test8()
	{
		string s8("abcdefghijklmn");
		cout << s8.find("hi", 6) << endl;
	}

	void test9()
	{
		string s9("abvcsa");
		cin >> s9;
		cout << s9 << endl;
	}
}



int main()
{
	yyh::test9();
	return 0;
}