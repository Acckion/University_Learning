#include <stdio.h>
#include <stdlib.h>

struct list {
    char val;
    struct list *next;
};

struct list *creatList(void) {
    char x;
    scanf("%c", &x);
    struct list *head = NULL, *tail = NULL;
    struct list *p;
    while (x != '\n') {
        p = (struct list *)malloc(sizeof(struct list));
        p->val = x;
        p->next = NULL;
        if (head == NULL)
            head = p;   
        else                         
            tail->next= p;
        tail = p;
        scanf("%c", &x);
    }
    if (tail != NULL)
        tail->next = NULL;
    return head;
}

void printList(struct list *head) {
    struct list *p = head;
    while (p!=NULL) {
        printf("%c", p->val);
        p = p->next;
    }
    printf("\n");
}

void putToArr(struct list *head) {
    struct list *p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    char arr[count];
    p = head;
    for (int i = 0; p != NULL; i++) {
        arr[i] = p->val;
        printf("%c ", arr[i]);
        p = p->next;
    }
    printf("\n");
}

struct list *reviseList(struct list *head, char c)
{
    int isFound = 0;
    struct list *p = head, *last = NULL;
    while (p!= NULL) {
        if (p->val == c) {
            if (last == NULL) {
                isFound = 1;
                head = p->next;
                free(p);
                p = head;
            }
            else {
                isFound = 1;
                last->next = p->next;
                free(p);
                p = last->next;
            }
        }
        else {
            last = p;
            p = p->next;
        }
    }
    if (!isFound) {
        int min = 128;
        struct list *temp, *add;
        p = head;
        while (p != NULL)
        {
            int diff = abs(c - p->val);
            if (min > diff)
            {
                min = diff;
                temp = p;
            }
            p = p->next;
        }
        add = (struct list *)malloc(sizeof(struct list));
        add->val = c;
        add->next = temp->next;
        temp->next = add;
    }
    return head;
}

int main(void) {
    struct list *head;
    head = creatList();
    putToArr(head);
    printList(head);
    char c;
    scanf("%c", &c);
    head = reviseList(head, c);
    printList(head);
    return 0;
}

