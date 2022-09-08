#include <vector>
#include <numeric>
#include <vector>
#include <algorithm>

std::vector<int> countPositivesSumNegatives(std::vector<int> input)
{
    std::vector<int>::iterator it = std::partition(input.begin(), std::end(input), [&](int i) {return i>0; });
    int dist = (int)std::distance(input.begin(), it);
    int neg = std::accumulate(it, input.end(),0);
    return {};
}

int main(){

        std::vector<int> result = countPositivesSumNegatives({ 1, 2, -15, 3,-12, 4, 5, 6, 7, 8, 9, 10, -11,  -13, -14 });

        std::vector<int> expected{ 10, -65 };
        std::vector<int> result2 = countPositivesSumNegatives({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15 });

        std::vector<int> expected3 = { 8, -50 };
        std::vector<int> result3 = countPositivesSumNegatives({ 0, 2, 3, 0, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14 });
  
        std::vector<int> result4 = countPositivesSumNegatives({ 1, 2, -15, 3,-12, 4, 5, 6, 7, 8, 9, 10, -11,  -13, -14 });

return 0;

}