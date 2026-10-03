/*
A department maintains student roll numbers dynamically. Write a C program using
a Singly Linked List to create the list, insert at the beginning and end, search for
a specified roll number, delete a specified roll number, and display the updated list
after each operation. Handle the case when a requested roll number is not available.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int roll;
    struct Node *next;
};
struct Node *head=NULL;
void display()
{
    struct Node *temp=head;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Roll numbers: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->roll);
        temp=temp->next;
    }
    printf("\n");
}
void insertBeginning()
{
    struct Node *newNode;
    int roll;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter roll number: ");
    scanf("%d",&roll);
    newNode->roll=roll;
    newNode->next=head;
    head=newNode;
    printf("Inserted at beginning.\n");
    display();
}
void insertEnd()
{
    struct Node *newNode,*temp;
    int roll;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter roll number: ");
    scanf("%d",&roll);
    newNode->roll=roll;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newNode;
    }
    printf("Inserted at end.\n");
    display();
}
void search()
{
    struct Node *temp=head;
    int roll,found=0;
    printf("Enter roll number to search: ");
    scanf("%d",&roll);
    while(temp!=NULL)
    {
        if(temp->roll==roll)
        {
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found)
        printf("Roll number %d found.\n",roll);
    else
        printf("Roll number %d not found.\n",roll);
}
void deleteNode()
{
    struct Node *temp=head;
    struct Node *prev=NULL;
    int roll;
    printf("Enter roll number to delete: ");
    scanf("%d",&roll);
    while(temp!=NULL&&temp->roll!=roll)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Roll number not found.\n");
        return;
    }
    if(prev==NULL)
        head=temp->next;
    else
        prev->next=temp->next;
    free(temp);
    printf("Roll number deleted successfully.\n");
    display();
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n--- Singly Linked List ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertBeginning();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                search();
                break;
            case 4:
                deleteNode();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
