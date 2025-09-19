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
     void detectCycle()
     {
         node*slow,*fast;
         slow=fast=head;
         while(fast->next->next!=nullptr)
         {
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast)
             {
                 cout<<"\nyes cycle is exits in this node";
                 return;
             }
         }
         
     }
     void detectCycleNode()
     {
         node*slow,*fast;
         slow=fast=head;
         while(fast->next->next!=nullptr)
         {
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast)
             {
                 slow=head;
                 while(slow!=fast)
                 {
                     slow=slow->next;
                     fast=fast->next;
                     
                 }
                 if(slow==fast)
                 {
                     cout<<endl<<slow->data<<" this node is cycling node of cycle\n";
                     return;
                 }
                 
             }
         }
     }
        
        
         void removeCycle()
{
    node *slow = head, *fast = head;

    // Step 1: Detect cycle
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) // cycle detected
        {
            // Step 2: Find start of cycle
            slow = head;
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }

            // Step 3: Break the cycle
            fast->next = nullptr;
            cout << "Cycle removed successfully.\n";
            return;
        }
    }

    cout << "No cycle found.\n";
}

     void display()
     {
         node*temp=head;
         while(temp->next!=nullptr)
         {
             cout<<temp->data<<" => ";
             temp=temp->next;
             
         }
         cout<<temp->data;
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
     l1.detectCycle();
     l1.detectCycleNode();
     l1.removeCycle();
     l1.display();
 }
