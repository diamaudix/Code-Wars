
#include <string>
#include <vector>

bool isLetter(char character) {

    if((character>=97 && character <=122)||(character>=65&&character<=90)) return true;
    return false;
}
std::vector<int> getCoefficients(const std::string& expression) {

    std::vector<int> coefficients;

    size_t secondOpenBracketPos = expression.find("(", 2);
    size_t secondCloseBracketPos = expression.find(")", secondOpenBracketPos + 1);

    std::string binomial1 = expression.substr(1, expression.find(")")-1); // token is "scott"
    std::string binomial2 = expression.substr(secondOpenBracketPos+1, secondCloseBracketPos-secondOpenBracketPos-1);

    std::string::iterator it = binomial1.begin();
    std::string coefficient1, coefficient2, constant1, constant2;

    while (!isLetter(*it)) {
        coefficient1.push_back(*it);
        it++;
    }
    it++;
    if (coefficient1 == "-")coefficient1 = "-1";
    while (it != binomial1.end()){
        constant1.push_back(*it);
        it++;
    }
    it = binomial2.begin();
    while (!isLetter(*it)) {
        coefficient2.push_back(*it);
        it++;
    }
    if (coefficient2 == "-")coefficient2 = "-1";
    it++;
    while (it != binomial2.end()) {
        constant2.push_back(*it);
        it++;
    }
    coefficients.push_back(coefficient1 == "" ? 1 : stoi(coefficient1));
    coefficients.push_back(stoi(constant1));
    coefficients.push_back(coefficient2 == "" ? 1 : stoi(coefficient2));
    coefficients.push_back(stoi(constant2));
    return coefficients;
}

char getLetter(std::string expression) {

    std::string::iterator it = expression.begin();

    while (it != expression.end()) {
        if (isLetter(*it)) return *it;
        it++;
    }
    return 0;
}

std::string quadratic_builder(const std::string& expression)
{
    std::string result;
    std::vector<int> coefficients = getCoefficients(expression);
    char letter = getLetter(expression);

    int squareCoefficient, linearCoefficient, constant;

    squareCoefficient = coefficients[0] * coefficients[2];

    linearCoefficient = (coefficients[0] * coefficients[3]) + (coefficients[1] * coefficients[2]);

    constant = coefficients[1] * coefficients[3];

   
    if (squareCoefficient != 0) {

        if (squareCoefficient == -1) result.push_back('-');
        else if (squareCoefficient != 1) result.append(std::to_string(squareCoefficient));
        
        result.push_back(letter);
        result.push_back('^');
        result.push_back('2');
    }
    if (linearCoefficient != 0) {
        if (linearCoefficient > 0) {
            result.push_back('+');
            if (linearCoefficient != 1) result.append(std::to_string(linearCoefficient));
        }
        if (linearCoefficient < 0) {
            if(linearCoefficient == -1) result.push_back('-');
            if (linearCoefficient != -1) result.append(std::to_string(linearCoefficient));
        }

        result.push_back(letter);
    }
    if(constant!=0){
        if (constant >= 0) result.push_back('+');
        result.append(std::to_string(constant)); 
    }
    return result;
}

int main(){
    
    std::string result;
    
    result = quadratic_builder("(x+2)(x+3)");// , "x^2+5x+6");//return "x^2+5x+6"
    result = quadratic_builder("(x-2)(x+7)");// , "x^2+5x-14"); //return "x^2+5x-14"
    result = quadratic_builder("(3y+2)(y+5)");// , "3y^2+17y+10");//return "3y^2+17y+10"
    result = quadratic_builder("(-h-7)(4h+3)");// , "-4h^2-31h-21");//return "-4h^2-31h-21"
    result = quadratic_builder("(-7x+2)(-5x+3)");// , "35x^2-31x+6")
    return 0;
};