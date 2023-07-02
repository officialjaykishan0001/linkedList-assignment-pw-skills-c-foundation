#include<iostream>
#include<algorithm>
using namespace std;
//problem : given a linkedList(singly) and a value x . you need to update the given linkedList like this
// all the element less than or equal to x is at left hand side of LInkedList and all the elemenst greater 
//than x is on the right side of the LinkedList..
class node{
	public : 
	int data;
	node* next;
	
	node(int val)
	{
		data = val;
		next= NULL;
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
		node* temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"-> ";
			temp = temp->next;
		}
		
		cout<<"NULL"<<endl;
		
		return ;
	}
	
	void insert(int val)
	{
		node* new_node = new node(val);
		
		if(head == NULL)
		{
			head = new_node;
			return ;
		}
		node* temp  = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		
		temp->next = new_node;
		
		return ;
		
	}
};

node* solution(node* &head,int &x)
{
	LinkedList tm;
	node* temp1 = head;
	node* newHead = temp1;
	node* prev = NULL;
	while(temp1!=NULL)
	{
		prev = temp1;
		if((temp1->data)>x)
		{
			tm.insert(temp1->data);
			node* tobedeleted = temp1 ;
			temp1 = temp1->next;
			prev->next = temp1;
				
		}
		else{
			temp1 = temp1->next;
		}
	
	}
	
	node* itr = temp1;
	while(itr->next!=NULL)
	{
		itr = itr->next;
	}
	
	itr->next = tm.head;
	
	return newHead;
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
    
    cout<<endl<<"the required LinkedList is : "<<endl;
    
    l.head = solution(l.head,x);
    
    l.display();
    
    
    
    return 0;
}
