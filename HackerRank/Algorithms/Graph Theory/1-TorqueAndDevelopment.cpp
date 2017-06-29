#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <set>
using namespace std;

class Graph {
public:
	Graph(int vertexCount, int c_lib, int c_road) : libCost(c_lib), roadCost(c_road) {
		graph.resize(vertexCount, Vertex());
		for (int i = 0; i < graph.size(); i++) {
			unvisitedVertices.insert(i);
		}
	}

	void addEdge(int u_i, int v_i) {
		insertIntoList(u_i, v_i);
		insertIntoList(v_i, u_i);
	}

	long getCost() {
		long currentCost = 0;
		while (!unvisitedVertices.empty()) {
			int currentVertex = *unvisitedVertices.begin();
			currentCost += (BFS(currentVertex)*roadCost) + libCost;
		}
		return currentCost;	
	}
private:
	struct Edge {
		Edge(int to) : to(to) { }
		int to;
	};
	struct Vertex {
		Vertex() {
			visited = false;
			edges = list<Edge>();
		}
		bool visited;
		list<Edge> edges;
	};

	vector<Vertex> graph; // 0-Based Adjacency List
	set<int> unvisitedVertices; //searching for an unvisited vertex becomes easier
	int libCost;
	int roadCost;

	void insertIntoList(int from, int to) {
		list<Edge> & edges = graph[from].edges;
		edges.push_back(Edge(to));
	}

	int BFS(int source) {
		// starting from `source` build BFS tree, mark visited nodes and
		// return number of edges in the built BFS tree
		queue<int> BFSqueue;
		BFSqueue.push(source);
		graph[source].visited = true;
		set<int>::iterator source_it = unvisitedVertices.find(source);
		unvisitedVertices.erase(source_it);
		int numEdges = 0;

		while (!BFSqueue.empty()) {
			int frontElement = BFSqueue.front();
			BFSqueue.pop();
			list<Edge> & edges = graph[frontElement].edges;

			for (list<Edge>::iterator edgeIter = edges.begin(); edgeIter != edges.end(); edgeIter++) {
				if (!graph[edgeIter->to].visited) {
					graph[edgeIter->to].visited = true;

					
					set<int>::iterator it = unvisitedVertices.find(edgeIter->to);
					if (it != unvisitedVertices.end()) {
						unvisitedVertices.erase(it);
					}

					BFSqueue.push(edgeIter->to);
					numEdges++;
				}
			}
		}
		return numEdges;
	}
};

int main() {
	int q;
	cin >> q;
	for (int t = 0; t < q; t++) {
		int n, m;
		long c_lib, c_road;
		cin >> n >> m >> c_lib >> c_road;
		if (c_lib <= c_road) {
			cout << c_lib*n << endl;
			// ignore the edge input
			for (int i = 0; i < m; i++) {
				int u_i, v_i;
				cin >> u_i >> v_i;
			}
		}
		else {
			Graph graph(n, c_lib, c_road);
			for (int i = 0; i < m; i++) {
				int u_i, v_i;
				cin >> u_i >> v_i;
				graph.addEdge(u_i - 1, v_i - 1);
			}
			cout << graph.getCost() << endl;
		}
		
	}
	return 0;
}