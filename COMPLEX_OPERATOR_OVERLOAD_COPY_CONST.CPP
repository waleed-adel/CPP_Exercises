#include<iostream.h>
#include<stdlib.h>
#include<conio.h>



class Complex
{
 private:

 float real,img;


 public:

 float get_real();
 float get_img();
 void set_real(float r);
 void set_img(float i);
 void print();

 //operator overloading
 int operator == (Complex& x);
 Complex& operator = (Complex& x);
 Complex operator + (Complex& x);
 Complex operator + (float f);
 friend Complex operator + (float f, Complex& x);



 //constructor
 Complex()
 { real = img = 0; }	   //1st constructor takes nothing and do nothing

 Complex(float r, float i)       //2nd constructor takes real & imaginary and sets them to zero
 { real = r;  img = i; }

 //copy constructor
 Complex(Complex& x);

 //destructor
  ~ Complex (){}
  //{ cout << "DESTROYED!!"; }  it will print every time an object is terminated
};


 //copy constructor definition
 Complex :: Complex(Complex& x)
 { real=x.real;  img=x.img; }


 //operator overloading definitions
 Complex& Complex :: operator = (Complex& x)
 {
  real = x.real;
  img = x.img;
  return *this;
 }


 Complex Complex :: operator + (Complex& x)
 {
  return Complex (real+x.real , img+x.img);
 }


 Complex Complex :: operator + (float f)
 {
  Complex temp (real+f,img);
  return temp;
 }


 int Complex :: operator == (Complex& x)
 {
  return (real == x.real && img == x.img);
 }


 //function definitions
 float Complex :: get_real()    //(::)because fn definiton is not inside the class
 { return real; }


 float Complex :: get_img()
 { return img; }


 void Complex :: set_real(float r)
 { real = r; }


 void Complex :: set_img(float i)
 { img = i; }


 void Complex :: print()
 {
  if (real == 0)
  {
   if(img == 0)  cout<<"Complex = 0";
   else
	{
	 if(img < 0)       cout<<"Complex = "<<"-i"<<abs(img); //prints absolute of number
	 else if(img > 0)  cout<<"Complex = "<<"i"<<img;
	}
  }
  else
  {
   cout<<"Complex = "<<real;
   if(img < 0)       cout<<" - i"<<abs(img); //prints absolute of number
   else if(img > 0)  cout<<" + i"<<img;
  }
 }

  //Standalone fn.

Complex add_complex (Complex a,Complex b)
{
  Complex temp( (a.get_real()+b.get_real()) , (a.get_img()+b.get_img()) );
  return temp;
}


Complex sub_complex (Complex a,Complex b)
{
  Complex temp( (a.get_real()-b.get_real()) , (a.get_img()-b.get_img()) );
  return temp;
}

Complex operator + (float f,Complex& x)
{
  Complex temp;
  temp.real=f+x.real;
  temp.img=x.img;
  return temp;
}


  //main function

int main()
{
  Complex c1,c2;
  float r,i;
  int x;
  clrscr();
  cout<<"Please Enter C1"<<endl<<"C1.REAL: ";
  cin>>r;
  c1.set_real(r);
  cout<<"C1.IMAGINARY: ";
  cin>>i;
  c1.set_img(i);
  cout<<endl<<"Please Enter C2"<<endl<<"C2.REAL: ";
  cin>>r;
  c2.set_real(r);
  cout<<"C2.IMAGINARY: ";
  cin>>i;
  c2.set_img(i);
  cout<<endl<<"C3 after Copying C1 in it:";
  Complex c3(c1);
  c3.print();
  cout<<endl<<endl<<"Sum: ";
  c3 = c1 + c2;
  c3.print();
  cout<<endl<<endl<<"C1 + 3: ";
  c3=c1+3;
  c3.print();
  cout<<endl<<endl<<"3 + C1: ";
  c3=3+c1;
  c3.print();
  x = (c1 == c2);
  if (x)
  cout<<endl<<endl<<"C1 == C2";
  else
  cout<<endl<<endl<<"C1 != C2";
  getch();
 return 0;
}
