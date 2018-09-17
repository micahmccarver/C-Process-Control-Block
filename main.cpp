
//-------------------------------------------------------------------------------------------
#ifndef main_C
#define main_C
#include<iostream>
#include"PCB.h"
#include<stdlib.h>
#include <ctime>
#include <cstdio>
using namespace std;
//-------------------------------------------------------------------------------------------


main()
{
  cout<<"Brandon Holman\n";
  cout<<"Micah McCarver\n";
  PCB toMove;  //provides a holder to move PCB from ready queue, if needed
  
  //begin test 1
  PCB table1[20]; //establish that the table and readyqueue are both created
  readyQueue q1;
  for(int i=0;i<20;i++)
    table1[i]= PCB(i+1, i+1, "new"); //fill up PCB while assigning new entries with status new 
  
  q1.insertProc(table1[4]); //enter 5,1,8,11 as per directions 
  q1.insertProc(table1[0]);
  q1.insertProc(table1[7]);
  q1.insertProc(table1[10]);
  q1.displayQueue();
  
  cout<<"removing highest prioity\n"; //program removes highest priority, established by lowest priority number (ie 1 has the highest priority)
  q1.removeHighestProc(toMove);
  q1.displayQueue();
  cout<<"removing highest prioity\n";
  q1.removeHighestProc(toMove);
  q1.displayQueue(); //program continues to remove highest priroity and display itself after removal 
  
  cout<<"adding new processes\n";
  
  q1.insertProc(table1[2]); //insert 3,7,2,12,9 as per directions
  q1.insertProc(table1[6]);
  q1.insertProc(table1[1]);
  q1.insertProc(table1[11]);
  q1.insertProc(table1[8]);
  q1.displayQueue();
  
  int qCount=q1.size();
  for(int i=0;i<qCount;i++) //loop continues to remove highest priority while displaying the queue after each individual removal
    {
      cout<<"removing highest prioity\n";
      q1.removeHighestProc(toMove);
      q1.displayQueue();
    }
  //end test 1
  

  //begin test 2
  PCB table2[20];
  readyQueue q2; //establish table2 and the second readyqueue for the second test. seperate from test 1 

  srand(time(0));
  for(int i=0;i<20;i++)
    table2[i]=PCB((rand()%50+1),i+1, "new"); //randomizes all priority values
  do{
    q2.insertProc(table2[(rand()%20+1)-1]); //inserts PCB from randomly chosen array slots from table to queue
  }while(q2.count != 10);

  clock_t start = clock(); //begins clock for calculating total time running

  for(int i=0;i<1000000;i++) //runs program 1000000 times while randomly deciding to add or remove a process with equal probability 
    {
      int flag = (rand()%2+1);
      if(flag==1)
	q2.insertProc(table2[(rand()%20+1)-1]);
      if(flag==2)
	q2.removeHighestProc(toMove);
    }
  printf("1000000 Loops-Time elapsed: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC); //prints the total time for the program
  //end test 2


  return 0;
}
#endif
