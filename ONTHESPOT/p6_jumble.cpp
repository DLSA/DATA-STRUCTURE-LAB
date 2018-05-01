#include<iostream>
#include<vector>
#include<string>
using namespace std;

class word
{
	private:
	   int found,i,j;
	   string word,jumble;
	public:
	void input()
	{
	   cout<<"Enter any word\n\n";
	   cin>>word;
	   cout<<"Enter another word to check if it can be rearranged to get the initial word\n";
	   cin>>jumble;
	   if(word.size()!=jumble.size())
	   {
         cout<<"words do not match\n\n";
	      return;
	   }
	   else
	   {

	   for(i=0;i<jumble.size();i++)
      {
         found=0;
         for(j=0;j<word.size();j++)
         {
            if(jumble[i]==word[j])
            {
               found=1;
               word[j]='*';
               break;
            }

         }
         if(found==0)
         {
            cout<<"words do not match\n\n";
            break;
         }


      }

if(found==1)
{
            cout<<"words match\n\n";
}
	   }

	}





};


int main()
{
		word obj;
		obj.input();

}







