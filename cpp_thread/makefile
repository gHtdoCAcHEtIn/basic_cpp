all: threads_test threads_jobs_test threads_mutex_test threads_mutex_jobs_test

threads_test: threads_test.cpp
	g++ \
	threads_test.cpp -std=c++11 \
	-lpthread \
	-o threads_test

threads_jobs_test: threads_jobs_test.cpp
	g++ \
	threads_jobs_test.cpp -std=c++11 \
	-lpthread \
	-o threads_jobs_test

threads_mutex_test: threads_mutex_test.cpp
	g++ \
	threads_mutex_test.cpp -std=c++11 \
	-lpthread \
	-o threads_mutex_test

threads_mutex_jobs_test: threads_mutex_jobs_test.cpp
	g++ \
	threads_mutex_jobs_test.cpp -std=c++11 \
	-lpthread \
	-o threads_mutex_jobs_test

clean:
	rm threads_test
	rm threads_jobs_test
	rm threads_mutex_test
	rm threads_mutex_jobs_test
	

