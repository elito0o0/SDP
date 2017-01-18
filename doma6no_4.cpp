#include "graph.h"
#include<iostream>
#include<queue> 
#include<set>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

list<int> Graph::vertices() const {
	list<int> result;

	for (const pair<int, list<int>>& p : graph) {
		result.push_back(p.first);
	}

	return result;
}

list<int>& Graph::successors(int vertex) {
	return graph[vertex];
}

Graph& Graph::add_vertex(int vertex) {
	graph[vertex] = {};
	return *this;
}

Graph& Graph::add_edge(int first_vertex, int second_vertex) {
	graph[first_vertex].push_back(second_vertex);
	graph[second_vertex].push_back(first_vertex);

	return *this;
}

bool Graph::is_edge(int first_vertex, int second_vertex) {
	for (int successor : successors(first_vertex)) {
		if (successor == second_vertex) {
			return true;
		}
	}

	return false;
}
list<int> sound_waves_order(Graph& graph, int start) {
	set<int> visited;
	visited.insert(start);
	list<int> l;
	queue<int> q;
	q.push(start);
	l.push_back(start);
	while (!q.empty())
	{
		int current_vertex = q.front();
		q.pop();

		cout << current_vertex << '\n';

		for (int successor : graph.successors(current_vertex))
		{
			if (visited.find(successor) == visited.end())
			{
				visited.insert(successor);
				int first = successor;
				if (current_vertex < first) {
					current_vertex = first;
					q.push(current_vertex);
					l.push_back(current_vertex);
				}

			}

		}
	}
	return l;
}
void bfs(Graph& graph, int vertex) {
	set<int> visited;
	visited.insert(vertex);
	auto less = [](int left, int right) {return left < right; };
	priority_queue<int, vector<int>, decltype(less)>pq(less);

	queue<int> q;
	q.push(vertex);
	pq.push(vertex);
	while (!q.empty()) {
		int current_vertex = pq.top();
		q.pop();
	

		//cout << current_vertex << '\n';
       cout << pq.top() << endl;
		pq.pop();
		for (int successor : graph.successors(current_vertex)) {
			if (visited.find(successor) == visited.end()) {
				visited.insert(successor);
				pq.push(successor);
				q.push(successor);
			}
		}
		
		
	}
	
		
	
}


int main() {
	Graph g;
	g.add_vertex(22).add_vertex(25).add_vertex(40).add_vertex(6).add_vertex(42).add_vertex(56);
	g.add_edge(22, 25).add_edge(22, 40).add_edge(25, 6).add_edge(25, 42).add_edge(6, 42).add_edge(42, 40).add_edge(42, 56);


	/*list<int> l = sound_waves_order(g, 22);

	for (int n : l) {
		cout << n << " ";
	}*/
	bfs(g, 22);
	//sound_waves_order(g, 22);
	system("pause");
	return 0;
}
