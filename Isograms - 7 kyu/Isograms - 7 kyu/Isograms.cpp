#include <set>
#include <string>
bool is_isogram(std::string str) {

    std::set<char> charSet;

    for (auto c : str) {


        if (c >= 65 && c <= 90) c += 32;

        if (charSet.find(c) == charSet.end()) {
            charSet.insert(c);
        }
        else {
            return false;
        }

    }
    return true;
}

int main() {
    bool answer;
    answer = is_isogram("Dermatoglyphics");// , Equals(true));
    answer = is_isogram("moose");// , Equals(false));
    answer = is_isogram("isIsogram");// , Equals(false));

    return 0;
}