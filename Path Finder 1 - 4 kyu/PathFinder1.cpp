#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Maze {
    
public:
    Maze(string maze);
    bool isPathFrom(unsigned int m, unsigned int n);
    bool canGo(string direction, unsigned int m, unsigned int n);
    bool canVisit(string direction, unsigned int m, unsigned int n);
    int side;
    std::vector<vector<bool>> mazeLayout;
    std::vector<vector<bool>> visited;
};

bool Maze::canVisit(string direction, unsigned int m, unsigned int n) {

    if (direction == "up") {
        if (m == 0) {
            cout << "Can't go up! Out of bounds - m == " << m << " n == " << n << endl;
            return false;
        }
        if (visited[m-1][n] == 1) {
            cout << "Already visited:  " << m-1 << " n == " << n << endl;
            return false;
        }
        cout << "*CAN* go left to - m == " << m-1 << " n == " << n << " ... not visited" << endl;
        return true;
    }
    if (direction == "down") {
        if (m == side - 1) {
            cout << "Can't go down! Out of bounds - m == " << m << " n == " << n << endl;
            return false;
        }
        if (visited[m+1][n] == 1) {
            cout << "Already visited:  " << m + 1 << " n == " << n  << endl;
            return false;
        }
        cout << "*CAN* go down to - m == " << m + 1 << " n == " << n << " ... not visited" << endl;
        return true;
    }
    if (direction == "left") {
        if (n == 0) {
            cout << "Can't go left! Out of bounds - m == " << m << " n == " << n << endl;
            return false;
        }
        if (visited[m][n - 1] == 1) {
            cout << "Already visited:  " << m << " n == " << n - 1 << endl;
            return false;
        }
        cout << "*CAN* go left to - m == " << m << " n == " << n - 1 << " ... not visited" << endl;
        return true;
    }
    if (direction == "right") {
        if (n == side-1) {
            cout << "Can't go right! Out of bounds - m == " << m << " n == " << n << endl;
            return false;
        }
        if (visited[m][n+1] == 1) {
            cout << "Already visited:  " << m << " n == " << n + 1 << endl;
            return false;
        }
        cout << "*CAN* go right to - m == " << m << " n == " << n + 1 << " ... not visited" << endl;
        return true;
    }
}

bool Maze::canGo(string direction, unsigned int m, unsigned int n) {

    if (direction == "up") {
        if (m == 0) {
            cout << "Can't go up! Out of bounds - m == " << m << " n == " << n << endl;
            return false;
        }
        if (mazeLayout[m - 1][n] == 1) {
            cout << "*CAN* go up to - m == " << m - 1 << " n == " << n << endl;
            return true;
        }
        cout << "Can't go up to - m == " << m-1 << " n == " << n  << " ... blocked" << endl;
        return false;
    }
    if (direction == "down") {
        if (m == side - 1) {
            cout << "Can't go down! Out of bounds - m == " << m << " n == " << n << endl;
            return false;
        }
        if (mazeLayout[m + 1][n] == 1) {
            cout << "*CAN* go down to - m == " << m+1 << " n == " << n << endl;
            return true;
        }
        cout << "Can't go down to - m == " << m+ 1 << " n == " << n  << " ... blocked" << endl;
        return false;
    }
    if (direction == "left") {
        if (n == 0) {
            cout << "Can't go left! Out of bounds - m == " << m << " n == " << n << endl;
            return false;
        }
        if (mazeLayout[m][n-1] == 1) {
            cout << "*CAN* go left to - m == " << m  << " n == " << n-1 << endl;
            return true;
        }
        cout << "Can't go left to - m == " << m << " n == " << n -1 << " ... blocked" << endl;
        return false;
    }
    if (direction == "right") {
        if (n == side -1) {
            cout << "Can't go right! Out of bounds - m == " << m << " n == "<<n<< endl;
            return false;
        }
        if (mazeLayout[m][n+1] == 1) {
            cout << "*CAN* go right to - m == " << m << " n == " << n+1 << endl;
            return true;
        }
        
        cout << "Can't go right to - m == " << m << " n == " << n + 1 << " ... blocked"<< endl;
        return false;
    }
}

bool Maze::isPathFrom(unsigned int m, unsigned int n) {
    cout << "Entering region: m = " << m << " n = " << n << endl;
    
    if ((m == side - 1 && n == side - 1)) {
        cout << "******WE MADE IT!!!*********";
        return true;
    }
    bool pathFound = false;
    visited[m][n] = true;

    if (canGo("up", m, n) && canVisit("up", m, n)) {
        cout << "GONNA MOVE ON UP" << endl;
        pathFound = isPathFrom(m - 1, n);
    }
    
    if(!pathFound){
        if (canGo("down", m, n) && canVisit("down", m, n)) {
            cout << "GONNA MOVE ON DOWN" << endl;
            pathFound = isPathFrom(m + 1, n);
        }
    }
    if (!pathFound) {
        if (canGo("left", m, n) && canVisit("left", m, n)) {
            cout << "GONNA MOVE ON LEFT" << endl;
            pathFound = isPathFrom(m, n-1);
        }
    }
    if (!pathFound) {
        if (canGo("right", m, n) && canVisit("right", m, n)) {
            cout << "GONNA MOVE ON RIGHT" << endl;
            pathFound = isPathFrom(m, n + 1);
        }
    }
    return pathFound;
}

Maze::Maze(string maze) {

    side = floor(sqrt(maze.length()));

    mazeLayout.resize(side, vector<bool>(side));
    std::cout << "maze length " << maze.length() << endl;

    unsigned int j = 0;
    unsigned int newLines = 0;
    for (unsigned int i = 0; i < maze.length(); i++) {

        char character = maze[i];

        if (character == '\n') { 
            j++; 
           // cout << "new line" << endl; 
            newLines++;
            continue;
        }
        else {
            mazeLayout[j][(i - newLines) % side] = (character == 46) ? true:false;
          //  cout << mazeLayout[j][(i-newLines)%side] << endl;
        }

    }

    visited.resize(side, vector<bool>(side));
}

bool path_finder(string maze) {
	// TODO: Determine whether one *CAN* reach the exit at (n - 1, n - 1)
	// starting from (0, 0) in a n × n maze (represented as a string)
	// and return a boolean value accordingly
	
    Maze newMaze(maze);
    bool pathFound = newMaze.isPathFrom(0, 0);
    if(pathFound)cout << "Holy Moly!  A path was found!  returning True!" << endl;
    if(!pathFound)cout << "Awwww!  A path was not found!  returning False!" << endl;
    return pathFound;
}


int main() {

      
            /*
              Maze:
                .W.
                .W.
                ...
            */
    path_finder(".W.\n.W.\n...");// , Equals(true));
            /*
              Maze:
                .W.
                .W.
                W..
            */
    path_finder(".W.\n.W.\nW..");// , Equals(false));
            /*
              Maze:
                ......
                ......
                ......
                ......
                ......
                ......
            */
    path_finder("......\n......\n......\n......\n......\n......");// , Equals(true));
            /*
              Maze:
                ......
                ......
                ......
                ......
                .....W
                ....W.
            */
    path_finder("......\n......\n......\n......\n.....W\n....W.");// , Equals(false));
  
}