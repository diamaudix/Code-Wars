#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>


char triangle(const std::string& row)
{
    size_t length = row.length();
    std::string thisRow = row;
    std::string nextRow;
    //answer.resize(((length * (length + 1)) / 2) - length);
    std::unordered_map<std::string, char> u = {
        {"RR",'R'},
        {"RG",'B'},
        {"RB",'G'},
        {"GR",'B'},
        {"GB",'R'},
        {"GG",'G'},
        {"BR",'G'},
        {"BB",'B'},
        {"BG",'R'},
    };
    char lookup;
    for (size_t i = 1; i < length; i++) {
        nextRow.resize(length - i, 0);
        for (int j = 0; j < nextRow.length(); j++) {
            std::string sub = thisRow.substr(j, 2);
            lookup = u.at(sub);
            nextRow[j] = lookup;
        }
        thisRow = nextRow;

    }

    return thisRow[0];
}


//
//void printString(const std::string& b) {
//
//    for (int i = 0; i < (int)b.length(); i++) {
//        for(int j=i+1; j<length)
//    }
//}

int main() {
    char result;
    
    result = triangle("RGBG"); //'B'),
    result = triangle("RBRGBRBGGRRRBGBBBGG"); //'G') });
    result = triangle("RBGRBGRBRRBGBRGBBBRBBRBRRRRRGGGRBBBRGGRBBRGBGBRBRGBBGRBBBRGBRBBRGBRGBRBRBBGRBGBRGRGBGRBBRBBRGGRBBRGBRBGRGRRRRRRGBBRGBBGRBBRGB"); //equals 
    result = triangle("B"); //'B'),
    result = triangle("GB"); //'R'),
    result = triangle("RRR"); //'R'),
    
    result = triangle("RBRGBRB"); //'G'),
    
}

//struct ColorNode {
//    ColorNode* lParent;
//    ColorNode* rParent;
//    char color;
//};
//
//class ParentGraph {
//    std::string base;
//    int len, nodes;
//    enum Color {red, green, blue};
//
//    ParentGraph(std::string b): base(b) {
//        len = base.length();
//        nodes = (len * (len + 1)) / 2;
//
//        // how to allocate enough memory for number of copies of "ColorNode" equal to "nodes"?
//    }
//
//
//};
