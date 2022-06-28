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

struct ListNode* mergeSort(struct ListNode *a, struct ListNode *b) {
    struct ListNode *res;

    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    if (a->val <= b->val) {
        res = a;
        res->next = mergeSort(a->next, b);
    } else {
        res = b;
        res->next = mergeSort(a, b->next);
    }

    return res;
}

void splitList(struct ListNode *head, struct ListNode **first, struct ListNode **second) {
    struct ListNode *slow=head, *fast=head;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *first = head;
    *second = slow->next;
    slow->next = NULL;
}

struct ListNode* sortList(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *first_half, *second_half;

    splitList(head, &first_half, &second_half);
}

int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list1 = initList(n);//, *list2 = initList(n);
    // struct ListNode *lst = mergeSort(list1, list2);
    // printList(lst);
    printList(sortList(list1));

    return 0;
}