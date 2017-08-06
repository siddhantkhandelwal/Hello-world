//Finds factorial upto input 100
#include<iostream>
using namespace std;

#define uplimit 150;

int product(int d, int fact[], int size)
{
	int carry = 0,i,prod;
	for(i=0;i<size;++i)
	{
	prod=(fact[i]*d)+carry;
	fact[i]=prod%10;
	carry=prod/10;
	}
	
	while(carry)
	{
		fact[size]=carry%10;
		carry/=10;
		size++;
	}
	return size;
}

int main()
{
	int num,fact[uplimit],size,d;
	cout<<"\nEnter The Number whose factorial is to be calculated: ";
	cin>>num;
	fact[0]=1;
	size=1;
	for(d=2;d<=num;++d)
		size=product(d,fact,size);
	cout<<"\nFactorial of the number is: ";
	for(int i=size-1;i>=0;i--)
		cout<<fact[i];
	return 0;
}
 