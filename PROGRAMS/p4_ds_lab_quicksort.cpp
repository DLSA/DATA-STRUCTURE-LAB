#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
class sorting
{
private:
	int i,j,k,n,pivotpos,partitions;
public:
	vector<int>vec;
	vector<int>vec1;

	int arrayin()							
	{
		cout<<"ENTER THE SIZE OF THE ARRAY\n\n"<<endl;
		cin>>n;
		srand((int)time(0));
		for(i=0;i<n;i++)
			vec.push_back(rand()%1000+1);
		vec1=vec;
		partitions=0;
		return vec.size();
			
	}
	
	void print(vector<int>vec)
	{
		for(i=0;i<vec.size();i++)
			cout<<vec[i]<<"\t";
		cout<<endl<<endl;
	
	}

	void quicksort(int low,int high,int pivot)
	{
		if(low<high)
		{
			pivotpos=partition(low,high,pivot);
			quicksort(low,pivotpos-1,low);
			quicksort(pivotpos+1,high,pivotpos+1);
		}
	
	}
	int partition(int low,int high,int pivot)
	{
		int i,j;
		i=low,j=high;
		int piv=vec[pivot];
		while(1)
		{
			while(vec[i]<piv)
				{i++;}
				
			while(vec[j]>piv)
				{j--;}
				
			if(i>=j)
				{break;}
				
			if(vec[i]==vec[j])
			{
			i=i+1;
			}
			swap(i,j);
		}
		partitions++;
		cout<<"\n"<<partitions<<" PATITION about pivot "<<piv<<"  IS done at index : ' "<<i<<" ' about  "<<vec[i]<<""<<endl;
		print(vec);
		cout<<"\n\nNEXT partition:\n"<<endl;
		return i;
	}
	void swap(int i,int j)
	{
		int temp=vec[j];
		vec[j]=vec[i];
		vec[i]=temp;
	}

};


int main()
{
sorting object;
int size=object.arrayin();
object.print(object.vec);
object.quicksort(0,size-1,0);
cout<<"\nArray sorted\n"<<endl;
cout<<"***************************************************************************************************************\n";

cout<<"\n\n\tUNSORTED ARRAY WAS:\n\n";
object.print(object.vec1);

cout<<"\n\n\tSORTED ARRAY IS:\n\n";
object.print(object.vec);

}
