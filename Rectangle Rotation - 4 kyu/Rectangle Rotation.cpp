#include <vector>
#include <numeric>
#include <functional>
#include <math.h>
using namespace std;

class Rectangle {
public:
    void rotate() {
        this->rotate(rot);
    }
  
    Rectangle(double a, double b) :length(a), width(b) {
        double c = (double)length / 2; double d = width / 2;
        pointA.X = -c; pointA.Y = d;
        pointB.X = c; pointB.Y = d;
        pointC.X = -c; pointC.Y = -d;
        pointD.X = c; pointD.Y = -d;
    }
    long long getNumIntegerPoints() {
        Line topLine, botLine, leftLine, rightLine;

        if (lineAB.intercept > lineDC.intercept) {
            topLine = lineAB; botLine = lineDC; leftLine = lineCA; rightLine = lineBD;
        }
        else {
            topLine = lineDC; botLine = lineAB; leftLine = lineBD; rightLine = lineCA;
        }
        long long sum = 0;
        double leftMost = min(min(pointA.X, pointB.X), min(pointC.X, pointD.X));
        double rightMost = max(max(pointA.X, pointB.X), max(pointC.X, pointD.X));
        long long start = (long long)ceil(leftMost);
        long long finish = (long long)floor(rightMost);

        for (long long i = start; i <= finish; i++) {
            long long topInt = (long long) min(floor(f(topLine, i)), floor(f(rightLine, i)));
            long long botInt = (long long) max(ceil(f(botLine, i)), ceil(f(leftLine, i)));
            sum += topInt - botInt +1;
        }
        return sum;
    }
private:
    struct Point{
        Point(double x, double y) : X(x), Y(y) {}
        Point() {}
        double X, Y;
    };
    struct Line {      
        Line(double s, double i) :slope(s), intercept(i) {}
        Line() { slope = 0; intercept = 0;}
        double slope, intercept;
    };
    struct RMatrix {
        RMatrix(double a, double b, double c, double d) : A(a), B(b),C(c),D(d) { }
        double A, B, C, D;
    };

    double length, width;
    Point pointA, pointB, pointC, pointD;
    Line lineAB, lineBD, lineDC, lineCA;
    const RMatrix rot = {0.70710678,-0.70710678, 0.70710678, 0.70710678 };

    void rotate(RMatrix rotation) {
        pointA = applyRotation(rotation, pointA);
        pointB = applyRotation(rotation, pointB);
        pointC = applyRotation(rotation, pointC);
        pointD = applyRotation(rotation, pointD);
        lineAB = getLine(pointA, pointB);
        lineBD = getLine(pointB, pointD);
        lineDC = getLine(pointD, pointC);
        lineCA = getLine(pointC, pointA);
    }
    Point applyRotation(RMatrix r, Point p ) {
        double xVal, yVal;
        vector<double> A1 = { r.A, r.B };
        vector<double> A2 = { r.C, r.D };
        vector<double> x = { p.X, p.Y };

        xVal = inner_product(A1.begin(), A1.end(), x.begin(), 0.0);
        yVal = inner_product(A2.begin(), A2.end(), x.begin(), 0.0);
        Point ans(xVal, yVal);
        return ans;
    }
    Line getLine(Point a, Point b) {
        double slp = (a.X - b.X) / (a.Y - b.Y);
        double intrcpt = a.Y - slp * (a.X);
        Line ans(slp, intrcpt);
        return ans;
    }    
    double f(Line line, long long x) {
        return (line.slope * x + line.intercept);
    }
};

long long rectangle_rotation(int a, int b)
{ 
    Rectangle rect((double)a, (double)b);
    rect.rotate();
    long long ans = rect.getNumIntegerPoints();
    return ans; // Do your magic!
}


int main() {
    long long ans;
   ans = rectangle_rotation(6, 4); // Equals(23));
   ans = rectangle_rotation(30, 2); // Equals(65));
   ans = rectangle_rotation(8, 6); // Equals(49));
   ans = rectangle_rotation(16, 20); // Equals(333));
   

   return 0;
}