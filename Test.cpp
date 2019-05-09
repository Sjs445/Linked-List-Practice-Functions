#include <iostream>
#include "IntegerList.cpp"

using namespace std;

int main() {
IntegerList list;

list.addFront(1);
list.addFront(4);
list.addFront(10);
list.addFront(2);
list.addFront(6);
list.addFront(7);
list.addFront(2);

list.print();
list.AddAtPosition(15, 2);
cout<<"Adding 15 at position 2 "<<endl;
list.print();
cout<<"Adding 25 to tail "<<endl;
list.addTail(25);
list.print();

cout<<"Position where 10 is "<<list.findNum(10);

cout<<"\nNumer of times 2 appears "<<list.numofTimes(2);

cout<<"Reversing list: "<<endl;
list.reverseList();
list.print();
cin.get();
	return 0;
}
