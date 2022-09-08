#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <math.h>
#include <set>
double constexpr INF = -9999;
using namespace std;

struct MoshIsland {
    vector<pair<int, int>> pitPoints = {};
};

class DanceFloor {
public:
    std::pair<size_t, size_t> findSpot();

    DanceFloor(const std::vector<std::string>& dance_floor) :floor(dance_floor) {
        M = (int)floor.size();
        N = (int)floor[0].length();
        elligible.resize(M, vector<double>(N, 0.0));
        for (int m = 0; m < M; m++) std::fill(elligible[m].begin(), elligible[m].end(), M - m);
    }

private:
    std::vector<std::string> floor;
    vector<vector<int>> visited;
    vector<vector<double>> elligible;
    int M, N;
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    
    inline bool isInsideGrid(int i, int j) { return (i >= 0 && i < M&& j >= 0 && j < N); }

    void printGrid();
    void printFloor();
    void printVisited();
    
    void applyEmpty();
    void factorHeight();
    void factorBeer();
    void considerMoshPits();
    
    void recurseMosh(int m, int n, MoshIsland& mosh);
    bool isMoshPit(MoshIsland& mosh);
    pair<int, int> findMaxScore();

};

pair<int, int> DanceFloor::findMaxScore() {
    pair<int, int> solution = {};
    double best = INF;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (elligible[m][n] > best) {
                best = elligible[m][n];
                solution = std::make_pair(m, n);
            }
        }
    }
    if (best == INF) return {};
    else return solution;
}
void DanceFloor::applyEmpty() {  
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (floor[m][n] != ' ') elligible[m][n] = INF;
        }
    }
}
void DanceFloor::factorHeight() {
    int alphaNum(0);
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (elligible[m][n] > 0) {
                int power = 0;
                if (isInsideGrid(m - 1, n) && floor[m - 1][n] != ' ') {
                    if (floor[m - 1][n] >= 65 && floor[m - 1][n] <= 90) alphaNum = floor[m - 1][n] - 64;
                    else alphaNum = floor[m - 1][n] - 96;
                    power = max(power, alphaNum);
                }
                elligible[m][n] *= pow(0.99, power);
            }
        }
    }
}
void DanceFloor::factorBeer() {   
    int k, l;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (elligible[m][n] > 0) {
                int beerCount = 0;
                for (int i = 0; i < 4; i++) {
                    k = m + dx[i];
                    l = n + dy[i];
                    if (isInsideGrid(k, l) && floor[k][l] >= 65 && floor[k][l] <= 90) beerCount++;
                }
                if(beerCount!=0) elligible[m][n] *= pow(0.8, beerCount);
            }
        }
    }   
}
bool DanceFloor::isMoshPit(MoshIsland& mosh) {

    if (mosh.pitPoints.size() < 4) return false;
    int spanCount = 0;
    vector<int> xCoordinates = {};

    for(int i=0; i<(int)mosh.pitPoints.size(); i++) xCoordinates.push_back(mosh.pitPoints[i].first);
    
    vector<int>::iterator it = xCoordinates.begin();
    vector<int>::iterator it2 = xCoordinates.begin();

    while (it2 != xCoordinates.end()) {
        int current = *it;
        it2++;
        while (it2!= xCoordinates.end() && *it2 == current) it2++;
        if (std::distance(it, it2) >= 2) spanCount++;
        auto index = std::distance(it, it2);
        advance(it, index);
    }    
    if (spanCount >= 2) return true;
    else return false;
}

void DanceFloor::considerMoshPits() {

    visited.resize(M, vector<int>(N, 0));
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (floor[m][n] != ' ') visited[m][n] = 9; //occupied - can't mosh
        }
    }
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (visited[m][n] == 0) {
                MoshIsland currentMosh;
                recurseMosh(m, n, currentMosh);
                if (isMoshPit(currentMosh)) {
                    for (auto& m : currentMosh.pitPoints) {
                        elligible[m.first][m.second] -= 2*M;  //enough to place lower than any other non-mosh spot
                    }
                }
            }
        }
    }
}
void DanceFloor::recurseMosh(int m, int n, MoshIsland &mosh) {   
    mosh.pitPoints.push_back(std::make_pair(m, n));
    visited[m][n] = 1;
    int k, l;
    for (int i = 0; i < 4; i++) {
        k = m + dx[i];
        l = n + dy[i];
        if (isInsideGrid(k, l) && visited[k][l] == 0)  recurseMosh(k, l, mosh);
    } 
}
std::pair<size_t, size_t> DanceFloor::findSpot()
{   
    applyEmpty();
    factorHeight();
    factorBeer();
    considerMoshPits();
    return findMaxScore();
}
void DanceFloor::printVisited() {
    cout << endl << "Currently Visited" << endl;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
           cout << visited[m][n] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void DanceFloor::printFloor()
{ 
    cout << endl<<"Original Dance Floor:"<<endl;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (floor[m][n] == ' ') cout << "* ";
            else cout << floor[m][n] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void DanceFloor::printGrid() {
    cout << "Current Availability Grid" << endl;
    for (int m = 0; m < M; m++) {
        for (int n = 0; n < N; n++) {
            if (elligible[m][n] <0 )cout << floor[m][n] << "\t";
            else cout << to_string(elligible[m][n]).substr(0, 5) << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

std::pair<size_t, size_t> best_place(const std::vector<std::string>& dance_floor)
{
    DanceFloor danceFloor(dance_floor);   
    return danceFloor.findSpot();
}
int main() {
    std::pair<size_t, size_t> actual;
    std::vector<std::string> dance_floor;
    dance_floor = {
      "gbvKq  JfiM I",
      "q jecl   fvoX",
      "L  Foa   ygKT"
    };
    // expected = { {1,1} };
    actual = best_place(dance_floor);
    dance_floor = {
        " ",
        " "
    };
    //expected = { {0,0} };
    actual = best_place(dance_floor);
    dance_floor = {
        "test",
        "    "
    };
    //expected = { {1,1} };
    actual = best_place(dance_floor);

    dance_floor = {
       " Aa "
    };
    //expected = { {0,3} };
    actual = best_place(dance_floor);

    dance_floor = {
       "  ",
       "A "
    };
    //expected = { {0,1} };
    actual = best_place(dance_floor);

    dance_floor = {
       "  ",
       "  ",
       "ZZ",
       "ZZ",
       "Z "
    };
    //expected = { {4,1} };
    actual = best_place(dance_floor);

    dance_floor = {
       "  a",
       "  a",
       "aa ",
       " aa"
    };
    //expected = { {2,2} };
    actual = best_place(dance_floor);

    dance_floor = {
       "  A  AA",
       "  A  A "
    };
    //expected = { {1,6} };
    actual = best_place(dance_floor);

    dance_floor = {
       "zzvz",
       "z  z",
       "z  z",
       "zzzz"
    };
    //expected = { {1,2} };
    actual = best_place(dance_floor);
    return 0;
}