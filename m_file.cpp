#include<iostream>
using namespace std;

int main(){
  int i,n,sum=0;
cout<<"EnterTHE Number:";
cin>>i;
n=i%10;
for( ; i>=n;sum+=n)
i/=10;{
cout<<"The bsum is "<<sum<<endl;
}
return 0;
}
