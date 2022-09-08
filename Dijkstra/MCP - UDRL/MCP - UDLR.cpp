// C++ program to get least cost path in a grid from
// top-left to bottom-right
#include <iostream>
#include <set>
#include <limits.h>
#include <array>
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
bool isInsideGrid(int i, int j)
{
    return (i >= 0 && i < ROW && j >= 0 && j < COL);
}

void printDistance(int print[ROW][COL]) {
    cout << "Current Distance Grid:" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << print[i][j]<<" ";
        }
        cout << endl;
    }
    cout << endl;
}
void printGrid(int grid[ROW][COL]) {
    cout << "Current Weight Grid:" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            cout << grid[i][j]<< " ";
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
        cout << "Cell" << i << " => M: " <<  (*it).m << " N : " << (*it).n << " Distance : " << (*it).distance << endl;
        ++it; ++i;
    }
    
    cout << endl;
}

// Method returns minimum cost to reach bottom
// right from top left
int shortest(int grid[ROW][COL], int row, int col)
{
    int distance[ROW][COL];

    // initializing distance array by INT_MAX
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            distance[i][j] = INT_MAX;

    printDistance(distance);
    printGrid(grid);
    // direction arrays for simplification of getting
    // neighbour
    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    set<cell> cellSet;

    // insert (0, 0) cell with 0 distance
    cellSet.insert(cell(0, 0, 0));
    printCellSet(cellSet);
    // initialize distance of (0, 0) with its grid value
    distance[0][0] = grid[0][0];

    // loop for standard dijkstra's algorithm
    while (!cellSet.empty())
    {
        // get the cell with minimum distance and delete
        // it from the set
        cell currentCell = *cellSet.begin();
        cellSet.erase(cellSet.begin());
        printDistance(distance);
        printCellSet(cellSet);
        printGrid(grid);
        // looping through all neighbours
        for (int i = 0; i < 4; i++)
        {
            int m = currentCell.m + dx[i];
            int n = currentCell.n + dy[i];

            // if not inside boundary, ignore them
            if (!isInsideGrid(m, n))
                continue;

            // If distance from current cell is smaller, then
            // update distance of neighbour cell
            if (distance[m][n] > distance[currentCell.m][currentCell.n] + grid[m][n])
            {
                // If cell is already there in set, then
                // remove its previous entry
                if (distance[m][n] != INT_MAX)
                    cellSet.erase(cellSet.find(cell(m, n, distance[m][n])));

                // update the distance and insert new updated
                // cell in set
                distance[m][n] = distance[currentCell.m][currentCell.n] + grid[m][n];
                cellSet.insert(cell(m, n, distance[m][n]));
            }
            printDistance(distance);
            printCellSet(cellSet);
            printGrid(grid);
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
    return distance[row - 1][col - 1];
}

// Driver code to test above methods
int main()
{
    int grid[ROW][COL] =
    {
        31, 100, 65, 12, 18,
        10, 13, 47, 157, 6,
        100, 113, 174, 11, 33,
        88, 124, 41, 20, 140,
        99, 32, 111, 41, 20
    };
    int grid2[ROW][COL] = { {0,3,4,5,2,4},
                            {0,3,5,1,3,2},
                            {9,1,9,9,9,9},
                            {0,0,9,9,9,9},
                            {0,9,9,9,9,9},
                            {0,0,0,0,1,1} };
    printGrid(grid2);
    cout << shortest(grid2, ROW, COL) << endl;
    return 0;
}