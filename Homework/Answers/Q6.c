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

int main()
{
    node *head, *p;
    int numara;

    printf("Enter the first number: ");
    scanf("%d", &numara);

    head = malloc(sizeof(node));
    p = head;

    p->number = numara;
    p->next = NULL;

    while (numara != -1)
    {
        if (numara % 2 == 1)
        {
            node *even = malloc(sizeof(node));
            even->number = numara;
            even->next = NULL;

            while (p->next != NULL)
            {
                p = p->next;
            }
            p->next = even;
            
        } else
        {
            node *odd = malloc(sizeof(node));
            odd->number = numara;
            odd->next = head;
            head = odd;
        }
        
        printf("Enter a number: ");
        scanf("%d", &numara);
    }
    
    traverseList(head);

    return 0;
}