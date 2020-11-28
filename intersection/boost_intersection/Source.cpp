//#include <iostream>
//#include <deque>
//
//#include <boost/geometry.hpp>
//#include <boost/geometry/geometries/point_xy.hpp>
//#include <boost/geometry/geometries/polygon.hpp>
//
//#include <boost/foreach.hpp>
//#include <windows.h>
//
//
//int main()
//{
//	typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;
//
//	polygon green, blue;
//
//	DWORD start = GetTickCount();
//	boost::geometry::read_wkt(
//		"POLYGON((2 1.3,2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3)"
//		"(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))", green);
//
//	boost::geometry::read_wkt(
//		"POLYGON((4.0 -0.5 , 3.5 1.0 , 2.0 1.5 , 3.5 2.0 , 4.0 3.5 , 4.5 2.0 , 6.0 1.5 , 4.5 1.0 , 4.0 -0.5))", blue);
//
//	std::deque<polygon> output;
//	boost::geometry::intersection(green, blue, output);
//	DWORD end = GetTickCount();
//	printf("Ê±¼ä£º%dms\n", (end - start));
//
//	int i = 0;
//	std::cout << "green && blue:" << std::endl;
//	BOOST_FOREACH(polygon const& p, output)
//	{
//		std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
//	}
//
//
//	return 0;
//}

#include <windows.h>
#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/io/io.hpp>
#include <boost/geometry/algorithms/area.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

namespace bg = boost::geometry;
namespace bgm = bg::model;
typedef bgm::polygon<bgm::d2::point_xy<double> > polygon;
using namespace std;

int main() 
{
	LARGE_INTEGER m_liPerfFreq = { 0 };
	QueryPerformanceFrequency(&m_liPerfFreq);
	LARGE_INTEGER liPerfNow = { 0 };
	polygon poly1, poly2;
	bg::read<bg::format_wkt>(poly1, "POLYGON((159, 39, 160 400, 320 400, 320 80, 159 79))");
	bg::read<bg::format_wkt>(poly2, "POLYGON((247 151, 75 289, 80 480, 880 480, 880 240, 247 151))");				 

	std::cout << bg::wkt(poly1) << "\n";
	std::cout << bg::wkt(poly2) << "\n";
	std::deque<polygon> output;
	LARGE_INTEGER m_liPerfStart = { 0 };
	double area = 0;
	QueryPerformanceCounter(&m_liPerfStart);
	bg::intersection(poly1, poly2, output);
	for (auto& p : output)
		area += bg::area(p);
	//cout << area;
	QueryPerformanceCounter(&liPerfNow);
	int time = (((liPerfNow.QuadPart - m_liPerfStart.QuadPart) * 1000000) / m_liPerfFreq.QuadPart);
	char buffer[100];
	sprintf(buffer, "ˆÌÐÐ•rég %d microsecond ", time);
	cout << buffer << endl;
}