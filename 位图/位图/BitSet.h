#pragma once
#include <iostream>
#include <vector>

namespace yyh
{
	template <size_t N>
	class BitSet
	{
	public:
		BitSet()
		{
			_bits.resize(N / 8 + 1, 0);
		}

		void set(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			_bits[i] |= (1 << j);
		}

		void reset(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			_bits[i] &= (~(1 << j));
		}

		bool search(int x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			return _bits[i] & (1 << j);
		}
	private:
		std::vector<char> _bits;
	};

	template <size_t N>
	class TwoBitSet
	{
	public:
		void set(size_t x)
		{
			if (!_b1.search(x) && !_b2.search(x))// 00
			{
				_b2.set(x);// 01
			}
			else if (!_b1.search(x) && _b2.search(x))// 01
			{
				_b1.set(x);
				_b2.reset(x);// 10
			}
			// 10²»±ä
		}

		void PrintOnce()
		{
			for (size_t i = 0; i < N; i++)
			{
				if (!_b1.search(i) && _b2.search(i))
					std::cout << i << std::endl;
			}
		}

	private:
		BitSet<N> _b1;
		BitSet<N> _b2;
	};

	void test2()
	{
		TwoBitSet<100> tb;
		tb.set(1);
		tb.set(1);
		tb.set(18);
		tb.set(18);
		tb.set(19);
		tb.set(88);
		tb.PrintOnce();
	}

	void test1()
	{
		BitSet<-1> bs;
		bs.set(1);
		bs.set(191111);
		bs.reset(191111);
		std::cout << bs.search(1) << std::endl;
		std::cout << bs.search(182222) << std::endl;
		std::cout << bs.search(191111) << std::endl;
		std::cout << bs.search(9944444) << std::endl;
		std::cout << bs.search(15) << std::endl;
		std::cout << bs.search(13) << std::endl;
	}
}