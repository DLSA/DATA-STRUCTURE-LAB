import java.util.Scanner;
import java.util.*;
import java.util.Arrays;
class MERGE
{
int i,j,size;

	public ArrayList<Integer> mergsort(ArrayList<Integer>vec,int low,int high)
	{
	int middle;
	if(low<high)
	{
		middle=(low+high)/2;
		mergsort(vec,low,middle);
		mergsort(vec,middle+1,high);
		merg(vec,low,middle+1,high);

	}
	for(int m=0;m<vec.size();m++)
		System.out.print(vec.get(m)+"\t");

		System.out.println();
		return vec;


	}

	void merg(ArrayList<Integer>vec,int s1,int s2,int high)
	{
		ArrayList<Integer>v1=new ArrayList<Integer>();
		ArrayList<Integer>v2=new ArrayList<Integer>();
		for(i=s1;i<s2;i++)
			v1.add(vec.get(i));
		for(i=s2;i<=high;i++)
			v2.add(vec.get(i));


	int i=0,j=0;
	int k=s1;
	while(i<v1.size() && j<v2.size())
	{	if(v1.get(i)<=v2.get(j))
		{
		vec.set(k,v1.get(i));
		i++;
		}
		else if(v2.get(j)<v1.get(i))
		{
		vec.set(k,v2.get(j));
		j++;
		}
		k++;
	}
	while(i<v1.size())
	{
		vec.set(k,v1.get(i));
		i++;
		k++;
	}
	while(j<v2.size())
	{
		vec.set(k,v2.get(j));
		j++;
		k++;
	}

	}

}

public class mergesort
{
	static int elements,i,cases,elm;
	static ArrayList<Integer>vec=new ArrayList<Integer>();
	static ArrayList<Integer>vec1=new ArrayList<Integer>();
	static ArrayList<Integer>vec2=new ArrayList<Integer>();
	public static void main(String args[])
	{
		Scanner scan =new Scanner(System.in);
		MERGE obj=new MERGE();
		while(true)
		{
			System.out.println("MERGE AT 1");
			System.out.println("MERGING AT 2");
			cases=scan.nextInt();

			switch(cases)
			{
			case 1:
				System.out.println("Enter no of elements in the list\n");
				elements=scan.nextInt();
				System.out.println("Enter elements\n");
				for(i=0;i<elements;i++)
				{	elm=scan.nextInt();
					vec.add(elm);
				}
				MERGE ob=new MERGE();
				vec=ob.mergsort(vec,0,elements-1);
				break;
			case 2:
				System.out.println("Enter no of elements in the list 1\n");
				elements=scan.nextInt();
				for(i=0;i<elements;i++)
				{	elm=scan.nextInt();
					vec1.add(elm);
				}
				int element1=elements;
				MERGE ob1=new MERGE();
				vec1=ob1.mergsort(vec1,0,elements-1);

				System.out.println("Enter no of elements in the list 2\n");
				elements=scan.nextInt();
				for(i=0;i<elements;i++)
				{	elm=scan.nextInt();
					vec2.add(elm);
				}
				vec2=ob1.mergsort(vec2,0,elements-1);

				for(i=0;i<elements;i++)
                    vec1.add(vec2.get(i));

                for(int m=0;m<vec1.size();m++)
                System.out.print(vec1.get(m)+"\t");


				ob1.merg(vec1,0,element1,element1+elements-1);




			}

		}





	}



}

