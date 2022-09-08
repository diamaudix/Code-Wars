//#include <iostream>
//using namespace std;
//#include <set>
//
//class PatternCounter {
//
//public:
//
//    PatternCounter(const char firstChar, const unsigned short len) :firstButton(firstChar), length(len) {
//
//        count = 0;
//        cout << firstChar<<" int: " <<firstChar-65 << endl;
//
//    }
//
//    int adjacencyMatrix[9][9] = { {0,1,0,1,1,1,0,1,0},  // when starting - no buttons pushed
//                                  {1,0,1,1,1,1,1,0,1},
//                                  {0,1,0,1,1,1,0,1,0},
//                                  {1,1,1,0,1,0,1,1,1},
//                                  {1,1,1,1,0,1,1,1,1},
//                                  {1,1,1,0,1,0,1,1,1},
//                                  {0,1,0,1,1,1,0,1,0},
//                                  {1,0,1,1,1,1,1,0,1},
//                                  {0,1,0,1,1,1,0,1,0} };
//
//    int visitedMatrix[9] = {0};
//    const char firstButton;
//    const unsigned short length;
//    int count;
//
//    void pushUnpushButton();
//    //void unpushUnpushButton();
//    void printAdjacencyMatrix(int button);
//    void printFullAdjacencyMatrix();
//    void printVisitedMatrix();
//    void pushUnpushButton(int button, string direction);
//    unsigned int getPatternCount();
//    void recursePattern(int button, int depth);
//};
//
//void PatternCounter::pushUnpushButton(int button, string direction ) {
//    
//    cout << endl<<"Pushing " << button << " " << direction << "!" << endl;
//
//    int status;
//
//    if (direction == "Down") status = 1;
//    else status = 0;
//
//    visitedMatrix[button] = status;
//    
//    switch (button) { //0, 2, 6, and 8 have no effect on eligibility
//
//    case(1)://2->0  0->2
//        adjacencyMatrix[0][2] = status;
//        adjacencyMatrix[2][0] = status;
//        break;
//    case(3): //0-6 6-0
//        adjacencyMatrix[0][6] = status;
//        adjacencyMatrix[6][0] = status;
//        break;
//    case(4): //0-8, 8-0, 1-7,7-1,2-6,6-2, 3-5,5-3,
//        adjacencyMatrix[0][8] = status;
//        adjacencyMatrix[8][0] = status;
//        adjacencyMatrix[1][7] = status;
//        adjacencyMatrix[7][1] = status;
//        adjacencyMatrix[2][6] = status;
//        adjacencyMatrix[6][2] = status;
//        adjacencyMatrix[3][5] = status;
//        adjacencyMatrix[5][3] = status;
//        break;
//    case(5): //2-8 8-2
//        adjacencyMatrix[2][8] = status;
//        adjacencyMatrix[8][2] = status;
//        break;
//  
//    case(7): // 8-6 6-8
//        adjacencyMatrix[6][8] = status;
//        adjacencyMatrix[8][6] = status;
//    
//    }
//}
//
//void PatternCounter::recursePattern(int button, int depth) {
//    
//    
//    //printVisitedMatrix();
//    cout <<endl<< "Visiting button : " << button << ", at depth: " << depth;
//
//    pushUnpushButton(button, "Down");
//    printVisitedMatrix();
//    
//
//    //printMatrices(button);
//    if (depth == length) {
//        count++;
//        cout << endl << "Added new path to pattern (now "<<count<<") ... returning." << endl;
//        
//        
//        pushUnpushButton(button, "Up");
//        //printFullAdjacencyMatrix();
//        
//        return;
//
//    }
//
//    for (int i = 0; i < 9; i++) {
//        if (i == button) continue;
//       // printAdjacencyMatrix(button);
//        if (adjacencyMatrix[button][i] && !visitedMatrix[i]){ // button is available
//            
//            recursePattern(i, depth + 1);
//           
//            
//           // printMatrices();
//           // printMatrices(button);
//        }
//        
//
//    }
//    pushUnpushButton(button, "Up");
//
//}
//
//unsigned int PatternCounter::getPatternCount() {
//    
//    
//    printFullAdjacencyMatrix();
//    recursePattern(firstButton - 65, 1);
//    return count;
//}
//
//void PatternCounter::printAdjacencyMatrix(int button) {
//    
//    
//    cout <<endl<< "Adjacency Matrix for button " << button << endl;
//    for (int i = 0; i < 9; i++) {
//        if (i % 3 == 0) cout << endl;
//        cout << adjacencyMatrix[button][i] << " ";
//
//
//    }
//}
//
//void PatternCounter::printFullAdjacencyMatrix() {
//      cout <<endl<< "Adjacency Matrix : " << endl << endl;
//
//    for (int i = 0; i <9; i++) {
//        for (int j = 0; j <9; j++) {
//            cout << adjacencyMatrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//  
//}
//
//void PatternCounter::printVisitedMatrix() {
//
//    cout << endl<< "Visited Matrix : "  << endl;
//
//    for (int i = 0; i < 9; i++) {
//        if (i % 3 == 0) cout << endl;
//        cout << visitedMatrix[i] << " ";
//
//
//    }
//}
//unsigned int countPatternsFrom(char firstDot, unsigned short length) {
//
//    if (length == 1) return 1;
//    if (length == 0 || length > 9) return 0;
//
//    PatternCounter counter(firstDot, length);
//    unsigned int answer = counter.getPatternCount();
//    cout <<endl<< "ANSWER:: " << answer << endl << endl;
//
//    return answer;
//
//}
//
//
//
//int main() {
//        
//    int count;
//    
//       // count = countPatternsFrom('A', 0);// Equals(0));
//       // count = countPatternsFrom('A', 10);// Equals(0));
//       // count = countPatternsFrom('B', 1);// Equals(1));
//        //count = countPatternsFrom('C', 2);// Equals(5));
//        count = countPatternsFrom('D', 3);// Equals(37));
//        count = countPatternsFrom('E', 4);// Equals(256));
//       count = countPatternsFrom('E', 8);// Equals(23280));
//    return 0;
//}