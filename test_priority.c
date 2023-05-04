#include <sched.h>
#include <stdio.h>
#include <time.h>
#include <sys/resource.h>

int main(int argc, char **argv)
{
  printf("Setting SCHED_OTHER and priority to %d\n",atoi(argv[1]));
  struct sched_param param;
  setpriority(PRIO_PROCESS, 0, atoi(argv[1]));
  sched_setscheduler(0, SCHED_OTHER, &param);
  
  for(int i=0;i<5;i++){
  int n = 1000000000;
  while(n>0) {

    if (!(n % 10000000)) {
      printf("%s OTHER Prio %d running (n=%d)\n",argv[2], atoi(argv[1]),n);
    }
    n--;
  }}

  printf("time : %ld",time(NULL));
  return 0;
}
