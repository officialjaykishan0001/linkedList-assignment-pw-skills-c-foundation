//7.Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.
//
//The first line of input contains n, the size of the list.
//
//The second line of input contains the elements of the linked list.
//
//Input5
//
//2 5 3 8 10
//
//
//Output
//
//2?3?5?8?10->NULL


#include <bits/stdc++.h>
using namespace std;
 
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
 
class linked_list
{
public:
    Node *head = NULL, *tail = NULL;
 
    void insert(int val)
    {
        if (head == NULL)
        {
            head = tail = new Node(val);
            return;
        }
        tail->next = new Node(val);
        tail = tail->next;
    }
 
    void print()
    {
        Node *curr_node = head;
        while (curr_node != NULL)
        {
            cout << curr_node->data << "->";
            curr_node = curr_node->next;
        }
        cout << "NULL\n";
    }
};
 
Node *insertion_sort_list(Node *head)
{
    Node *new_head = new Node(0);
    new_head->next = head;
    Node *prev = new_head, *curr = head;
    while (curr != NULL)
    {
        if (curr->next != NULL && curr->next->data < curr->data)
        {
            while (prev->next != NULL && prev->next->data < curr->next->data)
            {
                prev = prev->next;
            }
            Node *temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
            prev = new_head;
        }
        else
        {
            curr = curr->next;
        }
    }
    head = new_head->next;
    return head;
}
 
int main()
{
    int n;
    cin >> n;
    linked_list ll;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        ll.insert(val);
    }
    ll.head = insertion_sort_list(ll.head);
    ll.print();
    return 0;
}
