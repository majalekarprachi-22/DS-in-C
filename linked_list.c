#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
 };
int main()
{ 
   struct node *head = NULL;
   struct node *temp;
     
  temp = (struct node*)malloc(sizeof(struct node));
   temp->data = 10;
   temp->next = NULL;
     
   head = temp;

 printf("Data = %d",head->data);

return 0;

}
