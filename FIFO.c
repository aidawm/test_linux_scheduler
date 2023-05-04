#include <sched.h>
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  printf("Setting SCHED_FIFO and priority to %d\n",atoi(argv[1]));
  struct sched_param param;
  param.sched_priority = atoi(argv[1]);
  if (sched_setscheduler(getpid(), SCHED_FIFO, &param) != 0) {
		printf("Failed to set the scheduler\n");
	}	   	
  int n = 0;
  while(1) {
    n++;
    if (!(n % 10000000)) {
      printf("FIFO Prio %d running (n=%d)\n",argv[1] ,n);
    }
  }
    
return 0;
}