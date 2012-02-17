#include "ThreadPool.H"

#include <boost/function.hpp>

#include <iostream>

using std::cout;
using std::endl;

void run(int x) {
	cout << "This is the job:" << x << endl;
}

int main() {
	Concurrent::ThreadPool threadPool(11);
	for (int x = 0; x < 1000; x++) {
		threadPool.execute(boost::bind(&run, x));
	}
	threadPool.shutdown();
	return 0;
}
