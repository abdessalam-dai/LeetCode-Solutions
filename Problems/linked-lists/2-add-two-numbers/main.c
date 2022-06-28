#include <stdio.h>
#include "linked_list.c"

void add_decimal(int a, int b, int *res, int *ret) {
    *res = (a+b+(*ret)) % 10;
    *ret = (a+b+(*ret)) / 10;
}

Node *addTwoNumbers(Node *l1, Node *l2) {
    Node *l3 = malloc(sizeof(Node));
    l3 = init_list();

    int res, ret = 0;
    Node *a, *b;
    a = l1;
    b = l2;

    while (a != NULL && b != NULL) {
        add_decimal(a->val, b->val, &res, &ret);
        l3 = insert_node(l3, res);

        a = a->next;
        b = b->next;
    }

    // Add remaining nodes of l1 if any
    while (a != NULL) {
        add_decimal(a->val, 0, &res, &ret);
        l3 = insert_node(l3, res);

        a = a->next;
    }

    // Add remaining nodes of l2 if any
    while (b != NULL) {
        add_decimal(0, b->val, &res, &ret);
        l3 = insert_node(l3, res);

        b = b->next;
    }

    // Add the last remainder
    if (ret != 0) {
        l3 = insert_node(l3, ret);
    }

    return l3;
}

int main() {
    Node *l1=init_list(), *l2=init_list(), *l3;
    // l1 = insert_node(l1, 2);
    // l1 = insert_node(l1, 4);
    // l1 = insert_node(l1, 3);

    // l2 = insert_node(l2, 5);
    // l2 = insert_node(l2, 6);
    // l2 = insert_node(l2, 4);

    l1 = insert_node(l1, 9);
    l1 = insert_node(l1, 9);
    l1 = insert_node(l1, 9);
    l1 = insert_node(l1, 9);
    l1 = insert_node(l1, 9);
    l1 = insert_node(l1, 9);
    l1 = insert_node(l1, 9);

    l2 = insert_node(l2, 9);
    l2 = insert_node(l2, 9);
    l2 = insert_node(l2, 9);
    l2 = insert_node(l2, 9);
    
    print_list(l1);
    print_list(l2);

    print_list(addTwoNumbers(l1, l2));


    // int a, b, res, ret;
    // a = 5;
    // b = 2;
    // add_decemal(a, b, &res, &ret);
    // printf("%d + %d = %d | %d", a, b, res, ret);

    return 0;
}