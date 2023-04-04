#include <iostream>
#include <map>
#include <string>
#include <mutex>
using namespace std;

//class anti_copy
//{
//public:
//	anti_copy()
//	{}
//	anti_copy(const anti_copy& ac) = delete;
//	anti_copy& operator=(const anti_copy& ac) = delete;
//private:
//};
//
//int main()
//{
//	anti_copy a;
//	anti_copy b(a);
//	return 0;
//}


//class OnlyHeap
//{
//public:
//	static OnlyHeap* GetObj()
//	{
//		return new OnlyHeap;
//	}
//
//	OnlyHeap(const OnlyHeap& hp) = delete;
//private:
//	OnlyHeap()
//	{}
//};

//class OnlyHeap
//{
//public:
//	OnlyHeap()
//	{}
//
//	OnlyHeap(const OnlyHeap& hp) = delete;
//
//	void Destroy()
//	{
//		this->~OnlyHeap();
//	}
//private:
//	~OnlyHeap()
//	{}
//};

//class StackOnly
//{
//public:
//	static StackOnly GetObj()
//	{
//		return StackOnly();
//	}
//
//	void use() const
//	{
//		cout << "void use()" << endl;
//	}
//
//private:
//	StackOnly()
//	{}
//
//	StackOnly(const StackOnly&) = delete;
//};

//class NoInherit final
//{
//public:
//private:
//};
//
//int main()
//{
//	StackOnly::GetObj().use();
//	const StackOnly& s = StackOnly::GetObj();
//	s.use();
//	return 0;
//}

//template <class Lock>
//class LockAuto
//{
//public:
//	LockAuto(Lock& lk)
//		: _lk(lk)
//	{
//		_lk.lock();
//	}
//
//	~LockAuto()
//	{
//		_lk.unlock();
//	}
//private:
//	Lock& _lk;
//};
//
//class Singleton
//{
//public:
//	static Singleton& GetObj()
//	{
//		// 第一次调用才会创建对象
//		if (_s == nullptr)// 只有第一次才用加锁
//		{
//			LockAuto<mutex> lock(_mutex);
//			if (_s == nullptr)
//			{
//				_s = new Singleton;
//			}
//		}
//		return *_s;
//	}
//
//	void insert(const std::string& s1, const std::string& s2)
//	{
//		_dict[s1] = s2;
//	}
//
//	void Print()
//	{
//		for (auto& e : _dict)
//		{
//			cout << e.first << "->" << e.second << endl;
//		}
//	}
//
//	// 防拷贝
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//private:
//	Singleton()
//	{}
//
//	std::map<std::string, std::string> _dict;
//private:
//	static Singleton* _s;// 声明
//	static mutex _mutex;// 锁
//};
//
//Singleton* Singleton::_s = nullptr;// 定义
//mutex Singleton::_mutex;// 定义


class Singleton
{
public:
	static Singleton& GetObj()
	{
		static Singleton dic;
		return dic;
	}

	void insert(const std::string& s1, const std::string& s2)
	{
		_dict[s1] = s2;
	}

	void Print()
	{
		for (auto& e : _dict)
		{
			cout << e.first << "->" << e.second << endl;
		}
	}

	// 防拷贝
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
private:
	Singleton()
	{}

	std::map<std::string, std::string> _dict;
};


int main()
{
	Singleton::GetObj().insert("corn", "玉米");

	Singleton& dic1 = Singleton::GetObj();
	dic1.insert("apple", "苹果");
	dic1.insert("banana", "香蕉");

	Singleton& dic2 = Singleton::GetObj();
	dic2.insert("pear", "梨");

	dic2.Print();
	return 0;
}
