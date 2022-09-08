using namespace std;
#define INF 999
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <functional>
class ShortestPathFinder {
public:
	

	ShortestPathFinder(string maze) {

		V = (int)sqrt((int)maze.length());
		W = V*V;
		grid.resize(V, vector<int>(V));
		cost.resize(W, vector<int>(W, INF));
		maze.erase(std::remove(maze.begin(), maze.end(), '\n'), maze.end());
		for (int i = 0; i <W; i++) {
			grid[i / V][i % V] = maze[i] - 48;
		}
		src = 0;
		parent.resize(W);
		dist.resize(W);
		visited.resize(W, false);
		for (int i = 0; i < W; i++) {
			dist[i] = INF;
		}
		dist[src] = 0;
		initializeCostGrid();
	}

	int findShortestPath(); //dijkstra's algorithm
	//void display();
	
private:
	int V,W, src;
	vector<int> parent, dist;
	vector<bool> visited;
	vector<vector<int>> grid, cost;

	std::vector< void(ShortestPathFinder::*)(int i, int j, int c)> vectorOfFunctions;
	void up(int i, int j, int c) {cost[c - V][c] = cost[c][c - V] = abs(grid[i][j] - grid[i - 1][j]);}
	void down(int i, int j, int c) {cost[c + V][c] = cost[c][c + V] = abs(grid[i][j] - grid[i + 1][j]);	}
	void left(int i, int j, int c) {cost[c][c - 1] = cost[c - 1][c] = abs(grid[i][j] - grid[i][j - 1]);	}
	void right(int i, int j, int c) {cost[c][c + 1] = cost[c + 1][c] = abs(grid[i][j] - grid[i][j + 1]);}
	int getNearestNode();
	void initializeCostGrid() {	
		function <int(int, int, int)> costGridInt = [=](int m, int n, int v) {  return m * v + n; };
		for (int i = 0; i <W; i++) cost[i][i] = 0;
		
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				bool atTop(i == 0), atBottom(i == V - 1), atLeft(j == 0),atRight(j == V - 1);
				int costInt = costGridInt(i, j, V);
				vectorOfFunctions.clear();
				if (atTop) {
					if (atLeft) vectorOfFunctions = { &ShortestPathFinder::right,&ShortestPathFinder::down };
					else if (atRight)vectorOfFunctions = { &ShortestPathFinder::left,&ShortestPathFinder::down };
					else vectorOfFunctions = { &ShortestPathFinder::left,&ShortestPathFinder::right, &ShortestPathFinder::down };
				}
				else if (atBottom) {
					if (atLeft)vectorOfFunctions = { &ShortestPathFinder::right,&ShortestPathFinder::up };
					else if (atRight)vectorOfFunctions = { &ShortestPathFinder::left,&ShortestPathFinder::up };
					else vectorOfFunctions = { &ShortestPathFinder::left,&ShortestPathFinder::right ,&ShortestPathFinder::up };
				}
				else if (atLeft)vectorOfFunctions = { &ShortestPathFinder::down,&ShortestPathFinder::right ,&ShortestPathFinder::up };
				else if (atRight)vectorOfFunctions = { &ShortestPathFinder::left,&ShortestPathFinder::down ,&ShortestPathFinder::up };
				else vectorOfFunctions = { &ShortestPathFinder::left,&ShortestPathFinder::right ,&ShortestPathFinder::up,&ShortestPathFinder::down };
				
				for (int k = 0; k < (int)vectorOfFunctions.size(); k++) (this->*vectorOfFunctions.at(k))(i, j, costInt);
			}
		}
		//printGrid();
		//printCostGrid();
	}
	/*void printGrid() {
		cout << "Current Alpine Grid: " << endl;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cout << grid[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	/*void printCostGrid() {
		cout << "Current Alpine Grid: " << endl;
		for (int i = 0; i <W; i++) {
			for (int j = 0; j <W; j++) {
				cout << cost[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
	}*/
};

int ShortestPathFinder::getNearestNode()
{
	int minValue = INF;
	int minNode = 0;
	for (int i = 0; i <W; i++) {
		if (!visited[i] && dist[i] < minValue) {
			minValue = dist[i];
			minNode = i;
		}
	}
	return minNode;
}
int ShortestPathFinder::findShortestPath()
{
	for (int i = 0; i <W - 1; i++) {
		int nearest = getNearestNode();
		visited[nearest] = true;
		for (int adj = 0; adj <W; adj++) { //update distances of all adjacent nodes
			if ((cost[nearest][adj] != INF) && (dist[adj] > (dist[nearest] + cost[nearest][adj]))) {
				dist[adj] = dist[nearest] + cost[nearest][adj];
				parent[adj] = nearest;
			}
		}

	}
	return dist[W - 1];
}
//void ShortestPathFinder::display()
//{
//	cout << "Node:\t\t\tCost :\t\t\tPath";
//
//	for (int i = 0; i <W; i++)
//	{
//		cout << i << "\t\t\t" << dist[i] << "\t\t\t" << " ";
//		cout << i << " ";
//		int parentNode = parent[i];
//		while (parentNode != src) {
//			cout << " <- " << parentNode << " ";
//			parentNode = parent[parentNode];
//		}
//		cout << endl << endl;
//	}
//
//	cout << "Visited Array:" << endl;
//	for (int i = 0; i <W; i++) cout << visited[i] << " ";
//	cout << endl;
//}
int path_finder(string maze)
{
	if (maze.length() < 2) return 0;
	ShortestPathFinder alps(maze);
	return alps.findShortestPath(); //source is 0
}

int main() {

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




//#include <vector>
//#include <string>
//#include <math.h>
//#include <algorithm>
//#include <iostream>
//using namespace std;
//class Alpinist {
//public:
//    int minSolutionSoFar;
//    Alpinist(string m) {
//        side = (int)sqrt((int)m.length());
//        grid.resize(side, vector<int>(side));
//        visited.resize(side, vector<bool>(side));
//        m.erase(std::remove(m.begin(), m.end(), '\n'), m.end());
//        for (int i = 0; i < side * side; i++) {
//            grid[i / side][i % side] = m[i] - 48;
//            visited[i / side][i % side] = 0;
//        }
//        minSolutionSoFar = +2147483647; //maximum int
//       // printGrid();
//    }
//    bool findMinClimb(int x, int y, int currentClimb);
//
//private:
//    void printGrid() {
//        cout << "Current Alpine Grid: " << endl;
//        for (int i = 0; i < side; i++) {
//            for (int j = 0; j < side; j++) {
//                cout << grid[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//    vector<vector<int>> grid;
//    vector<vector<bool>> visited;
//    int side;
//    bool canGo(int x, int y);
//};
//bool Alpinist::canGo(int x, int y) {
//    return(x<0 || y<0 || x>side - 1 || y>side - 1 || visited[x][y] == 1) ? false : true;
//}
//bool Alpinist::findMinClimb(int x, int y, int currentClimb)//order: East,South, West, North;
//{
//    if (currentClimb > minSolutionSoFar)return false;
//    if (x == side - 1 && y == side - 1) {
//        if (currentClimb < minSolutionSoFar) minSolutionSoFar = currentClimb;
//        return true;
//    }
//    if (!canGo(x - 1, y) && !canGo(x + 1, y) && !canGo(x, y - 1) && !canGo(x, y + 1)) return false;  //up, down, left, right, respectively
//
//    visited[x][y] = 1;
//    int heightDifference;
//    bool successful;
//    if (canGo(x + 1, y)) { //down
//        heightDifference = abs(grid[x][y] - grid[x + 1][y]);
//        successful = findMinClimb(x + 1, y, currentClimb + heightDifference);
//        visited[x + 1][y] = 0;
//    }
//    if (canGo(x, y + 1)) { //right
//        heightDifference = abs(grid[x][y] - grid[x][y + 1]);
//        successful = findMinClimb(x, y + 1, currentClimb + heightDifference);
//        visited[x][y + 1] = 0;
//    }
//    if (canGo(x - 1, y)) { //up
//        heightDifference = abs(grid[x][y] - grid[x - 1][y]);
//        successful = findMinClimb(x - 1, y, currentClimb + heightDifference);
//        visited[x - 1][y] = 0;
//
//    }
//    if (canGo(x, y - 1)) { //left
//        heightDifference = abs(grid[x][y] - grid[x][y - 1]);
//        successful = findMinClimb(x, y - 1, currentClimb + heightDifference);
//        visited[x][y - 1] = 0;
//    }
//    if (!successful) {
//        visited[x][y] = 0;
//        return false;
//    }
//    return successful;
//}
//int path_finder(string maze)
//{
//    Alpinist alps(maze);
//    alps.findMinClimb(0, 0, 0);
//    return alps.minSolutionSoFar;
//}
//
//int main() {
//
//    string s1 =
//
//        "000\n"
//        "000\n"
//        "000";
//
//    string s2 =
//
//        "010\n"
//        "010\n"
//        "010";
//
//    string s3 =
//
//        "010\n"
//        "101\n"
//        "010";
//
//    string s4 =
//
//        "0707\n"
//        "7070\n"
//        "0707\n"
//        "7070";
//
//    string s5 =
//
//        "700000\n"
//        "077770\n"
//        "077770\n"
//        "077770\n"
//        "077770\n"
//        "000007";
//
//    string s6 =
//
//        "777000\n"
//        "007000\n"
//        "007000\n"
//        "007000\n"
//        "007000\n"
//        "007777";
//
//    string s7 =
//
//        "000000\n"
//        "000000\n"
//        "000000\n"
//        "000010\n"
//        "000109\n"
//        "001010";
//
//    string codeWars =
//        "9580\n"
//        "2538\n"
//        "7738\n"
//        "4804";
//
//
//    int result;
//    result = (path_finder(codeWars));
//
//    result = (path_finder(s3)); //Equals(4));
//
//    result = (path_finder(s4)); //Equals(42));
//    result = (path_finder(s1)); //Equals(0));
//    result = (path_finder(s2)); //Equals(2));
//
//    result = (path_finder(s5)); //Equals(14));
//    result = (path_finder(s6)); //Equals(0));
//    result = (path_finder(s7)); //Equals(4));
//
//
//    return 0;
//}
