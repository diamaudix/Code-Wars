
/* Dynamic Programming implementation of MCP problem */
#include<limits.h>
#include<iostream>
#define R 6
#define C 6
using namespace std;
int min(int x, int y, int z);

void printMatrix(int temp[R][C]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << temp[i][j] << " ";
        }
        cout << endl << endl;
    }
}
int minCost(int cost[R][C], int m, int n)
{
    int i, j;

    // Instead of following line, we can use int tc[m+1][n+1] or
    // dynamically allocate memory to save space. The following line is
    // used to keep the program simple and make it working on all compilers.
    int tc[R][C];

    tc[0][0] = cost[0][0];

    /* Initialize first column of total cost(tc) array */
    for (i = 1; i <= m; i++)
        tc[i][0] = tc[i - 1][0] + cost[i][0];

    cout << "Current tc Grid:" << endl;
    printMatrix(tc);

    /* Initialize first row of tc array */
    for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j - 1] + cost[0][j];

    cout << "Current tc Grid:" << endl;
    printMatrix(tc);

    /* Construct rest of the tc array */
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            tc[i][j] = min(tc[i - 1][j - 1],
                tc[i - 1][j],
                tc[i][j - 1]) + cost[i][j];

    cout << "Current tc Grid:" << endl;
    printMatrix(tc);

    return tc[m][n];
}


/* A utility function that returns minimum of 3 integers */
int min(int x, int y, int z)
{
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

/* Driver code*/
int main()
{
    //int cost[R][C] = { {1, 2, 3},
    //                   {4, 8, 2},
    //                   {1, 5, 3} };

    int cost1[R][C] = { {0,3,4,5,2,4},
                       {0,3,5,1,3,2},
                       {9,1,9,9,9,9},
                       {0,0,9,9,9,9},
                       {0,9,9,9,9,9},
                       {0,0,0,0,1,1} };
    
    cout << "Original Grid:" << endl;
    printMatrix(cost1);
    cout << "  " << minCost(cost1, R-1, C-1);
    return 0;
}

// This code is contributed by shivanisinghss2110