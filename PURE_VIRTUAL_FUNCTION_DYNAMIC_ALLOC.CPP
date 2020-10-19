#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>

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
 virtual void draw () = 0; //pure virtual fn.

 //destructor
 ~ Shape () {}
};


class Point
{
  private:

  int x,y;


  public:

  //constructors
  Point () { /*cout<<"Point Default Constructor\n"; x=y=0;*/ } //default constructor
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
  ~ Point () {/*cout<<"Point Destructor\n";*/ }
};


class Line : public Shape
{
  private:

  Point start,end;


  public:

  //constructors
  Line () { /*cout<<"Line Default Constructor\n";*/ }
  Line (int x,int y) { start.set_xy(x,y);  end.set_xy(x,y);}
  Line (int x1,int y1,int x2,int y2,int color)
  {
   start.set_xy(x1,y1);  end.set_xy(x2,y2);
   setColor(color);
  }
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
  void draw ()
  {
   setcolor(color);  //fn in graphics.h
   line(start.get_x(),start.get_y(),end.get_x(),end.get_y());
  }

  //destructor
  ~ Line () {/* cout<<"Line Destructor\n";*/ }
};



class Circle : public Shape
{
  private:

  Point center;
  int rad;


  public:

  //constructor
  Circle ()
  {
   //cout<<"Default Circle Constructor\n";
   rad = 0; center.set_xy(0,0);
  }


  Circle(int x,int y,int r,int color)
  {
   rad = r; center.set_x(x); center.set_y(y);
   setColor(color);
  }


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
  void draw ()
  {
   setcolor(color);
   circle (center.get_x(),center.get_y(),rad);
  }
  //destructor
  ~ Circle () { /*cout<<"Circle Destructor\n";*/ }
};


class Rectangle : public Shape
{
  private:

  Point p1,p2;   //two points


  public:

  //constructor
  Rectangle ()
  {
   //cout<<"Default Rectangle Constructor\n";
   p1.set_xy(0,0);  p2.set_xy(0,0);
  }

  Rectangle (int x1,int y1,int x2,int y2,int color)
  {
   p1.set_xy(x1,y1);  p2.set_xy(x2,y2);
   setColor(color);
  }

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
  void draw ()
  {
   setcolor(color);
   rectangle(p1.get_x(),p1.get_y(),p2.get_x(),p2.get_y());
  }

  //destructor
  ~ Rectangle ()  {/* cout<<"\nRectangle Destructor\n";*/ }
};


class Pic
{
  private:

  int nl,nc,nr;   //nl:no.of lines,,nc:no.of circle,,nr:no.of rectangles
  Line* lptr;      //nlp:ptr to number of lines
  Circle* cptr;
  Rectangle* rptr;


  public:

  //constructor
  Pic()
  {
   nl = nc = nr = 0;
   lptr = NULL;
   cptr = NULL;
   rptr = NULL;
  }

 Pic(int l,int c,int r,Line* lp,Circle* cp,Rectangle* rp)
 {
   nl = l;        nc = c;         nr = r;
   lptr = lp  ;   cptr = cp;     rptr = rp;
 }


 //copy constructor
 Pic (Pic& p);


 //functions
 void setLines (int l,Line* lp);
 void setCircles (int c,Circle* cp);
 void setRects (int r,Rectangle* rp);
 void paint ();

 //operator overloading
 Pic& operator = (Pic &p);

 //destructor
 ~ Pic ()
 {
  delete [] lptr;
  delete [] cptr;
  delete [] rptr;
 }
};

 //copy constructor
 Pic :: Pic (Pic& p)
 {
  nl = p.nl;       nc = p.nc;      nr = p.nr;
  delete [] lptr;
  delete [] cptr;
  delete [] rptr;
  lptr = new Line [nl];
  cptr = new Circle [nc];
  rptr = new Rectangle [nr];
  for (int i=0;i<nl;i++)
  {
   lptr[i]=p.lptr[i];
  }
   for (i=0;i<nc;i++)
  {
   cptr[i]=p.cptr[i];
  }
   for (i=0;i<nr;i++)
  {
   rptr[i]=p.rptr[i];
  }
 }


 //operator overloading definitions
 Pic& Pic :: operator = (Pic& p)
 {
  nl = p.nl;       nc = p.nc;      nr = p.nr;
  delete [] lptr;
  delete [] cptr;
  delete [] rptr;
  lptr = new Line [nl];
  cptr = new Circle [nc];
  rptr = new Rectangle [nr];
  for (int i=0;i<nl;i++)
  {
   lptr[i]=p.lptr[i];
  }
   for (i=0;i<nc;i++)
  {
   cptr[i]=p.cptr[i];
  }
   for (i=0;i<nr;i++)
  {
   rptr[i]=p.rptr[i];
  }
  return (*this);
 }


 //functions
 void Pic :: setLines (int l,Line* lp)
 {
  nl = l;
  delete []lptr;
  lptr = new Line [nl];
  for (int i=0;i<nl;i++)
  {
   lptr[i]=lp[i];
  }
 }


 void Pic :: setCircles (int c,Circle* cp)
 {
  nc = c;
  delete []cptr;
  cptr = new Circle [nc];
  for (int i=0;i<nc;i++)
  {
   cptr[i]=cp[i];
  }
 }

 void Pic :: setRects (int r,Rectangle* rp)
 {
  nr = r;
  delete []rptr;
  rptr = new Rectangle [nr];
  for (int i=0;i<nr;i++)
  {
   rptr[i]=rp[i];
  }
 }

 void Pic :: paint ()
 {
  for (int i=0;i<nl;i++)
  lptr[i].draw();
  for (i=0;i<nc;i++)
  cptr[i].draw();
  for (i=0;i<nr;i++)
  rptr[i].draw();
 }




 /////////////////////////////////////////////////////////////////////////
 //main fn

void main ()
{
 clrscr();
 int gdriver = DETECT,gmode,errorCode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	errorCode = graphresult();
	if (errorCode != grOk)
	{
	 cout<<"Can not initialize graphics"<<endl;
	}
	else
	{
	 Pic myPic;
	 Circle cArr[3] = {Circle(50,50,50,2),Circle(200,100,100,1),Circle(450,50,30,12)};
	 Rectangle rArr[2] = {Rectangle (30,40,170,100,11),Rectangle(420,50,500,300,12)};
	 Line lArr[2] = {Line(420,50,300,300,3),Line(40,500,500,400,5)};

	 myPic.setCircles(3,cArr);
	 myPic.setRects(2,rArr);
	 myPic.setLines(2,lArr);

	 myPic.paint();

	 getch();
	 closegraph();
	}
}