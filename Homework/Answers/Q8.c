#include <stdio.h>
#include <stdlib.h>

//This question actually is the same with question number 4

struct node
{
    int number;
    struct node *next;
};

typedef struct node node;

node *swapFirstAndLast(node *head)
{
    node *p, *q, *temp;
    p = head;
    q = head;
    
    temp->number = p->number;
    temp->next = NULL;

    while (p->next != NULL)
    {
        p = p->next;
    }

    q->number = p->number;
    p->number = temp->number;
    
    return head;
}

void traverseList(node *head)
{
    node *p;
    p = head;

    while (p != NULL)
    {
        printf("%d--->", p->number);
        p = p->next;
    }
}

int main()
{
    node *p, *head;
    int N;

    printf("Enter the number of list: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            head = malloc(sizeof(node));
            p = head;
        } else
        {
            p->next = malloc(sizeof(node));
            p = p->next;
        }
        printf("Enter a number: ");
        scanf("%d", &p->number);
        p->next = NULL;
    } 

    printf("List before deleting middle list: \n");
    traverseList(head);

    head = swapFirstAndLast(head);

    printf("\nList after deleting middle list: \n");
    traverseList(head);

    return 0;
}