#include<stdio.h>
#define SIZE 5
struct stack
{ 
  int arr[SIZE];
  int top;
};
void init_stack(struct stack *sp)
{
  sp->top=-1;
}

int stack_full(struct stack *sp)
{
  if(sp->top == SIZE-1)
    return 1;
  else
    return 0;
}
 
void push(struct stack *sp,int data)
{
   if(stack_full(sp))
{ 
  printf("stack is full\n");
}
   else
{
 (sp->top)++;
sp->arr[sp->top]=data;
}
}

int stack_empty(struct stack *sp)
{
   if(sp->top==-1)
     return 1;
   else
     return 0;
}

void pop(struct stack *sp)
{
  if(stack_empty(sp))
 {
  printf("Stack is Empty.\n"); 
 }
  else
 {
  
printf("%d <- Deleted\n", sp->arr[sp->top]);

(sp->top)--;
}
}

int peek(struct stack *sp)
{
  return sp->arr[sp->top];
}

int main()
{
  int ch,data;

 struct stack s1;
 init_stack(&s1);

do
{
printf("\n0.Exit\n");
printf("1.Push\n");
printf("2.Pop\n");
printf("3.Peek\n");

printf("Enter Your Choice : ");
scanf("%d", &ch);

switch(ch)
{
    case 0:printf("Bye Bye...\n");
	   break;
    case 1:printf("Enter Data");
           scanf("%d",&data);
           push(&s1,data);
           break;
    case 2:pop(&s1);
           break;
    case 3:
	   if(stack_empty(&s1))
	{
	   printf("Stack is Empty.\n");
	}
	   else
	{
	  data = peek(&s1);
	  printf("Peek Value : %d\n", data);
	}
          break;
         default:
		printf("Invalid Choice.\n");
		}

		printf("Top = %d\n", s1.top);

	}while(ch != 0);
 
return 0;

}
















