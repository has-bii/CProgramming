#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *next;
};

typedef struct node node;

void traverseList(struct node *head)
{
    struct node *p;
    p = head;

    while (p != NULL)
    {
        printf("%d--->", p->number);
        p = p->next;
    }
}

struct node* deleteMiddleList(struct node* head)
{
    node *q, *p;
    p = head;

    int counter = 1;

    while (p->next != NULL)
    {
        p = p->next;
        counter++;
    }

    p = head;

    counter = (counter/2);

    for (int i = 1; i < counter; i++)
    {
        q = p;
        p = p->next;
    }
    
    q->next = p->next;
    free(p);

    return head;
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

    head = deleteMiddleList(head);
    printf("\nList after deleting middle list: \n");
    traverseList(head);

    return 0;
}