//in this program we will try to solve the singly linkedList assignment problem no 1

//Problem statement : You are given two non-empty linked lists representing two non-negative integers. The digits
//are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and store the
//sum in the first linked list.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class node{
    public : 
    int data;
    node* next;

    node(int val)
    {
        data = val ;
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
        node* temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp = temp->next;
        }
    cout<<"NULL"<<endl;
        return ;
    }

    void insert(int num)
    {
        node* new_node = new node(num);

        if(head==NULL){
            head = new_node;
            return ;
        }

        node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;

        }

        temp->next = new_node;

        return;
    }
};

node* sumOfLinkedList(node* head1,node* head2)
{
	node* temp1 = head1;//this temp1 will traverse through the head1
	node* temp2 = head2;//this temp2 will traverse throught the head2
	
	LinkedList ans;//this is the ans linkedList where we store the answer.
	while(temp1!=NULL && temp2!=NULL)
	{
		ans.insert(temp1->data + temp2->data);
		temp1 = temp1->next; //here we push the temp1 pointer to one step ahead.
		temp2 = temp2->next;//here we push the temp2 pointer to one step ahead.

	}
	
	while(temp1 !=NULL)//in case if temp1 is not fully traversed due to temp2 
	{
		ans.insert(temp1->data);
		temp1 =temp1->next;//push one step ahead.
	}
	
	while(temp2 !=NULL)//in case if temp2 is not fully traversed due to temp1.
	{
		ans.insert(temp2->data);
		temp2 = temp2->next;//push the temp2 one step ahead.
	}
	
	return ans.head; 
	
	
}
int main()
{
	int m,n;
	cin>>m;
	cout<<endl;
	cin>>n;
	LinkedList l1;
	while(m--)
	{
		int ele;
		cin>>ele;
		l1.insert(ele);
	}
	LinkedList l2;
	while(n--)
	{
		int ele;
		cin>>ele;
		l2.insert(ele);
	}
	
	LinkedList output;
	output.head = sumOfLinkedList(l1.head,l2.head);
	
	cout<<"The final answer is : "<<endl;
	
	output.display();
	return 0;
}
/*Jai Jai Jai Bajarangbali...
this program coded by Jay kishan kharwar
at
time : 12:49
date : 26-06-2023*/
