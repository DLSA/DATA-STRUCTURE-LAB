import java.util.Scanner;
import java.util.Stack;
import java.util.*;


class node 
	{	
	node left,right;
	int info;
	node(int info)
	{
	left=null;
	right=null;
	this.info=info;
	}
	}
	
	



class binarytree
	{
		node root,temp;
	 public void insert(int info)
	 {
	 	if(root==null)
	 	{
		root=new node(info);	 	
 		}
 		else
 		{
 		node temp=new node(info);
 		node link=attachpoint(root,info);
 		if(info<link.info)
 		{
 			link.left=temp;
 		}
 		else
 			link.right=temp;
 		}
	 }
	 public node attachpoint(node link,int info)
	 {
	 	
	 	if(info>link.info)
	 	{
	 		if(link.right==null)
	 		{
	 		return link;
	 		}
	 		else
	 		return attachpoint(link.right,info);
	 	}
	 	else
	 		if(link.left==null)
	 		{
	 		return link;
	 		}
	 		else
	 		return attachpoint(link.left,info);
	 
	 }
	public void inorder(node temp)
	{
		if(temp==null)
		{
			return;
		}
		else 
		{
			inorder(temp.left);
			System.out.print(temp.info+"\t");
          		inorder(temp.right);
	
		}
	}
	public void preorder(node temp)
	{
		if(temp==null)
		{
			return;
		}
		else 
		{
		
			System.out.print(temp.info+"\t");
			preorder(temp.left);
          		preorder(temp.right);
	
		}
	}
	public void postorder(node temp)
	{
		if(temp==null)
		{
			return;
		}
		else 
		{
			postorder(temp.left);
          		postorder(temp.right);
			System.out.print(temp.info+"\t");
	
		}
	}
	public void levelorder(node temp)
	{
	
	
	}
	public void inorder2(node temp)
	{
		Stack<node> stk = new Stack<node>();
		while(temp!=null)
		{
			stk.push(temp);
			temp=temp.left;
		}
	while(!stk.isEmpty())
	{
		temp=stk.pop();
		System.out.print(temp.info+"\t");
		if(temp.right!=null)
		{
		temp=temp.right;
		
		while(temp!=null)
		{
			stk.push(temp);
			temp=temp.left;
		}
		}
		
	}	
	}
	public void preorder2(node temp)
	{
		Stack<node> stk = new Stack<node>();
		stk.push(temp);
		while(!stk.isEmpty())
		{
			temp=stk.pop();
			System.out.print(temp.info+"\t");
			if(temp.right!=null)
			stk.push(temp.right);
			if(temp.left!=null)
			stk.push(temp.left);
		}
	}
	public void postorder2(node temp)
	{
		Stack<node> stk = new Stack<node>();
		
	}
	public void levelorder2(node temp)
	{
	
	
	}
}








public class ds_lab_treetraversal_p5

	{
	
		public static void main(String args[])
		{
			Scanner scan= new Scanner(System.in);
			binarytree btree= new binarytree();
			while(true)
			{
			
          		  System.out.println("\nPress 1 to insert an element in the tree");
          		  System.out.println("Press 2 for traversing the tree \n\n");
          		  int a=scan.nextInt();
          		  switch(a)
          		  {
          		  case 1:
          		  		System.out.println("enter element ");
          		       	  	btree.insert(scan.nextInt());
          		       	  	break;
          		  case 2:
          		  		if(btree.root==null){System.out.println("Tree has no nodes!\n\n");break;}
          				
          		  		System.out.println("RECURSIVE TRAVERSAL:");
			  				System.out.print("\nDFT:\nINORDER TRAVERSAL:\t");
			  				btree.inorder(btree.root);System.out.println();
			  				
			  				System.out.print("PREORDER TRAVERSAL:\t");
			  				btree.preorder(btree.root);System.out.println();
			  				
			  				System.out.print("POSTORDER TRAVERSAL:\t");
			  				btree.postorder(btree.root);System.out.println();
			  				
			  			//	System.out.println("\nBFT:\nLEVEL ORDER TRAVERSAL:\t");
			  			//	btree.levelorder(btree.root);System.out.println();
		  		  		
          		  		System.out.println("\n\nITERATIVE TRAVERSAL:");
          		  		
			  				System.out.print("\nDFT:\nINORDER TRAVERSAL:\t");
			  				btree.inorder2(btree.root);System.out.println();
			  				
			  				System.out.print("PREORDER TRAVERSAL:\t");
			  				btree.preorder2(btree.root);System.out.println();
			  				
			  			//	System.out.print("POSTORDER TRAVERSAL:\t");
			  			//	btree.postorder2(btree.root);System.out.println();
			  				
			  			//	System.out.println("\nBFT:\nLEVEL ORDER TRAVERSAL:\t");
			  			//	btree.levelorder2(btree.root);System.out.println();
          				break;	
          				  		
          		  
          		  		
          		  default:	
          		  		System.out.println("Invalid entry!\n\n");break;
          		  				  
          		  }
			
			
			}	
			
	
		}
	}
