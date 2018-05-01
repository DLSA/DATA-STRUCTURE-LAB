#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
using namespace std;
	class linkedlists
	{
	private:
		int i,j,val,nodes,pos;
		vector<int>vec;
		struct node		//USER DEFINED DATA TYPE
		{
			struct node * prev;
			int info;
			struct node *next;
		};
		struct node *head,*last,*temp,*tempprev,*tempnext;
	public:
		void createnode(int nodes)
		{
		head=NULL,last=NULL,temp=NULL;
		this->nodes=nodes;
		cout<<"Enter the data separated by spaces\n";
		for(j=0;j<nodes;j++)		/*creating linked list here*/
			{
			
			cin>>val;
    			temp =(struct node*) malloc(sizeof(struct node));
    			temp->info=val;
				if(head==NULL)
				{
				head=temp;
				head->prev=NULL;
				head->next=NULL;
				last=head;
				continue;
				}
			temp->prev=last;
			last->next=temp;
			temp->next=NULL;
			last=temp;
							/*creating linked list here*/
			}
		}
/*-----------------------------------------printing the linked list-----------------------------------------------*/
		void printlist()		
		{
		temp=head;cout<<"\n";
			i=100;
		while(i--)
			{
			cout<<temp->info<<"  ";
			temp=temp->next;
			}
		cout<<"linked list contain  "<<nodes<<"  elements"<<endl;
		}
			void makecircular()
		{
			last->next=head;
			head->prev=last;
			
		}
/*-------------------------------declaring functions for INSERT and DELETE operations on linked list-------------------------------*/
void frontinsert();
void lastinsert();
void nthinsert();
void frontdelete();
void lastdelete();
void nthdelete();
void traverse();

	};
                          //end of linkedlist class

/*----------------------------------------main function----------------------------------------------------------*/
main()

{

	int nodes,choice,subchoice;
		cout<<"\nEnter the size of your data\n";
		cin>>nodes;
		linkedlists mob;
	mob.createnode(nodes);
	mob.makecircular();
	mob.printlist();
		/*CHOOSE INSERTION OR DELETION */
		while(1)
			{
			cout<<"\n\n\nPress '1' for inserting an element in the linked list"<<endl;
			cout<<"Press '2' for deleting an element from the linked list"<<endl;
			cout<<"Press '3' for printing the list"<<endl;
			cout<<"Press '4' to exit"<<endl;
			cout<<"\nEnter the action to be performed : ";
        		cin>>choice;
			switch(choice)
			{
			case 1:
					/*CHOOSE INSERTION POSITION*/
				cout<<"Press '1' for inserting at the n'th position"<<endl;
				cout<<"Press '4' to go back"<<endl;
				cin>>subchoice;
				switch(subchoice)
					{
					case 1:
						mob.nthinsert();break;
					default:break;
			
					}
				break;
			case 2:
					/*CHOOSE DELETION POSITION*/
				cout<<"Press '1' for deleting the n'th element"<<endl;
				cout<<"Press '4' to go back"<<endl;
				cin>>subchoice;
				switch(subchoice)
					{
					case 1:
						mob.nthdelete();break;
					default:break;
			
					}
				break;
			
			case 3:
				mob.printlist();	//printing list
				break;
			case 4:
				return 0;		//exit	
				
				
			default:
				cout<<"NOT A valid option"<<endl;
				break;
			
			}

	}
}



void linkedlists::frontinsert()                   //insertion at FRONT place
{
cout<<"\nEnter element"<<"\n";
cin>>val;
temp =(struct node*) malloc(sizeof(struct node));
temp->info=val;
temp->next=head;
head->prev=temp;
temp->prev=NULL;
head=temp;
last->next=head;
nodes++;
printlist();
}

/*--------------------------------------------CLASS linkedlists extension------------------------------------------*/


void linkedlists::lastinsert()			//insertion at last place
{
cout<<"\nEnter element"<<"\n";
cin>>val;
temp =(struct node*) malloc(sizeof(struct node));
temp->info=val;
temp->next=NULL;
temp->prev=last;
last->next=temp;
last=temp;
last->next=head;
nodes++;
printlist();
}

void linkedlists::nthinsert()			//insertion at nth place
{
temp =(struct node*) malloc(sizeof(struct node));
cout<<"\nEnter position"<<"\n";
cin>>pos;
pos=pos%nodes;
if(pos==1)
{
	frontinsert();
	return;
}
if(pos==0||pos==nodes)
{
	lastinsert();
	return;
}

cout<<"\nEnter element"<<"\n";
cin>>val;
temp->info=val;
traverse();
tempprev->next=temp;
temp->prev=tempprev;
temp->next=tempnext;
tempnext->prev=temp;
last->next=head;
nodes++;
printlist();
}

void linkedlists::frontdelete()			//deletion of FRONT node
{
temp=head;
head=head->next;
head->prev=NULL;
free(temp);
nodes--;
printlist();

}

void linkedlists::lastdelete()			//deletion of last node
{
temp=last;
last=last->prev;
last->next=NULL;
free(temp);
nodes--;
printlist();
}

void linkedlists::nthdelete()			//deletion of nth node
{
cout<<"\nEnter position"<<"\n";
cin>>pos;
pos=pos%nodes;
if(pos==1)
{
	frontdelete();
	return;
}
if(pos==0||pos==nodes)
{
	lastdelete();
	return;
}
traverse();
temp=tempnext;
tempnext=temp->next;
tempprev->next=tempnext;
tempnext->prev=tempprev;
free(temp);
nodes--;
printlist();
}

void linkedlists::traverse()			// reaching at pos position of linked lists
{
pos--;
tempnext=head;
while(pos--)
{
tempnext=tempnext->next;
}
tempprev=tempnext->prev;
}

