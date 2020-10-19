#include<iostream.h>
#include<conio.h>
#include<stdlib.h>




 class Complex
{
 private:

 float real,img;


 public:


 //constructor
 Complex()
 { real = img = 0; }	 //1st constructor takes nothing and initialize to 0

 Complex(float r, float i)  //2nd constructor takes real & imaginary and sets them
 { real = r;  img = i; }

 //copy constructor
 Complex(Complex& x);

 //functions
 float get_real();
 float get_img();
 void set_real(float r);
 void set_img(float i);
 friend ostream& operator << (ostream& out, Complex& c);

 //destructor
  ~ Complex (){}
};


 //copy constructor definition
 Complex :: Complex(Complex& x)
 { real=x.real;  img=x.img; }


 //function definitions
 float Complex :: get_real()    //(::)because fn definiton is not inside the class
 { return real; }


 float Complex :: get_img()
 { return img; }


 void Complex :: set_real(float r)
 { real = r; }


 void Complex :: set_img(float i)
 { img = i; }


 //standalone functions
 ostream& operator << (ostream& out , Complex& c)  //print complex
 {
  if (c.real == 0)
   {
	if(c.img == 0)  out<<"0";
	else
	 {
	  if(c.img < 0)       out<<" -i"<<abs(c.img); //prints absolute of number
	  else if(c.img > 0)  out<<" i"<<c.img;
	 }
   }
   else
   {
	out<<c.real;
	if(c.img < 0)       out<<" - i"<<abs(c.img); //prints absolute of number
	else if(c.img > 0)  out<<" + i"<<c.img;
   }
  return out;
 }



template <class T>
class Stack
{
 private:

 int tos,size;
 static int counter;
 T* stk;


 public:

 //constructor
 Stack()
 {
  tos = 0;
  size = 10;
  stk = new T [size];
  counter++;
 }

 Stack(int s)
 {
  tos = 0;
  size = s;
  stk = new T [size];
  counter++;
 }


 //copy constructor
 Stack (Stack& s);


 //operator overloading
 Stack& operator = (Stack& s);


 //functions
 void push (T data);
 void pop (T& data);
 static int getCounter()  { return counter; }
 friend void viewContent(Stack& s);


 //destructor
  ~ Stack ()
 {
  if (stk)  delete [] stk;
  counter--;
 }
};


 //static variable definition
 template <class T>
 int Stack <T> :: counter = 0;


 //copy constructor
 template <class T>
 Stack <T> :: Stack (Stack<T>& s)
 {
  tos = s.tos;
  size = s.size;
  stk = new T [size];
  counter++;
 }

 //function definition
 template <class T>
 void Stack <T> :: push (T data)
 {
  if (tos == size)
  cout<<"\nSTACK IS FULL!!";
  else
  {
   stk[tos] = data;
   tos++;
  }
 }

  template <class T>
  void Stack <T> :: pop (T& data)
  {
   if (!tos)
   cout<<"STACK IS EMPTY!!";
   else
   {
	tos--;
	stk[tos]=data;
   }
  }



  //operator overloading
  template <class T>
  Stack<T>& Stack<T> :: operator = (Stack<T>& s)
  {
   if (stk)  delete []stk;
   size=s.size;
   tos=s.tos;
   stk = new T [size];
   for(int i=0;i<tos;i++)
   stk[i]=s.stk[i];
   return(*this);
  }

  //standalone fn.
  template <class T>
  void viewContent(Stack<T>& s)
  {
	for (int i=0;i<s.tos;i++)
	cout<<s.stk[i];
  }




//////////////////////////////////////////////////////////////////////////////

//main fn.

void main()
{
clrscr();
Stack<int>s1;
cout<<"Stack<int>s1\nCounter of Stack<int>: ";
cout<<s1.getCounter()<<endl;
//cout<<Stack<int> :: getCounter()<<endl;
Stack<float>s2;
cout<<"\nStack<float>s2\nCounter of Stack<float>: ";
cout<<s2.getCounter()<<endl;
Stack<Complex>s3,s4;
cout<<"\nStack<Complex>s3,s4\nCounter of Stack<Complex>: ";
cout<<Stack<Complex> :: getCounter()<<endl;
{
 Stack<int>s5;
 cout<<"\n{\n Stack<int>s5\n Counter of Stack<int>: ";
 cout<<s5.getCounter()<<"\n}\n";
}
cout<<"\nCounter of Stack<int>: ";
cout<<Stack<int> :: getCounter()<<endl;
Stack<char>s6,s7,s8;
cout<<"\nStack<char>s6,s7,s8\nCounter of Stack<char>: ";
cout<<s6.getCounter();
getch();
}