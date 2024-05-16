#include <sys/time.h>
#include "libfxtime.h"

// compute elapsed time between 2 timevals
#define TIME(t1,t2) ((t2).tv_sec-(t1).tv_sec)+(((t2).tv_usec-(t1).tv_usec)/1e6)

// times execution of a function
float fxtime(void *(*f)(void *), void **retval, void **arg){
	if(arg == 0 || f == 0) return -1.0;
	struct timeval t0, tf;
	void *ret;
	gettimeofday(&t0, 0);
	ret = f(*arg);
	gettimeofday(&tf, 0);
	if(retval != 0) *retval = ret;
	return TIME(t0,tf);
}

#undef TIME
