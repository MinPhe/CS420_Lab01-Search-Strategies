// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices 
// reachable from s.
#include<iostream>
#include <vector>
#include<fstream>
#include<queue>
#include<stack>
#include<map>
using namespace std;
bool BFS(int n, int s, int d, vector<int>*& graph);
void DFS(int n, int s, int d, vector<int>*& graph);
void printPath(int n, int s, int d, int*& path); 
void UCS(int n, int s, int d, vector<pair<int, int>> graph[50]);
struct option {
	bool operator()( const pair<int, int>& a, const pair<int, int>& b)const {
	return a.second > b.second;
	}
};
void main() {
	ifstream fin;
	fin.open("input.txt");
	if (fin.fail())
		return;

	int n;	//number of nodes
	int s, d, code;	//start node, destination node, code strategy
	int u;	//	weight
	fin >> n >> s >> d >> code;
	map<pair<int, int>, int>cost;
	if (code == 0 || code == 1 || code == 3)
	{
		vector<int>* graph;
		graph = new vector<int>[n];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				fin >> u;
				if (u)
					graph[i].push_back(j);
			}
	}
	else if (code == 2 || code == 4 || code == 5) {
		vector<pair<int, int>> graph[50];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				fin >> u;
				if (u) {
					graph[i].push_back(make_pair(j, u));
				}
			}
		if (code == 4 || code == 5 || code == 6) {

		}
	}
	else {
		cout << "Wrong input!\n";
		return;
	}
	fin.close();

	return;
}
bool inFrontier(priority_queue<pair<int, int>, vector<pair<int, int>>, option>q, int v) {
	while (!q.empty()) {
		if (q.top().first == v)
			return true;
		q.pop();
	}
	return false;
}
void UCS(int n, int s, int d, vector<pair<int,int>> graph[50]) {
	bool* visited = new bool[n];
	int* path = new int[n];
	priority_queue<pair<int, int>,vector<pair<int,int>>,option>q;	//frontier
	vector<int>exp;	//expanded

	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		path[i] = -1;
	}
	visited[s] = true;
	q.push(make_pair(s,0));
	if (d == s) {
		cout << endl << s;
		return;
	}

	while (!q.empty()) {
		int u = q.top().first;
		q.pop(); exp.push_back(u);
		for (int i = 0; i < graph[u].size(); ++i)
		{
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] || !inFrontier(q, v)) {
				if (v == d)
				{
					path[v] = u;
					for (int i = 0; i < exp.size(); ++i)
						cout << exp[i] << ' ';
					cout << endl;
					printPath(n, s, d, path);
					delete[] visited, path;
					return;
				}
				visited[v] = true;
				q.push(make_pair(v,w));
				path[v] = u;
			}
			else if()
		}
	}

	for (int i = 0; i < exp.size(); ++i)
		cout << exp[i] << ' ';
	cout << endl;
	printPath(n, s, d, path);
	delete[] visited, path;
	return;

}
void printPath(int n, int s, int d, int*& path) {
	int* back = new int[n];

	if (path[d] == -1) {
		cout << "No path." << endl;
		return;
	}
	int j = 0;
	while (true) {
		back[j++] = d;
		d = path[d];
		if (s == d) { back[j++] = s; break; }
	}

	for (int i = j - 1; i >= 0; --i)
		cout << back[i] << " ";

	delete[] back;
}
