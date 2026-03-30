#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} NODE, *PNODE, **PPNODE;

PNODE createNode(int data)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = data;
    newn->left = NULL;
    newn->right = NULL;

    return newn;
}

bool insertNode(PPNODE root, int data)
{
    bool inserted = false;
    PNODE temp = *root;
    PNODE newn = NULL;
    newn = createNode(data);

    if (*root == NULL)
    {
        *root = newn;
        inserted = true;
    }
    else
    {
        while (1)
        {
            if (data == temp->data)
            {
                printf("\nNode with value %d already exists, cannot insert duplicate node...\n", data);
                inserted = false;
                break;
            }
            else if (data < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = newn;
                    inserted = true;
                    break;
                }
                temp = temp->left;
            }
            else if (data > temp->data)
            {

                if (temp->right == NULL)
                {
                    temp->right = newn;
                    inserted = true;
                    break;
                }
                temp = temp->right;
            }
        }
    }

    return inserted;
}

bool removeNode(PPNODE root, int data)
{
    return false;
}

void inOrder(PNODE root)
{
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main()
{

    printf("\n---------------------------------------Tree----------------------------------------------\n");

    int choice = 0, value = 0;
    bool ret = false;
    PNODE tree = NULL;
    while (1)
    {
        printf("\nMenu :\n1. Create a tree.\n2. Insert a node in the tree.\n3. Remove a specific node from the tree.\n4.Inorder Traversal.\n5.Exit");
        printf("\nEnter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            PNODE tree = NULL;
            printf("\nIntialized a tree...\nYou can insert nodes now!");
            break;
        case 2:
            printf("\n------------------------------Insert function-----------------------------------\n");
            printf("\nEnter a node value to insert : ");
            value = 0;
            scanf("%d", &value);

            ret = insertNode(&tree, value);

            if (ret == true)
            {
                printf("\nSuccess : %d inserted in our tree!\n", value);
            }
            else
            {
                printf("\nError : inserting %d in the tree, try again!\n", value);
            }

            break;
        case 3:
            printf("\n------------------------------Remove function-----------------------------------\n");
            printf("\nEnter the node value you want to remove : ");
            value = 0;
            scanf("%d", &value);
            ret = removeNode(&tree, value);

            if (ret == true)
            {
                printf("\nSuccess : %d node removed from the tree!\n", value);
            }
            else
            {
                printf("\nError : removing %d node from the tree, try again!\n", value);
            }
            break;
        case 4:
            printf("\n------------------------------Inorder Traversal----------------------------------\n");
            printf("LEFT => NODE => RIGHT\n");
            inOrder(tree);
            break;            
        case 5:
            printf("\n----------------------------Thankyou for using Trees-----------------------------\n");
            exit(0);
        default:
            printf("\nInvalid choice entered...\n");
            break;
        }
    }

    return 0;
}