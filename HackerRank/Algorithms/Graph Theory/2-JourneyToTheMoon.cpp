#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>
using namespace std;

class Graph {
public:
	Graph(int N) {
		graph.resize(N, Vertex());
		for (int i = 0; i < N; i++) {
			unvisitedVertices.insert(i);
		}
	}

	void addEdge(int u_i, int v_i) {
		graph[u_i].edges.push_back(Edge(v_i));
		graph[v_i].edges.push_back(Edge(u_i));
	}

	long getCombinationCount() {
		list<int> clusters;
		
		while (!unvisitedVertices.empty()) {
			int unvisitedVertex = *unvisitedVertices.begin();
			int currentCluster = BFS(unvisitedVertex);
			clusters.push_back(currentCluster);
		}
		
		long combinationCount = 0;
		for (list<int>::iterator it = clusters.begin(); it != clusters.end(); it++) {
			combinationCount += ((long)*it) * (long(graph.size() - *it));
		}
		return combinationCount/2;
	}

private:
	struct Edge {
		Edge(int u_i) : to(u_i) { }
		int to;
	};
	struct Vertex {
		Vertex() : visited(false), edges(list<Edge>()) {}
		bool visited;
		list<Edge> edges;
	};

	vector<Vertex> graph; // Adjacency List representation
	set<int> unvisitedVertices;

	int BFS(int source) {
		// return the number of vertices visited during traversal
		queue<int> BFSqueue;
		graph[source].visited = true;
		BFSqueue.push(source);
		set<int>::iterator source_ptr = unvisitedVertices.find(source);
		unvisitedVertices.erase(source_ptr);
		int vertexCount = 1;

		while (!BFSqueue.empty()) {
			int frontElement = BFSqueue.front();
			list<Edge> & currentList = graph[frontElement].edges;
			BFSqueue.pop();
			
			for (list<Edge>::iterator it = currentList.begin(); it != currentList.end(); it++) {
				if (!graph[it->to].visited) {
					graph[it->to].visited = true;
					set<int>::iterator visit_ptr = unvisitedVertices.find(it->to);
					unvisitedVertices.erase(visit_ptr);

					BFSqueue.push(it->to);
					vertexCount++;
				}
			}
		}
		return vertexCount;
	}
};

int main() {
	int N, P;
	cin >> N >> P;
	Graph graph(N);
	for (int i = 0; i < P; i++) {
		int A, B;
		cin >> A >> B;
		graph.addEdge(A, B);
	}

	cout << graph.getCombinationCount();
	return 0;
}