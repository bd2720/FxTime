#ifndef FXTIME_H
#define FXTIME_H

/*
   Times the execution of a function "f" defined like so:
	void *f(void *);
   Stores "f" return value in "retval", if non-null.
   Params "f" and "arg" must be non-null.
*/
float fxtime(void *(*f)(void *), void **retval, void **arg);

#endif
