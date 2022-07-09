// basic_exams_smart_pointer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
auto f1(double a, int b)->double {
	return a + b;
}

template<typename T, typename U>
auto eff(T t, U u) -> decltype(T*U) {
	return t + u;
}

//https://supwills.com/post/understanding-cpp-smart-pointer
class A {

};


struct Base {
	Base() {
		std::cout << "Base::Base()\n" << std::endl;
	}

	~Base() {
		std::cout << "Base::~Base()\n" << std::endl;
	}
};

/*struct Derived : public Base
{
	Derived() {
		std::cout << "Derived: " << std::endl;
	}

	~Derived() {
		std::cout << "~ Derived" << std::endl;
	}
};

void thr(std::shared_ptr<Base> p) {
	std::cout << "base : " << std::endl;
}*/

/*class Base1 {
public:
	Base1(shared_ptr<Base> b) {
		std::cout << "base1" << std::endl;
	}

	shared_ptr<base>;
};
*/


#include <iostream>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

struct Base
{
	Base() { std::cout << "  Base::Base()\n"; }
	// Note: non-virtual destructor is OK here
	~Base() { std::cout << "  Base::~Base()\n"; }
};

struct Derived : public Base
{
	Derived() { std::cout << "  Derived::Derived()\n"; }
	~Derived() { std::cout << "  Derived::~Derived()\n"; }
};

void thr(std::shared_ptr<Base> p)
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::shared_ptr<Base> lp = p; // thread-safe, even though the
								  // shared use_count is incremented
	{
		static std::mutex io_mutex;
		std::lock_guard<std::mutex> lk(io_mutex);
		std::cout << "local pointer in a thread:\n"
			<< "  lp.get() = " << lp.get()
			<< ", lp.use_count() = " << lp.use_count() << '\n';
	}
}

int main()
{
	std::shared_ptr<Base> p = std::make_shared<Derived>();

	std::cout << "Created a shared Derived (as a pointer to Base)\n"
		<< "  p.get() = " << p.get()
		<< ", p.use_count() = " << p.use_count() << '\n';
	std::thread t1(thr, p), t2(thr, p), t3(thr, p);
	p.reset(); // release ownership from main
	std::cout << "Shared ownership between 3 threads and released\n"
		<< "ownership from main:\n"
		<< "  p.get() = " << p.get()
		<< ", p.use_count() = " << p.use_count() << '\n';
	t1.join(); t2.join(); t3.join();
	std::cout << "All threads completed, the last one deleted Derived\n";
}



/*int main()
{
	char c1 = 1.57e27;
	//char c2{1.57e27};

	// decltype{x}, y;
	auto ret = f1(2, 3);
	std::cout << "ret: " << ret << std::endl;

	// eff<int, double>(2, 3.0);
//	std::shared_ptr<A> p1(p);
//	std::shared_ptr<A> p2(p);

	// std::cout << "ret2: " << ret2 << std::endl;
	std::cout << "finished: " << std::endl;

	shared_ptr<Base> base = shared_ptr<Base>(new Base());
//	shared_ptr<Base> derived = shared_ptr<Derived>(new Derived());
	shared_ptr<Base1> base1 = shared_ptr<Base1>(new Base1(base));
	shared_ptr<Base1> base2 = shared_ptr<Base1>(new Base1(base));

	std::cout << "base: " << std::endl;

    return 0;
}

*/

