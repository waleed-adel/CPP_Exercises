#include<iostream.h>
#include<conio.h>
#include<stdlib.h>


class Geoshape
{
 protected:

 int dim1,dim2;


 public:

 //constructors
 Geoshape ()             { dim1 = dim2 = 0;}
 Geoshape (int a,int b)  { dim1 = a;  dim2 = b; }

 /* geoshape cannot contain any copy constructor
  or any function that require creation of object*/
 //functions
 void setDim1 (int x)    { dim1 = x; }
 void setDim2 (int x)    { dim2 = x; }
 int getDim1 ()          { return dim1; }
 int getDim2 ()          { return dim2; }
 virtual float calc () = 0;
 float sum_area (Geoshape* p1 , Geoshape* p2 , Geoshape* p3);

 //destructor
 ~ Geoshape () {}
};



class Triangle : public Geoshape
{
   public:

   //constructors
   Triangle() {}
   Triangle(int b,int h) { dim1 = b; dim2 = h; }


   //functions
   void setHeight (int h)      { dim2 = h; }
   void setBase (int b)        { dim1 = b; }
   float calc ()  { return 0.5*dim1*dim2; }

   //destructor
   ~ Triangle () {}
};


class Rect : public Geoshape
{
  public:

  //constructor
  Rect () {}
  Rect (int l,int w)      { dim1 = l;  dim2 = w; }


  //functions
  void setLenght(int l)   { dim1 = l; }
  void setWidth(int w)    { dim2 = w;  }
  float calc ()           { return dim1*dim2; }

  //destructor
  ~ Rect () {}
};


class Square : protected Rect
{
  public:

  //constructors
  Square(){}
  Square(int x)        { dim1 = dim2 = x; }

  //functions
  void setSide(int x)  { dim1 = dim2 = x; }
  float calc()         { return dim1*dim2; }

  //destructor
  ~ Square () {}
};


class Circle : public Geoshape
{
   public:

   //constructor
   Circle () {}
   Circle (int r)           { dim1 = dim2 = r; }

   //function
   void setRadius (int r)   { dim1 = dim2 = r; }
   float calc()             { return dim1*dim2*3.14; }

   //destructor
   ~ Circle () {}
};


  //standalone function
 float sum_area (Geoshape* p1 , Geoshape* p2 , Geoshape* p3)
 {
  return  ( p1 -> calc () + p2 -> calc () + p3 -> calc ());
 }


///////////////////////////////////////////////////////////////////////////

 //main fn.

void main ()
{
 clrscr();
 Triangle t (3,5);
 Circle c (5);
 Rect r(5,4);
 Square s (5);
 Geoshape* p1 = &t;
 Geoshape* p2 = &c;
 Geoshape* p3 = &r;
 cout<<"Triangle (3,5)\nArea of Triangle: "<<t.calc();
 cout<<"\n\nCircle (5)\nArea of Circle: "<<c.calc();
 cout<<"\n\nRectangle (5,4)\nArea of rectangle: "<<r.calc();
 cout<<"\n\nSquare (5)\nArea of Square: "<<s.calc();
 cout<<"\n\n\n(Triangle + Circle + Rect) Areas: "<<sum_area(p1,p2,p3);
 getch();
}