#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int rthread; //***
} *root = NULL;
void main()
{
    int choice, item;
    do
    {
        printf("\nEnter the item which you want to insert?\n");
        scanf("%d", &item);
        insert(item);
        printf("\nPress 1 to insert nodes more nodes in tree \n");
        scanf("%d", &choice);
    } while (choice == 1);
}
void insert(int item)
{
    struct node *ptr, *parentptr, *nodeptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("can't insert");
    }
    else
    {
        ptr->data = item;
        ptr->left = NULL;
        ptr->right = NULL;
        ptr->rthread = 1;//***
        if (root == NULL)
        {
            root = ptr;
        }
        else
        {
            parentptr = NULL;
            nodeptr = root;
            while (nodeptr != NULL)
            {
                parentptr = nodeptr;
                if (item < nodeptr->data)
                {
                    nodeptr = nodeptr->left;
                }
                else//***

                {
                    if (nodeptr->rthread == 0)
                    {
                        nodeptr = nodeptr->right;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (item < parentptr->data)
            {
                parentptr->left = ptr;
                ptr->right = parentptr;//***
            }
            else
            {
                ptr->right = parentptr->right;  //***
                parentptr->right = ptr;
                parentptr->rthread = 0;  //***
            }
        }
        printf("Node Inserted");
    }
}
