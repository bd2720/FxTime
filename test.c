#include <stdio.h>
#include "libfxtime.h"

void *testFunc(void *arg){
	if(arg == 0) return (void *) 0;
	long n = (long)arg;
	long sum = 0;
	for(long i = 0; i < n; i++){
		sum += i;
	}
	return (void *) sum;
}

int main(){
	long a = 1000;
	long s1 = (long) testFunc((void *)a);
	printf("s1=%ld\n", s1);

	long b = 5000000;
	long s2;
	float t = fxtime(testFunc, (void **)&s2, (void **)&b);
	printf("s2=%ld\n", s2);
	printf("t=%f\n", t);
	return 0;
}
