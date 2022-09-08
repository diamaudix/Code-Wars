#include <vector>
using namespace std;
typedef long long LL;
class Dioph
{
public:
	static vector<pair <long, long>> solEquaStr(LL n);
    static vector<pair<LL, LL>> getCandidatePairs(LL n);
};
vector<pair<LL, LL>> Dioph::getCandidatePairs(LL n)
{
    
    vector<pair<LL, LL>> results;
    for (long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            results.push_back(make_pair(n / i, i));
        }
    }
    

    return results;
}

vector<pair<long, long>> Dioph::solEquaStr(LL n)
{
    vector<pair<LL, LL>> candidates = getCandidatePairs(n);
    vector<pair<long, long>> answer;
    for (auto p : candidates) {

        if ((p.first + p.second) % 2 == 0 && (p.first - p.second) % 4 == 0) {
            answer.push_back(std::make_pair((p.first + p.second) / 2, (p.first - p.second) / 4));
        }
    }
    
    
    return answer;


}
int main() {

    vector<pair <long, long>> ans1;
    ans1 = Dioph::solEquaStr(5);//Equals { {3, 1} };
    
    vector<pair <long, long>> ans2 = Dioph::solEquaStr(9001);// Equals { {4501, 2250} };
    
    ans2 = Dioph::solEquaStr(90005); //[45003, 22501], [9003, 4499], [981, 467], [309, 37]


    return 0;
}


//
//
//long x(0), y(0);
//vector<pair<long, long>> vec;
//
//for (x = 3; x < 3 * n; x++) {
//    for (y = 1; y <= x / 2; y++) {
//        long m = x * x - 4 * y * y;
//
//        //cout << "For X: " << x << ", Y: " << y << ",  N = " << m << "\n";
//        if (m == n) vec.push_back(make_pair(x, y));
//    }
//}
//
//vector<pair<long, long>>::iterator it = vec.begin();
//while (it != vec.end()) {
//    cout << "Answer = x: " << it->first << ", y: " << it->second << endl;
//    it++;
//}
//
//return vec;