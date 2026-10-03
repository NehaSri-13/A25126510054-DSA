/*
Develop a C program for a Doubly Linked List representing a sequence of web pages
visited by a user. The program should insert a new page, move forward and backward,
delete a specified page, and display the pages from first-to-last and last-to-first
while handling beginning and end conditions correctly.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char page[50];
    struct Node *prev;
    struct Node *next;
};
struct Node *head=NULL;
struct Node *current=NULL;
void insertPage()
{
    struct Node *newNode;
    char page[50];
    newNode=(struct Node *)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter webpage name: ");
    scanf("%49s",page);
    strcpy(newNode->page,page);
    newNode->prev=NULL;
    newNode->next=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        struct Node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
    current=newNode;
    printf("Webpage inserted successfully.\n");
}
void moveForward()
{
    if(current==NULL)
    {
        printf("No webpage available.\n");
        return;
    }
    if(current->next==NULL)
    {
        printf("Already at the last page.\n");
    }
    else
    {
        current=current->next;
        printf("Current page: %s\n",current->page);
    }
}
void moveBackward()
{
    if(current==NULL)
    {
        printf("No webpage available.\n");
        return;
    }
    if(current->prev==NULL)
    {
        printf("Already at the first page.\n");
    }
    else
    {
        current=current->prev;
        printf("Current page: %s\n",current->page);
    }
}
void deletePage()
{
    struct Node *temp=head;
    char page[50];
    if(head==NULL)
    {
        printf("No webpages available.\n");
        return;
    }
    printf("Enter webpage to delete: ");
    scanf("%49s",page);
    while(temp!=NULL&&strcmp(temp->page,page)!=0)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Webpage not found.\n");
        return;
    }
    if(temp->prev!=NULL)
        temp->prev->next=temp->next;
    else
        head=temp->next;
    if(temp->next!=NULL)
        temp->next->prev=temp->prev;
    if(current==temp)
    {
        if(temp->next!=NULL)
            current=temp->next;
        else
            current=temp->prev;
    }
    free(temp);
    printf("Webpage deleted successfully.\n");
}
void displayForward()
{
    struct Node *temp=head;
    if(head==NULL)
    {
        printf("No webpages available.\n");
        return;
    }
    printf("Pages from first to last:\n");
    while(temp!=NULL)
    {
        printf("%s ",temp->page);
        temp=temp->next;
    }
    printf("\n");
}
void displayBackward()
{
    struct Node *temp=head;
    if(head==NULL)
    {
        printf("No webpages available.\n");
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    printf("Pages from last to first:\n");
    while(temp!=NULL)
    {
        printf("%s ",temp->page);
        temp=temp->prev;
    }
    printf("\n");
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n--- Doubly Linked List ---\n");
        printf("1. Insert Page\n");
        printf("2. Move Forward\n");
        printf("3. Move Backward\n");
        printf("4. Delete Page\n");
        printf("5. Display First to Last\n");
        printf("6. Display Last to First\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        if(scanf("%d",&choice)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            continue;
        }
        switch(choice)
        {
            case 1:
                insertPage();
                break;
            case 2:
                moveForward();
                break;
            case 3:
                moveBackward();
                break;
            case 4:
                deletePage();
                break;
            case 5:
                displayForward();
                break;
            case 6:
                displayBackward();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
