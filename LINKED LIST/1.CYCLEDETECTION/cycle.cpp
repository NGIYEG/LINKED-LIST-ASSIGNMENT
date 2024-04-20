#include <stdio.h>
#include <stdlib.h>

struct Node {
    int input1;
    struct Node* next;
};

void push(struct Node** head_ref, int new_input)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->input1 = new_input;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

bool hasCycle(struct Node* head)
{
    if (head == NULL) {
        return false;
    }

    struct Node* s = head;
    struct Node* f = head;

    while (f != NULL && f->next != NULL) {
        s = s->next;          
        f = f->next->next;    

        if (s == f) {
            return true;
        }
    }

    return false;
}

int main()
{
    struct Node* head = NULL;

    push(&head, 9);
    push(&head, 10);
    push(&head, 11);
    push(&head, 12);

    head->next->next->next->next = head;

    if (hasCycle(head))
        printf("True");
    else
        printf("False");

    return 0;
}
