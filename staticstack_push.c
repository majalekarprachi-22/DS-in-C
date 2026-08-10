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
   if(sp->top==SIZE-1)
        return 1;
   else
       return 0;
}
void push(struct stack *sp, int data)
{
     if(stack_full(sp))
{
        printf("Stack is full.\n");
}
     else
{
     (sp->top)++;
    sp->arr[sp->top] = data;

     printf("%d pushed into stack.\n",data);
}
}
int main()
{ 
struct stack s;

init_stack(&s);

push(&s,10);
push(&s,20);
push(&s,30);

return 0;
}

   
