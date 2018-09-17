/*********************************************************************************************

File: PCB.h, header file
Name: Micah McCarver and Brandon Holman
Date Written: 9/11/17 - 9/15/17
CS433 - Assignment 1 - Priority Queue of Processes
Description: Program that is designed to create a PCB and ReadyQueue. Two tests possible.
No special instructions or assumptions

*********************************************************************************************/

//------------------------------------------------------------------
#ifndef PCB_H
#define PCB_H
#include<iostream>
using namespace std;
//------------------------------------------------------------------

class PCB
{
 public:
  int priority;
  int id;
  string state;
 public:
  PCB();
  PCB(int p,int id,string s);
};

class readyQueue
{
 public:
  PCB Queue[20];
  int count;
 public:
  readyQueue();
  
  //PURPOSE: checks to see if queue is full
  bool isFull();

  //PURPOSE: checks to see if queue is empty
  bool isEmpty();

  //PURPOSE: function to sort through queue and find lowest priority avaliable 
  int searchPriority();

  //PURPOSE: to insert a process into queue
  //PARAMETER: placeholder variable for item to be added
  void insertProc(PCB insert);
  
  //PURPOSE: removes highest priority process
  //PARAMETER: ToMove is variable to be removed 
  void removeHighestProc(PCB&);
  
  //PURPOSE: returns count variable to define size of queue
  int size();
  
  //PURPOSE: Prints queue
  void displayQueue();
};
#endif
