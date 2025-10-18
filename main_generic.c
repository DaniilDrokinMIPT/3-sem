#include <stdio.h>
#include "list_generic.h"

DECLARE_LIST(int)
DEFINE_LIST(int)

DECLARE_LIST(double)
DEFINE_LIST(double)

void print_int_list(List_int* list) {
    Node_int* current = list->head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void print_double_list(List_double* list) {
    Node_double* current = list->head;
    while (current) {
        printf("%.1f ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("Testing generic list with int:\n");
    List_int int_list = init_int(0);

    push_back_int(&int_list, 10);
    push_back_int(&int_list, 20);
    push_front_int(&int_list, 5);
    push_front_int(&int_list, 1);

    print_int_list(&int_list);
    printf("Pop front: %d\n", pop_front_int(&int_list));
    printf("Pop back: %d\n", pop_back_int(&int_list));
    print_int_list(&int_list);

    destroy_int(&int_list);

    printf("\nTesting generic list with double:\n");
    List_double double_list = init_double(0);

    push_back_double(&double_list, 10.5);
    push_back_double(&double_list, 20.5);
    push_front_double(&double_list, 5.5);

    print_double_list(&double_list);
    printf("Pop front: %.1f\n", pop_front_double(&double_list));
    print_double_list(&double_list);

    destroy_double(&double_list);

    return 0;
}
