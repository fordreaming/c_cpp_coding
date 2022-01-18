#include <iostream>
#include <deque>

#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>

#include <boost/foreach.hpp>


using namespace std;

int64_t CurrentTimeMillis()
{
//    int64_t timems = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//    return timems;
    return 0;
}

unsigned long GetTickCount()
{
    struct timespec ts;
//    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000000);
}

void demoTest1(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

//    case 1
//    std::string shape1 = "POLYGON((49 133,66 136,56 154,36 146,48 133,49 133))";
//    boost::geometry::read_wkt(shape1, green);

//    std::string shape2 = "POLYGON((49 133,66 136,56 154,36 146,48 133,49 133))";
//    boost::geometry::read_wkt(shape2, blue);

    //case 2
//    std::string shape1 = "POLYGON((0 4, 4 4, 4 0, 0 0, 0 4))";
//    boost::geometry::read_wkt(shape1, green);

//    std::string shape2 = "POLYGON((0 4, 4 4, 4 0, 0 0, 0 4))";
//    boost::geometry::read_wkt(shape2, blue);


//    boost::geometry::read_wkt(
//        "POLYGON((0 0, 0 4, 4 4, 4 0, 0 0))", green);

//    boost::geometry::read_wkt(
//        "POLYGON((2 2, 2 0, 4 0, 2 2))", blue);

//        boost::geometry::read_wkt(
//            "POLYGON((491 1660,349 1756,498 1971,547 1717,491 1660))", green);

//        boost::geometry::read_wkt(
//            "POLYGON((491 1660,349 1756,498 1971,547 1717,491 1660))", blue);

//        std::string shape1 = "POLYGON((586 1349,883 1448,469 1710,431 1424,586 1349))";
//        boost::geometry::read_wkt(shape1, green);

//        std::string shape2 = "POLYGON((586 1349,883 1448,469 1710,431 1424,586 1349))";
//        boost::geometry::read_wkt(shape2, blue);


//    std::string shape1 = "POLYGON((586 1349,883 1448,469 1710,431 1424,586 1349))";
//    std::string shape1 = "POLYGON((586 1349,431 1424,469 1710,883 1448,586 1349))";
//    boost::geometry::read_wkt(shape1, green);

//    std::string shape2 = "POLYGON((586 1349,431 1424,469 1710,883 1448,586 1349))";
//    boost::geometry::read_wkt(shape2, blue);


//    std::string shape1 = "POLYGON((462 2533,455 2703,650 2745,685 2544,462 2533))";
//    boost::geometry::read_wkt(shape1, green);

//    std::string shape2 = "POLYGON((462 2533,455 2703,650 2745,685 2544,462 2533))";
//    boost::geometry::read_wkt(shape2, blue);


//    std::string shape1 = "POLYGON((1519 2498,1272 2692,1660 2689,1519 2498))";
//    boost::geometry::read_wkt(shape1, green);

//    std::string shape2 = "POLYGON((1519 2498,1272 2692,1660 2689,1519 2498))";
//    boost::geometry::read_wkt(shape2, blue);

    std::string shape1 = "POLYGON((1399 1402,501 1413,1399 1402))";
    boost::geometry::read_wkt(shape1, green);

    std::string shape2 = "POLYGON((1399 1402,501 1413,1399 1402))";
    boost::geometry::read_wkt(shape2, blue);

    std::deque<polygon> output;
//    int64_t startTime = CurrentTimeMillis();
    boost::geometry::intersection(green, blue, output);

    int i = 0;
//    std::cout << "green && blue:" << std::endl;
    BOOST_FOREACH(polygon const& p, output)
    {
        std::cout << i++ << ": " << boost::geometry::area(p) << std::endl;
    }
//    std::cout << "time is: " <<CurrentTimeMillis() - startTime << " ms" << std::endl;
    //2.50205
}

void demoTest2(){
    typedef boost::geometry::model::polygon<boost::geometry::model::d2::point_xy<double> > polygon;

    polygon green, blue;

    boost::geometry::read_wkt(
        "POLYGON((0 4, 4 4, 4 0, 0 0, 0, 4))", green);

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
        "POLYGON((0 4,4 4 ,4 0,0 0, 0 4))", green);

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
