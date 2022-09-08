

//using namespace std;
//#define INF 99999
//#include <vector>
//#include <string>
//#include <iostream>
//#include <math.h>
//#include <functional>
//class ShortestPathFinder {
//public:
//	int V, src;
//	vector<int> parent, dist;
//	vector<bool> visited;
//	vector<vector<int>> grid, cost;
//
//	ShortestPathFinder(string maze) {
//
//		V = (int)sqrt((int)maze.length());
//		grid.resize(V, vector<int>(V));
//		cost.resize(V * V, vector<int>(V * V, INF));
//		maze.erase(std::remove(maze.begin(), maze.end(), '\n'), maze.end());
//		for (int i = 0; i < V * V; i++) {
//			grid[i / V][i % V] = maze[i] - 48;
//		}
//
//		/*cost = {
//		{0, 4, INF,INF,INF,INF,INF,8,INF},
//		{4, 0,8, INF,INF,INF,INF, 8, INF},
//		{INF,8,0,7,INF, 4,INF,INF, 2},
//		{INF,INF, 7, 0, 9, 14, INF,INF,INF},
//		{INF,INF,INF,9,0,10,INF,INF,INF},
//		{INF,INF,4, 14, 10,0, 2,INF,INF},
//		{INF,INF,INF,INF,INF,2,0,1,6},
//		{8,11,INF,INF,INF,INF,1,0,7},
//		{INF,INF,2,INF,INF,INF,6,7,0}
//		};*/
//		src = 0;
//		//V = cost.size();
//		parent.resize(V*V);
//		dist.resize(V*V);
//		visited.resize(V*V, false);
//
//		for (int i = 0; i < V*V; i++) {
//			dist[i] = INF;
//		}
//		dist[src] = 0;
//		initializeCostGrid();
//	}
//
//	int findShortestPath(); //dijkstra's algorithm
//	void display();
//	int getNearestNode();
//
//private:
//	void initializeCostGrid() {
//		for (int i = 0; i < V*V; i++) cost[i][i] = 0;
//
//		function <int(int, int, int)> costGridInt = [=](int m, int n, int v) {  return m * v + n; };
//		bool top(false), bottom(false), left(false), right(false);
//		
//		for (int i = 0; i < V; i++) {
//			for (int j = 0; j < V; j++) {
//				bool top = (i == 0);
//				bool bottom = (i == V - 1);
//				bool left = (j == 0);
//				bool right = (j == V - 1);
//
//				int costInt = costGridInt(i, j, V);
//
//				if (top) {
//
//
//					if (left) {
//						cost[costInt+V][costInt] = cost[costInt][costInt + V] = abs(grid[i][j] - grid[i + 1][j]);
//						cost[costInt][costInt + 1] = cost[costInt+1][costInt] = abs(grid[i][j] - grid[i][j+1]);
//						
//					}
//					else if (right) {
//						cost[costInt + V][costInt] = cost[costInt][costInt + V] = abs(grid[i][j] - grid[i + 1][j]);
//						cost[costInt][costInt - 1] = cost[costInt - 1][costInt] = abs(grid[i][j] - grid[i][j - 1]);
//					}
//					else {
//						cost[costInt + V][costInt] = cost[costInt][costInt + V] = abs(grid[i][j] - grid[i + 1][j]);
//						cost[costInt][costInt + 1] = cost[costInt + 1][costInt] = abs(grid[i][j] - grid[i][j + 1]);
//						cost[costInt][costInt - 1] = cost[costInt - 1][costInt] = abs(grid[i][j] - grid[i][j - 1]);
//					}
//				}
//				else if (bottom) {
//					if (left) {
//						cost[costInt - V][costInt] = cost[costInt][costInt - V] = abs(grid[i][j] - grid[i - 1][j]);
//						cost[costInt][costInt + 1] = cost[costInt + 1][costInt] = abs(grid[i][j] - grid[i][j + 1]);
//					}
//					else if (right) {
//						cost[costInt - V][costInt] = cost[costInt][costInt - V] = abs(grid[i][j] - grid[i - 1][j]);
//						cost[costInt][costInt - 1] = cost[costInt - 1][costInt] = abs(grid[i][j] - grid[i][j - 1]);
//					}
//					else {
//						cost[costInt - V][costInt] = cost[costInt][costInt - V] = abs(grid[i][j] - grid[i - 1][j]);
//						cost[costInt][costInt + 1] = cost[costInt + 1][costInt] = abs(grid[i][j] - grid[i][j + 1]);
//						cost[costInt][costInt - 1] = cost[costInt - 1][costInt] = abs(grid[i][j] - grid[i][j - 1]);
//					}
//				}
//				else if (left) {
//					cost[costInt - V][costInt] = cost[costInt][costInt - V] = abs(grid[i][j] - grid[i - 1][j]);
//					cost[costInt + V][costInt] = cost[costInt][costInt + V] = abs(grid[i][j] - grid[i + 1][j]);
//					cost[costInt][costInt + 1] = cost[costInt + 1][costInt] = abs(grid[i][j] - grid[i][j + 1]);
//				}
//				else if (right) {
//					cost[costInt - V][costInt] = cost[costInt][costInt - V] = abs(grid[i][j] - grid[i - 1][j]);
//					cost[costInt + V][costInt] = cost[costInt][costInt + V] = abs(grid[i][j] - grid[i + 1][j]);
//					cost[costInt][costInt - 1] = cost[costInt - 1][costInt] = abs(grid[i][j] - grid[i][j - 1]);
//
//				}
//				else {
//					cost[costInt - V][costInt] = cost[costInt][costInt - V] = abs(grid[i][j] - grid[i - 1][j]);
//					cost[costInt + V][costInt] = cost[costInt][costInt + V] = abs(grid[i][j] - grid[i + 1][j]);
//					cost[costInt][costInt - 1] = cost[costInt - 1][costInt] = abs(grid[i][j] - grid[i][j - 1]);
//					cost[costInt][costInt + 1] = cost[costInt + 1][costInt] = abs(grid[i][j] - grid[i][j + 1]);
//				}
//			}
//		}
//		printGrid();
//		printCostGrid();
//
//	}
//	void printGrid() {
//		cout << "Current Alpine Grid: " << endl;
//		for (int i = 0; i < V; i++) {
//			for (int j = 0; j < V; j++) {
//				cout << grid[i][j] << "\t";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//	void printCostGrid() {
//		cout << "Current Alpine Grid: " << endl;
//		for (int i = 0; i < V*V; i++) {
//			for (int j = 0; j < V*V; j++) {
//				cout << cost[i][j] << "\t";
//			}
//			cout << endl;
//		}
//		cout << endl;
//	}
//};
//
//int ShortestPathFinder::getNearestNode()
//{
//	int minValue = INF;
//	int minNode = 0;
//	for (int i = 0; i < V*V; i++) {
//		if (!visited[i] && dist[i] < minValue) {
//			minValue = dist[i];
//			minNode = i;
//		}
//	}
//	return minNode;
//}
//int ShortestPathFinder::findShortestPath()
//{
//	for (int i = 0; i < V*V - 1; i++) {
//		int nearest = getNearestNode();
//		visited[nearest] = true;
//
//		for (int adj = 0; adj < V*V; adj++) { //update distances of all adjacent nodes
//
//			if ((cost[nearest][adj] != INF) && (dist[adj] > (dist[nearest] + cost[nearest][adj]))) {
//				dist[adj] = dist[nearest] + cost[nearest][adj];
//				parent[adj] = nearest;
//			}
//		}
//
//	}
//	return dist[V*V-1];
//}
//void ShortestPathFinder::display()
//{
//	cout << "Node:\t\t\tCost :\t\t\tPath";
//
//	for (int i = 0; i < V*V; i++)
//	{
//		cout << i << "\t\t\t" << dist[i] << "\t\t\t" << " ";
//		cout << i << " ";
//		int parentNode = parent[i];
//		while (parentNode != src) {
//			cout << " <- " << parentNode << " ";
//			parentNode = parent[parentNode];
//		}
//		cout << endl<<endl;
//	}
//
//	cout << "Visited Array:" << endl;
//	for (int i = 0; i < V*V; i++) cout << visited[i] << " ";
//	cout << endl;
//}
//int path_finder(string maze)
//{
//	ShortestPathFinder alps(maze);
//	int shortest = alps.findShortestPath(); //source is 0
//	return shortest;
//}
//
//int main() {
//
//	string s0 = "8";
//	string s1 =
//
//		"000\n"
//		"000\n"
//		"000";
//
//	string s2 =
//
//		"010\n"
//		"010\n"
//		"010";
//
//	string s3 =
//
//		"010\n"
//		"101\n"
//		"010";
//
//	string s4 =
//
//		"0707\n"
//		"7070\n"
//		"0707\n"
//		"7070";
//
//	string s5 =
//
//		"700000\n"
//		"077770\n"
//		"077770\n"
//		"077770\n"
//		"077770\n"
//		"000007";
//
//	string s6 =
//
//		"777000\n"
//		"007000\n"
//		"007000\n"
//		"007000\n"
//		"007000\n"
//		"007777";
//
//	string s7 =
//
//		"000000\n"
//		"000000\n"
//		"000000\n"
//		"000010\n"
//		"000109\n"
//		"001010";
//
//	string codeWars =
//		"9580\n"
//		"2538\n"
//		"7738\n"
//		"4804";
//	string codeWars3 =
//		"432\n"
//		"961\n"
//		"054";
//
//
//	int result;
//	result = (path_finder(codeWars3));
//	result = (path_finder(codeWars));
//
//
//	result = (path_finder(s3)); //Equals(4));
//
//	
//	result = (path_finder(s4)); //Equals(42));
//	result = (path_finder(s1)); //Equals(0));
//	result = (path_finder(s2)); //Equals(2));
//
//	result = (path_finder(s5)); //Equals(14));
//	result = (path_finder(s6)); //Equals(0));
//	result = (path_finder(s7)); //Equals(4));
//
//
//	return 0;
//}

// C++ program to get least cost path in a grid from
// top-left to bottom-right
#include <iostream>
#include <set>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;
//
//#define ROW 6
//#define COL 6
constexpr unsigned int ROW = 6;
constexpr unsigned int COL = 6;
// structure for information of each cell
struct cell
{
	int m, n;
	int distance;
	cell(int x, int y, int distance) :
		m(x), n(y), distance(distance) {}
};

// Utility method for comparing two cells
bool operator<(const cell& a, const cell& b)
{
	if (a.distance == b.distance)
	{
		if (a.m != b.m)
			return (a.m < b.m);
		else
			return (a.n < b.n);
	}
	return (a.distance < b.distance);
}

// Utility method to check whether a point is
// inside the grid or not
bool isInsideGrid(int i, int j, int side)
{
	return (i >= 0 && i < side && j >= 0 && j < side);
}

void printDistance(int print[ROW][COL]) {
	cout << "Current Distance Grid:" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << print[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void printGrid(int grid[ROW][COL]) {
	cout << "Current Weight Grid:" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void printCellSet(set<cell> cellSet) {
	cout << "Current CellSet:" << endl;
	std::set<cell>::iterator it = cellSet.begin();
	int i = 0;
	while (it != cellSet.end()) {
		cout << "Cell" << i << " => M: " << (*it).m << " N : " << (*it).n << " Distance : " << (*it).distance << endl;
		++it; ++i;
	}

	cout << endl;
}

// Method returns minimum cost to reach bottom
// right from top left
int shortest(vector<vector<int>> grid, int side)
{

	vector<vector<int>> distance;
	distance.resize(side, vector<int>(side));

	// initializing distance array by INT_MAX
	for (int i = 0; i < side; i++)
		for (int j = 0; j < side; j++)
			distance[i][j] = INT_MAX;

	//printDistance(distance);
	//printGrid(grid);
	// direction arrays for simplification of getting
	// neighbour
	int dx[] = { -1, 0, 1, 0 };
	int dy[] = { 0, 1, 0, -1 };

	set<cell> cellSet;

	// insert (0, 0) cell with 0 distance
	cellSet.insert(cell(0, 0, 0));
	printCellSet(cellSet);
	// initialize distance of (0, 0) with its grid value
	distance[0][0] = 0; //grid[0][0]

	// loop for standard dijkstra's algorithm
	while (!cellSet.empty())
	{
		// get the cell with minimum distance and delete
		// it from the set
		cell currentCell = *cellSet.begin();
		cellSet.erase(cellSet.begin());
		//printDistance(distance);
		//printCellSet(cellSet);
		//printGrid(grid);
		// looping through all neighbours
		for (int i = 0; i < 4; i++)
		{
			int m = currentCell.m + dx[i];
			int n = currentCell.n + dy[i];

			// if not inside boundary, ignore them
			if (!isInsideGrid(m, n,side))
				continue;

			// If distance from current cell is smaller, then
			// update distance of neighbour cell
			if (distance[m][n] > distance[currentCell.m][currentCell.n] + abs(grid[currentCell.m][currentCell.n] - grid[m][n]))
			{
				// If cell is already there in set, then
				// remove its previous entry
				if (distance[m][n] != INT_MAX)
					cellSet.erase(cellSet.find(cell(m, n, distance[m][n])));

				// update the distance and insert new updated
				// cell in set
				distance[m][n] = distance[currentCell.m][currentCell.n] + abs(grid[currentCell.m][currentCell.n] - grid[m][n]);
				cellSet.insert(cell(m, n, distance[m][n]));
			}
			//printDistance(distance);
			//printCellSet(cellSet);
			//printGrid(grid);
		}
	}

	// uncomment below code to print distance
	// of each cell from (0, 0)
	/*
	for (int i = 0; i < row; i++, cout << endl)
		for (int j = 0; j < col; j++)
			cout << distance[i][j] << " ";
	*/
	// distance[row - 1][col - 1] will represent final
	// distance of bottom right cell from top left cell
	return distance[side - 1][side - 1];
}

int path_finder(string maze)
{

	int V;
	vector<vector<int>> grid;

	V = (int)sqrt((int)maze.length());
	grid.resize(V, vector<int>(V));
	maze.erase(std::remove(maze.begin(), maze.end(), '\n'), maze.end());
	for (int i = 0; i < V * V; i++) {
		grid[i / V][i % V] = maze[i] - 48;
	}


	int shortestPath = shortest(grid, V); //source is 0
	return shortestPath;
}

// Driver code to test above methods
int main()
{
	/*int grid[ROW][COL] =
	{
		31, 100, 65, 12, 18,
		10, 13, 47, 157, 6,
		100, 113, 174, 11, 33,
		88, 124, 41, 20, 140,
		99, 32, 111, 41, 20
	};*/
	//int grid2[ROW][COL] = { {0,3,4,5,2,4},
	//						{0,3,5,1,3,2},
	//						{9,1,9,9,9,9},
	//						{0,0,9,9,9,9},
	//						{0,9,9,9,9,9},
	//						{0,0,0,0,1,1} };
	//printGrid(grid2);
	//cout << shortest(grid2, ROW, COL) << endl;



	string s0 = "8";
	string s1 =

		"000\n"
		"000\n"
		"000";

	string s2 =

		"010\n"
		"010\n"
		"010";

	string s3 =

		"010\n"
		"101\n"
		"010";

	string s4 =

		"0707\n"
		"7070\n"
		"0707\n"
		"7070";

	string s5 =

		"700000\n"
		"077770\n"
		"077770\n"
		"077770\n"
		"077770\n"
		"000007";

	string s6 =

		"777000\n"
		"007000\n"
		"007000\n"
		"007000\n"
		"007000\n"
		"007777";

	string s7 =

		"000000\n"
		"000000\n"
		"000000\n"
		"000010\n"
		"000109\n"
		"001010";

	string codeWars =
		"9580\n"
		"2538\n"
		"7738\n"
		"4804";
	string codeWars3 =
		"432\n"
		"961\n"
		"054";


	int result;
	result = (path_finder(codeWars3));
	result = (path_finder(codeWars));


	result = (path_finder(s3)); //Equals(4));

	
	result = (path_finder(s4)); //Equals(42));
	result = (path_finder(s1)); //Equals(0));
	result = (path_finder(s2)); //Equals(2));

	result = (path_finder(s5)); //Equals(14));
	result = (path_finder(s6)); //Equals(0));
	result = (path_finder(s7)); //Equals(4));


	return 0;
}