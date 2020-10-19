#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>



class String
{
 private:

 int size;
 char* str;


 public:

 //constructors
 String () { size = 0; str = NULL;}     //default constructor
 String (char* s);

 //copy constructor
 String (String& s);

 //functions
 char charAt (int index);
 int indexof (char ch);
 int indexof (int start,char ch);
 String substring (int start);
 String substring (int start,int end);
 String concat (String s2);
 static String lowercase (String& s1);
 static String uppercase (String& s1); /*can be declared as friend function
									   and their definition as standalone function*/
 friend void print (String s);

 //operator overloading
 String& operator =  (String& s);
 String& operator += (String s);
 String operator  +  (String s);


 //destructor
 ~ String () { delete [] str; }

};

 //constructor definition
 String :: String (char* s)
 {
  size = 0;
  for (int i=0; s[i]!=NULL ; i++)
  {
   size++;
  }
  str = new char [size];
  for (i=0;i<size;i++)
  {
   str[i]=s[i];
  }
  str[i]=NULL;
 }


 //copy constructor definition
 String :: String (String& s)
 {
  this -> size = s.size;
  str = new char [size];
  for (int i=0 ;i<size;i++)
  {
   this -> str[i] = s.str[i];
  }
  str[i]=NULL;
 }



 //operator overloading definitions
 String& String :: operator = (String& s)
 {
  delete [] str;
  this -> size = s.size;
  str = new char [size];
  for (int i=0;i<size;i++)
  {
   str[i] = s.str[i];
  }
  str[i]=NULL;
 return *this;
 }

 String String :: operator + (String s)
 {
  String temp;
  temp.size = size + s.size;
  for (int i=0;i<size;i++)
  {
   temp.str[i]=str[i];
  }
  for (i=size;i<temp.size;i++)
  {
   temp.str[i]=s.str[i-size];
  }
  temp.str[i]=NULL;
  return temp;
 }


 String& String :: operator += (String s)
 {
  String temp(*this);
  delete [] str;
  this -> size = this -> size + s.size;
  str = new char [size];
  for (int i=0;i<temp.size;i++)
  {
   str[i]=temp.str[i];
  }
  for (i=temp.size;i<size;i++)
  {
   str[i]=s.str[i-temp.size];
  }
  str[i]=NULL;
  return *this;
 }

 //functions definition
 char String :: charAt (int index)
 { return str[index]; }

 int String :: indexof (char ch)
 {
  for (int i=0;i<size;i++)
  {
   if (str[i]==ch)
   return i;
  }
  return -1;
 }

 int String :: indexof (int start,char ch)
 {
  for (int i=start;i<size;i++)
  {
   if (str[i]==ch)
   return i;
  }
  return -1;
 }

 String String :: substring (int start)
 {
  String temp;
  if (start < size)
  {
	temp.size = (this -> size) - start;
	temp.str = new char [temp.size];
	for (int i=start;i<size;i++)
	{
	 temp.str[i-start]=str[i];
	}
  temp.str[i-start]=NULL;
  }
  return temp;
 }


 String String :: substring (int start,int end)
 {
  String temp;
  if (end > start && end <= size)
  {
	temp.size = end - start;
	temp.str = new char [temp.size];
	for (int i=start;i <= end;i++)
	{
	 temp.str[i-start]=str[i];
	}
  temp.str[i-start]=NULL;
  }
  return temp;
 }

 String String :: concat (String s2)
 {
  String temp;
  temp.size = size + s2.size;
  temp.str = new char [temp.size];
  for (int i=0;i<size;i++)
  {
   temp.str[i]=str[i];
  }
  for (i=size;i<temp.size;i++)
  {
   temp.str[i]=s2.str[i-size];
  }
  s2.str[i-size]=NULL;
  return temp;
 }

 /*lowercase and upper case can be standalone functions
 without using (String ::) or static functions as below*/
 String String :: lowercase (String& s1)     //return string in lower case
 {
  String temp;
  temp.size = s1.size;
  temp.str = new char [temp.size];
  for (int i=0;i<s1.size;i++)
  {
   if (s1.str[i] <= 'Z' && s1.str[i] >= 'A')
   {
	temp.str[i] = s1.str[i] + 32 ;
   }
   else
   temp.str[i] = s1.str[i];
  }
  temp.str[i]=NULL;
 return temp;
 }

 String String :: uppercase (String& s1)   //return string in upper case
 {
  String temp;
  temp.size = s1.size;
  temp.str = new char [temp.size];
  for (int i=0;i<s1.size;i++)
  {
   if (s1.str[i] <= 'z' && s1.str[i] >= 'a')
   {
	temp.str[i] = s1.str[i] - 32 ;
   }
   else
   temp.str[i] = s1.str[i];
  }
 temp.str[i]=NULL;
 return temp;
 }


 //standalone fn.
 void print(String s)
 {
  for (int i=0;i<s.size && s.str[i]!=NULL;i++)
  {
   cout<<s.str[i];
  }
 }


 /////////////////////////////////////////////////////////////////////////

 //main fn.

 void main ()
 {
  clrscr();
  String s1("Walid Adel");
  cout<<"S1('Walid Adel'): ";
  print(s1);
  String s3 (" Hassan");
  cout<<"\nS3(' Hassan'): ";
  print (s3);
  String s2;
  s2 = s1 + s3;
  cout<<"\nS1 + S3 = ";
  print (s2);
  cout<<"\nS2 = S3\nS2:";
  s2 = s3;
  print (s2);
  s2 += s3;
  cout<<"\nS2 += S3\nS2:";
  print (s2);
  cout<<"\n\nChar at Index 6 in S1: "<<s1.charAt(6);
  cout<<"\nFirst Occurence of 'd' in S1: "<<s1.indexof('d');
  cout<<"\nFirst Occurence of 'd' in S1 staring from Index 5: "<<s1.indexof(5,'d');
  String s4;
  s4 = s1.substring(5);
  cout<<"\n\nSubstring from S1 starting from Index 5\nS4: ";
  print (s4);
  String s5;
  s5 = s1.substring(0,5);
  cout<<"\nSubstring from S1\nstarting from Index 0 and ending at Index 5\nS5: ";
  print (s5);
  s5 = s5.concat (s4);
  cout<<"\n\nS5 = Concat (S5,S4)\nS5: ";
  print (s5);
  String s6;
  s6 = String :: lowercase(s5); //cannot be called directly without String ::
  cout<<"\nS5 (Lower Case): ";
  print (s6);
  s6 = String :: uppercase(s5);
  cout<<"\nS5 (Upper Case): ";
  print (s6);
  getch();
 }