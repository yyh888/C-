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

		const char& operator[](size_t pos) const
		{
			assert(pos < _size&& pos >= 0);
			return _str[pos];
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size && pos >= 0);
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
	};

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
}



int main()
{
	yyh::test4();
	return 0;
}