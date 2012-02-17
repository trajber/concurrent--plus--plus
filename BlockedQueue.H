#ifndef __CONCURRENT_BLOCKED_QUEUE_H__
#define __CONCURRENT_BLOCKED_QUEUE_H__

#include <boost/thread/condition_variable.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

#include <vector>

using std::vector;

namespace Concurrent {
	template<typename T>
	class BlockedQueue {
	public:
		void put(const T &t) {
			boost::lock_guard<boost::mutex> lock(_mut);
			_elements.push_back(t);
			_cond.notify_all();
		}

		T take() {
			boost::unique_lock<boost::mutex> lock(_mut);
			while (_elements.empty()) {
				_cond.wait(lock);
			}

			T t = _elements.front();
			_elements.erase(_elements.begin());
			return t;
		}

		bool empty() const {
			boost::lock_guard<boost::mutex> lock(_mut);
			return _elements.empty();
		}

		size_t size() const {
			boost::lock_guard<boost::mutex> lock(_mut);
			return _elements.size();
		}

	private:
		boost::mutex _mut;
		boost::condition_variable _cond;
		vector<T> _elements;
	};
}

#endif
