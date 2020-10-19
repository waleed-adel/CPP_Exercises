#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

class Base
{
 protected:

 int a,b;


 public:

 //constructors
 Base () { cout<<"Base Constructor\n"; }  //default constructor
 Base (int x) { a = b = x; }

 //copy constructor
 Base (Base& base) { a = base.a; b = base.b; }


 //operator overloading
 Base& operator = (Base& base)
 {
  a = base.a;
  b = base.b;
  return *this;
 }

 //functions
 void setA (int a)         { this -> a = a; }
 void setB (int b)         { this -> b = b; }
 int getA ()               { return a;      }
 int getB ()               { return b;      }
 int calculate_sum ()      { return a + b;  }

 //destructor
 ~ Base () { cout<<"Base Destructor\n"; }
};


class Derived : public Base
{
 private:

 int c;


 public:

 //cosntructors
 Derived () { cout<<"Derived Constructor\n"; }   //default constructor
 Derived (int x)         { c = x; }


 //copy constructor
 Derived (Derived& d)    { c = d.c; }

 //operator overloading
 Derived& operator = (Derived& d)
 {
  c = d.c;
  return *this;
 }

 //functions
 void setC (int x)       { c = x; }
 int getC ()             { return c; }

 //override function
 int calculate_sum ()    { return ( (Base :: calculate_sum()) + c ); }

 //destructor
 ~ Derived () { cout<<"Derived Destructor\n"; }
};


int main ()
{
 Base b(10);
 cout<<"Base (10) : "<<"("<<b.getA()<<","<<b.getB()<<")\n";
 b.setA(5);
 b.setB(10);
 cout<<"Base (5,10): "<<"("<<b.getA()<<","<<b.getB()<<")\n";
 cout<<"Sum (A+B): "<<b.calculate_sum()<<endl<<endl;
 Derived d(5);
 d.setA(5);
 d.setB(10);
 cout<<"Derived (5): "<<d.getC()<<endl;
 cout<<"Sum (A+B+C): "<<d.calculate_sum()<<endl;
 getch();
 return 0;
}