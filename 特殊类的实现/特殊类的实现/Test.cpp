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
//		// ��һ�ε��òŻᴴ������
//		if (_s == nullptr)// ֻ�е�һ�β��ü���
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
//	// ������
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//private:
//	Singleton()
//	{}
//
//	std::map<std::string, std::string> _dict;
//private:
//	static Singleton* _s;// ����
//	static mutex _mutex;// ��
//};
//
//Singleton* Singleton::_s = nullptr;// ����
//mutex Singleton::_mutex;// ����


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

	// ������
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
private:
	Singleton()
	{}

	std::map<std::string, std::string> _dict;
};


int main()
{
	Singleton::GetObj().insert("corn", "����");

	Singleton& dic1 = Singleton::GetObj();
	dic1.insert("apple", "ƻ��");
	dic1.insert("banana", "�㽶");

	Singleton& dic2 = Singleton::GetObj();
	dic2.insert("pear", "��");

	dic2.Print();
	return 0;
}
