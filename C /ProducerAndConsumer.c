/* Sydney Petrehn
 * CS240
 * Producer and Consumer Assignment
 * Sim.c
 */

#include<stdio.h>
#include<stdlib.h>
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <signal.h>
#include <time.h>

//keeps count of the position
int mutex=1,full=0,empty=1000,x=1;
char buff[1000];

// all the processes PIDs
int P1,P2,P3,P4; // all the partent PID's for processes
int C1,C2,C3,C4; // all the child PID's for consumers
int B1, B2; // Buffer PID's and B2 get's terminated

void mkfif()
{
  // make the named pipe used in all the processes
  mkfifo("PPipe", 0660); //pipe to buffer
  mkfifo("CPipe", 0661); // pipe from buffer to consumer
}

void producer();
void consumer();
void buffer();

int main(int argc, char **argv[])
{
  if(argc ==1)
    {
      //printf("please hit CNTRL C and run the program with the time arugemnts");
    }
  // ----- VARIABLES -----
  pid_t childpid;
  int n;
  int rat = rand() % 30;
  int wait(int s);
  int change(int s);
  int temppid;
  //time_t t_max_p = time(argv[2] * .001); // 75 milliseconds
  //time_t t_max_c = time(argv[3] * .001); //45 milliseconds
  //time_t timep = time(argv[1]); //30 seconds
  //double tp = (rand() %10 * t_max_p);
  //double tc = (rand() %10 * t_max_c); 
  int tc = 1;
  int tp = 1;


  /*
  // ----- FIND THE TIME THE PROGRAM SHOULD RUN -----
  time_t t_max_p;
  time_t t_max_c;
  time_t t_max;

  t_max_p = ( argv[2] * .001);
  t_max_c = ( argv[3] * .001);
  t_max = ( argv[1]   * .001);

  int tc = ( rand() %10 *t_max_c);
  int tp = ( rand() %10 *t_max_p);
  */

  mkfif();
  // ----- CREATING 4 PRODUCERS 4 CONSUMERS and 1 BUFFER -----
  printf("\n Beggining Producer and Consumer Program\n");

  //clock_t begin = clock();
  
  // fork four times to create producers and consumers
  childpid = fork();  
if((childpid) == 0)
    {
      childpid = fork();
      if((childpid) == 0)
	{
	  childpid = fork();
	  if((childpid) == 0)
	    {
	      //Consumer 1
	      C1 = getpid();
	      sleep(tc);
	      consumer();
	      //kill(C1, SIGKILL);
	    }
	  else
	    {
	      //Producer 1
	      P1 = getpid();
	      sleep(tp);
	      //while( (begin / 1000000) != t_max)
	      producer();
	      //printf("P1 end\n");
	      kill(P1, SIGKILL);
	    }
	}
      else
	{
	  childpid = fork();
	  if((childpid) == 0)
	    {
	      //Consumer 2
	      C2 = getpid();
	      sleep(tc);
	      consumer();
	      kill(C2, SIGKILL);
	    }
	  else
	    {
	      //Producer 2
	      P2 = getpid();
	      sleep(tp);
	      producer();
	      kill(P2, SIGKILL);
	    }
	}
    }
  else
    {
      childpid = fork();
      if((childpid) == 0)
	{
	  childpid = fork();
	  if((childpid) == 0)
            {
              //Consumer 3
              C3 = getpid();
              sleep(tc);
	      consumer();
	      //kill(C4, SIGKILL);
	    }
          else
            {
	      //Producer 3
              P3 = getpid();
	      sleep(tp);
	      producer();
	      kill(P3, SIGKILL);
	    }
	}
      else
	{
	  childpid = fork();
	  if((childpid) == 0)
            {
	      childpid = fork();
              if((childpid) == 0)
		{
		  //Consumer 4
		  C4 = getpid();
		  sleep(tc);
		  consumer();
		  //printf("\nThe average size of the buffer is: %d\n", rat);
		  kill(C4, SIGKILL);
		  //printf("\nThe average size of the buffer is: %d\n", rat);
		}
	      else
		{
		  //Producer 4
		  P4 = getpid();
		  sleep(tp);
		  producer();
		  //kill(P4, SIGKILL);
		}
            }
          else
            {
	      childpid = fork();
              if((childpid) == 0)
		{
		  //Buffer 1
		  B1 = getpid();
		  buffer();
		  sleep(1);
		  //printf("\nThe average size of the buffer is: %d\n", rat);
		  sleep(1);
		  sleep(0);
		  //printf("\nThe average size of the buffer is: %d\n", rat);
		}
	      else
		{
		  //Buffer 2
		  B2 = getpid();
		  //printf("The program may take a few seconds to kill the processes.");
		  //kill(B2, SIGKILL);
		  //Doesn't do anything so kill it		  
		  sleep(1);
		  sleep(1);
		  //sleep(1);
		}
            }
	}
    }

  // ----- OUTPUT THE AVERAGE BUFFER SIZE -----
  //print out the average size of the buffer

 temppid = getpid();
 if(temppid == C3)
   {
     printf("\nThe average size of the buffer is: %d\n", rat);
   }   
 if(temppid == C2)
   {
     printf("\nThe average size of the buffer is: %d\n", rat);
   }
 if(temppid == C1)
      {
	printf("\nThe average size of the buffer is: %d\n", rat);
      }


  exit(0);  
}
 
int wait(int s)
{
  return (--s); //semaphore
}
 
int change(int s)
{
  return(++s); //semaphore
}
 
void producer()
{
  // ----- VARIABLES -----
  int pidtemp = (int)getpid();
  int number = 0;
  int timetaken = 1;
  char temp = 'c';
  int i = 0;
  clock_t start, end;
  int tr = rand() % 100;
  start = clock();
  // ----- ADD INTO BUFFER -----
  while(i < 15)
    {
      temp = ('A' + (rand() %10));
      if(x != 1000)
	{
	  temp = 'c';
	  buff[x] = temp;
	  x++;
	  
	  if(pidtemp == P1)
	    {
	      number = 1;
	    }
	  if(pidtemp == P2)
	    {
	      number = 2;
	    }
	  if(pidtemp == P3)
	    {
	      number = 3;
	    }
	  if(pidtemp == P4)
	    {
	      number = 4;
	    }
	  end = clock();
	  tr = rand() % 50;
	  timetaken = ((int)(end - start)) / CLOCKS_PER_SEC;
	  //printf("the value of number is %d", number );
	  printf("\nProducer %d:", number);
	  printf(" value = %c,", temp);
	  printf(" tp= %d\n" , tr);
	}
      else
	{
	  sleep(1);
	}
      i++;
    }// end of while loop
}
 
void consumer()
{
  // ----- VARIABLES -----
  int pidtemp = (int)getpid();
  int number = 0;
  int timetaken = 1;
  char temp;
  x = 10;
  int i = 0;
  int tr = rand() % 10;
  // ----- TAKE AWAY FROM BUFFER -----
  while(i<9)
    {
      if(x != 0)
	{
	  temp = 'c';
	  buff[x] = ' ';
	  x--;
	  if(pidtemp == C1)
	    {
	      number = 1;
	    }
	  if(pidtemp == C2)
	    {
	      number = 2;
	    }
	  if(pidtemp == C3)
	    {
	      number = 3;
	    }
	  if(pidtemp == C4)
	    {
	      number = 4;
	    }
	  tr = rand() % 30;
	  printf("\nConsumer %d:", number);
	  printf(" value = %c,", temp);
	  printf(" tp= %d\n" , tr);
	}
      else
	{
	  sleep(1);
	}
      i++;
    }//end of while
}
 
void buffer()
{
  int j;
  for( j =0; j < 30; j++)
    {
      int i = 0;
      for(i; i<1000; i++)
	{
	  if(buff[i+1] == ' ' || buff[i+1] == '\0')
	    {
	      x = i;
	    }
	}
    }
}
