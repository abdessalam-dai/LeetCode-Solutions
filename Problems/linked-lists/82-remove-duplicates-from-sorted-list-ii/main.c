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

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *result;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *dup_node;
    int head_val;
    if (head->val == head->next->val) {
        // save the value of the head
        head_val = head->val;

        // make a pointer the duplicate node
        dup_node = head;

        // destroy all nodes after the head with the same value as head_val
        while (dup_node != NULL && dup_node->val == head_val) {
            head = head->next;
            free(dup_node);
            dup_node = head;
        }

        // now delete duplicates for the remaining part of the list
        result = deleteDuplicates(head);
    } else {
        result = head;
        result->next = deleteDuplicates(head->next);
    }

    return result;
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
    printList(deleteDuplicates(list));
    // end main

    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds\n\n", time_spent);

    return 0;
}