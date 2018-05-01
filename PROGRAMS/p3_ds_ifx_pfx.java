import java.util.*;
import java.util.Vector;
import java.util.Scanner;
class our_stack					//stack class using Vector class in java
{
		int i,j,top=-1;
		Vector vec = new Vector();		// isempty()
	public boolean isEmpty()
	{
		return top==-1;
	}
	
	public void push(Object o)				//push
	{
		top++;
		vec.add(o);			
	}
	public Object pop()					//pop
	{
	       	 if( isEmpty() )
	       	 {
           	 throw new NoSuchElementException("Underflow Exception");
           	 }
		Object b=vec.get(top--);
		vec.setSize(top+1);
		return b;
	}
	public Object peek()					//peek
	{
		if(!isEmpty())
		       	return vec.get(top);
		 return -1;
	}
	public void print_stack()					//printing stack
	{
		if(isEmpty())
		{
		System.out.println("Stack is empty");
		}
		 Iterator itr = vec.iterator();
    
		while(itr.hasNext())
		{
		 System.out.print(itr.next()+"\t");
		        
		}	
	}
};


class ds_ifx_pfx_p3
{
	static int i=0,flag=0;
	static Scanner sc;
	static char c; 
	static char prec_c;
	
		public static void main(String args[])
		{
			
			sc=new Scanner(System.in);
			String infix=new String("");			//infix string
			String postfix=new String("");			//postfix string
			
			our_stack s=new our_stack();			//object s of stack class
			infix=sc.next();
		 	System.out.println(infix);
		 	System.out.println("char\tSTACK\t\tPOSTFIX");
		 	while(i<infix.length())
		 	{
		 		
		 		c=infix.charAt(i);
		 		
		 		System.out.print(c+"\t");
		 		if(c=='('||c=='['||c=='{')			//for opening braces push
		 		{
		 			if(flag==1){postfix+=" ";}
		 			s.push(c);flag=0;
		 		}	
		 		else if(Character.isLetterOrDigit(c))		//flag : for storing multidigit operands
		 			{postfix+=c;				//partition between operands & operator
		 			flag=1;}
		 		else if(c==')'||c=='}'||c==']')            
		 		{	if(flag==1){postfix+=" ";}flag=0;	//closing braces pop
		 			if(c==')')
		 			{
		 				while(!s.isEmpty()&&s.peek()!='('&&s.peek()!='{'&&s.peek()!='[')
		 					postfix+=s.pop();
		 				if(s.isEmpty()||s.peek()!='(')
		 					System.out.println("Invalid Expression");
		 				else
		 					s.pop();
		 				
		 			}
		 			if(c=='}')
		 			{
		 				while(!s.isEmpty()&&s.peek()!='('&&s.peek()!='{'&&s.peek()!='[')
		 					postfix+=s.pop();
		 				if(s.isEmpty()||s.peek()!='{')
		 					System.out.println("Invalid Expression");
		 				else
		 					s.pop();
		 				
		 			}
		 				if(c==']')
		 			{
		 				while(!s.isEmpty()&&s.peek()!='('&&s.peek()!='{'&&s.peek()!='[')
		 					postfix+=s.pop();
		 				if(s.isEmpty()||s.peek()!='[')
		 					System.out.println("Invalid Expression");
		 				else
		 					s.pop();
		 				
		 			}
		 					
		 		}
		 		
		 		else
		 		{
		 		if(flag==1){postfix+=" ";}
		 		flag=0;
		 		 while (!s.isEmpty() && Prec(c,(char)s.peek()))  //poping when true
                 	 	  postfix += s.pop();
                		s.push(c);
		 		
		 		
		 		
		 		
		 		
		 		}
		 		s.print_stack();
		 		System.out.print("\t\t"+ postfix);
		 		System.out.println("");
		 		i++;
		 	}
		 	postfix+=" ";
		 	while(!s.isEmpty())			//poping rest elements out of stack
		 		postfix+=s.pop();
					
		 System.out.println("Expression:\t"+postfix);				
		}
			static boolean Prec(char ch1,char ch2)		//returns true if priority of ch1 <= ch2  else false
		   	 {  int p1,p2;
				if(ch1=='+'||ch1=='-')
					p1=1;
			        else if(ch1=='*'||ch1=='/'||ch1=='%')
					p1=2;
			      	else if(ch1=='^')	
			      		p1= 3;
			      	else return true;
			      	if(ch2=='+'||ch2=='-')
					p2=1;
			        else if(ch2=='*'||ch2=='/'||ch2=='%')
					p2=2;
			      	else if(ch2=='^')	
			      		p2= 3;
			      	else return true;
			      	if(p1>p2)
			      		return false;
				return true;
		        }
		
}

