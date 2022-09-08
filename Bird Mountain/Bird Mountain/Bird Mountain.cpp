//#include <vector>
//#include <iostream>
//using namespace std;
//
//class BirdMountain {
//
//public: 
//
//    BirdMountain(vector<string> maze) {
//        
//        M = (int)maze.size();
//        N = (int)maze[0].length();
//        grid.resize(M, vector<int>(N,0));
//   
//        for (int m = 0; m < M; m++) {
//            for (int n = 0; n < N; n++) {
//                if(maze[m][n] == '^') grid[m][n] = 1;
//            }
//        }
//
//        printGrid();
//        
//    }
//    int findHeight();
//
//private:
//    vector<vector<int>> grid;
//    int M, N, height;
//    int dx[4] = { -1, 0, 1, 0 }; //left,down, up, right
//    int dy[4] = { 0, 1, 0, -1 };
//
//    void printGrid() {
//        cout << "Current Grid:" << endl;
//        
//        for (int m = 0; m < M; m++) {
//            for (int n = 0; n < N; n++) {
//                cout << grid[m][n];
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//    bool outsideGrid(int x, int y);
//};
//
//bool BirdMountain::outsideGrid(int x, int y)
//{
//    return (x<0 || y<0 || x>=M || y>=N);
//}
//int BirdMountain::findHeight()
//{
//    bool finished = false;
//    int changeCount;
//    int height = 0;
//
//    while (!finished) {
//        ++height;
//        changeCount = 0;
//        for (int m = 0; m < M; m++) {
//            for (int n = 0; n < N; n++) {
//
//                int x(m), y(n), current(grid[m][n]), cellCount(0);
//                if (current < height) continue;
//
//                for (int i = 0; i < 4; i++) {
//
//                    x = m + dx[i];
//                    y = n + dy[i];
//                    if (grid[x][y] < height || outsideGrid(x, y)) {
//                        i = 4;
//                        continue;
//                    }                  
//                    else ++cellCount;
//                }
//
//                if (cellCount == 4) {
//                    ++grid[m][n];
//                    ++changeCount;
//                }
//            }
//            finished = !changeCount;
//        }
//    }
//    return height;
//}
//
//int peak_height(std::vector<std::string>& mountain) {
//	// Your code here!
//    BirdMountain bm(mountain);
//
//    int result = bm.findHeight();
//
//    return (result);
//}

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
class BirdMountain {
public:
    int findHeight();
    BirdMountain(vector<string> maze) {
        M = (int)maze.size(); N = (int)maze[0].length();
        grid.resize(M, vector<int>(N, 0));
        for (int m = 0; m < M; m++) for (int n = 0; n < N; n++) if (maze[m][n] == '^') grid[m][n] = 1;
    }
private:
    vector<vector<int>> grid;
    int M, N;
    int dx[4] = { -1, 0, 1, 0 }; //left,down, up, right
    int dy[4] = { 0, 1, 0, -1 };
};

int BirdMountain::findHeight() {
    bool finished = true; int changeCount, height(0);
    std::function<bool(int&, int&)> outsideGrid = [&](int a, int b) { return (a < 0 || b < 0 || a >= M || b >= N); };
    for (int m = 0; m < M; m++) if (find(grid[m].begin(), grid[m].end(), 1) != grid[m].end()) finished = false;

    while (!finished) {
        changeCount = 0; ++height;
        for (int m = 0; m < M; m++) {
            for (int n = 0; n < N; n++) {
                int x(m), y(n), current(grid[m][n]), cellCount(0);
                if (current < height) continue;
                for (int i = 0; i < 4; i++) {
                    x = m + dx[i];
                    y = n + dy[i];
                    if (outsideGrid(x, y) || grid[x][y] < height) continue;
                    else ++cellCount;
                }
                if (cellCount == 4) {
                    ++grid[m][n];
                    ++changeCount;
                }
            } finished = !changeCount;
        }
    } return height;
}
int peak_height(std::vector<std::string>& mountain) {
    BirdMountain bm(mountain);
    return (mountain.empty() ? 0 : bm.findHeight());
}


int main() {

    
            std::vector<std::string> mountain = {
                "^^^^^^        ",
                " ^^^^^^^^     ",
                "  ^^^^^^^     ",
                "  ^^^^^       ",
                "  ^^^^^^^^^^^ ",
                "  ^^^^^^      ",
                "  ^^^^        "
            };
            std::vector<std::string> mountain2 = {
                "              ",
                "              ",
                "              ",
                "              ",
                "              ",
                "              ",
                "              "
            };

            std::vector<std::string> mountain3 = {
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^",
                            "^^^^^^^^^^^^^^^^^^^^^"
            };

            int result;
            result = peak_height(mountain2); //Equals 11
            result = peak_height(mountain3); //Equals 3
            
            result = 4;
}