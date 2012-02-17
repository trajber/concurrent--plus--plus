#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include <boost/thread.hpp>
#include <boost/function.hpp>
#include <boost/bind.hpp>

#include "BlockedQueue.H"

namespace Concurrent {
	class ThreadPool {
	public:
		ThreadPool(const int threadCount);
		~ThreadPool();

		void execute(boost::function<void(void)> func);

		void shutdown();
	private:
		void lookForAJob();
		void fillWithPoison();
		void poisoning();

		BlockedQueue<boost::function<void ()> > _tasks;
		int _threadCount;
		boost::thread_group _threads;
		bool _running;
	};
}

#endif /* __THREAD_POOL_H__ */
