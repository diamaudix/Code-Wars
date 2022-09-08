#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

class IntPart
{
public:
    static string part(long long n);
    static string calculatePartitions(long long m);
    static string printPartitions(long long range, double average, double median);
    //static void printArr(vector<long long> p, long long m);
    static void nextPartition(vector<long long>& pVec, long long& kIndex);
};

/*void IntPart::printArr(vector<long long> p, long long m) {
    for (long long i = 0; i < m; i++)
        cout << p[i] << " ";
    cout << endl;
}*/

void IntPart::nextPartition(vector<long long> &pVec, long long &kIndex) {

    //  printArr(pVec, kIndex + 1);
    long long remValue = 0;
    while (kIndex >= 0 && pVec[kIndex] == 1) {
        kIndex--;
        remValue+=1;
    }
    if (kIndex < 0)
        return;
    pVec[kIndex]--;
    remValue++;
    while (remValue > pVec[kIndex]) {
        pVec[kIndex + 1] = pVec[kIndex];
        remValue = remValue - pVec[kIndex];
        kIndex++;
    }
    pVec[kIndex + 1] = remValue;
    kIndex++;
}

string IntPart::calculatePartitions(long long n) {

    vector<long long> pVec, pVecProducts {n};
    pVec.resize(n, 0);
    long long kIndex = 0;
    pVec[kIndex] = n;
    bool isFinished = false;
    //printArr(pVec, kIndex + 1);

    long long minVal(1), maxVal(n), count(1);

    while (!isFinished) {
        IntPart::nextPartition(pVec, kIndex);
        vector<long long>::iterator it = std::find(pVec.begin(), pVec.end(), 0);
        long long endPoint = std::distance(pVec.begin(), it);
        long long product = accumulate(pVec.begin(), pVec.begin() + endPoint, 1, std::multiplies<long long>());

        it = std::find(pVecProducts.begin(), pVecProducts.end(), product);
        if (it == pVecProducts.end()) {
            maxVal = std::max(maxVal, product);
            pVecProducts.push_back(product);
            count++;
        }
        isFinished = (pVec[0] == 1) ? true : false;
    }
    std::sort(pVecProducts.begin(), pVecProducts.end());
    double median = (count % 2 == 0) ? ((double)pVecProducts[count/2.0 -1] 
        + (double)pVecProducts[count/2]) / 2.0 : double(pVecProducts[count/2]);
    long long range = maxVal - minVal;
    double average = (double)accumulate(pVecProducts.begin(), pVecProducts.end(), 0.0)/(double)count;
    return IntPart::printPartitions(range, average, median);
}

string IntPart::part(long long n) {
    if (n == 0) return IntPart::printPartitions(0, 0.0, 0.0);
    if (n == 1) return IntPart::printPartitions(0, 1.0, 1.0);  
    string answer = IntPart::calculatePartitions(n);
    return answer;

}

string IntPart::printPartitions(long long range, double average, double median) {

    string r = to_string(range);
    string a = to_string(round(average * 100.0) / 100.0);
    string m = to_string(round(median * 100.0) / 100.0);
    size_t foundA = a.find_first_of('.')+3;
    size_t foundM = m.find_first_of('.')+3;
    return ("Range: " + r + " Average: " + a.substr(0,foundA) + " Median: " + m.substr(0, foundM));
}
int main(){

       // IntPart::part(8);// "Range: 0 Average: 1.00 Median: 1.00");
        string answer = IntPart::part(2);// "Range: 1 Average: 1.50 Median: 1.50");
        answer = IntPart::part(3);// "Range: 2 Average: 2.00 Median: 2.00");
        answer = IntPart::part(4);// "Range: 3 Average: 2.50 Median: 2.50");
        answer = IntPart::part(5);// "Range: 5 Average: 3.50 Median: 3.50");
        return 0;
}