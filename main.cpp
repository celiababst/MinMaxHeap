#include "minmax.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

int main()
{
  ifstream infile;
  string fileName = "data.txt";
  infile.open(fileName);
  minmax heap;

  if(infile.is_open())
  {
    int val;
    string s;
    while(getline(infile, s, ','))
    {
      val = atoi(s.c_str());
      heap.insert(val);
    }
  }
  else
  {
    cout<<"File could not be opened!\n";
  }

  //--------------------------------MENU-------------------------
  int choice;
  while(choice!=6)
  {
  cout<<"Please choose one of the following commands:\n";
  cout<<"(1) Build heap\n";
  cout<<"(2) Insert\n";
  cout<<"(3) Delete\n";
  cout<<"(4) Print min level elements\n";
  cout<<"(5) Print max level elements\n";
  cout<<"(6) Exit\n";
  cin>>choice;

  if(choice==1)
  {
    heap.print();
  }
  else if(choice==2)
  {
    int val;
    cout<<"Enter the value to insert:\n";
    cin>>val;
    heap.insert(val);
    cout<<val<<" has been inserted successfully.\n";
  }
  else if(choice==3)
  {
    heap.removeRoot();
    cout<<"Root has been deleted successfully.\n";
  }
  else if(choice==4)
  {
    heap.printMin();
  }
  else if(choice==5)
  {
    heap.printMax();
  }
  else if(choice==6)
  {
    cout<<"Exiting...";
    return 0;
  }
  else
  {
    cout<<"Not a valid option! Try again.\n";
  }
  }

  return 0;
}
