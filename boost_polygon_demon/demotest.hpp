#include <iostream>
#include <deque>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

#include <boost/foreach.hpp>


using namespace std;

int64_t CurrentTimeMillis()
{
    int64_t timems = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    return timems;
}

unsigned long GetTickCount()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000000);
}

void demoTest1(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    boost::geometry::read_wkt(
        "POLYGON((2.4 1.7,2.8 1.8,3.4 1.2,3.7 1.6,3.4 2,4.1 3,5.3 2.6,5.4 1.2,4.9 0.8,2.9 0.7,2 1.3,2.4 1.7)"
            "(4.0 2.0, 4.2 1.4, 4.8 1.9, 4.4 2.2, 4.0 2.0))", green);

    boost::geometry::read_wkt(
        "POLYGON((4.0 -0.5 , 3.5 1.0 , 2.0 1.5 , 3.5 2.0 , 4.0 3.5 , 4.5 2.0 , 6.0 1.5 , 4.5 1.0 , 4.0 -0.5))", blue);

    std::deque<polygon> output;
    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
//    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
    //2.50205
}

void demoTest2(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    boost::geometry::read_wkt(
        "POLYGON((0 4,4 4 ,4 0,0 0, 0, 4))", green);

    boost::geometry::read_wkt(
        "POLYGON((2 1, 2 2 , 6 2 , 6 1 , 2 1))", blue);

    std::deque<polygon> output;
    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
}


void demoTest3(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    boost::geometry::read_wkt(
        "POLYGON((31 61, 49 61, 49 246, 31 246, 31, 61))", green);

    boost::geometry::read_wkt(
        "POLYGON((99.575 192.904, 132.0619 192.904 , 132.0619 382.6, 99.575, 382.6, 99.575 192.904))", blue);

    std::deque<polygon> output;
    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
}

void demoTest4(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    boost::geometry::read_wkt(
        "POLYGON((0 4,4 4 ,4 0,0 0, 0, 4))", green);

    boost::geometry::read_wkt(
        "POLYGON((2 1, 2 2 , 6 2 , 5 1.5, 6 1.5, 6 1 , 2 1))", blue);

    std::deque<polygon> output;
    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
}


void demoTest5(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    std::string shape1 = "POLYGON((0 0, 0 4, 4 4, 4 0, 0 0))";
    std::string shape2 = "POLYGON((2 2, 4 0, 3 0.5, 2 0, 2 2))";
    boost::geometry::read_wkt(shape1, green);
    boost::geometry::read_wkt(shape2, blue);

    std::deque<polygon> output;
    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
}

void demoTest6(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    std::string shape1 = "POLYGON((220 276, 630 274, 4635 269, 4627 46, 242 39, 222 276, 220 276))";
    std::string shape2 = "POLYGON((221 0, 221 431, 1183 431, 1183 0, 221 0))";
    boost::geometry::read_wkt(shape1, green);
    boost::geometry::read_wkt(shape2, blue);

    std::deque<polygon> output;
    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
}

void demoTest7(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    std::string shape1 = "POLYGON((221 314, 363 317, 418 389, 622 296, 600 123, 450 77, 489 219, 356 218, 221 314))";
    std::string shape2 = "POLYGON((297 285, 297 430, 476 430, 476 285, 297 285))";
    boost::geometry::read_wkt(shape1, green);
    boost::geometry::read_wkt(shape2, blue);

    std::deque<polygon> output;
    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
}

void demoTest8(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    std::string shape1 = "POLYGON((221 314, 363 317, 418 389, 622 296, 600 123, 450 77, 489 219, 356 218, 221 314))";
    std::string shape2 = "POLYGON((297 285, 297 430, 476 430, 476 285, 297 285))";
    boost::geometry::read_wkt(shape1, green);
    boost::geometry::read_wkt(shape2, blue);

    std::deque<polygon> output;
    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
}
