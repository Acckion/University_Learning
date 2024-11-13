#include <stdio.h>
#include <stdlib.h>
struct s_list
{
    int data;
    struct s_list *next;
};
struct s_list *create_list(int *p);
int main(void)
{
    struct s_list *head, *p;
    int s[10], i = 0;
    while (i < 10)
    {
        scanf("%d", &s[i]);
        if (s[i] == 0)
            break;
        i++;
    }

    head = create_list(s);
    p = head;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
struct s_list *create_list(int *p)
{
    struct s_list *loc_head = NULL, *head = NULL;
    if (p[0] == 0)
        ;
    else
    {
        while (*p)
        {
            loc_head = (struct s_list *)malloc(sizeof(struct s_list));
            loc_head->data = *p++;
            loc_head->next = head;
            head = loc_head;
        }
    }
    return loc_head;
}
