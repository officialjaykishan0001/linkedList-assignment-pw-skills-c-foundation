#include<iostream>
#include<vector>
#include<algorithm>
//problem : given a linkedlist(singly) you need to remove/delete the dublicate from it.?
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

void remove_dublicate(node* &head)
{
	node* temp = head;
	
	while(temp->next!=NULL)
	{
		if(temp->data==temp->next->data)
		{
			node* tm = temp->next;
			temp->next = temp->next->next;
			delete(tm);
		}
		else{
			temp = temp->next;
		}
	}
	
	return ;
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
    
    cout<<endl<<"The required LinkedList is : "<<endl;
    remove_dublicate(l.head);
    l.display();
    return 0;
}
/*Jai jai Jai Bajarangbali...
this program coded by jay kishan kharwar
at
time : 1:16
date : 19-06-2023*/
