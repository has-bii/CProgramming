#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[50];
    int age;
    struct node *next;
};

typedef struct node node;

void traverseList(node *head)
{
    node *p;
    p = head;

    printf("\n%-10s%-13s\n", "Name", "Age");

    while (p->next != NULL)
    {
        printf("%-10s%-13d\n", p->name, p->age);
        p = p->next;
    }
        printf("%-10s%-13d\n", p->name, p->age);
}

struct node *deleteNode(node *head, int umur)
{
    node *p, *q;

    p = head;

    while (p->next != NULL && p->age != umur)
    {
        q = p;
        p = p->next;
    }

    if (p->age == umur)
    {
        q->next = p->next;
        free(p);
    } else if (p->next == NULL)
    {
        printf("The element has not been found");
    }

    return head;
}

int main()
{
    node *p, *head;
    int N, age;

    printf("Enter the number of element: ");
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
        
        printf("Enter the name: ");
        scanf("%s", p->name);
        printf("Enter the age: ");
        scanf("%d", &p->age);

        p->next = NULL;
    }
    
    traverseList(head);

    printf("Enter the age of element will be deleted: ");
    scanf("%d", &age);

    head = deleteNode(head, age);
    
    traverseList(head);

    return 0;
}