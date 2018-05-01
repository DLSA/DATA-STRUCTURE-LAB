import java.util.*;
import java.util.Vector;
import java.util.Scanner;
class queue
{
    int i,j,front=-1,rear=-1;
		Vector vec = new Vector();
    public boolean isEmpty()
    {
        return front==-1&&rear==-1;
    }
    public void insert(Object o)
    {
        if(front==-1)
        {
            front=0;
            rear=0;
            vec.add(o);
        }
       else
       {
           vec.add(o);
           rear++;
       }

    }
    public Object delete()
    {
        Object b=3;

	       	 if(front==-1)
	       	 {
           	 throw new NoSuchElementException("Underflow Exception");
           	 }
           	 else if(front==rear)
             {
                 front=-1;
                 rear=-1;
                 vec.clear();
                 return b;
             }
		b=vec.get(front++);
		return b;

    }
public void print_queue()					//printing stack
	{
		if(isEmpty())
		{
		System.out.print("Queue is empty\n\n");
		}
		 Iterator itr = vec.iterator();
        for(i=0;i<front;i++)
        {
            itr.next();
        }
		while(itr.hasNext())
		{
		 System.out.print(itr.next()+"\t");

		}
	}






};

class ds_queue_p3
{
	static Scanner sc;

		public static void main(String args[])
		{

			sc=new Scanner(System.in);
			queue q=new queue();
			q.print_queue();
			int a;


		 while(true)
          {

            System.out.println("\n\nQUEUE INSERT OR DELETE");
            System.out.println("Press 1 to insert");
            System.out.println("Press 2 to delete");
            System.out.println("Press 3 to EXIT");
			a=sc.nextInt();
			switch(a)
			{
            case 1:
            System.out.println("Enter  element");
                q.insert(sc.next());
                q.print_queue();
                break;
            case 2:
                q.delete();
                q.print_queue();
                break;
            case 3:
                return;
            default:
            System.out.println("INCORRECT OPTION");


			}

          }


		}

};
