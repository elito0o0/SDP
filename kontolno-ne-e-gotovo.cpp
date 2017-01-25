#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<set>
#include<stack>
using namespace std;
class Graph {
	map<int, list<int>> g;
public:
	list<int>& successors(int v) {
		return g[v];
	}
	Graph& add_vertex(int v) {
		g[v] = {};
		return *this;
	}
	Graph& add_edge(int first, int second) {
		g[first].push_back(second);
		g[second].push_back(first);

		return *this;
	}
};
int bfs(Graph& g, int room) {
	queue<int> q;
	set<int> visited;
	int days = 0;
	visited.insert(room);
	q.push(room);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		int current = g.successors(cur).size();
		// min = g.successors(cur).size();
		// max = g.successors(cur).size();
		current--;
		for (int p : g.successors(cur)) 
		{ 
			

			if (visited.find(p) == visited.end())
			{
				visited.insert(p);
				q.push(p);
			}
			/*if (min > g.successors(p).size()) {
				min = g.successors(p).size();
			}
			if (max < g.successors(p).size()) {
				max = g.successors(p).size();
			}*/
			

		}
		current--;
		if (current == 0) {
			days++;
		}
		
	}
	/*cout << max << endl;
	cout << min << endl;
	*/
	cout << "\n";
	return days;
}
list<int> kth_level(Graph& g, int k,int room) {
	queue<int> nodes;
	nodes.push(room);
	set<int> visited;
	visited.insert(room);
	list<int> nodes_on_kth_level;
	int current_level = 0;
	unsigned long current_level_nodes_count = 1;

	while (!nodes.empty()) {
		if (current_level_nodes_count == 0) {
			++current_level;
			current_level_nodes_count = nodes.size();
		}

		if (current_level == k) {
			while (!nodes.empty()) {
				nodes_on_kth_level.push_back(nodes.front());
				nodes.pop();
			}

			return nodes_on_kth_level;
		}
		int cur_vertex = nodes.front();
		for (int successor : g.successors(cur_vertex)) {
			if (visited.find(successor) == visited.end())
			{
				visited.insert(successor);
				nodes.push(successor);
			}

		}

		nodes.pop();
		--current_level_nodes_count;
	}

	return nodes_on_kth_level;
}
int main() {
	Graph g;
	g.add_vertex(101).add_vertex(104).add_vertex(107).add_vertex(210).add_vertex(310).add_vertex(130).add_vertex(340).add_vertex(317).add_vertex(613).add_vertex(415).add_vertex(623)
	.add_edge(101, 104).add_edge(101, 107).add_edge(101, 210).add_edge(210, 310).add_edge(107, 130).add_edge(107, 340).add_edge(130, 317).add_edge(340, 613).add_edge(613,415);
	
	cout << "Days: " << bfs(g, 101) << endl;
	list<int> l = kth_level(g, 3, 101);
	for (int n : l) {
		cout << n << endl;
	}
	system("pause");
	return 0;
}
