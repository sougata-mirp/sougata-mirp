#include<iostream>
using namespace std;
int main() {
int a,b,c,d;
cout<<"Enter the cutoff marks of A: ";
cin>>a;
cout<<"Enter the cutoff marks of B :";
cin>>b;
cout<<"Enter the cutoff marks ofC :";
cin>>c;
cout<<"Enter the obtained number :";
cin>>d;
if(a>=100)
  if(b>=60) 
     if(c>=50)
       if(d<a)
         if(d<b)
           if(d>=c)
              cout<<"Your grade is C";
 else
      cout<<"You have failed";
else
     cout<<"Your Grade is B:";
else
    cout<<"Your grade is A";
else
     cout<<"Invalid cueoff marks";
else
    cout<<"Invalid cut off marks";
else
   cout<<"Invalid cutoff marks"; 
    return 0;
}          
