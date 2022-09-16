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
		string& operator+=(const char ch);// +=����
		string& operator+=(const char* str);
		void resize(size_t n, char ch = '\0');// ��ʼ������
		size_t find(const char ch);// �����ַ�
		size_t find(const char* str, size_t pos = 0);// �����ַ���
		string& insert(size_t pos, const char ch);// �����ַ�
		string& insert(size_t pos, const char* str);// �����ַ���
		string& erase(size_t pos, size_t len = npos);// ɾ��
	private:
		char* _str;
		size_t _size;
		size_t _capacity;// _capacity��ʾ��Ч�ַ�����
	public:
		static const size_t npos = -1;
	};
}

ostream& operator<<(ostream& out, yyh::string& s);// ���
istream& operator>>(istream& in, yyh::string& s);// ����