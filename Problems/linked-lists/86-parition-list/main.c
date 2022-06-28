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

struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL || head->next == NULL) return head;

    struct ListNode *before_head = NULL, *after_head = NULL,
                    *prev1 = NULL, *prev2 = NULL,
                    *node = head, *next;
    while (node != NULL) {
        next = node->next;
        node->next = NULL;
        if (node->val < x) {
            if (before_head == NULL) {
                before_head = node;
            } else {
                prev1->next = node;
            }
            prev1 = node;
        } else {
            if (after_head == NULL) {
                after_head = node;
            } else {
                prev2->next = node;
            }
            prev2 = node;
        }
        node = next;
    }
    if (prev1 == NULL) return after_head;

    prev1->next = after_head;
    return before_head;
}

int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);
    printList(list);
    printList(partition(list, 1));

    return 0;
}