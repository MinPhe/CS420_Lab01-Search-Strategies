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
void UCS(int n, int s, int d, vector<int>*& graph);
struct option {
	bool operator() const pair<int, int>& a, const pair<int, int>& b)const {
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
	if (code == 0 || code == 1||code==3)
	{
		vector<int>* graph;
		graph = new vector<int>[n];

		
		switch (code)
		{
		case 0: {for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				fin >> u;
				if (u)
					graph[i].push_back(j);
			}
			  BFS(n, s, d, graph);	break; }
		case 1:readDFS(fin, n, graph); DFS(n, s, d, graph);	break;
		case 3:break;
		}
		for (int i = 0; i < n; ++i)
			graph[i].clear();
		delete[] graph, graph = NULL;
		/*for (int i = 0; i < n; ++i) {
			for (int j = 0; j < graph[i].size(); ++j)
				cout << graph[i][j] << ' ';
			cout << endl;
		}
		cout << endl;*/
	}
	else if (code ==2 || code == 4 || code == 5) {

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				fin >> u;
				if (u) {
					graph[i].push_back(j);
					cost[make_pair(i, j)] = u;
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

void UCS(int n, int s, int d, vector<int>*& graph, map<pair<int, int>, int> cost) {
	bool* visited = new bool[n];
	int* path = new int[n];
	priority_queue<pair<int, int>>q;	//frontier
	vector<int>exp;	//expanded

	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		path[i] = -1;
	}
	visited[s] = true;
	q.push(s);
	if (d == s) {
		cout << endl << s;
		return;
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop(); exp.push_back(u);
		for (int i = 0; i < graph[u].size(); ++i)
		{
			int v = graph[u][i];

			if (!visited[v]) {
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
				q.push(v);
				path[v] = u;
			}
		}
	}

	for (int i = 0; i < exp.size(); ++i)
		cout << exp[i] << ' ';
	cout << endl;
	printPath(n, s, d, path);
	delete[] visited, path;
	return;

}
bool inFrontier(queue<int> q, int v) {
	while (!q.empty()) {
		if (q.front() == v)
			return true;
		q.pop();
	}
	return false;
}
bool BFS(int n, int s, int d, vector<int>*& graph) {
	bool* visited = new bool[n];
	int* path = new int[n];
	queue<int>q;	//frontier
	vector<int>exp;	//expanded

	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		path[i] = -1;
	}
	visited[s] = true;
	q.push(s);
	if (d == s) {
		cout << endl << s;
		return true;
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop(); exp.push_back(u);
		for (int i = 0; i < graph[u].size(); ++i)
		{
			int v = graph[u][i];

			if (!visited[v] || !inFrontier(q, v)) {
				if (v == d)
				{
					path[v] = u;
					for (int i = 0; i < exp.size(); ++i)
						cout << exp[i] << ' ';
					cout << endl;
					printPath(n, s, d, path);
					delete[] visited, path;
					return true;
				}
				visited[v] = true;
				q.push(v);
				path[v] = u;
			}
		}
	}

	for (int i = 0; i < exp.size(); ++i)
		cout << exp[i] << ' ';
	cout << endl;
	printPath(n, s, d, path);
	delete[] visited, path;
	return true;
}
void readDFS(ifstream& fin, int n, vector<int>*& graph) {
	int graphTmp[50][50];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			fin >> graphTmp[i][j];
		}
	for (int i = n - 1; i >= 0; --i)
		for (int j = n - 1; j >= 0; --j)
			if (graphTmp[i][j])
				graph[i].push_back(j);
}
void DFS(int n, int s, int d, vector<int>*& graph) {
	bool* visited = new bool[n];
	int* path = new int[n];
	stack<int>frontier;	//frontier
	vector<int>exp;	//expanded

	for (int i = 0; i < n; ++i)
	{
		visited[i] = false;
		path[i] = -1;
	}
	visited[s] = true;
	frontier.push(s);
	if (d == s) {
		cout << endl << s;
		return;
	}

	while (!frontier.empty()) {
		int u = frontier.top();
		frontier.pop(); exp.push_back(u);
		for (int i = 0; i < graph[u].size(); ++i)
		{
			int v = graph[u][i];

			if (!visited[v]) {
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
				frontier.push(v);
				path[v] = u;
			}
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
