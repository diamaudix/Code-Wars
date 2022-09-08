#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct Point { int M, N; };

class SnailRecurser {
public:
    SnailRecurser(const vector<vector<int>> snail_map) {
        
        snail_matrix = snail_map;
        m = (int)snail_matrix.size();
        n = (int)snail_matrix[0].size();
        count = 0;
        maxCount = m * n;
        visited.resize(m);
        for (int i = 0; i < m; i++) visited[i].resize(n, 0);
    }

    vector<int> getAnswer();
    void recurseMatrix(Point element);

private:
    vector<vector<int>> snail_matrix;
    vector<vector<bool>> visited;
    vector<int> answer;
    
    int m, n, count, maxCount;
      
    bool canGoTo(Point element);
    bool canVisit(Point element);
};
vector<int> SnailRecurser::getAnswer() {
    return answer;
}

bool SnailRecurser::canGoTo(Point element) {
    return (element.M < 0 || element.M >= m || element.N < 0 || element.N >= n) ? false : true;
}
bool SnailRecurser::canVisit(Point element) {
    return (visited[element.M][element.N] ? false : true);
}

void SnailRecurser::recurseMatrix(Point el) {

    count++;
    if (count > maxCount) return;
    visited[el.M][el.N] = true;
    answer.push_back(snail_matrix[el.M][el.N]);

    Point right = { el.M, el.N + 1 };
    Point left = { el.M, el.N - 1 };
    Point up = { el.M - 1, el.N };
    Point down = { el.M + 1, el.N };

    if (canGoTo(right) && canVisit(right)) {
        if (!canGoTo(up) || !canVisit(up)) recurseMatrix(right);
        else recurseMatrix(up);
    }
    else if (canGoTo(down) && canVisit(down)) recurseMatrix(down);
    else if (canGoTo(left) && canVisit(left)) recurseMatrix(left);
    else if (canGoTo(up) && canVisit(up)) recurseMatrix(up);

}

vector<int> snail(const vector<vector<int>>& snail_map) {
	
    SnailRecurser snail(snail_map);
    snail.recurseMatrix({ 0,0 });
    return snail.getAnswer();
}


int main(){
        vector<vector<int>> v;
        vector<int> answer;
        
        v = { {1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} };
        answer = snail(v);// Equals(expected));
        


        v = { {1,2,3}, {8,9,4}, {7,6,5} };
       // expected = { 1,2,3,4,5,6,7,8,9 };
       answer = snail(v);// Equals(expected));
        v = { {1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} };
     //   expected = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };

        v = { {} };
      //  expected = {};
       answer = snail(v);// Equals(expected));

        v = { {1} };
       // expected = { 1 };
       answer = snail(v);// Equals(expected));

        v = { {1,2}, {4,3} };
     //   expected = { 1,2,3,4 };
       answer = snail(v);// Equals(expected));answer = snail(v);// Equals(expected));
       return 0;
}
