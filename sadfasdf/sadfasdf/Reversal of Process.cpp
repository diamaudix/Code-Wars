#include <string>
#include <unordered_set>
using namespace std;
namespace process
{
    std::string decode(const std::string& r)
    {
        std::string decoded; unordered_set<int> check;
        std::size_t found = r.find_first_not_of("0123456789");
        long cipher = stol(r.substr(0, found));
        for (auto c : r.substr(found, r.length())) {
            for (int i = 1; i <= 26; i++) {
                check.insert(i * cipher % 26);
                if (i * cipher % 26 == c-97) decoded.push_back((c==97)?'a':(char)(i + 97));
            }   
        }
        return (check.size()==26)?decoded:"Impossible to decode";
    }
}


int main() {

#include <string>

    std::string answer;

    //encode("mer", 6015)-- > "6015ekx"
    answer = process::decode("6015ekx"); //mer
    answer = process::decode("1273409kuqhkoynvvknsdwljantzkpnmfgf"); //"uogbucwnddunktsjfanzlurnyxmx");
    answer = process::decode("1544749cdcizljymhdmvvypyjamowl"); //"mfmwhbpoudfujjozopaugcb");
    answer = process::decode("105860ymmgegeeiwaigsqkcaeguicc"); //"Impossible to decode");
    answer = process::decode("1122305vvkhrrcsyfkvejxjfvafzwpsdqgp"); //"rrsxppowmjsrclfljrajtybwviqb");
    answer = process::decode("7235897srigyvazffyrtxizwgpmvpts"); //"qfkoexapddefbtkpiojcxjbq");

    return 0;
}