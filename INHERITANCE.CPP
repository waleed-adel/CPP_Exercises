#include<iostream.h>
#include<stdlib.h>
#include<conio.h>


class Shape
{
 protected:

 int color;


 public:

 //constructors
 Shape () {} //default constructor
 Shape (int c) { color = c; }

 //functions
 void setColor (int c) { color = c;    }
 int getColor ()       { return color; }

 //destructor
 ~ Shape () {}
};


class Line : public Shape
{
  private:

  int length;


  public:

  //constructors
  Line () {}
  Line (int l) { length = l; }

  //functions
  void setLength (int l) { length = l;    }
  int getLength ()       { return length; }

  //destructor
  ~ Line () {}
};


class Circle : public Shape
{
  private:

  int rad;


  public:

  //constructor
  Circle () {}  //default constructor
  Circle (int r)  { rad = r; }

  //functions
  void setRadius (int r)  { rad = r;    }
  int getRadius ()        { return rad; }

  //destructor
  ~ Circle () {}
};

class Rectangle : public Shape
{
   protected:

   int dim1,dim2;


   public:

   //constructor
   Rectangle () {}
   Rectangle (int l,int w)  { dim1 = l;  dim2 = w; }

   //functions
   void setDim1 (int l)     { dim1 = l;    }
   void setDim2 (int w)     { dim2 = w;    }
   int getDim1 ()           { return dim1; }
   int getDim2 ()           { return dim2; }

   //destructor
  ~ Rectangle () {}
};