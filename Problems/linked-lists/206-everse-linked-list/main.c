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

struct ListNode *reverseList(struct ListNode *head) {
    struct ListNode *prev, *next;

    prev = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);
    printList(list);
    printList(reverseList(list));


    return 0;
}