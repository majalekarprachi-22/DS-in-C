#include<stdio.h>
#include<stdlib.h>

struct node{
             int data;
             struct node *next;
};
void display(struct node *head)
{
  struct node *temp;
   temp = head;
  while(temp!=NULL)
{
   printf("%d ->",temp->data);
   temp = temp->next;
}
   printf("NULL");
}
int main()
{
   struct node*head=NULL;
   struct node*first=NULL;
   struct node*second=NULL;
   struct node*third=NULL;

   first=(struct node*)malloc(sizeof(struct node));
   
   second=(struct node*)malloc(sizeof(struct node));
   
   third=(struct node*)malloc(sizeof(struct node));

first->data=10;
first->next=second;
second->data=20;
second->next=third;
third->data=30;
third->next=NULL;

head=first;

display(head);

return 0;


}





