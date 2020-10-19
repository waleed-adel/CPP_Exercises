#include<iostream.h>
#include<stdlib.h>
#include<conio.h>



class Point
{
  private:

  int x,y;


  public:

  //constructors
  Point () { cout<<"Point Default Constructor\n"; x=y=0; } //default constructor
  Point (int n) { x = y = n; }
  Point (int x,int y) { this->x = x; this->y = y; }

  //copy constructor
  Point (Point& p) { x = p.x; y = p.y; }

  //functions
  void set_x (int x)  { this->x = x ; }
  void set_y (int y)  { this->y = y ; }
  int get_x ()        { return x; }
  int get_y ()        { return y; }
  void set_xy (int x,int y)   { this->x = x;  this->y = y; }
  void print_point ()  { cout<<"("<<x<<","<<y<<")";}

  //destructor
  ~ Point () { cout<<"Point Destructor\n"; }
};


class Line
{
  private:

  Point start,end;


  public:

  //constructors
  Line () { cout<<"Line Default Constructor\n"; }
  Line (int x,int y) { start.set_xy(x,y);  end.set_xy(x,y);}
  Line (int x1,int y1,int x2,int y2)
  { start.set_xy(x1,y1);  end.set_xy(x2,y2); }
  Line (Point p1 , Point p2)
  { start = p1;  end = p2; }


  //copy constructor
  Line (Line &l)
  {
	start.set_xy(l.start.get_x(),l.start.get_y());
	end.set_xy(l.end.get_x(),l.end.get_y());
  }

  //functions
  void set_start (int x,int y) { start.set_xy(x,y); }
  void set_end (int x,int y)   { end.set_xy(x,y); }
  void set_start (Point p)     { start = p; }
  void set_end (Point p)       { end = p; }
  void print_line ()
  {
   cout<<"Line Start Point (X1,Y1): ";
   start.print_point();
   cout<<"\nLine End Point (X2,Y2): ";
   end.print_point();
  }

  //destructor
  ~ Line () { cout<<"Line Destructor\n"; }
};



class Circle
{
  private:

  Point center;
  int rad;


  public:

  //constructor
  Circle ()
  {
   cout<<"Default Circle Constructor\n";
   rad = 0; center.set_xy(0,0);
  }


  Circle(int x,int y,int r)
  { rad = r; center.set_x(x); center.set_y(y); }


  Circle (Point p , int r) { center = p;  rad = r; }


  //functions
  void set_center (int x,int y)  { center.set_x(x);  center.set_y(y); }
  void set_center (Point p )     { center = p; }
  void set_rad (int r)           { rad = r; }
  Point get_center ()            { return center; }
  int get_rad ()                 { return rad; }
  void print_circle()
  {
   cout<<"Circle Data\nCenter: ";
   center.print_point();
   cout<<"\t\tRadius: "<<rad<<endl;
  }

  //destructor
  ~ Circle () { cout<<"Circle Destructor\n"; }
};


class Rectangle
{
  private:

  Point p1,p2;   //two points


  public:

  //constructor
  Rectangle ()
  {
   cout<<"Default Rectangle Constructor\n";
   p1.set_xy(0,0);  p2.set_xy(0,0);
  }

  Rectangle (int x1,int y1,int x2,int y2)
  { p1.set_xy(x1,y1);  p2.set_xy(x2,y2); }

  Rectangle (Point p1,Point p2)
  { this->p1 = p1;  this->p2 = p2; }


  //functions
  void set_p1 (Point p1)      { this->p1 = p1; }
  void set_p1 (int x,int y)   { p1.set_x(x);  p1.set_y(y); }
  void set_p2 (Point p2)      { this->p2 = p2; }
  void set_p2 (int x,int y)   { p2.set_x(x);  p2.set_y(y); }
  Point get_p1 ()              { return p1; }
  Point get_p2 ()              { return p2; }
  void print_rectangle ()
  {
   cout<<"Rectangle Data\n";
   cout<<"P1: ";
   p1.print_point();
   cout<<"\t\tP2: ";
   p2.print_point();
  }

  //destructor
  ~ Rectangle ()  { cout<<"\nRectangle Destructor\n"; }
};



 //main fn.


 int main()
 {
  int x,y;
  cout<<"Please Enter First Point: ";
  cin>>x>>y;
  Point p1(x,y);
  cout<<"Please Enter Second Point: ";
  cin>>x>>y;
  Point p2(x,y);
  cout<<"P1: ";
  p1.print_point();
  cout<<endl<<"P2: ";
  p2.print_point();
  cout<<endl<<endl;
  Line l(p1,p2);
  l.print_line();
  cout<<endl<<endl;
  Circle c(p1,5);
  c.print_circle();
  cout<<endl<<endl;
  Rectangle ret(p1,p2);
  ret.print_rectangle();
  getch();
  return 0;
 }
