#include<iostream>
using namespace std;

int main(){
int min=0,max=120;
int mid,response;
//possible age>=min
//possible age<=max
(max-min<=1);
while (max-min>1){
mid=(max+min)/2;

cout<<"Is your age less than ";
cout<<mid<<endl;
cin>>response;
if(response==1)
max=mid;
else
min=mid;
}
cout<<"Age is"<<min<<endl;
return 0;
} 
