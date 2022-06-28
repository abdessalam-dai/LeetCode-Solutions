#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node *init_list() {
    Node* head = malloc(sizeof(Node));
    head = NULL;

    return head;
}

Node *insert_node(Node *llist, int new_val) {
    Node *new_node = malloc(sizeof(Node));
    new_node->val = new_val;
    new_node->next = NULL;

    if (llist == NULL) {
        return new_node;
    } else {
        Node *node = llist;
        
        while (node->next != NULL) {
            node = node->next;
        }

        node->next = new_node;
        return llist;
    }
}

void print_list(Node *llist) {
    if (llist == NULL) {
        printf("The list is empty!\n");
    } else {
        Node* node = llist;

        while (node != NULL) {
            printf("%d => %s", node->val, node->next==NULL?"NULL":"");
            node = node->next;
        }
        printf("\n");
    }
}
