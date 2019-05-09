#include <iostream>
#include "IntegerList.h"

IntegerList::IntegerList()
{
    head=NULL;
}

IntegerList::~IntegerList()
{
    for(int i=0; i<size(); i++)
    {
        removeFront();
    }
}

int& IntegerList::front()
{
    return head->getElement();
}

void IntegerList::addFront(int e)
{
    IntListNode * node = new IntListNode(e, head);
    head=node;
}

void IntegerList::removeFront()
{
    IntListNode * temp = head;
    head=head->getNext();
    delete temp;
    temp=NULL;
}

void IntegerList::print()
{
    IntListNode * temp = head;
    while(temp!=NULL)
    {
        cout<<temp->getElement()<<" ";
        temp=temp->getNext();
    }
    cout<<endl;
}

int IntegerList::size() const
{
    IntListNode * temp = head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->getNext();
    }
    return count;
}

void IntegerList::AddAtPosition(int e, int p)
{
    if(head==NULL)
    {
        addFront(e);
        return;
    }

    IntListNode * curr=head;
    IntListNode * prev=NULL;

    for(int i=0; i<size(); i++)
    {
        prev=curr;
        curr=curr->getNext();
        if(i==p-1)
        {
            IntListNode * newNode = new IntListNode(e, curr);
            prev->setNext(newNode);
            return;
        }
    }
}

int IntegerList::sum()
{
    IntListNode * node = head;
    return(sum(node));
}

int IntegerList::sum(IntListNode * node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        return(node->getElement()+sum(node->getNext()));
    }
    
}

double IntegerList::avg()
{
    return(double(sum())/double(size()));
}

void IntegerList::addTail(int num)
{
    IntListNode * temp = head;
    addTail(temp, num);
}

void IntegerList::addTail(IntListNode * node, int num)
{
    if(node->getNext()==NULL)
    {
        IntListNode * newNode = new IntListNode(num, NULL);
        node->setNext(newNode);
        return;
    }
    else
    {
        addTail(node->getNext(), num);
    }
}

int IntegerList::findNum(int num)
{
    IntListNode * temp = head;
    return(findNum(num, temp));
}

int IntegerList::findNum(int num, IntListNode * node)
{
    if(node==NULL || node->getElement()==num)
    {
        return 0;
    }
    else
    {
        return(1+findNum(num, node->getNext()));
    }
}

int IntegerList::numofTimes(int num)
{
    IntListNode * temp = head;
    return(numofTimes(num, temp));
}

int IntegerList::numofTimes(int num, IntListNode * temp)
{
    if(temp==NULL)
    {
        return 0;
    }

    if(temp->getElement()==num)
    {
        return(1+numofTimes(num, temp->getNext()));
    }
    else
    {
        return(0+numofTimes(num, temp->getNext()));
    }
    
}

void IntegerList::reverseList()
{
    IntListNode * curr=head;
    IntListNode * prev=NULL;
    IntListNode * next=NULL;

    while(curr!=NULL)
    {
        next=curr->getNext();
        curr->setNext(prev);
        prev=curr;
        curr=next;
    }
    head=prev;
}