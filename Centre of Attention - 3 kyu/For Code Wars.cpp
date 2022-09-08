//using namespace std;
//#include <vector>
//#include <functional>
//#include <math.h>
//
//struct Solution {
//    unsigned currentBest;
//    vector<unsigned> pixels;
//};
//
//vector<unsigned> solveCentre(const vector<unsigned>& map, unsigned w, unsigned c) {
//
//    unsigned mSize = (unsigned)map.size();
//
//    function<unsigned(unsigned)> up = [=, &up](unsigned index) {
//        return (map[index] != c) ? 0 : (index < w) ? 1 : (int)(1 + up(index - w)); };
//
//    function<unsigned(unsigned)> down = [=, &down](unsigned index) {
//        return (map[index] != c) ? 0 : (index + w > mSize - 1) ? 1 : (int)(1 + down(index + w)); };
//
//    function<unsigned(unsigned)> right = [=, &right](unsigned index) {
//        return (map[index] != c) ? 0 : ((index + 1) % w == 0) ? 1 : (int)(1 + right(index + 1)); };
//
//    function<unsigned(unsigned)> left = [=, &left](unsigned index) {
//        return (map[index] != c) ? 0 : ((index - 1) % w == w - 1 || index == 0) ? 1 : (int)(1 + left(index - 1)); };
//
//    unsigned upScore(0), downScore(0), leftScore(0), rightScore(0), pixelScore(0);
//
//    Solution solution = {};
//    solution.currentBest = 0;
//
//    for (unsigned i = 0; i < mSize; i++) {
//        if (map[i] != c)continue;
//        upScore = (i < w) ? 1 : 1 + up(i - w);
//        downScore = (i > mSize - w - 1) ? 1 : 1 + down(i + w);
//        rightScore = (i + 1) % w == 0 ? 1 : 1 + right(i + 1);
//        leftScore = ((i == 0) || ((i - 1) % w == w - 1)) ? 1 : 1 + left(i - 1);
//
//        pixelScore = min(min(upScore, downScore), min(leftScore, rightScore));
//
//        if (pixelScore == solution.currentBest) {
//            solution.pixels.push_back(i);
//        }
//        else if (pixelScore > solution.currentBest) {
//            solution.currentBest = pixelScore;
//            solution.pixels.clear();
//            solution.pixels.push_back(i);
//        }
//    }
//
//    return solution.pixels;
//}
//
//
//vector<unsigned> central_pixels(unsigned colour)
//{
//
//    // unsigned width = Image.width; unsigned height = Image.height;
//    // vector<unsigned> pixelMap = this.pixels;
//    vector<unsigned> answer = solveCentre(pixels, width, colour);
//    return answer;
//}
