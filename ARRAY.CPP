#include<iostream.h>
#include<stdlib.h>
#include<conio.h>


class Array
{
  private:

  int size, *data;


  public:

  //constructors
  Array (int size);


  //functions
  void addElement (int index , int x);
  int getElement (int index);
  void resize (int new_size);


  //operator overloading
  int& operator [] (int index);  //get reference of a specific element in array (to get data from it or edit it)

  //destructor
  ~ Array ();
};

   //constructor definition
   Array :: Array (int size)
   {
	this -> size =  size;
	data = new int [this -> size];
   }


   //destructor definition
   Array :: ~ Array ()
   { delete [] data; } //free allocated array space after finishing fn.


   //functions definition
   void Array :: addElement (int index , int x)
   { data[index] = x; }


   int Array :: getElement (int index)
   { return data[index]; }


   void Array :: resize (int new_size)   //suitable only when new_size > old size, else data loss will occur
   {
	int* temp;
	temp = new int [new_size];
	size = new_size;
	for (int i=0;i<new_size;i++)
	{
	 temp[i]=data[i];
	}
	delete []data;
	data=temp;
   }


   //operator overloading
   int& Array :: operator [] (int index)
   { return data [index]; }


   //main fn.

int main ()
{
 clrscr();
 int i,x,size;
 cout<<"Please Enter Size: ";
 cin>>size;
 Array a1(size);
 cout<<endl<<"Please Enter Index: ";
 cin>>i;
 cout<<"Please Enter A Number: ";
 cin>>x;
 a1.addElement(i,x);  //adds x to element[i] of array
 cout<<"Element["<<i<<"] = "<<a1.getElement(i)<<endl;
 cout<<endl<<"Please Enter New Size: ";
 do
 {
  cin>>x;
  if(x < size)
  cout<<"\nNew Size < Old Size\nLOSE OF DATA MAY OCCUR!!\nPlease Enter New Size: ";
  else
  {
   a1.resize(x);
   cout<<"\nResize Successful\n";
  }
 }while(x < size);
 cout<<"After Resizing ==> Element["<<i<<"] = "<<a1.getElement(i)<<endl;
 getch();
 return 0;
}