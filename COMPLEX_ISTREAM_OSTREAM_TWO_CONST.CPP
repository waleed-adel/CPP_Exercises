#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>



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
 operator float ();
 Complex& operator = (Complex& x);
 Complex operator + (Complex& x);
 Complex operator + (float f);
 Complex& operator ++ ();
 Complex operator ++ (int dummy);
 Complex& operator () (float r);
 Complex& operator () (float r,float i);
 friend Complex operator + (float f, Complex& x);
 friend istream& operator >> (istream& in, Complex& c);
 friend ostream& operator << (ostream& out, Complex& c);

 //constructor
 Complex()
 { real = img = 0; }	   //1st constructor takes nothing and initialize to 0

 Complex(float r, float i)       //2nd constructor takes real & imaginary and sets them
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


 Complex& Complex :: operator ++ ()    //prefix (Default case)
 {
  real++; img++;
  return *this;
 }


 Complex Complex :: operator ++ (int dummy)  //Dummy input is never used but it lets compiler diffrentiate between them
 {
   Complex temp(*this);
   temp.real++;  temp.img++;
   return temp;
 }


 Complex :: operator float ()
 {
  return (float)sqrt((real*real)+(img*img));
 }


 Complex& Complex :: operator () (float r)
 {
  real = r;
  return *this;
 }


 Complex& Complex :: operator () (float r,float i)
 {
  real = r;  img = i;
  return *this;
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
	/*we can use operator << overloading here cout<<c;*/
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


istream&  operator >> (istream& in , Complex& c)  //input complex
{
 cout<<"Please Enter Real Number: ";
 in>>c.real;
 cout<<"Please Enter Imaginary Number: ";
 in>>c.img;
 return in;
}


ostream& operator << (ostream& out , Complex& c)  //print complex
{
 if (c.real == 0)
  {                                  /*we can just use print fn. here
									   c.print();
									   return out; */
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


  //main function

int main()
{
  Complex c1,c2;
  clrscr();
  cout<<"float C1(5,5): "<<(float)c1(5,5)<<endl;
  c1 (20);              //set real value only using ()operator
  cout<<"C1(20): "<<c1<<endl;  //directly print full complex without writing c1.real and c1.img using << overloading
  c2 (10,5);            //set to these values using () operator
  cout<<"C2(10,5): "<<c2<<endl<<endl;
  cin>>c1;
  cout<<endl<<"Complex = "<<c1<<endl;
  cout<<"++ Complex = "<<++c1<<endl;
  cout<<"Complex ++ = "<<c1++<<endl;
  getch();
 return 0;
}
