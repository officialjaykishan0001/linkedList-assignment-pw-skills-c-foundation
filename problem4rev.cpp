#include<iostream>

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


class list{
	public : 
	node* head;
	
	
	list ()
	{
		head = NULL;
	}
	
	void insert(int val)
	{
		node* newhead = new node(val);
		
		if(head == NULL)
		{
			head = newhead ;
			return ;
		}
		
		node* temp = head;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
			
		}
		
		temp->next = newhead;
		
		return ;
	}
	
	void display()
	{
		node* temp = head;
		while(temp!=NULL)
		{
			cout<<temp->val<<" ";
			temp = temp->next;
		}
		cout<<"NULL"<<endl;
		
		return ;
	}
};

void RevAndMerge(node* &head,int left,int right)
{
	node* temp = head;
	
	for(int i=0;i<left-1;i++)
	{
		temp = temp->next;
		
	}
	
	node* curr = temp->next;
	
	node* prev = NULL;
	
	for(int i=0;i<right-left;i++)
	{
		node* next = curr->next;
		curr->next  = prev;
		prev = curr;
		curr = next;
		
	}
	
	temp->next->next = curr;
	temp->next = prev;
	
	
}
int main()
{
	list l;
	int n;
	cout<<"Enter the size of the list : ";
	cin>>n;
	
	cout<<endl<<"Now, Enter the nodes : "<<endl;
	while(n--)
	{
		int ele;
		cin>>ele;
		
		l.insert(ele);
	}
	
	int left,right;
	cout<<"Enter the left pointer : ";
	cin>>left;
	
	cout<<endl<<"Enter the right pointer : ";
	cin>>right;
	
	RevAndMerge(l.head,left,right);
	
	cout<<endl<<endl;
	l.display();
	
	
	return 0;
}
