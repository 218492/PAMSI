#include <iostream>

#include "node.hpp"
#include "list.hpp"
#include "stack.hpp"

using namespace std;

int Stack::push(int value)
{
  return List::add(value,List::size()+1);
}

Node Stack::pop()
{
  return List::remove(List::size());
}

int Stack::size()
{
  return List::size();
}

void Stack::display()
{
  List::display();
}

/*
Stack::~Stack()
{
  while(top!=NULL)
    {
      Node *tmp=top;
      top=top->next;
      delete tmp;
    }
}
*/
