#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node * next;
};

typedef struct node node;

struct node* cutheadaddlast(struct node* head)
{
    node *p;
    node *temp = malloc(sizeof(node));
    p = head;

    temp->number = p->number;
    temp->next = NULL;
    
    head = p->next;

    while (p->next != NULL)
    {
        p = p->next;
    }
    
    p->next = temp;

    return head;
}

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

int main()
{
    struct node *p, *head;
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

    printf("\nLinked list before the function:\n");

    traverseList(head);

    head = cutheadaddlast(head);

    printf("\nLinked list after the function:\n");

    traverseList(head);

    return 0;
}