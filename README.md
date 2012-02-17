concurrent++
=======

**concurrent++** is a very simple library for deal with concurrency problems in C++
It still under development and so far it only have two classes: a fixed thread-pool and a BlockedQueue.

Pre-requisites
-----------------

- C++ compiler
- make
- Boost libraries

Build
-----------------
Just type 'make' and the magic happens

BlockedQueue
---------
A simple thread-safe blocked queue.
The method take() waits if no element are present on this queue

ThreadPool
---------
A very simple fixed thread-pool. An exemple of its usage can be found at thread_pool_test.cpp file

Limitations
-------------
Many limitations. Use it at your own risk ;-)

Copyright and License
---------------------
<pre>
I don't like licenses, because I don't like having to worry about all this
legal stuff just for a simple piece of software I don't really mind anyone
using. But I also believe that it's important that people share and give back;
so I'm placing this work under the following license.


BOLA - Buena Onda License Agreement (v1.1)
------------------------------------------

This work is provided 'as-is', without any express or implied warranty. In no
event will the authors be held liable for any damages arising from the use of
this work.

To all effects and purposes, this work is to be considered Public Domain.


However, if you want to be "buena onda", you should:

1. Not take credit for it, and give proper recognition to the authors.
2. Share your modifications, so everybody benefits from them.
3. Do something nice for the authors.
4. Help someone who needs it: sign up for some volunteer work or help your
   neighbour paint the house.
5. Don't waste. Anything, but specially energy that comes from natural
   non-renewable resources. Extra points if you discover or invent something
   to replace them.
6. Be tolerant. Everything that's good in nature comes from cooperation.
</pre>
