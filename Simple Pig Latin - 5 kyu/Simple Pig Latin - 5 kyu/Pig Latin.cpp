#include <string>
#include <math.h>
using namespace std;


string pig_it(string str)
{
    string answer;
    size_t posBegin(0), lastPunct(0), firstPunct(0);
    do {
        firstPunct = str.find_first_of(" .; -!? , \"\'",posBegin);
        if (firstPunct == 0) {
            lastPunct = str.find_first_not_of(" .; -!? , \"\'", firstPunct);
            string punctSpace = str.substr(firstPunct, lastPunct - firstPunct);
            answer.append(punctSpace);
            posBegin = lastPunct;
            continue;
        }     
        if (firstPunct == str.npos) {
            string word = str.substr(posBegin, firstPunct - posBegin);
            rotate(word.begin(), word.begin() + 1, word.end());
            word.append("ay");
            answer.append(word);
            break;
        }
        lastPunct = str.find_first_not_of(" .; -!? , \"\'", firstPunct);
        
        
        string punctSpace = str.substr(firstPunct, lastPunct - firstPunct);
        
        
        string word = str.substr(posBegin, firstPunct-posBegin);
        rotate(word.begin(), word.begin() + 1, word.end());
        
        word.append("ay");
        word.append(punctSpace);
        answer.append(word);
        posBegin = lastPunct;
    } while (lastPunct != str.npos);
    if(answer[answer.size()-1] == ' ')answer.pop_back();
    return answer;
}


int main() {

    string result;
            result = pig_it("I!! love, Göksenin!!- van Snuggles!");
            result = pig_it("This is my string"); //Equals("hisTay siay ymay tringsay"));
            result = pig_it("Pig latin is cool"); //Equals("igPay atinlay siay oolcay"));
            result = pig_it("Acta est fabula"); //Equals("ctaAay steay abulafay"));

    return 0;
}