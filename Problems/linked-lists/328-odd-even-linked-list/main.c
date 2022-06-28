#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *initList(int size) {
    struct ListNode *head = NULL;

    struct ListNode *prev, *temp;

    for (int i=0; i<size; i++) {
        temp = malloc(sizeof(temp));
        printf("Enter the value of the %dth node: ", i+1);
        scanf("%d", &(temp->val));
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
    }

    return head;
}

void printList(struct ListNode *head) {
    struct ListNode *node = head;
    if (head == NULL) {
        printf("The list is empty!");
    } else {
        while (node != NULL) {
            printf("%d => ", node->val);
            node = node->next;
        }
        printf("NULL");
    }
    printf("\n");
}

struct ListNode* oddEvenList(struct ListNode* head) {
    // if the list is empty or contains only one node then return it
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *new_head,
                    *prev_odd_node, *odd_head=NULL, *odd_node,
                    *prev_even_head,
                    *prev_even_node, *even_head=NULL, *even_node;

    // else, create two new lists, one for odd nodes, another for even nodes then link them
    int indice = 1;
    while (head != NULL) {
        if (indice%2 == 0) {
            even_node = malloc(sizeof(struct ListNode));
            even_node->val = head->val;
            even_node->next = NULL;
            if (even_head == NULL) {
                even_head = even_node;
            } else {
                prev_even_node->next = even_node;
            }
            prev_even_node = even_node;
        } else {
            odd_node = malloc(sizeof(struct ListNode));
            odd_node->val = head->val;
            odd_node->next = NULL;
            if (odd_head == NULL) {
                odd_head = odd_node;
            } else {
                prev_odd_node->next = odd_node;
            }
            prev_odd_node = odd_node;

            prev_even_head = odd_node;
        }
        head = head->next;
        indice++;
    }

    prev_even_head->next = even_head;
    return odd_head;
}

int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);
    printList(list);
    printList(oddEvenList(list));

    return 0;
}