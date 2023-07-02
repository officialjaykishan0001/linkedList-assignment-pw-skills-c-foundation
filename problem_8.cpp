#include<iostream>
#include<algorithm>
#include<vector>

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
	int size ;
	LinkedList()
	{
		head = NULL;
	
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
		size++;
		return ;
	}	
};

vector<node*> solution(node* head,int k,int n)
{
	int no_of_parts = n/k;
	vector<node*> output;
	
	node* temp = head;
	
	while(temp!=NULL)
	{	LinkedList tm;
		for(int i=0;i<no_of_parts;i++)
		{
		
			tm.insert(temp->val);
			temp = temp->next;
				
		}	
		output.push_back(tm.head);
		
		
	}
	
	return output;
}

int main()
{
	LinkedList l;
	int n;
	cout<<"No of Node : ";
	cin>>n;
	
	while(n--)
	{
		int ele;
		cin>>ele;
		l.insert(ele);
	}
	
	int k;
	cout<<"Enter the value of K : ";
	cin>>k;
	
	vector<node*> result = solution(l.head,k,n);
	
	while(result[0]!=NULL)
	{
		cout<<result[0]->val<<" ";
		result[0] = result[0]->next;
	}
	return 0;
}
