#include <iostream>
#include <thread>
#include <vector>
#include <windows.h>
#include <mutex>
#include <atomic>
#include <condition_variable>

using namespace std;

//void fun()
//{
//	Sleep(1100);
//	cout << this_thread::get_id() << endl;
//}
//
//int main()
//{
//	thread t1([]() {
//		while (true)
//		{
//			Sleep(1000);
//			cout << this_thread::get_id() << endl;
//		}
//		});
//	thread t2(fun);
//
//	t1.join();
//	t2.join();
//	return 0;
//}

//static int val = 0;
//mutex mtx;
//
//void fun1(int n)
//{
//	mtx.lock();
//	for (int i = 0; i < n; i++)
//	{
//		val++;
//	}
//	mtx.unlock();
//}
//
//void fun2(int n)
//{
//	mtx.lock();
//	for (int i = 0; i < n; i++)
//	{
//		val++;
//	}
//	mtx.unlock();
//}
//
//int main()
//{
//	thread t1(fun1, 100000);
//	thread t2(fun1, 200000);
//	t1.join();
//	t2.join();
//	cout << val << endl;
//	return 0;
//}

//atomic<int> val = 0;
//
//void fun1(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		val++;
//	}
//}
//
//void fun2(int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		val++;
//	}
//}
//
//int main()
//{
//	thread t1(fun1, 100000);
//	thread t2(fun1, 200000);
//	t1.join();
//	t2.join();
//	cout << val << endl;
//	return 0;
//}

//int main()
//{
//	atomic<int> val = 0;
//	auto func = [&](int n) {
//		for (int i = 0; i < n; i++)
//		{
//			val++;
//		}
//	};
//	thread t1(func, 10000);
//	thread t2(func, 20000);
//	t1.join();
//	t2.join();
//	cout << val << endl;
//	return 0;
//}

//if (try_lock())
//{
//	// ...
//}
//else
//{
//	// 干其他的事情
//}

//void fun()
//{
//	lock();
//	fun();// 递归
//	unlock();
//}


//int main()
//{
//	int val = 0;
//	mutex mtx;
//	auto func = [&](int n) {
//		lock_guard<mutex> lock(mtx);
//		for (int i = 0; i < n; i++)
//		{
//			val++;
//		}
//	};
//	thread t1(func, 10000);
//	thread t2(func, 20000);
//	t1.join();
//	t2.join();
//	cout << val << endl;
//	return 0;
//}

int main()
{
	int val = 1;
	mutex mtx;
	condition_variable cv;
	thread t1([&]() {
		while (val < 100)
		{
			unique_lock<mutex> lock(mtx);
			while (val % 2 == 0)
			{
				cv.wait(lock);// 阻塞
			}
			cout << "thread 1" << "->" << val << endl;
			val++;
			cv.notify_one();
		}
		});
	thread t2([&]() {
		while (val <= 100)
		{
			unique_lock<mutex> lock(mtx);
			while (val % 2 != 0)
			{
				cv.wait(lock);
			}
			cout << "thread 2" << "->" << val << endl;
			val++;
			cv.notify_one();
		}
		});
	t1.join();
	t2.join();
	return 0;
}