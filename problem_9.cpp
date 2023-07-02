/*PROBLEM _ 9 : You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning
and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is
the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

The first line of input contains n, the size of the list.

The second line of input contains the elements of the linked list.

Input

6

0 3 1 0 2 0


Output

4->2->NULL
*/

#include<iostream>
#include<algorithm>

using namespace std;

class node{
	public : 
	int val;
	node* next;
	
	node(int data)
	{
		val = data;
		next = NULL;
	}
	
	
};

class LinkedList{
	public : 
	node* head;
	
	LinkedList()
	{
		head = NULL;
	}
	
	void display()
	{
		node* temp =head;
		while(temp!=NULL)
		{
			cout<<temp->val<<" ";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
	}
	
	void insert(int val)
	{
		node* newNode = new node(val);
		
		if(head==NULL)
		{
			head = newNode;
			return ;
		}
		
		node* temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
			
		}
		
		temp->next = newNode;
		return  ;
	}	
};


node* sumOfConsucative(node* head)
{
	if(head==NULL)
	{
		return NULL;
	}
	int sum = 0;
	node* temp  = head;
	LinkedList output;
	while(temp!=NULL)
	{
		if(temp->val == 0 && sum!=0)
		{
			output.insert(sum);
			sum = 0;
		}
		else{
			sum+=temp->val;
		}
		temp = temp->next;
	}
	
	if(sum!=0)
	{
		output.insert(sum);
	}
	return output.head;
}



int main()
{
	
	LinkedList l;
	int n;
	cout<<"Enter No of node : ";
	cin>>n;
	
	while(n--)
	{
		int ele;
		cin>>ele;
		l.insert(ele);
	}
	
	LinkedList result;
	result.head = sumOfConsucative(l.head);
	
	cout<<endl<<"Final Answer : "<<endl<<endl;
	
	result.display();
	return 0;
}
/*Jai Jai Jai Bajarangbali....
this program coded by jay kishan kharwar
at
time : 2:26
date : 02-07-2023*/
