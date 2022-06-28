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

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *prev_left_node, *left_node,
                    *right_node, *next_right_node,
                    *prev, *node, *next;

    int i = 1;
    prev_left_node = NULL;
    left_node = head;
    while (left_node != NULL && i < left) {
        prev_left_node = left_node;
        left_node = left_node->next;
        i++;
    }

    i = 1;
    right_node = head;
    while (right_node != NULL && i < right) {
        right_node = right_node->next;
        i++;
    }
    next_right_node = right_node->next;

    node = left_node;
    prev = next_right_node;
    while (node != next_right_node) {
        next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }

    if (prev_left_node == NULL) return right_node;

    prev_left_node->next = right_node;
    return head;
}


int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);
    printList(list);
    printList(reverseBetween(list, 1, 4));

    return 0;
}