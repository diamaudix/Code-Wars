/*1) Create a set sptSet (shortest path tree set) that keeps track of vertices included in shortest path tree, 
	i.e., whose minimum distance from source is calculated and finalized. Initially, this set is empty. 
2) Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. 
	Assign distance value as 0 for the source vertex so that it is picked first. 
3) While sptSet doesn’t include all vertices 
….a) Pick a vertex u which is not there in sptSet and has minimum distance value. 
….b) Include u to sptSet. 
….c) Update distance value of all adjacent vertices of u. 
	To update the distance values, iterate through all adjacent vertices. 
	For every adjacent vertex v, if sum of distance value of u (from source) and weight of edge u-v, is less than the distance value of v, 
	then update the distance value of v.
*/

using namespace std;
#define INF 99999
#include <vector>
#include <iostream>
class ShortestPathFinder {
public:
	int V, src;
	vector<int> parent, dist;
	vector<bool> visited;
	vector<vector<int>> cost;

	ShortestPathFinder() {
		cost = {
		{0, 4, INF,INF,INF,INF,INF,8,INF},
		{4, 0,8, INF,INF,INF,INF, 8, INF},
		{INF,8,0,7,INF, 4,INF,INF, 2},
		{INF,INF, 7, 0, 9, 14, INF,INF,INF},
		{INF,INF,INF,9,0,10,INF,INF,INF},
		{INF,INF,4, 14, 10,0, 2,INF,INF},
		{INF,INF,INF,INF,INF,2,0,1,6},
		{8,11,INF,INF,INF,INF,1,0,7},
		{INF,INF,2,INF,INF,INF,6,7,0}
		};
		src = 0;
		V = cost.size();
		parent.resize(V);
		dist.resize(V);
		visited.resize(V,false);

		for (int i = 0; i < V; i++) {
			dist[i] = INF;
		}
		dist[src] = 0;
	}

	void dijkstra();
	void display();
	int getNearestNode();
};

int ShortestPathFinder::getNearestNode()
{
	int minValue = INF;
	int minNode = 0;
	for (int i = 0; i < V; i++) {
		if (!visited[i] && dist[i] < minValue) {
			minValue = dist[i];
			minNode = i;
		}
	}
	return minNode;
}
void ShortestPathFinder::dijkstra()
{
	for (int i = 0; i < V-1; i++) {
		int nearest = getNearestNode();
		visited[nearest] = true;

		for (int adj = 0; adj < V; adj++) { //update distances of all adjacent nodes

			if ((cost[nearest][adj] != INF) && (dist[adj] > (dist[nearest] + cost[nearest][adj]))) {
				dist[adj] = dist[nearest] + cost[nearest][adj];
				parent[adj] = nearest;
			}
		}

	}
}
void ShortestPathFinder::display()
{
	cout << "Node:\t\t\tCost :\t\t\tPath";

	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t\t" << dist[i] << "\t\t\t" << " ";
		cout << i << " ";
		int parentNode = parent[i];
		while (parentNode != src) {
			cout << " <- " << parentNode << " ";
			parentNode = parent[parentNode];
		}
		cout << endl;
	}
}

int main() {

	ShortestPathFinder spf;

	spf.dijkstra();
	spf.display();

	for (int i = 0; i < spf.V; i++) {
		for (int j = 0; j < spf.V; j++) {
			//construct matrix
		}
	}

	return 0;
}

