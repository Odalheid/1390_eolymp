#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> used;
vector<set<int>> graph;
bool flag = 0; // нет цикла

void dfs(const int &ancestor, const int &vertex) {
	++used[vertex];
	if (used[vertex] > 1) return;
	for (set<int>::iterator it = graph[vertex].begin(); it != graph[vertex].end(); ++it) {
		int to = *it;
		if (!used[to] && to != ancestor) {
			dfs(vertex, to);
		} 
		else if (used[to] == 1 && to != ancestor) flag = 1;
	}
	++used[vertex];
	return;
}

int main()
{
	int vertices, edges;
	cin >> vertices >> edges;
	used.resize(vertices, 0);
	graph.resize(vertices);
	for (int i = 0; i < edges; ++i) {
		int a, b; cin >> a >> b;
		if (graph[b - 1].find(a - 1) == graph[b - 1].end() && graph[a - 1].find(b - 1) == graph[a - 1].end()) {
			graph[a - 1].emplace(b - 1);
			graph[b - 1].emplace(a - 1);
		}
	}
	dfs(-1, 0);
	if (!flag) cout << "NO\n";
	else cout << "YES\n";
    return 0;
}

