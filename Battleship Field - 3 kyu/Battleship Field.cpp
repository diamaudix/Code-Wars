#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;
void printField(std::vector< std::vector<int> > field) {
    cout << "Current Field:" << endl;
    for (unsigned int i = 0; i < field.size(); i++) {

        for (unsigned int j = 0; j < field[i].size(); j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}

int scanForShips(std::vector< std::vector<int> > &field, int shipSize) {

    int shipsFound = 0;

    for (int m = 0; m<field.size(); m++) {

        for (int n = 0; n < field[m].size()-shipSize; n++)
        {
            bool shipFound = true;
            for (int i = 0; i < shipSize; i++)
            {
                if ((field[m][n + i]) != 1)
                {
                    shipFound = false;
                    break;
                }               
            }

            if (shipFound)
            {
                shipsFound++;
                for (int j = 0; j < shipSize; j++)
                {
                    field[m][n + j] = 9;
                }
            }
        }
    }
    for (int n = 0; n < field[0].size(); n++)
    {
        for (int m = 0; m < field.size()-shipSize; m++)
        {
            bool shipFound = true;
            for (int i = 0; i < shipSize; i++)
            {
                if (field[m + i][n] != 1)
                {
                    shipFound = false;
                    break;
                }
            }

            if (shipFound)
            {
                shipsFound++;
                for (int j = 0; j < shipSize; j++)
                {
                    field[m+j][n] = 9;
                }
            }
        }  
    }
    return shipsFound;
}

bool testForDiagonals(std::vector< std::vector<int> > field) {

    
    for (int m = 0; m < field.size(); m++) {
        bool atLeft = false;  bool atRight = false; bool atTop = false; bool atBottom = false;

        if (m == 0) atTop = true; 
        if (m == field.size() - 1) atBottom = true;

        for (unsigned int n = 0; n < field.size(); n++) {

            if (n == 0) atLeft = true;
            if (n == field.size() - 1) atRight = true;

            if (field[m][n] == 0)continue;

            if (atTop) {
                if (atLeft) {
                    if (field[m + 1][n + 1] == 1) return true;
                }
                else if (atRight) {
                    if (field[m + 1][n - 1] == 1) return true;
                }
                else {
                    if ((field[m + 1][n + 1] == 1) || (field[m + 1][n - 1] == 1)) return true;
                }
            
            }
            else if (atBottom) {
                if (atLeft) {
                    if (field[m - 1][n + 1] == 1) return true;
                }
                else if (atRight) {
                    if (field[m - 1][n - 1] == 1) return true;
                }
                else {
                    if ((field[m - 1][n + 1] == 1) || (field[m - 1][n - 1] == 1)) return true;
                }

            }

            else if (atLeft) {
                if (atTop) {
                    if (field[m + 1][n + 1] == 1) return true;
                }
                else if (atBottom) {
                    if (field[m - 1][n + 1] == 1) return true;
                }
                else {
                    if ((field[m + 1][n + 1] == 1) || (field[m - 1][n + 1] == 1)) return true;
                }

            }
            else if (atRight) {
                if (atTop) {
                    if (field[m + 1][n - 1] == 1) return true;
                }
                else if (atBottom) {
                    if (field[m - 1][n - 1] == 1) return true;
                }
                else {
                    if ((field[m + 1][n - 1] == 1) || (field[m - 1][n - 1] == 1)) return true;
                }

            }
            else { //somewhere in the middle

                if ((field[m + 1][n + 1] == 1) || (field[m + 1][n - 1] == 1)
                    || (field[m - 1][n + 1] == 1) || (field[m - 1][n - 1] == 1)) return true;
                
            }

        }
    }
    return false;

}
bool testForAdjacent(std::vector< std::vector<int> > field) {

    for (int m = 0; m < field.size(); m++) {
        for (unsigned int n = 0; n < field[m].size(); n++) {

            if (field[m][n] != 9) continue;

            bool atLeft = (n == 0);
            bool atTop = (m == 0);
            bool atRight = (n == field[m].size() - 1);
            bool atBottom = (m == field.size() - 1);

            if (atTop) {
                if (atLeft) {
                    if ((field[m + 1][n] == 1) || (field[m][n + 1] == 1)) return false;
                }
                else if (atRight){
                    if ((field[m + 1][n] == 1) || (field[m][n-1] == 1)) return false;
                }
                else {
                    if ((field[m + 1][n] == 1) || (field[m][n + 1] == 1) || (field[m][n-1]==1)) return false;
                }

            }
            else if (atBottom) {
                if (atLeft) {
                    if ((field[m-1][n] == 1) || (field[m][n + 1] == 1)) return false;
                }
                else if (atRight) {
                    if ((field[m - 1][n] == 1) || (field[m][n - 1] == 1)) return false;
                }
                else {
                    if ((field[m - 1][n] == 1) || (field[m][n + 1] == 1) || (field[m][n - 1]==1)) return false;
                }

            }
            else if (atLeft) {
                if ((field[m - 1][n] == 1) || (field[m+1][n] == 1) || (field[m][n + 1] == 1)) return false;

            }
            else if (atRight) {
                if ((field[m - 1][n] == 1) || (field[m + 1][n] == 1) || (field[m][n - 1] == 1)) return false;
            }
            else {
                if ((field[m - 1][n] == 1) || (field[m + 1][n] == 1) || (field[m][n - 1] == 1) || (field[m][n+1]==1)) return false;
            }
        }
    }
    return true;
}

bool validate_battlefield(std::vector< std::vector<int> > field) {
	
    
    std::vector< std::vector<int> > modifiedField = field;

    int numberOfOversizeShipsFound = scanForShips(modifiedField, 5);
    if (numberOfOversizeShipsFound>0) return false;
    modifiedField = field;

    if (bool test = testForDiagonals(field) == true) { return false; }

    int submarineSize = 1;
    int destroyerSize = 2;
    int cruiserSize = 3;
    int battleshipSize = 4;

    int submarines = 4;
    int destroyers = 3;
    int cruisers = 2;
    int battleships = 1;
    
    printField(modifiedField);

    int numberOfBattleshipsFound = scanForShips(modifiedField, battleshipSize);
    printField(modifiedField);
    bool keepGoing = testForAdjacent(modifiedField);
    if (!keepGoing) return false;
    
    int numberOfCruisersFound = scanForShips(modifiedField, cruiserSize);
    printField(modifiedField);
    keepGoing = testForAdjacent(modifiedField);
    if (!keepGoing) return false;
    
    int numberOfDestroyersFound = scanForShips(modifiedField, destroyerSize);
    printField(modifiedField);
    keepGoing = testForAdjacent(modifiedField);
    if (!keepGoing) return false;
    
    int numberOfSubmarinesFound = scanForShips(modifiedField, submarineSize);
    printField(modifiedField);
    keepGoing = testForAdjacent(modifiedField);
    if (!keepGoing) return false;

    if (numberOfSubmarinesFound == 4 && numberOfDestroyersFound == 3
        && numberOfCruisersFound == 2 && numberOfBattleshipsFound == 1) {
        return true;
    }
    return false;
}

int main(){
        bool test = validate_battlefield(std::vector< std::vector<int> > {
        std::vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        std::vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        std::vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
});// , Equals(true));

        bool test2 = validate_battlefield(std::vector< std::vector<int> > {
        std::vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        std::vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        std::vector<int> {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
        std::vector<int> {0, 0, 1, 1, 0, 1, 0, 0, 1, 0},
        std::vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        });
return 0;
}