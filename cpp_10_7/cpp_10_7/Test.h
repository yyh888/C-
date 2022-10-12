#pragma once
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

namespace yyh
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		// ���캯��
		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		// ��������
		//vector(const vector<T>& x)
		//{
		//	_start = new T[x.capacity()];
		//	_finish = _start;
		//	_endofstorage = _start + x.capacity();
		//	// ����
		//	for (size_t i = 0; i < x.size(); i++)
		//	{
		//		*_finish = x[i];
		//		_finish++;
		//	}
		//}

		// �ִ�д��
		// v1(v2)
		vector(const vector<T>& x)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(x.begin(), x.end());
			swap(tmp);
		}

		//vector<T>& operator=(const vector<T>& x)
		//{
		//	for (size_t i = 0; i < x.size(); i++)
		//	{
		//		push_back(x[i]);
		//	}
		//	return *this;
		//}

		//�ִ�д��
		vector<T>& operator=(vector<T> x)
		{
			swap(x);
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[]_start;
				_finish = _endofstorage = _start = nullptr;
			}
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		iterator begin()
		{
			return _start;
		}

		const_iterator begin() const
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator end() const
		{
			return _finish;
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				// ����
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*_finish = x;
			_finish++;
		}

		void pop_back()
		{
			assert(size() > 0);
			_finish--;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			if (size() == capacity())
			{
				// ����
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _start + len;
			}
			// �ƶ�����
			iterator cur = end() - 1;
			while (cur >= pos)
			{
				*(cur + 1) = *cur;
				cur--;
			}
			*pos = val;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			assert(size() > 0);
			iterator del = pos;
			while (del != end())
			{
				*del = *(del + 1);
				del++;
			}
			_finish--;
			return pos;
		}

		void reserve(size_t n)
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					size_t sz = size();
					T* tmp = new T[n];
					if (_start)
					{
						//memcpy(tmp, _start, sizeof(T) * sz);
						for (size_t i = 0; i < sz; i++)
						{
							tmp[i] = _start[i];
						}
						delete[]_start;
					}
					_start = tmp;
					_finish = _start + sz;
					_endofstorage = _start + n;
				}
			}
		}

		void resize(size_t n, const T& val = T())// ��������
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_finish != _endofstorage)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

	private:
		iterator _start;// ���ݿ�ʼ
		iterator _finish;// ���ݽ���
		iterator _endofstorage;// �ռ��β
	};
}




