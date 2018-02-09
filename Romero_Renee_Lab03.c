/* 
 CMPS 3600 OS
 Romero Renee
 Lab 03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

int array1[] ={ 10, 20, 30, 40, 50};
int array2[]= { 0, 2, 3, 4, 5};
int rndm1;
int rndm2;
int quotient;

void error_handler(int signum)
{
    printf("%d / %d = %d \n", array1[rndm1], array2[rndm2], quotient);
    printf("Numbers cannot be divided by 0 \n");
    printf("Program will now be Terminated. Goodbye.\n");
    raise(SIGTERM);
}

void division_handler(int signum)
{
    srand(time(NULL));
    rndm1 = rand() % 5;
    rndm2 = rand() % 5;
    signal(SIGFPE, error_handler);
    alarm(1);
    quotient = array1[rndm1] / array2[rndm2];
    printf("%d / %d = %d \n", array1[rndm1], array2[rndm2], quotient);

}
int main()
{

    while(1)
    {
        signal(SIGALRM, division_handler);
        alarm(1);
        sleep(1);
    }
  return 0;
}
