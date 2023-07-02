#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
//time complexity : o(n)
//space complexity : o(1);
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

int  decimalEqua(node* head){
	node* curr = head;
	node* prev = NULL;
	while(curr!=NULL)
	{
		node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	int sum = 0;
	int i = 0;
	while(prev!=NULL)
	{
		sum = sum + ((prev->val) *
		 pow(2,i));
		prev = prev->next;
		i++;
	}
	
	return sum;
}
int main()
{
	int n;
	cout<<"Enter how many node your want : ";
	cin>>n;
	
	cout<<"Now, enter the node : "<<endl;
	list l;
	while(n--)
	{
		int ele;
		cin>>ele;
		
		l.insert(ele);
	}

	cout<<endl<<"the decimal equavalent is : "<<decimalEqua(l.head)<<endl;
	return 0;
	
}
/*jai jai jai bajarangbali...
this program coded by jay kishan kharwar
at
time : 2:45
date : 24-06-2023*/
