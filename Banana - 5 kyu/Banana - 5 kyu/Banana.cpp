#include <iostream>
#include <string>
#include <unordered_set>
using BananaSet = std::unordered_set<std::string>;
class Bananagram {
public:
    BananaSet goBananas();
    Bananagram(const std::string original) :word(original) {
        wordLength = (unsigned int)word.length();
        bLength = (unsigned int)banana.length();
    }
private:
    BananaSet answerSet;
    const std::string word;
    unsigned int wordLength, bLength;
    const std::string banana = "banana";
    void recurseWord(std::string wordString, unsigned int bIndex, unsigned int wordIndex);
};
BananaSet Bananagram::goBananas() {
    if (wordLength < bLength) return {};
    recurseWord(word, 0, 0);
    return answerSet;
}
void Bananagram::recurseWord(std::string wordString, unsigned int bIndex, unsigned int wordIndex) {
    if (wordIndex >= wordLength) return; //terminating condition 1
    int remainingBanana(bLength - bIndex), remainingWord(wordLength - wordIndex);
    if (remainingBanana > remainingWord) return; //terminating condition 2

    if (bIndex == bLength - 1) { // last character has different behaviour
        if (banana[bIndex] == word[wordIndex]) {
            wordString[wordIndex] = '-';
            recurseWord(wordString, bIndex, wordIndex + 1);
            wordString[wordIndex] = banana[bIndex];
            for (unsigned int i = wordIndex + 1; i < wordLength; i++) wordString[i] = '-';
            answerSet.insert(wordString);
        }
        else {
            wordString[wordIndex] = '-';
            recurseWord(wordString, bIndex, wordIndex + 1);
        }
    }
    else {
        for (unsigned int i = wordIndex; i < wordLength; i++) {// search for next occurrence of banana[bIndex]  in "word"
            if (wordString[i] == banana[bIndex]) {
                recurseWord(wordString, bIndex + 1, i + 1);
                wordString[i] = '-';
            }
            else {
                wordString[i] = '-';
                recurseWord(wordString, bIndex, i + 1);
            }
        }
    }
}
BananaSet bananas(const std::string& s) {
    Bananagram bananagram(s);
    BananaSet answers;
    return bananagram.goBananas();
}



int main() {

    BananaSet actual;

   //works:   actual = bananas("banann"); // equals {};

    // works : actual = bananas("banana"); //equals "banana" };

    actual = bananas("bbananana"); //equals "b-an--ana", "-banana--", "-b--anana", "b-a--nana", **"-banan--a"**,
                       //"b-ana--na", "b---anana", "-bana--na", "-ba--nana", **"b-anan--a"**,
                       //"-ban--ana", "b-anana--" };


    actual = bananas("bananaaa"); //equals "banan-a-", "banana--", "banan--a" };

    actual = bananas("bananana"); //equals "ban--ana", "ba--nana", "bana--na", "b--anana", "banana--", "banan--a" };
    return 0;
}


