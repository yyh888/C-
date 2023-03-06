#pragma once
#include <iostream>
#include <string>
#include <bitset>


namespace yyh
{
	struct BKDRHash
	{
		size_t operator()(const std::string& s)
		{
			size_t value = 0;
			for (auto ch : s)
			{
				value *= 31;
				value += ch;
			}
			return value;
		}
	};

	struct APHash
	{
		size_t operator()(const std::string& s)
		{
			size_t hash = 0;
			for (long i = 0; i < s.size(); i++)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};

	struct DJBHash
	{
		size_t operator()(const std::string& s)
		{
			size_t hash = 5381;
			for (auto ch : s)
			{
				hash += (hash << 5) + ch;
			}
			return hash;
		}
	};



	template<size_t N,
	class K = std::string,
	class HashFunc1 = BKDRHash,
	class HashFunc2 = APHash,
	class HashFunc3 = DJBHash>
	class BloomFilter
	{
	public:
		void set(const K& x)
		{
			size_t idx1 = HashFunc1()(x) % (5 * N);
			size_t idx2 = HashFunc2()(x) % (5 * N);
			size_t idx3 = HashFunc3()(x) % (5 * N);
			_bs.set(idx1);
			_bs.set(idx2);
			_bs.set(idx3);
		}

		bool test(const K& x)
		{
			size_t idx1 = HashFunc1()(x) % (5 * N);
			if (!_bs.test(idx1))
			{
				return false;
			}
			size_t idx2 = HashFunc2()(x) % (5 * N);
			if (!_bs.test(idx2))
			{
				return false;
			}
			size_t idx3 = HashFunc3()(x) % (5 * N);
			if (!_bs.test(idx3))
			{
				return false;
			}
			return true;
		}
	private:
		std::bitset<N * 5> _bs;
	};

	void test()
	{
		std::string arr[] = { "北京", "武汉", "广州", "上海", "北京", "北京", "广州",
	"上海", "上海" };
		BloomFilter<10> bs;
		for (auto& e : arr)
		{
			bs.set(e);
		}
		for (auto& e : arr)
		{
			std::cout << bs.test(e) << std::endl;
		}
		std::cout << std::endl;
		// 测试误判
		srand(time(0));
		for (auto& e : arr)
		{
			std::cout << bs.test(e + std::to_string(rand())) << std::endl;
		}
	}
}