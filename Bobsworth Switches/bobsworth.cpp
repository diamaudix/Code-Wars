#include <vector>
std::vector<int> off(int n) {
    if (n == 1) return { 1 };
    std::vector<bool> switches(n, 0);
    std::vector<int> answer;
    for (int i = 2; i <= n; i++) {


        for (int j = i-1; j < n; j += i) {
            switches[j] = switches[j] == 0 ? 1 : 0;

        }


    }

    for (unsigned int i = 0; i < switches.size(); i++) {

        if (switches[i] == 0) answer.push_back(i+1);

    }

    return answer;

}
int main(){
std::vector<int> r1 = { 1 };
std::vector<int> r2 = { 1 };
std::vector<int> r3 = { 1,4 };

off(1);// , Equals(r1));
off(2);// , Equals(r2));
off(4);// , Equals(r3));
return 0;
}
