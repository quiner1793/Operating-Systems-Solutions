#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <string.h>
#include <sys/resource.h>

int main(){
	int size = 1024*1024*10;
        struct rusage usage;
    for (int i = 0; i < 20; i++){
        int* mem = calloc(size / sizeof (int), sizeof(int));
	memset(mem, 0, size);
	
	 getrusage(RUSAGE_SELF, &usage);
        printf("time_t : %li; ru_maxrss : %ld; ru_ixrss : %ld; ru_idrss : %ld; ru_isrss : %ld\n", usage.ru_stime.tv_sec, usage.ru_maxrss, usage.ru_ixrss, usage.ru_idrss, usage.ru_isrss);
        sleep(1);
    }
    printf("Finish allocation\n");

    return 0;
}
