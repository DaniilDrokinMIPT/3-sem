#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* ptr;
};

typedef struct node Node;

int main() {
    Node n1, n2, n3;

    n1.value = 10;
    n2.value = 20;
    n3.value = 30;

    n1.ptr = &n2;
    n2.ptr = &n3;
    n3.ptr = &n1;

    Node* current = &n1;
    for (int i = 0; i < 10; i++) {
        printf("%d\n", current->value);
        current = current->ptr;
    }

    return 0;
}
