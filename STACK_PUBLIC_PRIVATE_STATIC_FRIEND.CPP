#include<iostream.h>
#include<stdlib.h>
#include<conio.h>


class Stack
{
  // variables
  private:

  int size,tos;
  int* stk;
  static int counter;  //initialized once and remains in memory with last value

  //Functions
  public:

  //cosntructors
  Stack(int size); //default parameter..if size not entered by user it will be initilaized to 10

  //Functions prototype
  void push (int x);
  void pop (int &data);
  void peak(Stack s);
  int empty_stack();
  int full_stack();
  static int getCounter();      //allows access to static variable
  friend void displayStack(Stack s);    //friend fn. allow it to operate on any object created of class Stack and defined as a standalone fn.

  //Destructors
  ~ Stack();
};

 //Static variables definition/init
 int Stack :: counter = 0;


 //Constructor Definition
 Stack :: Stack(int size = 10)
 {                       //we can change fn. argument name instead of using this->
  this -> size = size;  //this-> is used when fn. argument name is same as an object member
  stk = new int[size];  //new is an operator same as fn. malloc..new variable type [number] allocates (variable type*number)
  tos = 0;
  counter++;
 }

 //Destructor Definition
  Stack :: ~ Stack()
  {
   if(stk) //if data(stack)is not allocated 'new' operator will return NULL
   delete []stk;
   counter--;
  }



 //Fn. Definitions

 int Stack :: getCounter()
 { return counter; }


 int Stack :: empty_stack()
 { return !tos; }   //if empty return 1 (true) else returns zero


 int Stack :: full_stack()
 { return tos==size; }   //if full return 1


 void Stack :: push (int data)
 {
  if( !full_stack() )    //if stack is full it won't push
  {
   stk[tos] = data;
   tos ++;
  }
 }


 void Stack :: pop (int &data) //call by reference..operations done directly on variable inside memory without use of pointers
 {
  if( !empty_stack() )  //if stack is empty it won't pop
  {
   tos --;
   data = stk[tos];  //it won't delete data popped it will just change tos and data will be updated with next data to be popped
  }
 }

 void Stack :: peak(Stack s)
 {
   cout<<"Last Element is: "<<s.stk[tos-1]<<endl;
 }

 //standalone function

 void displayStack(Stack s)
 {
  int i;
  for (i=0;i<s.tos;i++)
  {
	cout<<s.stk[i]<<endl;
  }

 }

 //main fn.

int main ()
{
 clrscr();
 int i,size,temp[10];
 Stack s(size);
 s.push(1);
 s.push(2);
 s.push(3);
 s.push(5);
 cout<<"Content of Stack"<<endl;
 displayStack(s);  //didn't use s.displayStack cuz it's friendly fn.
 cout<<endl;
 s.peak(s);
 cout<<endl<<"Contents Popped"<<endl;
 for (i=0;i<2;i++)
 {
  s.pop(temp[i]);
  cout<<temp[i]<<endl;
 }
 getch();
 return 0;
}


