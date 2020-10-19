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


  public:

  //cosntructors
  Stack(int size); //default parameter..if size not entered by user it will be initilaized to 10

  //copy constructor
  Stack (Stack& s); //for copying one stack contents into another


  //Functions prototype
  void push (int x);
  void pop (int &data);
  void peak(Stack s);
  int empty_stack();
  int full_stack();
  static int getCounter();      //allows access to static variable
  friend void displayStack(Stack s);    //friend fn. allow it to operate on any object created of class Stack and defined as a standalone fn.

  //operator overloading
  Stack& operator = (Stack& s);
  Stack  operator + (Stack& s);

  //Destructors
  ~ Stack();

};//end of class


 //Static variables definition/init
 int Stack :: counter = 0;


 //Constructor Definition
 Stack :: Stack(int size = 10)
 {                       //we can change fn. argument name instead of using this->
  this -> size = size;  //this-> is used when fn. argument name is same as an object member
  stk = new int[this->size];  //new is an operator same as fn. malloc..new variable type [number] allocates (variable type*number)
  tos = 0;
  counter++;
 }

 //Copy Constructor Definition
 Stack :: Stack (Stack& s)
 {
  tos=s.tos;
  size=s.size;
  stk=new int[size];
  for(int i=0;i<tos;i++)
  {
   stk[i]=s.stk[i];
  }
 }



 //Destructor Definition
  Stack :: ~ Stack()
  {
   if(stk) //if data(stack)is not allocated 'new' operator will return NULL
   delete []stk;
   counter--;
  }


 //operator overloading definitions
 Stack& Stack :: operator = (Stack& s)
 {
  tos=s.tos;
  size=s.size;
  delete []stk;   //delete previous allocation to allocate and assign new values to it
  stk= new int[size];
  for (int i=0;i<tos;i++)
  {
   stk[i]=s.stk[i];
  }
 return *this; //*this returns what the address in this is pointing to (object which this is pointing to)
 }


 Stack Stack :: operator +(Stack& s)
 {
  Stack temp;
  int i=0;
  temp.tos = tos + s.tos;
  temp.size = size + s.size;
  temp.stk= new int [temp.size];
  for (i=0;i<tos;i++)
  {
   temp.stk[i]=stk[i];
  }
  for (i=0;i<s.tos;i++)
  {
   temp.stk[i+tos]=s.stk[i];
  }
   return temp;
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
	cout<<s.stk[i]<<"\t";
  }
 }

 //main fn.

int main ()
{
 clrscr();
 int i;
 Stack s1,s2;
 s1.push(1);
 s1.push(2);
 s1.push(3);
 s1.push(4);
 cout<<"Content of S1:"<<endl;
 displayStack(s1);  //didn't use s.displayStack cuz it's friendly fn.
 cout<<endl;
 s2.push(5);
 s2.push(6);
 s2.push(7);
 s2.push(8);
 cout<<endl<<"Contents of S2:"<<endl;
 displayStack(s2);
 Stack s3(s1);
 cout<<endl<<endl<<"Stack S3 after Copying S1 into it:"<<endl;
 displayStack(s3);
 cout<<endl;
 s3 = s1 + s2;
 cout<<endl<<endl<<"S1 + S2 concatenated:"<<endl;
 displayStack(s3);
 getch();
 return 0;
}
