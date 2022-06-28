#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>       // for clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> 
#include <math.h>

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

struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *node1=head, *node2=head->next, *prev_node1;
    
    while (node1 != NULL && node2 != NULL) {
        node1->next = node2->next;
        node2->next = node1;
        if (node1 != head) {
            prev_node1->next = node2;
        } else {
            head = node2;
        }
        prev_node1 = node1;
        node1 = node1->next;
        if (node1 != NULL) {
            node2 = node1->next;
        }
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
    printList(swapPairs(list));
    // end main

    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n(The elapsed time is %f seconds)\n\n", time_spent);

    return 0;
}