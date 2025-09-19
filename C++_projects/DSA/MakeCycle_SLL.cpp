//i am making cycle at third position and run at specific times print function because temp not point null at end it will point 3 node again

#include<iostream>
 using namespace std;
 class node
 {
     public:
     int data;
     node*next;
     node(int data)
     {
         this->data=data;
         next=nullptr;
     }
 };
 class SLL
 {
     node*head;
     int size=0;
     public:
     SLL()
     {
         head=nullptr;
     }
     void addHead(int data)
     {
         node*newnode=new node(data);
         if(head==nullptr)
         {
             head=newnode;
             size++;
         }
         else
         {
             
         
         newnode->next=head;
         head=newnode;
         size++;
        }
     }
     void addEnd(int data)
     {
         node*newnode=new node(data);
         if(head==nullptr)
         {
             head=newnode;
             size++;
         }
         else
         {
             node*temp=head;
             while(temp->next!=nullptr)
             {
                 temp=temp->next;
             }
              temp->next=newnode;
              size++;
         }
     }
     void print()
     {
         node*temp=head;
        // while(temp->next!=nullptr)
        for(int i=0;i<10;i++)
         {
             cout<<temp->data<<" => ";
             temp=temp->next;
         }
         cout<<temp->data;
     }
     void makeCycle(int pos)
     {
         node*temp=head;
         while(temp->next!=nullptr)
         {
             temp=temp->next;
         }
         node*place=head;
         for(int i=0;i<pos-1;i++)
         {
             place=place->next;
         }
         temp->next=place;
     }
     
 };
 int main()
 {
     SLL l1;
     l1.addHead(1);
     l1.addEnd(2);
     l1.addEnd(3);
     l1.addEnd(4);
     l1.addEnd(5);
     l1.addEnd(6);
     l1.makeCycle(3);
     l1.print();
 }
