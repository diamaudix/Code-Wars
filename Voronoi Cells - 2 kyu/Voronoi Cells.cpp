using namespace std;
#include <vector>
struct Line
{
	double slope, intercept;
};

struct Point
{
	double x, y;

	Point() : x(0.0), y(0.0) {}
	Point(double x, double y) : x(x), y(y) {}
};

vector<double> voronoi_areas(const vector<Point>& p)
{
	return {};

}

int main (){
	vector<Point> p;
	vector<double> actual, expected;

	//(Square_Cell)
	
		p = { {0.0, 0.0}, {2.0, 0.0}, {-2.0, 0.0}, {0.0, 2.0}, {0.0, -2.0} };
		//expected = { 4, -1, -1, -1, -1 };
		actual = voronoi_areas(p);
		
	

	//(Triangular_Cells)
	
		p = { {2,1}, {2,-1}, {4.4, 2.2}, {4.4, -2.2}, {-0.4, 2.2}, {-0.4, -2.2} };
		//expected = { 8, 8, -1, -1, -1, -1 };
		actual = voronoi_areas(p);
		
		return 0;
}