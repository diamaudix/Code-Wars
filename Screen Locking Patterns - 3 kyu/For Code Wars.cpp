#include <iostream>
#include <set>
using namespace std;

class PatternCounter {

public:

    PatternCounter(const char firstChar, const unsigned short len) :firstButton(firstChar), length(len) {}

    int adjacencyMatrix[9][9] = { {0,1,0,1,1,1,0,1,0},  // when starting - no buttons pushed
                                  {1,0,1,1,1,1,1,0,1},
                                  {0,1,0,1,1,1,0,1,0},
                                  {1,1,1,0,1,0,1,1,1},
                                  {1,1,1,1,0,1,1,1,1},
                                  {1,1,1,0,1,0,1,1,1},
                                  {0,1,0,1,1,1,0,1,0},
                                  {1,0,1,1,1,1,1,0,1},
                                  {0,1,0,1,1,1,0,1,0} };

    int visitedMatrix[9] = { 0 };
    const char firstButton;
    const unsigned short length;
    int count = 0;

    void pushUnpushButton();
    void pushUnpushButton(int button, string direction);
    unsigned int getPatternCount();
    void recursePattern(int button, int depth);
};

void PatternCounter::pushUnpushButton(int button, string direction) {

    int status = (direction == "Down")? 1: 0;
    visitedMatrix[button] = status;
    switch (button) { //0, 2, 6, and 8 have no effect on eligibility

    case(1)://enables/disables 2->0  0->2
        adjacencyMatrix[0][2] = status;
        adjacencyMatrix[2][0] = status;
        break;
    case(3): //enables/disables 0-6 6-0
        adjacencyMatrix[0][6] = status;
        adjacencyMatrix[6][0] = status;
        break;
    case(4): //enables/disables 0-8, 8-0, 1-7,7-1,2-6,6-2, 3-5,5-3,
        adjacencyMatrix[0][8] = status;
        adjacencyMatrix[8][0] = status;
        adjacencyMatrix[1][7] = status;
        adjacencyMatrix[7][1] = status;
        adjacencyMatrix[2][6] = status;
        adjacencyMatrix[6][2] = status;
        adjacencyMatrix[3][5] = status;
        adjacencyMatrix[5][3] = status;
        break;
    case(5): //enables/disables 2-8 8-2
        adjacencyMatrix[2][8] = status;
        adjacencyMatrix[8][2] = status;
        break;

    case(7): //enables/disables 8-6 6-8
        adjacencyMatrix[6][8] = status;
        adjacencyMatrix[8][6] = status;

    }
}

void PatternCounter::recursePattern(int button, int depth) {

    pushUnpushButton(button, "Down");
    if (depth == length) {  //victory condition
        count++;
        pushUnpushButton(button, "Up");
        return;
    }
    for (int i = 0; i < 9; i++) {
        if (i == button) continue;
        if (adjacencyMatrix[button][i] && !visitedMatrix[i]) recursePattern(i, depth + 1);
    }
    pushUnpushButton(button, "Up");
}

unsigned int PatternCounter::getPatternCount() {
    recursePattern(firstButton - 65, 1);
    return count;
}

unsigned int countPatternsFrom(char firstDot, unsigned short length) {

    if (length == 1) return 1;
    if (length == 0 || length > 9) return 0;
    PatternCounter counter(firstDot, length);
    return counter.getPatternCount();
}



int main() {

    int count;

    // count = countPatternsFrom('A', 0);// Equals(0));
    // count = countPatternsFrom('A', 10);// Equals(0));
    // count = countPatternsFrom('B', 1);// Equals(1));
     //count = countPatternsFrom('C', 2);// Equals(5));
    count = countPatternsFrom('D', 3);// Equals(37));
    count = countPatternsFrom('E', 4);// Equals(256));
    count = countPatternsFrom('E', 8);// Equals(23280));
    return 0;
}