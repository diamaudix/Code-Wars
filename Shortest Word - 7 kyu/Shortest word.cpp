#include <string>
#include <iostream>
#include <vector>
using namespace std;
int find_short(std::string str)
{
    int minLength(0), count(1);

    vector<string> v;
    std::string::iterator it = str.begin();

    string temp = "";
    for (int i = 0; i < str.length(); ++i) {

        if (str[i] == ' ') {
            v.push_back(temp);
            temp = "";
        }
        else {
            temp.push_back(str[i]);
        }

    }
    v.push_back(temp);

    minLength = (int)v[0].length();
    for (int i = 1; i < v.size(); i++) {
        if ((int)v[i].length() < minLength) minLength = (int)v[i].length();
    }
    return minLength;

    //while (it != str.end()) {
    //    //  cout <<"Current Char : "<<*it<<endl;
    //    


    //    // cout<<"Count: "<< count <<endl;
    //    if (*it == *(str.end()-1)||*it == ' ') {
    //        if (minLength == 0) {
    //            // cout<<endl<<"New word! "<<endl;
    //            minLength = count;
    //        }
    //        else {
    //            // cout<<endl<<"New word! "<<endl;
    //            if (count != 0 && count < minLength) minLength = count - 1;

    //        }
    //        count = -1;
    //    }
    //    it++;
    //    count++;
    //    
    //}
    //return minLength;
}

int main(){

    int ans;
        ans = find_short("bitcoin take over the world maybe who knows perhaps"); //quals(3));
        ans = find_short("turns out random test cases are easier than writing out basic ones"); //quals(3));
        ans = find_short("lets talk about javascript the best language"); //quals(3));
        ans = find_short("i want to travel the world writing code one day"); //quals(1));
        ans = find_short("Lets all go on holiday somewhere very cold"); //quals(2));
        ans = find_short("Let's travel abroad shall we"); //quals(2));
        return 0;
    }