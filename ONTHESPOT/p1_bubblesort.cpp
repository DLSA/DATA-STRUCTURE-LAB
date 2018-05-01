#include<iostream>
#include<vector>
using namespace std;
int main()
{
int i,j,k,sz,ele;
vector<int>numbers;
cout<<"ENTER THE SIZE"<<endl;
cin>>sz;

for(i=0;i<sz;i++)
{
cin>>ele;
numbers.push_back(ele);
}
for(i=0;i<sz;i++)
{
	for(j=i+1;j<sz;j++)
	{
	if(numbers[i]>numbers[j])
	{
	ele=numbers[i];
	numbers[i]=numbers[j];
	numbers[j]=ele;
	
	}
	
	
	}

}

cout<<"\n\nSORTED  LIST IS :\n";
for(i=0;i<sz;i++)
{
cout<<numbers[i]<<"\t";

}
}
