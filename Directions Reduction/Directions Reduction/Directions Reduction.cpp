#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;
class DirReduction
{
public:
    static vector<string> dirReduc(vector<string>& arr);
    static vector<int> directionsToNumbers(vector<string>& arr);
    static vector<string> numbersToDirections(vector<int>& arr);
    static void printArr(vector<string>& arr);
};

//void DirReduction::printArr(vector<string>& arr)
//{
//    for (int i = 0; i < (int)arr.size(); i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
vector<int> DirReduction::directionsToNumbers(vector<string>& arr)
{
    vector<int> result(arr.size());
    for(int i = 0; i<(int)arr.size(); i++){
        if (arr[i] == "NORTH") result[i] = 0;
        if (arr[i] == "SOUTH") result[i] = 1;
        if (arr[i] == "EAST") result[i] =100;
        if (arr[i] == "WEST") result[i] =101;
            
    }
    return result;
}
vector<string> DirReduction::numbersToDirections(vector<int>& arr)
{
    vector<string> result(arr.size());
    for (int i = 0; i < (int)arr.size(); i++) {
        if (arr[i] == 0) result[i] = "NORTH";
        if (arr[i] == 1) result[i] = "SOUTH";
        if (arr[i] == 100) result[i] = "EAST";
        if (arr[i] == 101) result[i] = "WEST";

    }
    return result;
}
vector<string> DirReduction::dirReduc(vector<string>& arr) {
    //printArr(arr);
    if (arr.empty()) return {};
    vector<int> ints = directionsToNumbers(arr);
    vector<int> diffs;
    int changeCount;
    do {
        changeCount = 0;
        std::adjacent_difference(ints.begin(), ints.end(), back_inserter(diffs));
        
        for (int i = 1; i < (int)diffs.size(); i++) {
            if (diffs[i] == 1 || diffs[i]==-1) {
                ints[i - 1] = -9999;
                ints[i] = -9999;
                changeCount++;
                break;
            }
        }
        ints.erase(std::remove(ints.begin(), ints.end(), -9999), ints.end());
        diffs.clear();    

    } while (changeCount != 0);
    return numbersToDirections(ints);
}
int main() {
    vector<string> result = { "" };
    
    vector<string> d0 = { "EAST", "SOUTH", "EAST", "NORTH", "EAST", "SOUTH", "NORTH", "NORTH", "NORTH", "WEST", "EAST", "NORTH", "WEST", "EAST", "WEST"};
    vector<string> ans0 = DirReduction::dirReduc(d0);
        //Expected: equal to["EAST", "SOUTH", "EAST", "NORTH", "EAST", "NORTH", "NORTH", "NORTH", "WEST"]


    vector<string> d1 = { "NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST" };
    vector<string> ans1 = DirReduction::dirReduc(d1);
    // vector<string> sol1 = { "WEST" };
    vector<string> d2 = { "NORTH","SOUTH","SOUTH","EAST","WEST","NORTH", "NORTH" };
    vector<string> ans2 = DirReduction::dirReduc(d2);
    //vector<string> sol2 = { "NORTH" };

    return 0;
}