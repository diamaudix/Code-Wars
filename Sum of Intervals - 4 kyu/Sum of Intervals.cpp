#include <vector>
#include <math.h>
using namespace std;

class Merger {
public:
    Merger(vector<pair<int, int>> intervalGroup) { //constructor
        intervals = intervalGroup;
        solution = { };
    }
    int deliverSolution();
private:
    vector<pair<int, int>> intervals; //data
    vector<pair<int, int>> solution;
    
    bool needsMerge(int a, int b); //functions
    bool isFinished();
    void mergePairs(int a, int b);
    void mergePass();
    void deletePair(int a);
    int sumIntervals();
};

int Merger::deliverSolution() { //main control flow
    
    if (intervals.size() == 1) {
        solution.push_back(intervals[0]);
        return sumIntervals();
    }
    while (!isFinished()) mergePass();
    for (auto p : intervals) solution.push_back(p); // only one remaining, or a set of mutually exclusive pairs 
    return sumIntervals(); //we are finished!
}

void Merger::mergePass() { //sweep intervals for updates

    bool firstNotFound = true;
    while (firstNotFound) {
        for (int l = 1; l < (int)intervals.size(); l++) {
            if (needsMerge(0, l)) firstNotFound = false;
        }
        if (firstNotFound) {
            solution.push_back(intervals[0]);
            deletePair(0);
        }
    }
    for (int i = 0; i < (int)intervals.size() - 1; i++) {
        for (int j = i + 1; j < (int)intervals.size(); j++) {
            if (needsMerge(i, j)) {
                mergePairs(i, j);
            }
        }
    }
}

bool Merger::isFinished() { // check if finished;

    if (intervals.size()<2) return true;
    for (int i = 0; i < (int)intervals.size() - 1; i++)
        for (int j = i + 1; j < (int)intervals.size(); j++)
            if (needsMerge(i, j)) return false;
    return true;
}

bool Merger::needsMerge(int a, int b) { // check if integer pairs need to be merged
    pair<int, int> first = intervals[a];
    pair<int, int> second = intervals[b];
    return (((first.second>=second.first)&&(first.second<= second.second))
        ||((second.second>= first.first)&&(second.second<= first.second)))?true:false;
}

void Merger::deletePair(int a) {
    intervals[a] = intervals.back();
    intervals.pop_back();
}
void Merger::mergePairs(int a, int b) { //merges pair of intervals, deletes old intervals; adds newly created

    pair<int, int> first = intervals[a];
    pair<int, int> second = intervals[b];
    int smaller = min(first.first, second.first);
    int larger = max(first.second, second.second);

    pair<int, int> merged = make_pair(smaller, larger);

    if (a > b) {
        deletePair(a);
        deletePair(b);
    }
    else {
        deletePair(b);
        deletePair(a);
    }
    intervals.push_back(merged);
}

int Merger::sumIntervals() { // returns sum of all intervals

    int sum=0;
    for (auto p : solution) sum += (abs(p.second - p.first));
    return sum;
}

int sum_intervals(vector<pair<int, int>> intervals) {
    Merger merge(intervals);
    int solution = merge.deliverSolution();
    return solution;
}

int main(){
   
    int ans;
  
    
    
    
    ans = sum_intervals({
        {101,102},
        {107,119},
        {-234,-213},
        {1,5},
        {10, 20},
        {1, 6},
        {16, 19},
        {5, 11},
        {-40, -27},
        {23, 31},
        { -26, -14},
        {1, 6},
        {-16, 1},
        {-5, 11},
        {88,105},
        {67, 81},
        {58, 69},
        {61, 62},
        {0, 11}
        }); // => 19
       
    ans = sum_intervals({
    {1,2},
    {6, 10},
    {11, 15}
        }); // => 9

    ans = sum_intervals({
        {1,4},
        {7, 10},
        {3, 5}
        }); // => 7
   
    return 0;
}

