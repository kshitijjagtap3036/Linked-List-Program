Linked list program to delete a given node in a singly linked list in c++ regardless of its position in one function. 
This program delets the node at beginning, middle, or end of the singly linked list all in one function.

Enjoy the code...!


#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node* next;
}*start=NULL;
static int count;
void create()
{
   char ch;
   do
   {
       struct node *new_node,*current;
       new_node=(struct node*)malloc(sizeof(struct node));
       cout<<"Enter data in node : ";
       cin>>new_node->data;
       new_node->next=NULL;
       if(start==NULL)
       {
           start=new_node;
           current=new_node;
       }
       else
       {
           current->next=new_node;
           current=new_node;
       }
       cout<<"\nDo you want to enter another data?(y/n) : ";
       cin>>ch;

       count++; //to get node count
   }while(ch!='n');
}
void display()
{
   struct node *temp;
   int i=0;
   temp=start;
   cout<<"\nElements in the list are\nNode Number\tData\n";
   while(temp!=NULL)
   {
       cout<<++i<<"\t\t"<<temp->data<<"\n";
       temp=temp->next;
   }
}
void del_node_position()
{
   char ch;
   do
   {
       struct node *node1,*temp,*delNode,*delPrev,*delNext,*secondNode;//*temp1;
       int pos,i,delData;
       temp=start;
       cout<<"\nEnter position of node to delete: ";
       cin>>pos;
       if(pos==1)
       {
           delData=start->data;
           start=start->next;
           free(temp);
       }
       else
       {
           temp=start;
           for(i=1;i<(pos-1);i++)
           {
               temp=temp->next;
           }
           delPrev=temp;
           delNode=delPrev->next;
           delNext=delNode->next;
           delPrev->next=delNext;
           delData=delNode->data;
           free(delNode);
       }
       count--;
       cout<<"Node "<<pos<<" with data field containing "<<delData<<" is deleted\n";
       if(count==0)
       {
           cout<<"\nLinked List is empty\n";
           break;
       }
       else
       {
           display();
           cout<<"\nDo you want to delete another node?(y/n)\n";
           cin>>ch;
       }
   }
   while(ch!='n');
}
void main()
{
   clrscr();
   create();
   display();
   del_node_position();
   getch();
}
