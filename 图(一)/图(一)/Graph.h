#pragma once

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_map>

using namespace std;

namespace matrix
{
	template <class V, class W, W MAX = INT_MAX, bool DIR = false>
	class Graph
	{
	public:
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);// �����������ֵ�洢��vector��
				_idxMap[a[i]] = i;// �������е�ÿһ������ӳ��һ���±�
			}

			_matrix.resize(n);
			for (size_t i = 0; i < n; i++)
			{
				_matrix[i].resize(n, MAX);
			}
		}

		// ��ȡ�����±�
		size_t GetIdx(const V& v)
		{
			auto it = _idxMap.find(v);
			if (it == _idxMap.end())
			{
				assert(false);
				return -1;
			}
			return it->second;
		}

		void addEdge(const V& src, const V& dst, const W& w)
		{
			size_t si = GetIdx(src);
			size_t di = GetIdx(dst);
			_matrix[si][di] = w;
			if (DIR == false)
			{
				_matrix[di][si] = w;
			}
		}
		void Print()
		{
			// ��ӡ������±���ӳ���ϵ
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			// ��ӡ���������
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				printf("%5d", i);
			}
			cout << endl;

			// ��ӡ����
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i << " "; // ��ӡ����������
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (_matrix[i][j] == MAX)
						printf("%5c", '*');
					else
						printf("%5d", _matrix[i][j]);
				}
				cout << endl;
			}
		}

		void BFS(const V& src)
		{
			size_t si = GetIdx(src);
			vector<bool> visited(_vertexs.size(), false);
			queue<int> q;
			q.push(si);
			visited[si] = true;
			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				cout << front << " : " << _vertexs[front] << endl;
				for (int i = 0; i < _matrix[front].size(); i++)
				{
					if (_matrix[front][i] != MAX)
					{
						if (visited[i] == false)
						{
							q.push(i);
							visited[i] = true;
						}
					}
				}
			}
		}

	private:
		vector<V> _vertexs;// ���㼯��
		unordered_map<V, int> _idxMap;// ����ӳ���±�
		vector<vector<W>> _matrix;// �ڽӾ���
	};

	void TestGraph()
	{
		Graph<char, int, INT_MAX, false> g("ABCDE", 5);
		g.addEdge('A', 'B', 1);
		g.addEdge('B', 'D', 4);
		g.addEdge('A', 'C', 2);
		g.addEdge('C', 'D', 9);
		g.addEdge('C', 'E', 8);
		//g.Print();
		g.BFS('B');
	}
}


namespace link_table
{
	template <class W>
	struct Edge
	{
		Edge(int dsti, const W& w)
			: _dsti(dsti)
			, _w(w)
			, _next(nullptr)
		{}
		int _dsti;
		W _w;// Ȩֵ
		Edge<W>* _next;
	};

	template <class V, class W, bool DIR = false>
	class Graph
	{
	public:
		Graph(const V* a, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				_vertexs.push_back(a[i]);// �����������ֵ�洢��vector��
				_idxMap[a[i]] = i;// �������е�ÿһ������ӳ��һ���±�
			}
			_tables.resize(n, nullptr);
		}

		// ��ȡ�����±�
		size_t GetIdx(const V& v)
		{
			auto it = _idxMap.find(v);
			if (it == _idxMap.end())
			{
				assert(false);
				return -1;
			}
			return it->second;
		}

		void addEdge(const V& src, const V& dst, const W& w)
		{
			size_t si = GetIdx(src);
			size_t di = GetIdx(dst);
			Edge<W>* eg = new Edge<W>(di, w);
			eg->_next = _tables[si];
			_tables[si] = eg;
			if (DIR == false)
			{
				Edge<W>* eg = new Edge<W>(si, w);
				eg->_next = _tables[di];
				_tables[di] = eg;
			}
		}
		void Print()
		{
			// ��ӡ������±���ӳ���ϵ
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				cout << "[" << i << "]" << "->" << _vertexs[i] << endl;
			}
			cout << endl;

			for (size_t i = 0; i < _tables.size(); ++i)
			{
				// ������ǰ��������ӡ�������е������Ϣ
				cout << _vertexs[i] << "[" << i << "]->";
				Edge<W>* cur = _tables[i];
				while (cur)
				{
					cout << "[" << _vertexs[cur->_dsti] << ":" << cur->_dsti << ":" << cur->_w << "]->";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}
		}

	private:
		vector<V> _vertexs;// ���㼯��
		unordered_map<V, int> _idxMap;// ����ӳ���±�
		vector<Edge<W>*> _tables;// �ڽӱ�
	};

	void TestGraph()
	{
		Graph<char, int, false> g("ABCDE", 5);
		g.addEdge('A', 'B', 1);
		g.addEdge('B', 'D', 4);
		g.addEdge('A', 'D', 2);
		g.addEdge('B', 'C', 9);
		g.addEdge('A', 'C', 8);
		g.addEdge('E', 'A', 5);
		g.addEdge('A', 'E', 3);
		g.addEdge('C', 'D', 6);
		g.Print();
	}
}