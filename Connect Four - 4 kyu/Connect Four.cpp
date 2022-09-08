#include <string>
#include <vector>
//#include <iostream>
using namespace std;

class ConnectFour {
public: 
    
    ConnectFour(vector<string> &mov) {
        moves = mov;
        m = 7;
        n = 6;
        piecesAdded = 0;
        maxPieces = m * n;
        board.resize(m, vector<int>(n));
        winner = "Draw";
    }  
    string applyMoves();
    
private:
    bool checkWinner(int column, int row);
    void addPiece(char a, string b, int& column, int& row);
    void splitString(string p,  string& a, string& b);
    int score(int column, int row, int colour, string direction);
   // void printBoard();

    vector<vector<int>> board;
    vector<string> moves;
    int m, n;
    int piecesAdded, maxPieces;
    string winner; //0 = draw; 1= red; 2= yellow
};

void ConnectFour::addPiece(char a, string b, int& column, int& row) {

    row = 0;
    column = (a == 'A') ? 0 : (a == 'B') ? 1 : (a == 'C') ? 2 : (a == 'D') ? 3 :
        (a == 'E') ? 4 : (a == 'F') ? 5 : (a == 'G') ? 6 : -1;
      
    for (; row < n; row++) {
        if (board[column][row] != 0) continue;
        else break;
    }
    board[column][row] = (b == "Red") ? 1 : 2;
    piecesAdded++;
}
int ConnectFour::score(int column, int row, int colour, string direction) {

    // ConnectFour::printBoard();

    if (direction == "up" && column < m-1) {
        if (board[column + 1][row] == colour) return 1 + score(column + 1, row, colour, "up");
    }
    else if (direction == "down" && column > 0) {
        if (board[column - 1][row] == colour) return 1 + score(column - 1, row, colour, "down");
    }
    else if (direction == "left" && row>0) {
        if (board[column][row - 1] == colour) return 1 + score(column, row - 1, colour, "left");
    }
    else if (direction == "right" && row < n-1) {
        if (board[column][row + 1] == colour) return 1 + score(column, row + 1, colour, "right");
    }
    else if (direction == "upRight" && column <m-1 && row<n-1) {
        if (board[column + 1][row + 1] == colour) return 1 + score(column + 1, row + 1, colour, "upRight");
    }
    else if (direction == "downRight" && column>0 && row < n-1) {
        if (board[column - 1][row + 1] == colour) return 1 + score(column - 1, row + 1, colour, "downRight");
    }
    else if (direction == "upLeft" && column < m-1 && row>0) {
        if (board[column + 1][row - 1] == colour) return 1 + score(column + 1, row - 1, colour, "upLeft");
    }
    else if (direction == "downLeft" && column>0 && row>0) {
        if (board[column - 1][row - 1] == colour) return 1 + score(column - 1, row - 1, colour, "downLeft");
    }
    return 0;
}

bool ConnectFour::checkWinner(int column, int row) {
    if (piecesAdded < 4) return false;   
    int colourInt = board[column][row];
    
    if (((score(column, row, colourInt, "up") + score(column, row, colourInt, "down")) >= 3) ||
        ((score(column, row, colourInt, "left") + score(column, row, colourInt, "right")) >= 3) ||
        ((score(column, row, colourInt, "upLeft") + score(column, row, colourInt, "downRight")) >= 3) ||
        ((score(column, row, colourInt, "upRight") + score(column, row, colourInt, "downLeft")) >= 3)) 
    {
        winner = (colourInt==1)? "Red":"Yellow";
        return true;
    }  
    if (piecesAdded >= maxPieces) return true; // draw (set in constructor - default)
    return false;
}
string ConnectFour::applyMoves() {

    for (string p : moves) {
        int column, row;
        string colString, colour;
        splitString(p, colString, colour);
        addPiece(colString[0], colour, column, row); // sets column/row by reference
       // ConnectFour::printBoard();
        if (checkWinner(column, row)) break;
    }
 //   cout << "Winner: " << winner << endl;
    return winner;
}
void ConnectFour::splitString(string turn, string& a, string& b) {
    size_t pos = turn.find('_');
    a = turn[0];
    b = turn.substr(pos+1, distance(turn.begin() + pos, turn.end()));
}
/*void ConnectFour::printBoard() {
    cout << "Current Board: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}*/

string who_is_winner(vector<string> pieces_position_list)
{
    ConnectFour game(pieces_position_list);
    return game.applyMoves();
}

int main() {
    string ans;
    ans = who_is_winner({
            "A_Red",
            "B_Yellow",
            "A_Red",
            "B_Yellow",
            "A_Red",
            "B_Yellow",
            "G_Red",
            "B_Yellow"
        }); // Equals("Yellow"));
    ans = who_is_winner({
            "C_Yellow",
            "E_Red",
            "G_Yellow",
            "B_Red",
            "D_Yellow",
            "B_Red",
            "B_Yellow",
            "G_Red",
            "C_Yellow",
            "C_Red",
            "D_Yellow",
            "F_Red",
            "E_Yellow",
            "A_Red",
            "A_Yellow",
            "G_Red",
            "A_Yellow",
            "F_Red",
            "F_Yellow",
            "D_Red",
            "B_Yellow",
            "E_Red",
            "D_Yellow",
            "A_Red",
            "G_Yellow",
            "D_Red",
            "D_Yellow",
            "C_Red"
        }); // Equals("Yellow"));
    ans = who_is_winner({
            "A_Yellow",
            "B_Red",
            "B_Yellow",
            "C_Red",
            "G_Yellow",
            "C_Red",
            "C_Yellow",
            "D_Red",
            "G_Yellow",
            "D_Red",
            "G_Yellow",
            "D_Red",
            "F_Yellow",
            "E_Red",
            "D_Yellow"
        }); // Equals("Red"));
    ans = who_is_winner({
            "F_Yellow",
            "G_Red",
            "D_Yellow",
            "C_Red",
            "A_Yellow",
            "A_Red",
            "E_Yellow",
            "D_Red",
            "D_Yellow",
            "F_Red",
            "B_Yellow",
            "E_Red",
            "C_Yellow",
            "D_Red",
            "F_Yellow",
            "D_Red",
            "D_Yellow",
            "F_Red",
            "G_Yellow",
            "C_Red",
            "F_Yellow",
            "E_Red",
            "A_Yellow",
            "A_Red",
            "C_Yellow",
            "B_Red",
            "E_Yellow",
            "C_Red",
            "E_Yellow",
            "G_Red",
            "A_Yellow",
            "A_Red",
            "G_Yellow",
            "C_Red",
            "B_Yellow",
            "E_Red",
            "F_Yellow",
            "G_Red",
            "G_Yellow",
            "B_Red",
            "B_Yellow",
            "B_Red"
        }); // Equals("Red"));
    ans = who_is_winner({
            "C_Yellow",
            "B_Red",
            "B_Yellow",
            "E_Red",
            "D_Yellow",
            "G_Red",
            "B_Yellow",
            "G_Red",
            "E_Yellow",
            "A_Red",
            "G_Yellow",
            "C_Red",
            "A_Yellow",
            "A_Red",
            "D_Yellow",
            "B_Red",
            "G_Yellow",
            "A_Red",
            "F_Yellow",
            "B_Red",
            "D_Yellow",
            "A_Red",
            "F_Yellow",
            "F_Red",
            "B_Yellow",
            "F_Red",
            "F_Yellow",
            "G_Red",
            "A_Yellow",
            "F_Red",
            "C_Yellow",
            "C_Red",
            "G_Yellow",
            "C_Red",
            "D_Yellow",
            "D_Red",
            "E_Yellow",
            "D_Red",
            "E_Yellow",
            "C_Red",
            "E_Yellow",
            "E_Red"
        }); // Equals("Yellow"));
    return 0;
}
