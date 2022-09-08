//#include <utility>
//#include <vector>
//#include <algorithm>
//#include <numeric>
//#include <functional>
//#include <math.h>
//#include <iostream>
//using namespace std;
//pair<int64_t, int64_t> find_min_max_product(vector<int32_t> arr, int k) {
//
//    /*for (int i = 0; i < (int)arr.size(); i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;*/
//    try{
//        auto test = arr.at(k);
//    }
//    catch (const std::exception& e) {
//        std::cout << e.what() << std::endl;
//        throw(e);
//    }
//
//    //if (k > (int)arr.size()) return {};
//
//    auto it = std::partition(arr.begin(), arr.end(), [](const auto& el) { return el < 0; });
//    auto pos = distance(it, arr.end());
//    auto neg = distance(arr.begin(), it);
//    vector<int32_t> pos(pos), neg(neg);
//
//
//    //for (auto i = 0; i < arr.size(); i++) {
//    copy(arr.begin(), it, neg.begin());
//    copy(it, arr.end(), pos.begin());
//    sort(pos.begin(), pos.end(), std::greater<int>());
//    sort(neg.begin(), neg.end());
//    int64_t minResult(999999999999), maxResult(-999999999999);
//    
//    int posLength = (int)pos.size();
//    int negLength = (int)neg.size();
//    int64_t pos_accum, neg_accum;
//    if (k <= posLength) {
//        maxResult = accumulate(pos.begin(), pos.begin() + k, 1, std::multiplies<int32_t>());
//    }
//    else {
//        
//        
//        maxResult = accumulate(pos.begin(), pos.begin() + posLength, 1, std::multiplies<int32_t>()) *
//            accumulate(neg.rbegin(), neg.rbegin() + k - posLength, 1, std::multiplies<int32_t>());
//    }
//    if (k <= negLength) {
//        if (negLength % 2 == 1) {
//            minResult = accumulate(neg.begin(), neg.begin() + k, 1, std::multiplies<int32_t>());
//        }
//        else if(posLength>0) {
//            minResult = accumulate(neg.begin(), neg.begin() + k-1, 1, std::multiplies<int32_t>())*
//                pos[0];
//        }
//    }
//    else {
//        if (negLength % 2 ==0) {
//
//            minResult = accumulate(neg.begin(), neg.begin() + negLength-1, 1, std::multiplies<int32_t>()) *
//                accumulate(pos.begin(), pos.begin() + k - negLength+1, 1, std::multiplies<int32_t>());
//        }
//        else {
//            minResult = accumulate(neg.begin(), neg.begin() + negLength, 1, std::multiplies<int32_t>()) *
//                accumulate(pos.begin(), pos.begin() + k - negLength, 1, std::multiplies<int32_t>());
//        }
//    }
//
//    for (int i = 2; i <= k && i<= posLength && i<= negLength; i += 2) {
//        pos_accum = accumulate(pos.begin(), pos.begin() + k - i, 1, std::multiplies<int32_t>())
//          * accumulate(neg.begin(), neg.begin() + i, 1, std::multiplies<int32_t>());
//        maxResult = max(pos_accum, maxResult);   
//    }
//    for (int i = 1; i <= k && i < posLength && i <= negLength; i += 2) {
//        neg_accum = accumulate(neg.begin(), neg.begin() + i, 1, std::multiplies<int32_t>())
//            * accumulate(pos.begin(), pos.begin() + k-i, 1, std::multiplies<int32_t>());
//        minResult = std::min(neg_accum, minResult);
//
//    }
//    return { std::make_pair(minResult, maxResult) };
//}

#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <math.h>
#include <iostream>
using namespace std;
pair<int64_t, int64_t> find_min_max_product(vector<int32_t> arr, int k) {

    
    
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << ", ";
    }
    cout << " k: " << k << endl;
    try {
        arr.at(k-1);
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        throw(e);
    }


    auto it = std::partition(arr.begin(), arr.end(), [](const auto& el) { return el < 0; });
    auto posLength = distance(it, arr.end());
    auto negLength = distance(arr.begin(), it);
    vector<int32_t> pos(posLength), neg(negLength);


    //for (auto i = 0; i < arr.size(); i++) {
    copy(arr.begin(), it, neg.begin());
    copy(it, arr.end(), pos.begin());
    sort(pos.begin(), pos.end(), std::greater<int>());
    sort(neg.begin(), neg.end());
    int64_t minResult(999999999999), maxResult(-999999999999);

    int64_t pos_accum, neg_accum;
    if (k == (int)arr.size()) {
        maxResult = accumulate(arr.begin(), arr.begin() + k, 1, std::multiplies<int32_t>());
        
        return { std::make_pair(maxResult, maxResult) };
    }
    if (negLength == 0) {
        maxResult = accumulate(arr.begin(), arr.begin() + k, 1, std::multiplies<int32_t>());
        return { std::make_pair(maxResult, maxResult) };
    }

    
    if (k <= posLength) {
        maxResult = accumulate(pos.begin(), pos.begin() + k, 1, std::multiplies<int32_t>());
    }
    else {
        maxResult = accumulate(pos.begin(), pos.begin() + posLength, 1, std::multiplies<int32_t>()) *
            accumulate(neg.begin(), neg.begin() + k - posLength, 1, std::multiplies<int32_t>());
    }
    if (k <= negLength) {
        minResult = accumulate(neg.begin(), neg.begin() + k, 1, std::multiplies<int32_t>());
    }
    else {
        minResult = accumulate(neg.begin(), neg.begin() + negLength, 1, std::multiplies<int32_t>()) *
            accumulate(pos.begin(), pos.begin() + k - negLength, 1, std::multiplies<int32_t>());
    }

    for (int i = 0; i <= k && i <= posLength && i <= negLength; i += 2) {
        pos_accum = accumulate(pos.begin(), pos.begin() + k - i, 1, std::multiplies<int32_t>())
            * accumulate(neg.begin(), neg.begin() + i, 1, std::multiplies<int32_t>());
        maxResult = max(pos_accum, maxResult);
    }
    for (int i = 1; i <= k && i < posLength && i <= negLength; i += 2) {
        neg_accum = accumulate(neg.begin(), neg.begin() + i, 1, std::multiplies<int32_t>())
            * accumulate(pos.begin(), pos.begin() + k - i, 1, std::multiplies<int32_t>());
        minResult = std::min(neg_accum, minResult);

    }
    if (minResult > maxResult) return { std::make_pair(maxResult,minResult) };
    return { std::make_pair(minResult, (maxResult<0)?0:maxResult) };
}
int main() {
    std::pair<int64_t, int64_t> result;


    // result = (find_min_max_product({ 1, -2, -3, 4, 6, 7 }, 1)); //Equals(Pair{ -3, 7 }));

    // k = 2: -3 * 7 = -21, 6 * 7 = 42
    //result = (find_min_max_product({ 1, -2, -3, 4, 6, 7 }, 2)); //Equals(Pair{ -21, 42 }));

    // k = 3: -3 * 6 * 7 = -126, 4 * 6 * 7 = 168
   
    result = (find_min_max_product({ -43, 5, -78, -50 }, 2)); //Equals(Pair{ -126, 168 }));
    
    result = (find_min_max_product({ 1, -2, -3, 4, 6, 7 }, 3)); //Equals(Pair{ -126, 168 }));
    result = (find_min_max_product({ 1, -2, -3, 4, 6, 7 }, 7));
    result = (find_min_max_product({ 1, -2, -3, 4, 6, 7,-5,-11,-31,-21,19,23,24,-2,17 }, 5)); //Equals(Pair{ -126, 168 }));


    return 0;
}