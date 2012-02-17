#include "ThreadPool.H"

using Concurrent::ThreadPool;

ThreadPool::ThreadPool(const int threadCount) :
	_threadCount(threadCount),
	_running(true) {

	for (int i = 0; i < _threadCount; i++) {
		boost::thread *t = new boost::thread(boost::bind(&ThreadPool::lookForAJob,
		                                                 this));
		_threads.add_thread(t);
	}
}

ThreadPool::~ThreadPool() {
	_threads.join_all();
}

void ThreadPool::execute(boost::function<void(void)> func) {
	if (_running == false) {
		return;
	}
	_tasks.put(func);
}

void ThreadPool::shutdown() {
	fillWithPoison();
	_threads.join_all();
}

void ThreadPool::poisoning() {
	_running = false;
}

void ThreadPool::fillWithPoison() {
	for (int i = 0; i < _threadCount; i++) {
		_tasks.put(boost::bind(&ThreadPool::poisoning, this));
	}
}

void ThreadPool::lookForAJob() {
	while(_running) {
		boost::function<void ()> f = _tasks.take();
		f();
	}
}
