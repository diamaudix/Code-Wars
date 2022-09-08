//using namespace std;
//#include <vector>
//#include <iostream>
//#include <functional>
//#include <math.h>
////struct Image
////{
////    unsigned* pixels;
////    vector<unsigned> pixelMap;
////    unsigned width, height;
////
////    Image(vector<unsigned> &p, unsigned w, unsigned h) {
////        this->pixels = p;
////        this->width = w;
////        this->height = h;
////
////    }
////
////    vector<unsigned> central_pixels(unsigned colour) const;
////    
////    void printPixels();
////    
////    // other functions ...
////};
//struct Image
//{
//    unsigned* pixels;
//    unsigned width, height;
//
//    vector<unsigned> central_pixels(unsigned colour) const;
//};
////void printPixels(vector<unsigned> map, unsigned width, unsigned height) {
////
////    cout << "Image: "<<endl;
////
////    for (unsigned i = 0; i < width*height; i++) {
////        if (i % width == 0) cout << endl;
////        cout << pixels[i] << " ";
////    }
////    cout << endl;
////}
//
//struct Solution {
//    unsigned currentBest;
//    vector<unsigned> topDepthPixels;
//};
//
//
//
//vector<unsigned> Image::central_pixels(unsigned colour) const
//{
//    unsigned c = colour;
//    unsigned w = width;
//    unsigned mSize = (unsigned)sizeof(pixels);
//
//    function<unsigned(unsigned)> up = [=,&up](unsigned index) {
//        return (pixels[index] != c) ? 0 : (index < w) ? 1 : (int)(1 + up(index - w));};
//
//    function<unsigned(unsigned)> down = [=, &down](unsigned index) {
//        return (pixels[index] != c) ? 0 : (index + w > mSize - 1) ? 1 : (int)(1 + down(index + w));};
//
//    function<unsigned(unsigned)> right = [=, &right](unsigned index) {
//        return (pixels[index] != c) ? 0 : ((index + 1) % w == 0) ? 1 : (int)(1 + right(index + 1)); };
//
//    function<unsigned(unsigned)> left = [=, &left](unsigned index) {
//        return (pixels[index] != c) ? 0 : ((index - 1) % w == w - 1 || index == 0) ? 1 : (int)(1 + left(index - 1)); };
//
//    unsigned upScore(0), downScore(0), leftScore(0), rightScore(0), pixelScore(0);
//
//    Solution solution = {};
//    solution.currentBest = 0;
//    
//    for (unsigned i = 0; i < mSize; i++) {
//        if (pixels[i] != c)continue;
//        upScore = (i < w) ? 1: 1 + up(i-w);
//        downScore = (i > mSize - w-1) ? 1 : 1+down(i + w);
//        rightScore = (i + 1) % w == 0 ? 1 : 1+right(i + 1);
//        leftScore = ((i==0)||((i - 1) % w == w - 1)) ? 1 : 1 + left(i - 1);
//
//        // leftScore = left(i - 1);
//       // rightScore = right(i+1);
//        pixelScore = min(min(upScore, downScore), min(leftScore, rightScore));
//        
//        if (pixelScore == solution.currentBest) {
//            solution.topDepthPixels.push_back(i);
//           // cout << "Added " << i << " to solution" << endl;
//        }
//        else if (pixelScore > solution.currentBest) {
//           // cout << "Added New Best " << i << " to solution.  wiping old" << endl;
//            solution.currentBest = pixelScore;
//            solution.topDepthPixels.clear();
//            solution.topDepthPixels.push_back(i);
//        }
//        else cout << i << " : REJECTED!"<<endl;
//
//       /* cout << "Upscore : " << upScore << " DownScore: " << downScore << endl;
//        cout << "LeftScore : " << leftScore << " RightScore: " << rightScore << endl;
//        cout << "PixelScore : " << pixelScore << endl << endl;*/
//    }
//
//
//    return solution.topDepthPixels;
//    //unsigned central_pixel = colour;
//
//    
// 
//
//  //  vector<unsigned> pixelMap =
//   
//  //  unsigned width = 10; unsigned height = 6;
//    
//   // printPixels(pixelMap, width, height);
//
//}
//
//
///* ---------------------------------------------------------------------------------- */
///*                               TESTS                                                */
///* ---------------------------------------------------------------------------------- */
//
//int main() {
//
//    vector<unsigned> map = { 1,1,4,4,4,4,2,2,2,2,
//                             1,1,1,1,2,2,2,2,2,2,
//                             1,1,1,1,2,2,2,2,2,2,
//                             1,1,1,1,1,3,2,2,2,2,
//                             1,1,1,1,1,3,3,3,2,2,
//                             1,1,1,1,1,1,3,3,3,3 };
//
//    Image image (map,10,6);
//    vector<unsigned> red_ctr = image.central_pixels(1); //{ 32 };
//
//    // Multiple blue pixels have the maximum depth of 2:
//    vector<unsigned> blue_ctr = image.central_pixels(2); //{ 16,17,18,26,27,28,38 };
//
//    // All the green pixels have depth 1, so they are all "central":
//    vector<unsigned> green_ctr = image.central_pixels(3); // { 35,45,46,47,56,57,58,59 };
//
//    // Similarly, all the purple pixels have depth 1:
//    vector<unsigned> purple_ctr = image.central_pixels(4); // { 2,3,4,5 };
//
//
//    // There are no pixels with colour 5:
//    vector<unsigned> non_existent_ctr = image.central_pixels(5); //{ };
//
//
//    // Changing one pixel can make a big difference to the result:
//    
//    //pixels[32] = 3;
//    vector<unsigned> new_ctr = image.central_pixels(1); // { 11, 21, 41, 43 };
//
//    return 0;
//}
//
//
//


''
#define deb(x) std::cout << #x << " " << x << std::endl;
using namespace std;
#include <vector>
#include <functional>
#include <math.h>
#include <iostream>

struct Solution {
    unsigned currentBest;
    vector<unsigned> pixelLocations;
};


vector<unsigned> Image::central_pixels(unsigned colour) const
{
    unsigned mSize = height * width;
    // deb(mSize);
    unsigned w(width), c(colour);
    // deb (w);

    function<unsigned(unsigned)> up = [=, &up](unsigned index) {
        return (pixels[index] != c) ? 0 : (index < w) ? 1 : (1 + up(index - w)); };

    function<unsigned(unsigned)> down = [=, &down](unsigned index) {
        return (pixels[index] != c) ? 0 : ((index + w > mSize - 1) ? 1 : (1 + down(index + w))); };

    function<unsigned(unsigned)> right = [=, &right](unsigned index) {
        return (pixels[index] != c) ? 0 : ((index + 1) % w == 0) ? 1 : (1 + right(index + 1)); };

    function<unsigned(unsigned)> left = [=, &left](unsigned index) {
        return (pixels[index] != c) ? 0 : ((index - 1) % w == w - 1 || index == 0) ? 1 : (1 + left(index - 1)); };

    unsigned upScore(0), downScore(0), leftScore(0), rightScore(0), pixelScore(0);

    Solution solution = {};
    solution.currentBest = 0;

    for (unsigned i = 0; i < mSize; i++) {

        if (pixels[i] != c)continue;

        upScore = (i < w) ? 1 : 1 + up(i - w);
        downScore = (i > mSize - w - 1) ? 1 : 1 + down(i + w);
        rightScore = (i + 1) % w == 0 ? 1 : 1 + right(i + 1);
        leftScore = ((i == 0) || ((i - 1) % w == w - 1)) ? 1 : 1 + left(i - 1);

        pixelScore = min(min(upScore, downScore), min(leftScore, rightScore));

        if (pixelScore == solution.currentBest) {
            //        cout << "Added " << i << " to solution" << endl;
            solution.pixelLocations.push_back(i);
        }
        else if (pixelScore > solution.currentBest) {
            //      cout << "Added New Best at " << i << " of "<<pixelScore<< " to solution.  wiping old" << endl;
            solution.currentBest = pixelScore;
            solution.pixelLocations.clear();
            solution.pixelLocations.push_back(i);
        }
        //     cout << "For index: "<<i<<endl;
        //     cout << "Upscore : " << upScore << " DownScore: " << downScore << endl;
         //    cout << "LeftScore : " << leftScore << " RightScore: " << rightScore << endl<<endl;
            // cout << "PixelScore : " << pixelScore <<" ... REJECTED" <<endl << endl;

    }

    return solution.pixelLocations;

}


