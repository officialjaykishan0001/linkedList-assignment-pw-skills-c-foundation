#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//problem : given a linkedList(singly) and a value x . you need to update the given linkedList like this
// all the element less than or equal to x is at left hand side of LInkedList and all the elemenst greater 
//than x is on the right side of the LinkedList..
//solution : 
//time complexity : o(n)
//space comlexity : o(n);
class node{
	public : 
	int data;
	node* next ;
	
	node(int val)
	{
		data = val;
		next = NULL;
	}
};

class LinkedList{
	public: 
	node* head;
	
	LinkedList()
	{
		head  = NULL;
	}
	
	void display()
	{
		node* temp = head;
		
		while(temp!=NULL)
		{
			cout<<temp->data<<" -> ";
			temp = temp->next;
			
		}
		cout<<"NULL"<<endl;
		return ;
	}
	
	void insert(int x)
	{
		node* newNode = new node(x);
		if(head==NULL)
		{
			head = newNode;
			return ;
		}
		
		node* temp =head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		
		temp->next = newNode;
		return ;
	}
};

node* solution(node* head,int x)
{
	if(head==NULL) return NULL;
	LinkedList left;
	LinkedList right;
	node* temp = head;
	while(temp!=NULL)
	{
		if(temp->data <= x)
		{
			left.insert(temp->data);
		}
		else{
			right.insert(temp->data);
			
		}
		
		temp = temp->next;
	}
	if(left.head==NULL) return right.head;
	node* tm = left.head;
	while(tm->next!=NULL)
	{
		tm = tm->next;
	}
	
	tm->next  = right.head;
	
	return left.head;
}
int main()
{

	LinkedList l;
	
    
    int n;
    cout<<"Enter The number of node you want to your LinkedList :  ";
    cin>>n;

    while(n--)
    {
        int ele;
        cin>>ele;

        l.insert(ele);
    }
	
    cout<<endl<<"Your entered LinkedList is : "<<endl;

    l.display();
    
    int x;
    cout<<endl<<"Enter the value of x : ";
    cin>>x;
    
    cout<<endl;
    
cout<<"The Required LinkeList is : "<<endl;

l.head = solution(l.head,x);

l.display();
	
	return 0;
}
