#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <iostream>

int solve(const std::string& eq)
{
    size_t pos(eq.find("=")), end(0);
    std::string leftSide(eq.substr(0, pos)), rightSide(eq.substr(pos + 1, eq.size()));
    std::vector<std::string> leftTokens, rightTokens;
    std::vector<int> leftTerms, rightTerms;
    bool xPos = true;

    if (leftSide.find('x') == std::string::npos) {
        std::string temp = leftSide;
        leftSide = rightSide;
        rightSide = temp;
    }


    while ((end = leftSide.find(" ")) != std::string::npos) {
        if (end != 0) leftTokens.push_back(leftSide.substr(0, end));
        leftSide.erase(0, end + 1);
    }
    if (leftSide != "")leftTokens.push_back(leftSide);

    while ((end = rightSide.find(" ")) != std::string::npos) {
        if (end != 0) rightTokens.push_back(rightSide.substr(0, end));
        rightSide.erase(0, end + 1);
    }
    if (rightSide != "") rightTokens.push_back(rightSide);

    for (size_t i = 0; i < leftTokens.size(); i++) {
        if (leftTokens[i] == "+") {
            if (leftTokens[(i++) + 1] == "x") xPos = true;
            else leftTerms.push_back(std::stoi(leftTokens[i]));
        }
        else if (leftTokens[i] == "-") {
            if (leftTokens[(i++) + 1] == "x") xPos = false;
            else leftTerms.push_back(-1 * std::stoi(leftTokens[i]));
        }
        else if(leftTokens[i]!="x") leftTerms.push_back(std::stoi(leftTokens[i]));
    }
    for (size_t i = 0; i < rightTokens.size(); i++) {
        if (rightTokens[i] == "+")  rightTerms.push_back(std::stoi(rightTokens[(i++) + 1]));
        else if (rightTokens[i] == "-") rightTerms.push_back(-1 * std::stoi(rightTokens[(i++) + 1]));
        else rightTerms.push_back(std::stoi(rightTokens[i]));
    }

    int leftSum = std::accumulate(leftTerms.begin(), leftTerms.end(), 0);
    int rightSum = std::accumulate(rightTerms.begin(), rightTerms.end(), 0);
    return (xPos) ? (rightSum-leftSum) : -1 * (rightSum-leftSum);
}



int main() {

    int solve(const std::string & eq);

    //std::string easy0 = "61 + 14 - 15 = 90 - 20 + x";
    //std::string easy1 = "x + 1 = 9 - 2";
    //std::string easy2 = "x - 2 + 3 = 2";
    //std::string easy3 = "x = + 2 - 5 + 9";
    //std::string easy4 = "- 10 = x";
    //std::string easy5 = "- x = - 1";
    //std::string easy6 = "x - 0 + 0 = 0";

    //std::cout << solve(easy0) << std::endl;
    //std::cout << solve(easy1) << std::endl;
    //std::cout << solve(easy2) << std::endl;
    //std::cout << solve(easy3) << std::endl;
    //std::cout << solve(easy4) << std::endl;
    //std::cout << solve(easy5) << std::endl;
    //std::cout << solve(easy6) << std::endl;

    std::cout << solve(" - x - 1 = 8") << std::endl; //-9
    std::cout << solve("x + 1 = 9 - 2") << std::endl; //-9
    std::cout << solve("- 9358 + 3569 - x = 946047") << std::endl; //-951836
    std::cout << solve("- 58 - 24 + 134 + 143 = + 16 + 53 - 101 - 64 + 37 - x") << std::endl; //-254
  //  std::cout << solve(easy6) << std::endl;


	return 0;
}