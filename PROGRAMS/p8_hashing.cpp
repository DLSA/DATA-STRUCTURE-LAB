#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define k 2069
#define m 0
#define KEY (logic%k)+m

class hashing
{
	private:
		int logic,key,i,j;
		vector<string>hash_table1;
		vector<string>hash_table2;
		vector<string>hash_table3[k+m];
		string info,str;
	public:
		hashing()
		{
			hash_table1.resize(k+m);
			hash_table2.resize(k+m);
			for(i=0;i<(k+m);i++)
			{
				hash_table1[i]="null";
				hash_table2[i]="null";
			}
		}
		int hash_function()
		{
			logic=0;
			for(i=0;i<info.size();i++)
				logic+=int(info[i]);
			return KEY;
		}
		void linearprobing()
		{
			cout<<"Enter info of current entry"<<endl;
			cin>>info;
			key=hash_function();
			while(hash_table1[key]!="null")
					key=(key+1)%k;
			hash_table1[key]=info;
		 
		}

		void lsearch()
		{
			cout<<"Enter the value \n"<<endl;
			cin>>info;
			key=hash_function();
			while(hash_table1[key]!="null"&&hash_table1[key]!=info)
					key=(key+1)%k;
			
			if(hash_table1[key]==info)
			cout<<"Value present :\t"<<key<<"\n\n"<<endl;
			else 
			cout<<"Value not found"<<endl;
		
		}
		void quadraticprobing()
		{
			cout<<"Enter info of current entry"<<endl;
			cin>>info;
			key=hash_function();
			j=1;
			while(hash_table2[key]!="null")
					{
						key=(key+j*j)%k;
						j++;
					}
			hash_table2[key]=info;
		 
		}

		void qsearch()
		{
			cout<<"Enter the value \n"<<endl;
			cin>>info;
			key=hash_function();
			j=1;
			while(hash_table2[key]!="null"&&hash_table2[key]!=info)
					{
					key=(key+j*j)%k;
					j=j+1;
					}
			if(hash_table2[key]==info)
			cout<<"Value present :\t"<<key<<"\n\n"<<endl;
			else 
			cout<<"Value not found"<<endl;
		
		}
		void openhashing()
		{	
			cout<<"Enter info of current entry"<<endl;
			cin>>info;
			key=hash_function();
			hash_table3[key].push_back(info);
		}
		void osearch()
		{
			cout<<"Enter the value \n"<<endl;
			cin>>info;
			key=hash_function();
			for(i=0;i<hash_table3[key].size();i++)
			{
			    if(hash_table3[key][i]==info)
			    {
				cout<<"Value present :\t"<<key<<"\n\n"<<endl;
				return;
			    }
			}
			cout << info << " is not found!" << endl;
		    
		
		}
		
		
};

int main()
{
	hashing obj;
	int choice;
	while(1)
	{
		cout<<"\n\n\nPress 1 for Hashing with linear probing (HASH TABLE 1) \n";
		cout<<"Press 2 to search the value in HASH TABLE 1 \n\n";
		cout<<"Press 3 for Hashing with Quadratic probing (HASH TABLE 2) \n";
		cout<<"Press 4 to search the value in HASH TABLE 2 \n\n";
		cout<<"Press 5 for Hashing with OPEN HASHING (HASH TABLE 3) \n";
		cout<<"Press 6 to search the value in HASH TABLE 3 \n\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
			obj.linearprobing();
			break;
		case 2:
			obj.lsearch();
			break;
		case 3:
			obj.quadraticprobing();
			break;
		case 4:
			obj.qsearch();
			break;
		case 5:
			obj.openhashing();
			break;
		case 6:
			obj.osearch();
			break;
		default:
			break;
		
		}
	}
}
