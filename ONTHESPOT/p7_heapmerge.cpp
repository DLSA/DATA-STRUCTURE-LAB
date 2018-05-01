#include<iostream>
#include<vector>
using namespace std;

class heap
{
	private:
		int comp,size1,size2,i,no;
		vector<int>list1;
		vector<int>list2;
		vector<int>list3;
	public:
	void input()
	{

		cout<<"\n\nEnter number of elements in list 1\n\n";
		cin>>size1;

		for(i=0;i<size1;i++)
		{
		cin>>no;
		list2.push_back(no);
		}

		cout<<"\n\nEnter number of elements in list 2\n\n";
		cin>>size2;
		for(i=0;i<size2;i++)
		{
		cin>>no;
		list3.push_back(no);
		}

	merge();

	}
	void merge()
	{
		int first,last,i,j;
		list1=list2;
		for(i=size1/2;i>=0;i--)
				domaxheapofnode_i(i,size1);

		list2=list1;
		list1=list3;
		for(i=size2/2;i>=0;i--)
				domaxheapofnode_i(i,size1);
		list3=list1;
		list1=list2;
		for(i=0;i<size2;i++)
        {
		list1.push_back(list3[i]);
		for(int j=(size1+i+1)/2;j>=0;j--)
				domaxheapofnode_i(j,size1+i);
        }


	}

    void domaxheapofnode_i(int pos,int sizef)
	{
	int leftchild=pos*2+1;

	int rightchild=pos*2+2;
	int larger=pos;

			if(leftchild<sizef)
			{
			if(list1[leftchild]>list1[larger])
				larger=leftchild;
			}
			if(rightchild<sizef)
			{
			if(list1[rightchild]>list1[larger])
				larger=rightchild;
			}
		if (larger != pos)
		{
		int temp=list1[pos];
		list1[pos]=list1[larger];
		list1[larger]=temp;
		domaxheapofnode_i(larger,sizef);
		}
	}



	void print()
	{

	cout<<"\n\n HEAP 1 is as follows\n\n";
		for(i=0;i<size1;i++)
				cout<<list2[i]<<"\t";
	cout<<"\n\n";
	cout<<"\n\n HEAP 2 is as follows\n\n";
		for(i=0;i<size1;i++)
				cout<<list3[i]<<"\t";
	cout<<"\n\nMERGED HEAP  is as follows\n\n";
		for(i=0;i<size1+size2;i++)
				cout<<list1[i]<<"\t";
	}



};


int main()
{
		heap obj;
		obj.input();
		obj.print();

}


