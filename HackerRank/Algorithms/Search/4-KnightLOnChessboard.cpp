#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
	Vertex(bool vis, bool edge, int dist) 
		: visited(vis), connected(edge) { }
	bool visited;
	bool connected; // true if there is an edge
};

class Graph {
public:
	Graph(int boardSize, int verticalMovement, int horizontalMovement) 
		: n(boardSize), vertical(verticalMovement), horizontal(horizontalMovement) {
		graph.resize(n*n);
		for (int i = 0; i < n*n; i++) {
			graph[i] = vector<Vertex>(boardSize*boardSize, Vertex(false, false, 0));
		}
	}

	int getDistance() {
		// 1 - Generate edges by knightMove
		const int a = vertical, b = horizontal;
		for (int i = 0; i < n*n; i++) {
			int x_1 = i % n, y_1 = (i - (x_1)) / n;
			// (x, y) -> (x + a, y + b*n)
			if (x_1 + a < n && y_1 + b < n) {
				graph[i][i + a + b*n].connected = true;
			}
			// (x, y) -> (x - a, y + b*n)
			if (x_1 - a >= 0 && y_1 + b < n) {
				graph[i][i - a + b*n].connected = true;
			}
			// (x, y) -> (x + a, y - b*n)
			if (x_1 + a < n && y_1 - b >= 0) {
				graph[i][i + a - b*n].connected = true;
			}
			// (x, y) -> (x - a, y - b*n)
			if (x_1 - a >= 0 && y_1 - b >= 0) {
				graph[i][i - a - b*n].connected = true;
			}
			// (x, y) -> (x + b, y + a*n)
			if (x_1 + b < n && y_1 + a < n) {
				graph[i][i + b + a*n].connected = true;
			}
			// (x, y) -> (x - b, y - a*n)
			if (x_1 - b >= 0 && y_1 - a >= 0) {
				graph[i][i - b - a*n].connected = true;
			}
			// (x, y) -> (x + b, y - a*n)
			if (x_1 + b < n && y_1 - a >= 0) {
				graph[i][i + b - a*n].connected = true;
			}
			// (x, y) -> (x - b, y + a*n)
			if (x_1 - b >= 0 && y_1 + a < n) {
				graph[i][i - b + a*n].connected = true;
			}
		} // above generates an undirected graph

		// 2 - Perform BFS over the graph starting from (0, 0)
		queue<int> BFSqueue;
		vector<int> distance(n*n);
		BFSqueue.push(0);

		graph[0][0].visited = true;
		distance[0] = 0;

		while (!BFSqueue.empty()) {
			int currentGrid = BFSqueue.front();
			BFSqueue.pop();

			for (int i = 0; i < n*n; i++) {
				if (graph[currentGrid][i].connected && !graph[currentGrid][i].visited) {
					distance[i] = distance[currentGrid] + 1;
					graph[currentGrid][i].visited = true;
					BFSqueue.push(i);

					if (i == n*n - 1) {
						return distance[i];
					}
				}
			}
		}

		// 3 - If still not returned, then there is no path connecting (0, 0) to (n - 1, n - 1)
		return -1;
	}

private:
	vector<vector<Vertex>> graph;
	int n, vertical, horizontal;
	// Graph vertices are indexed from 0 to (n^2 - 1) where board size is n^2
};

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			Graph currentGraph(n, i, j);
			cout << currentGraph.getDistance() << " ";
		}
		cout << endl;
	}
	return 0;
}