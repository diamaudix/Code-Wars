#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>
using namespace std;
typedef std::unordered_map<std::string, double> stringdblmap;
class Tour
{
public:
    static int tour(std::vector<std::string>& arrFriends, std::vector<std::vector<std::string>>& ftwns, stringdblmap& h);
};

double getDistance(double a, double b) {

    double side = min(a, b);
    double hypotenuse = max(a, b);
    double distance = sqrt(hypotenuse * hypotenuse - side * side);


    return distance;
}

int Tour::tour(std::vector<std::string>& arrFriends, std::vector<std::vector<std::string>>& ftwns, stringdblmap& h) {
    
    std::vector<std::string> toVisit;

    for (unsigned int i = 0; i < arrFriends.size();i++) {

        for (unsigned int j = 0; j < ftwns.size();j++) {

            if ((arrFriends[i]) == ftwns[j][0]) {
                toVisit.push_back(ftwns[j][1]);
            }

        }
    }

    double distance=0;
    double a, b;


    for (unsigned int k = 0; k < toVisit.size();k++) {

        if (k == 0) distance += h.at(toVisit[k]);
                
                else {
                    a = h.at(toVisit[k-1]); b = h.at(toVisit[k]);
                    distance += getDistance(a, b);
                    if (k == toVisit.size() - 1) distance += h.at(toVisit[k]);
                }
 
          
           
        }
        
  

    return (int)distance;
}



int main(){

        std::vector<std::string> friends1 = { "A1", "A2", "A3", "A4", "A5" };
        std::vector<std::vector<std::string>> fTowns1 = { {"A1", "X1"}, {"A2", "X2"}, {"A3", "X3"}, {"A4", "X4"} };
        stringdblmap distTable1 = { {"X1", 100.0}, {"X2", 200.0}, {"X3", 250.0}, {"X4", 300.0} };
        Tour::tour(friends1, fTowns1, distTable1);// , 889);

        friends1 = { "A1", "A2", "A3", "A4", "A5" };
        fTowns1 = { {"A1", "X1"}, {"A2", "X2"}, {"A3", "X3"}, {"A4", "X4"}, {"A5", "X5"} };
        distTable1 = { {"X1", 100.0}, {"X2", 200.0}, {"X3", 250.0}, {"X4", 300.0}, {"X5", 320.0} };
        Tour::tour(friends1, fTowns1, distTable1);// , 1020);
    
}
