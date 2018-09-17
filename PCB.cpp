//------------------------------------------------------------------
#ifndef PCB_C
#define PCB_C
#include<iostream>
#include"PCB.h"
using namespace std;
//------------------------------------------------------------------


//------------------------------------------------------------------
PCB::PCB()      //default constructor 
{
  priority= id = 0;
  state = " ";
}
//------------------------------------------------------------------
PCB::PCB(int p, int i, string s)
{
  priority = p; //priority value
  id = i;       //ID value
  state = s;    //current PCB state
}
//------------------------------------------------------------------
readyQueue::readyQueue()
{
  count=0;
}
//------------------------------------------------------------------
bool readyQueue::isFull()
{
  return(count==20)?true:false; //ReadyQueue declared full if more than 20 entries
}
//------------------------------------------------------------------
bool readyQueue::isEmpty()
{
  return(count==0)?true:false; //check to see if queue is empty
}
//------------------------------------------------------------------
int readyQueue::searchPriority()
{
  int lowest;
  for(int i = 0; i < 20; i++) //sorts through ReadyQueue and finds first entry with "ready" state 
    {
      if(Queue[i].state=="ready")
	{
	  lowest = i;
	  break;
	}
    }
  for(int j =lowest+1;j<20;j++) //comapares "ready" state entries and holds item with lowest priority 
    {
      if(Queue[j].state=="ready")
	if(Queue[lowest].priority<Queue[j].priority)
	  lowest = lowest;
	else
	  lowest = j;
    }
  return lowest; //returns lowest priority "ready" state entry in ReadyQueue 
}
//------------------------------------------------------------------
void readyQueue::insertProc(PCB toInsert)
{
  if(isFull()) //checks if full before inserting
    return;
  else
    {
      for(int i=0; i<20; i++) //check to validate ID before insertion
        {
          if(Queue[i].id==toInsert.id)
            return;
	}
      for(int i=0; i<20; i++) //loop for insertiom, if inserted the state and count are changed accordingly
	if(Queue[i].state !="ready")
	  {
	    toInsert.state="ready";
	    Queue[i]=toInsert;
	    count++;
	    return;
	  }
    }
}
//------------------------------------------------------------------
void readyQueue::removeHighestProc(PCB& toMove)
{
  if(isEmpty()) //checks if queue is empty before removal attempt 
    return;
  else
    {
      int toDelete = searchPriority();
      Queue[toDelete].id=0;
      Queue[toDelete].state="running";
      toMove = Queue[toDelete];//provides space to pass by reference to another function if it was neccessary
      count--;
    }    
}
//------------------------------------------------------------------
int readyQueue::size()
{
  return count; 
}
//------------------------------------------------------------------
void readyQueue::displayQueue()
{
  for(int i=0; i<20; i++)
    {
      if(Queue[i].state == "ready")
	cout << Queue[i].id << ": " << Queue[i].priority << "\n"; //output is displayed in ID:Priority format
    }
}

#endif
