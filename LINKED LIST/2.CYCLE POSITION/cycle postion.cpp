#include <stdio.h>
#include <stdlib.h>

struct Node {
    int input1;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->input1 = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

struct Pair {
    int first;
    int second;
};

struct Pair hasCycle(struct Node* head) {
    if (head == NULL) {
        return (struct Pair) {0, -1};
    }

    struct Node* s = head;
    struct Node* f = head;
    int pos = 0;

    while (f != NULL && f->next != NULL) {
        s = s->next;          
        f = f->next->next;    
        pos++;

        if (s == f) {
            return (struct Pair) {1, pos};
        }
    }

    return (struct Pair) {0, -1};
}

int main() {
    struct Node* head = NULL;

    push(&head, 9);
    push(&head, 10);
    push(&head, 11);
    push(&head, 12);

    head->next->next->next->next = head;

    struct Pair result = hasCycle(head);

    if (result.first)
        printf("True, Cycle starts at position: %d\n", result.second);
    else
        printf("False\n");

    return 0;
}
