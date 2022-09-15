#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;
namespace yyh
{
	class string
	{
	public:
		string(const char* str = "");// ����
		~string();// ����
		string(const string& s);// ��������
		string& operator=(const string& s);// ��ֵ����
		char* c_str() const;// �����ַ���
		size_t size() const;// ����size
		char& operator[](size_t pos);// []����
		const char& operator[](size_t pos) const;// const[]����
		typedef char* iterator;// ������
		iterator begin();
		iterator end();
		typedef const char* const_iterator;// const������
		const_iterator begin() const;
		const_iterator end() const;
		void push_back(const char ch);// β���ַ�
		void append(const char* str);// β���ַ���
	private:
		char* _str;
		size_t _size;
		size_t _capacity;// _capacity��ʾ��Ч�ַ�����
	};
}