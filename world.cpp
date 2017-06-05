#include<iostream>
using namespace std;

int main(){
int x[5]={1,2,3,4,5};
for(int i=0;i<5;i++)
cout<<x[i]<<" ";

char name[50]="my_name";
//print name using loop

cout<<name<<endl;


cout<<"Enter first name";
cin>>name;
for(int i=0;i<50;i++)
cout<<name[i]<<" "<<i<<endl;
cout<<name<<endl;

//print name using loop, not to use "cout<<name"
return 0;
}
