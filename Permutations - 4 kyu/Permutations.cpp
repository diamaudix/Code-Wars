#include <string>
#include <vector>
#include <set>
#include <functional>
using namespace std;

class Permuter {
public:

    Permuter(string str) : startingString(str) {} //constructor

    void swapMembers(string &s, int a, int b); //functions
    vector<string> getPermutations();
    void recursePermutation(string s, int pivot);
    vector<string> setToVector();

    const string startingString; //data
    vector<string> answerVec;
    set<string> answerSet;
};
void Permuter::recursePermutation(string str, int pivot) {

    std::function<void(string&, int, int)> swap = [=](string &s, int a, int b) {
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
    };
    if (pivot >= (int)(str.length() - 2)) {
        answerSet.insert(str);
        swap(str, (int)(str.length() - 2), (int)(str.length() - 1));
        answerSet.insert(str);
    }
    else {
        for (int i = pivot + 1; i <= (int)(str.length()); i++) { //stop 2 from end
            Permuter::recursePermutation(str, pivot + 1);
            swap(str, pivot, i);
        }
    }
}

vector<string> Permuter::setToVector() {
    for (auto p : answerSet) {
        answerVec.push_back(p);
    }
    return answerVec;
}

vector<string> Permuter::getPermutations() {
    if (startingString.length() < 2) return { startingString };  
    Permuter::recursePermutation(startingString, 0);
    return  (answerVec = setToVector());
}

vector<string> permutations(string s) {
    Permuter permuter(s);
    return permuter.getPermutations();
}


int main() {

    vector<string> g = permutations("Goksenin");//equals {"a"},

    vector<string> abcde = permutations("abcde");//equals {"a"},
    vector<string> test1 =  permutations("a");//equals {"a"},
    vector<string> test2 = permutations("ab"); // equals{"ab", "ba"}, 
    vector<string> test3 = permutations("aabb"); //equals{"aabb", "abab", "abba", "baab", "baba", "bbaa"},

    return 0;
}