CC      = g++
CFLAGS  = -I/usr/local/include/boost/ -O3 -Wall -Werror -pipe -ggdb
LDFLAGS = -lpthread -lboost_thread -ggdb

all: thread_pool_test clean

thread_pool_test: thread_pool_test.cpp ThreadPool.o
	$(CC) -o $@ $^ $(LDFLAGS)

ThreadPool.o: ThreadPool.cpp
	$(CC) -c $(CFLAGS) $<

clean:
	rm *.o
