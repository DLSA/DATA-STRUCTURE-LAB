#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
class strings
{
    char universal[1000];
    char sub[1000];
    int found=0,i,j,k,count=0;
    public:
    void input()
    {
        cout<<"Enter the main string\n";
        scanf("%[^\n]%*c",&universal);
        cout<<"Enter the sub string\n";
            scanf("%[^\n]%*c",&sub);
        for(i=0,j=0;i<strlen(universal);i++,j++)
        {
            if(found==0)
            {
                if(universal[i]==sub[0])
                {
                    found=1;
                    k=i;
                    j=0;
                }
            }
            if (found==1&&j!=strlen(sub)-1)
            {
                if(universal[i]!=sub[j])
                {
                    found=0;
                }

            }
             if(found==1&&j==strlen(sub)-1)
            {
                cout<<"FOUND SUBSTRING from index "<<k<<"  to  "<<k+j<<"\n";
                found=0;
                count++;

            }


        }
        if(count!=0)
        cout<<"String found :"<<count<<"\t times\n\n\n";
        else
        cout<<"\nString not found\n";
    }





};

int main()
{
    strings obj;
    obj.input();

}
