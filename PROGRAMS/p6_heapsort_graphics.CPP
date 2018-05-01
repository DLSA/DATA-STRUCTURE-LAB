#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
class heap
{
	private:
		int comp,size,i,no,reduce,opt;
	       int list[100];
			char text[128];
	public:
	void input()
	{

		printf("\n\nEnter number of elements\n\n");
		scanf("%d",&size);
		

		for(i=0;i<size;i++)
		{
		scanf("%d",&list[i]);
		}
    opt=20-(size/2);
	clrscr();
	 	heapsort(size);
		print(0);
	
	}
	void heapsort(int size)
	{
		int first,last,i,j;
	//	for(i=0;i<size;i++)
	//			printf("%d\t",list[i]);
	//	printf("\nTHIS IS A HEAP :\n");
		for(i=size/2;i>=0;i--)
				domaxheapofnode_i(i,size);


	//	for(j=0;j<size;j++)
	//			printf("%d\t",list[j]);
	//	printf("\n");
		for(i=size-1;i>0;i--)
		{
		//	printf("\n\n HEAP CREATED!  ");
		//	visual(300,20,0,i,0,0);
			first=list[0];
			list[0]=list[i];
			list[i]=first;
			domaxheapofnode_i(0,i);

	//		printf("\nGREATEST ELEMENT From 1 to %d  is placed at : %d in the heap\n",i,i+1);
	//		for(j=0;j<size;j++)
	//			printf("%d\t",list[j]);
	//	printf("\n");
		}
	}


	void domaxheapofnode_i(int pos,int size)
	{
	int leftchild=pos*2+1;
	int rightchild=pos*2+2;
	int larger=pos;

			if(leftchild<size)
			{
			if(list[leftchild]>list[larger])
				larger=leftchild;
			}
			if(rightchild<size)
			{
			if(list[rightchild]>list[larger])
				larger=rightchild;
			}
		if (larger != pos)
		{
		int temp=list[pos];
		list[pos]=list[larger];
		list[larger]=temp;
		domaxheapofnode_i(larger,size);
		}

	reduce=1;
	clrscr();
	print(size);
	printf(" \n\n\nHEAPIFYING! \n");
	setcolor(WHITE);
	visual(300,20,0,size,pos,0);
	delay(5000);
	clrscr();
	delay(1000);
	}



	void print(int size)
	{

	printf("\n CONTENTS OF THE ARRAY\n\n");
		for(int i=0;i<size;i++)
				printf("%3d",list[i]);
				
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nLIST AS being Processed:\n");
		for(i=0;i<size;i++)
				printf("-\t");
		while(i<this->size)
		{
				printf("%3d",list[i]);
				i++;
		}
	
	}
	void visual(int x,int y,int pos,int size,int curr,int reduce)
	{
		
	setbkcolor(GREEN);
		if(pos>=size)
		{
			return;
		}
		
		if(pos==curr)
		{
		setcolor(BLUE);
		circle(x,y,opt);
		setfillstyle(SOLID_FILL,BLUE);
		floodfill(x,y,BLUE);
		}
		else
	{
			setcolor(YELLOW);
		circle(x,y,opt);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(x,y,YELLOW);
	}
		setcolor(RED);
		sprintf(text,"%d",list[pos]);
		outtextxy(x-7,y-7,text);
		setcolor(GREEN);
		if(pos*2+1<size)
		line(x,y,x-60+reduce,y+60-reduce);
		if(pos*2+2<size)
		line(x,y,x+60-reduce,y+60-reduce);
		visual(x-60+reduce,y+60-reduce,pos*2+1,size,curr,reduce+8);
		
		visual(x+60-reduce,y+60-reduce,pos*2+2,size,curr,reduce+8);
	}


};





int main()
{
	int gd=DETECT,gm,i,j,k;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	setbkcolor(GREEN);
		heap obj;
		obj.input();
		setcolor(GREEN);
		printf("\t\t\tDONE!");
		getch();
	closegraph();

	return 0;
}
