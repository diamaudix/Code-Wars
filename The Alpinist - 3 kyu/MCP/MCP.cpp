
/* Dynamic Programming implementation of MCP problem */
#include<limits.h>
#include<iostream>
#include <vector> 
#include <string>

#define R 3
#define C 3
using namespace std;

class SPF {
public:
	int V, W, src;
	int m, n;
	vector<int> parent, dist;
	vector<bool> visited;
	vector<vector<int>> grid, cost;
	SPF(string maze) {

		V = (int)sqrt((int)maze.length());
		m = n = V;
		W = V * V;
		grid.resize(V, vector<int>(V));
		maze.erase(std::remove(maze.begin(), maze.end(), '\n'), maze.end());
		for (int i = 0; i < W; i++) {
			grid[i / V][i % V] = maze[i] - 48;
		}
		initializeCostGrid();
	}
	void initializeCostGrid();
    int min(int x, int y, int z);
    int minCost();
};

void SPF::initializeCostGrid()
{


}
int SPF::minCost()
{
    int i, j;

    // Instead of following line, we can use int tc[m+1][n+1] or
    // dynamically allocate memory to save space. The following line is
    // used to keep the program simple and make it working on all compilers.
	vector<vector<int>> tc;
	
	tc.resize(V, vector<int>(V));
    
	tc[0][0] = cost[0][0];

    /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++)
        tc[i][0] = tc[i - 1][0] + cost[i][0];

    /* Initialize first row of tc array */
    for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j - 1] + cost[0][j];

    /* Construct rest of the tc array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i - 1][j - 1],
                tc[i - 1][j],
                tc[i][j - 1]) + cost[i][j];

    return tc[m][n];
}

/* A utility function that returns minimum of 3 integers */
int SPF::min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

int path_finder(string maze)
{
	if (maze.length() < 2) return 0;
	SPF alps(maze);
	int minimum = alps.minCost();
	return minimum; //source is 0
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
// This code is contributed by shivanisinghss2110