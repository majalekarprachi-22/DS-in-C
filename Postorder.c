#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int value)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}
void postorder(struct Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    struct Node *root=NULL;
    int n,i,value;

    printf("Enter the number of nodes:");
    scanf("%d",&n);
    printf("Enter %d values:\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        root=insert(root,value);
    }

    printf("\n Postorder Traversal:");
    postorder(root);
}