//@ttention in this program we will gonna to solve the singly linkedList assignment problem no 6.

//the problem statement : Given the head of a linked list, return the node where the cycle begins. If there is no 
//cycle, return null.


#include<iostream>
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

node* cyclicNode(node* head)
{
	bool flag = false;//this is for the checking if there is any circle presen then it will be true else, false;
	node* slow = head;//this is our slow pointer recently pointing to the head.
	node* fast = head->next;//this is our fast pointer recently pointing to the head.
	while(fast != NULL or fast->next!=NULL)
	{
		slow = slow->next;
		fast= fast->next->next;
		if(slow == fast)
		{
			flag = true;
			break;
		}
		
		
	}
	
	if(flag)
	{
		slow = head;
		while(slow !=fast)
		{
			slow = slow ->next;
			fast = fast->next;
		}
		return slow;
	}
	
	return NULL;
}

int main()
{
	
	
	
	return 0;
	
}
/*jai jai Jai Bajarangbali....
this program coded by Jay kishan kharwar
at time : 1:06
date : 26-06-2023*/
