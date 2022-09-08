#include <list>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
std::vector<int> getGroup(int base) {

    std::vector<int> group;

    switch (base % 10) {
    case 0:

        group = { 0 };
        break;
    case 1:
        group = { 1 };
        break;
    case 2:
        group = { 2,4,8,6 };
        break;
    case 3:
        group = { 3,9,7,1 };
        break;
    case 4:
        group = { 4,6 };
        break;
    case 5:
        group = { 5 };
        break;
    case 6:
        group = { 6 };
        break;
    case 7:
        group = { 7,9,3,1 };
        break;
    case 8:
        group = { 8,4,2,6 };
        break;
    case 9:
        group = { 9,1 };
        break;
    default:
        break;
    }


    return group;

}

int last_digit(list<int> array) {
    
    if (array.empty()) return 1;  
    std::vector<int> truncatedData;

    int compressedPower=0;

    int baseDigit = (array.front());
    baseDigit %= 10;
    truncatedData.push_back(baseDigit);

    std::list<int>::iterator it = array.begin();
    it++;
    for (; it != array.end(); it++) {

        truncatedData.push_back(*it % 10000);
    }
    
    for(int i=truncatedData.size()-1;i>0; i-- ){

        if (truncatedData[i] == 0) {
            truncatedData[i-1] = 1;
            truncatedData.erase(truncatedData.begin() + i);
        }
        else if (truncatedData[i - 1] == 0) {
            truncatedData[i - 1] = 0;
            truncatedData.erase(truncatedData.begin() + i);
        }

    }

    if (truncatedData.size() == 1) return truncatedData[0]%10;

    std::vector<int>::reverse_iterator rit = truncatedData.rbegin();
    while (rit != truncatedData.rend()-2) {
        compressedPower = *(rit + 1);
        int startingPower = compressedPower;
        for (int i = *rit; i > 1; i--) {
            compressedPower = (startingPower*compressedPower) % 10000;
        }
        compressedPower %= 1000;
        *(rit +1) = compressedPower;
        rit++;
    }

    std::vector<int> group = getGroup(baseDigit);
    size_t modulus = group.size();

    int placeInGroup = (compressedPower -1) % modulus;
    int answer = group[placeInGroup];
    
    return answer;
}

int main(){
        int dig = last_digit({0,0,0,0,0,7}); //Equals(1));
        dig = last_digit({ 0,0 }); //Equals(1));
        dig = last_digit({ 0,0,0 }); //Equals(0));
        dig = last_digit({ 0,0,0,0,0 }); //Equals(0));
        dig = last_digit({ 0,0,0,0,3,0 }); //Equals(1));
        dig = last_digit({ 1,2 }); //Equals(1));
        dig = last_digit({ 3,4,5 }); //Equals(1));
        dig = last_digit({ 4,3,6 }); //Equals(4));
        dig = last_digit({ 7,6,21 }); //Equals(1));
        dig = last_digit({ 12,30,21 }); //Equals(6));
        dig = last_digit({ 2,2,2,0 }); //Equals(4));
        dig = last_digit({ 937640,767456,981242 }); //Equals(0));
        dig = last_digit({ 123232,694022,140249 }); //Equals(6));
        dig = last_digit({ 499942,898102,846073 }); //Equals(6));
       
        dig = last_digit({ 499942,898102,846073 }); //Equals(6));
        
        int rand1 = rand() % 100;
        int rand2 = rand() % 10;
        dig = last_digit({ rand1 }); //Equals(rand1 % 10));
        dig = last_digit({ rand1,rand2 }); //Equals((int)pow(rand1 % 10, rand2) % 10));
       return 0;
}