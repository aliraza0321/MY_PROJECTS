//reverse dubbly linked list without traverse back

#include <iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node*pre;
    node(int data)
    {
        this->data=data;
        next=nullptr;
        pre=nullptr;
    }
   
};
class DLL
{
    node*head;
    public:
     DLL()
     {
         head=nullptr;
    }
    void addAtHead(int data)
    {
        node*newnode=new node(data);
        if(head==nullptr)
        {
            head=newnode;
            
        }
        else
        {
            newnode->next=head;
            head->pre=newnode;
            head=newnode;
        }
    }
    void addEnd(int data)
    {
        node*newnode=new node(data);
        if(head==nullptr)
        {
            head=newnode;
        }
        else
        {
            node*temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            newnode->pre=temp;
            temp->next=newnode;
            
        }
    }
    void print()
    {
        node*temp=head;
        while(temp->next!=nullptr)
        {
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<endl;
    }
    void reverse()
    {
        node*before,*cur,*after;
        before=nullptr;
        cur=after=head;
        while(cur!=nullptr)
        {
            after=cur->next;
            cur->next=before;
            cur->pre=after;
            before=cur;
            cur=after;
            
        }
        head=before;
    }
};
int main()
{
    
    DLL l1;
    l1.addAtHead(1);
    l1.addEnd(2);
    l1.addEnd(3);
    l1.print();
    l1.reverse();
    l1.print();
    // Write C code here
    //printf("Try programiz.pro");

    return 0;
}
