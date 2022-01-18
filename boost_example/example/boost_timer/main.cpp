//#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include <boost/timer.hpp>
#include <boost/progress.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/pool/pool.hpp>

using namespace std;
using namespace boost;

void Time_Example()
{
    timer t;
    cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << endl;
    cout << "min timespan:" << t.elapsed_min() << "s" << endl;

    for(int i = 0; i < 100; i++) {
        t.restart();
        sleep(1);
        cout << "now time elapsed:" << t.elapsed() << "s" << endl;
    }
}

void progress_timer_example() {
    boost::progress_timer  t;
//    cout << t.elapsed() << endl;
    for(int i = 0; i < 10; i++) {
        sleep(1);
    }
}

void progress_display_example() {
    vector<string> v(100);
    ofstream fs("text.txt");

    progress_display pd(v.size());

    vector<string>::iterator pos;
    for(pos = v.begin(); pos != v.end(); ++pos) {
        fs << *pos << endl;
        ++pd;
    }
}

void scoped_ptr_example() {
    scoped_ptr<string> sp(new string("text"));
    cout << *sp << endl;
    cout << sp->size() << endl;
}

void shared_ptr_exmaple_std() {
    shared_ptr<int> sp(new int(10));
    assert(sp.unique());

    shared_ptr<int> sp2 = sp;

    shared_ptr<string> sp3 = make_shared<string>("make_shared");
    shared_ptr<vector<int>> spv = make_shared<vector<int>> (10, 2);

}

void pool_example()
{
    pool<> pl(sizeof(int));
    int *p = (int *)pl.malloc();
    assert(pl.is_from(p));

    pl.free(p);
    for(int i = 0; i < 100; ++i)
    {
        pl.ordered_malloc(10);
    }
}
int main(int argc, char *argv[])
{
//    QCoreApplication a(argc, argv);
//    Time_Example();
//    progress_timer_example();
//    progress_display_example();
//    scoped_ptr_example();
//    shared_ptr_exmaple_std();
    pool_example();
//    return a.exec();
}
