#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

#define ESC   27

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



 //constructor
 Complex()
 { real = img = 0; }	   //1st constructor takes nothing and do nothing

 Complex(float r, float i)       //2nd constructor takes real & imaginary and sets them to zero
 { real = r;  img = i; }

 //destructor
  ~ Complex (){}
  //{ cout << "DESTROYED!!"; }  it will print every time an object is terminated
};

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


  //main function

int main()
{
  Complex c1,c2;
  float r,i;
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
  cout<<endl<<endl<<"Sum: ";
  add_complex(c1,c2).print();
  cout<<endl<<"Difference: ";
  sub_complex(c1,c2).print();
  getch();
 return 0;
}

