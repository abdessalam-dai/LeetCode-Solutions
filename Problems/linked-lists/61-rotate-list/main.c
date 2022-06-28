#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> 

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

struct ListNode *rotateRightOnce(struct ListNode *head) {
    struct ListNode *tail=head, *prev_tail;
    while (tail->next != NULL) {
        prev_tail = tail;
        tail = tail->next;
    }
    prev_tail->next = NULL;
    tail->next = head;
    head = tail;

    return head;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        return head;
    }

    // No need to rotate the list k times, rotate it k MOD len(list) times
    int len = 0;
    struct ListNode *node = head;
    while (node != NULL) {
        len++;
        node = node->next;
    }

    k %= len;

    while (k) {
        head = rotateRightOnce(head);
        k--;
    }

    return head;
}

int main() {
    double time_spent = 0.0;
    clock_t begin = clock();
 
    // main program
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);
    printList(list);
    printList(rotateRight(list, 2000000000));
    // end main

    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n(The elapsed time is %f seconds)\n\n", time_spent);

    return 0;
}