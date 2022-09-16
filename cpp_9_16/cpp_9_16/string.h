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
		string(const char* str = "");// 构造
		~string();// 析构
		string(const string& s);// 拷贝构造
		string& operator=(const string& s);// 赋值拷贝
		char* c_str() const;// 返回字符串
		size_t size() const;// 返回size
		char& operator[](size_t pos);// []访问
		const char& operator[](size_t pos) const;// const[]访问
		typedef char* iterator;// 迭代器
		iterator begin();
		iterator end();
		typedef const char* const_iterator;// const迭代器
		const_iterator begin() const;
		const_iterator end() const;
		void push_back(const char ch);// 尾插字符
		void append(const char* str);// 尾插字符串
		string& operator+=(const char ch);// +=重载
		string& operator+=(const char* str);
		void resize(size_t n, char ch = '\0');// 初始化扩容
		size_t find(const char ch);// 查找字符
		size_t find(const char* str, size_t pos = 0);// 查找字符串
		string& insert(size_t pos, const char ch);// 插入字符
		string& insert(size_t pos, const char* str);// 插入字符串
		string& erase(size_t pos, size_t len = npos);// 删除
	private:
		char* _str;
		size_t _size;
		size_t _capacity;// _capacity表示有效字符个数
	public:
		static const size_t npos = -1;
	};
}

ostream& operator<<(ostream& out, yyh::string& s);// 输出
istream& operator>>(istream& in, yyh::string& s);// 输入