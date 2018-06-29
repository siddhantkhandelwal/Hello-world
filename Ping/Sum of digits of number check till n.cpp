#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
long long unsigned int num, r, n;
int c=0, s=0;
char d, choice='y';
while(choice=='y')
{
    num = r = n = c = s = d = 0;
cout<<"Enter Range(0 <-> ";
cin>>r;
cout<<"Enter The Number Which has to be identified as sum of the digits of the numbers till "<<r<<" ";
cin>>n;
for (long long unsigned int i=0;i<=r;i++)
    {
        num=i;
        s=0;
        do
        {
            d=num%10;
            s+=d;
            num/=10;
            if (s>n)
                break;
        }while(num!=0);
        if (s==n)
        c++;

        else
        continue;
    }
cout<<"The Number of Numbers whose sum is "<<n<<" are "<<c;
cout<<"\n\nContinue (y or n): ";
cin>>choice;

}
return 0;
}
