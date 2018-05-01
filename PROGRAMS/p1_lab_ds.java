import java.util.Random;
import java.util.*;
import java.util.Scanner;
import java.util.Arrays;
class lab_ds_p1
{
	static int comp;
		static long t1,t2,t3;
public static void main(String[] args)
{
	Scanner s=new Scanner(System.in);
	System.out.println("\n\nEnter number of elements");
		int N=s.nextInt();
		Random generate=new Random();
		ArrayList<Integer>data=new ArrayList<Integer>(N);
			for (int i=1; i<=N; i++)
			data.add(generate.nextInt(100000));	
		// System.out.println(data);

		data=heapsort(data,N);
	System.out.println("\n\n\tSorted list is as follows\n");
		System.out.println(data);
	System.out.println("Enter element to be searched in the list");
		int element=s.nextInt();
		comp=0;
t1=System.nanoTime();
		int val=binarysearch(data,element,N,0,N);

t2=System.nanoTime();
		if(val==-1)
		{
	System.out.println("element not present in the list "+"\t"+comp);
		}
		else
	System.out.println("element found at position "+(val+1)+"\t"+comp);
	t3=t2-t1;


System.out.println("\n\nWorst case comparisions are :"+(log2(N))+"\t");
System.out.print("\n\tTIME:\n\t in nanoseconds :"+t3+"\n\n");

System.out.print(" \t in milliseconds :"+t3/1000000+"\n\n");	
		
}
public static ArrayList<Integer> heapsort(ArrayList<Integer>data,int N)
{
	int first,last;
System.out.println(data);
		for(int i=N/2;i>=0;i--)
			domaxheapofnode_i(data,i,N);
		
	//  System.out.println(data);
		for(int i=N-1;i>=0;i--)
		{
			first=data.get(0);
			last=data.get(i);
			data.set(0,last);
			data.set(i,first);
			domaxheapofnode_i(data,0,i);	
		}
return data;
}
public static void domaxheapofnode_i(ArrayList<Integer>data,int pos,int size)
{
int leftchild=pos*2+1;
int rightchild=pos*2+2;
int larger=pos;
		
		if(leftchild<size)
		{
		if(data.get(leftchild)>data.get(larger)&&leftchild<=size)
			larger=leftchild;
		}
		if(rightchild<size)
		{
		if(data.get(rightchild)>data.get(larger)&&rightchild<=size)
			larger=rightchild;
		}
	if (larger != pos)
        {	
	int temp=data.get(pos);
	data.set(pos,data.get(larger));
	data.set(larger,temp);
	domaxheapofnode_i(data,larger,size);
	}
}

public static int binarysearch(ArrayList<Integer>data,int element,int N,int left,int right)
{
		
		if(right<left)
		{
		return -1;
		}
		else
		{
		int middle=(left+right)/2;
			int mid=data.get(middle);
			if(mid==element)
			{
				return middle;	
				
			}

			comp=comp+3;
			if(mid>element)
			return binarysearch(data,element,N,left,middle-1);
			else
			return binarysearch(data,element,N,middle+1,right);
		}

}



public static double logb( double a, double b )
{
return Math.log(a) / Math.log(b);
}

public static double log2( double a )
{
return logb(a,2);
}


}

