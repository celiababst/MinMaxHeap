#include "minmax.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

minmax::minmax()
{
  heap = new int[127];
  size = 127;
}

minmax::~minmax()
{

}

void minmax::insert(int val)
{
  bool inserted = false;
  if(heap[0]==0)
  {
    heap[0] = val;
    inserted = true;
  }
  else
  {
    while(inserted == false)
    {
      for(int i = 0; i < size; i++)
      {
        int child1 = ((2*i) + 1);
        int child2 = ((2*i) + 2);
        if(heap[child1]==0) //child 1
        {
          heap[child1] = val;
          inserted = true;
          break;
        }
        if(heap[child2]==0)//child 2
        {
          heap[child2] = val;
          inserted = true;
          break;
        }
      }
    }
  }
  buildHeap();
}

void minmax::buildHeap()
{
  bool swapped = true;
  while(swapped)
  {
  swapped = false;
  int currentlevel = 0;
  int nodesPerLevel = 0;
  for(int i = 0; i < size; i++) //this is doing more than it needs to; looking at every single int
  {                           //and also could be going beyond what the size of the array is at this point
    int parent = floor((i-1)/2); //parent index
    if(parent<0) {parent = 0;}
    if((heap[parent]==0) && (heap[i]!=0))
    {  //if parent is empty & child is not
      int temp = heap[i];
      heap[i] = heap[parent];
      heap[parent] = temp;
      swapped = true;
    }
    else if(currentlevel%2==0) //if on a min level
    {
      if((heap[parent]<heap[i])&&(heap[i]!=0))
      {  //if parent is less than child & child is not empty
        int temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;
        swapped = true;
      }
    }
    else //if on a max level
    {
      if((heap[parent]>heap[i])&&(heap[i]!=0))
      {  //if parent is greater than child & child is not empty
        int temp = heap[i];
        heap[i] = heap[parent];
        heap[parent] = temp;
        swapped = true;
      }
    }
    if((i-parent)==nodesPerLevel) //if the number of nodes is equal to the currentlevel
    {
      currentlevel++; //then move up next level
      nodesPerLevel = pow(2, currentlevel);
    }
  }
  }
  grandparentSwap();
}

void minmax::grandparentSwap()
{
  bool swapped = true;
  while(swapped)
  {
  swapped = false;
  int currentlevel = 2;
  int nodesPerLevel = 4;
  for(int i = 3; i < size; i++)
  {
    int parent = floor((i-1)/2);
    int grandparent = floor((parent-1)/2);
    if(grandparent<0) {grandparent=0;}
    if(heap[i]==0) {break;}
      if(currentlevel%2==0)//make sure the min is bigger than previous mins
      {
        if(heap[grandparent]>heap[i])
        {
          int temp = heap[i];
          heap[i] = heap[grandparent];
          heap[grandparent] = temp;
          swapped = true;
        }
      }
      else //make sure max is small than previous maxes
      {
        if(heap[grandparent]<heap[i])
        {
          int temp = heap[i];
          heap[i] = heap[grandparent];
          heap[grandparent] = temp;
          swapped = true;
        }
      }
      if((i-parent)==nodesPerLevel) //if the number of nodes is equal to the currentlevel
      {
        currentlevel++; //then move up next level
        nodesPerLevel = pow(2, currentlevel);
      }
    }
  }
}

void minmax::removeRoot()
{
  heap[0] = 0;
  buildHeap();
}

void minmax::printMin()
{
  int currentlevel = 0;
  int currentNumNodes = 0;
  int powNum = 0;
  for(int i = 0; i < size; i++)
  {
    currentNumNodes++;
    int levelNumNodes = pow(2, powNum);
    int nodesRemaining = levelNumNodes - currentNumNodes;
    if(currentlevel%2==0) //if we're on a min level
    {
      cout<<heap[i];
      if(nodesRemaining==0)
      {
        cout<<"\n";
        currentNumNodes=0;
        currentlevel++;
        powNum++;
      }
      else
      {
        cout<<" : ";
      }
    }
    else
    {
      if(nodesRemaining==0)
      {
        currentNumNodes=0;
        currentlevel++;
        powNum++;
      }
    }
  }
}

void minmax::printMax()
{
  int currentlevel = 0;
  int currentNumNodes = 0;
  int powNum = 0;
  for(int i = 0; i < size; i++)
  {
    currentNumNodes++;
    int levelNumNodes = pow(2, powNum);
    int nodesRemaining = levelNumNodes - currentNumNodes;
    if((currentlevel%2==1)&&(currentlevel!=0))
    {
      cout<<heap[i];
      if(nodesRemaining==0)
      {
        cout<<"\n";
        currentNumNodes=0;
        currentlevel++;
        powNum++;
      }
      else
      {
        cout<<" : ";
      }
    }
    else
    {
      if(nodesRemaining==0)
      {
        currentNumNodes=0;
        currentlevel++;
        powNum++;
      }
    }
  }
}

void minmax::print()
{
  int currentlevel = 0;
  int currentNumNodes = 0;
  int powNum = 0;
  for(int i = 0; i < size; i++)
  {
    cout<<heap[i];
    currentNumNodes++;
    int levelNumNodes = pow(2, powNum);
    int nodesRemaining = levelNumNodes - currentNumNodes;
    if(nodesRemaining==0)
    {
      cout<<"\n";
      currentNumNodes=0;
      currentlevel++;
      powNum++;
    }
    else
    {
      cout<<" : ";
    }
  }
}
