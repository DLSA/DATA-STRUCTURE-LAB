#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

class World_Cup
{
private:
    int i,j,k,teams,remaining,luck,counts;
    int arr[100][100];
            int winner1=0,winner2=0;

public:
    void stats()
    {
        cout<<"Enter no of participating teams\n";
        cin>>teams;
        int parts=teams/5;
        remaining=teams%5;
        for(i=0;i<parts;i++)
        {
            teams=5;
            if(i==parts-1)
            {
                teams=5+remaining;
            }

            for(i=0;i<teams;i++)
            {
            cout<<"TEAM "<<i+1<<":\t";
                counts=0;
                for(j=0;j<i;j++)
                {
                    arr[i][j]=arr[j][i];
                    counts+=luck;
                    cout<<arr[i][j]<<"\t";
                }

                for(j=i;j<teams;j++)
                {
                    srand((int)time(0));
                    luck=(j+i)%3;
                    luck=luck-1;
                    if(luck==1)
                        luck=2;
                    if(luck==2);
                        luck=1;
                    arr[i][j]=j%2;
                    counts+=j%2;
                    cout<<arr[i][j]<<"\t";
                }
                arr[i][j]=counts;
                cout<<arr[i][j]<<"\t\n";
            }
            int max1=0;
            for(k=0;k<teams;k++)
            {
                max1=0;
                if(arr[k][teams]>max1)
                {
                    winner1=winner2;
                    max1=arr[k][teams];
                    winner2=k;
                }
            }
            cout<<"\n"<<winner1+1<<"  and  "<<winner2+1<<"\tARE WINNING TEAMS"<<endl;


        }



        if(teams%2==0)
        {
            cout<<winner1+1<< "\tWINS\n";
        }
         if(teams%2==1)
        {
            cout<<winner2+1<< "\tWINS\n";
        }


    }



};




int main()
{
    World_Cup obj;
    obj.stats();





}
