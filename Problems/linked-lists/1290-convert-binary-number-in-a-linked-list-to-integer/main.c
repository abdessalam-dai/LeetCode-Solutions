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

int getDecimalValue(struct ListNode* head) {
    struct ListNode *node=head;

    // Calculate the length of the linked list
    int len=0;
    while (node != NULL) {
        len++;
        node = node->next;
    }
    
    // Convert the binary number represented by the linked list to decimal
    node = head;
    int dec_val = 0;
    int i = 1;
    while (node != NULL) {
        dec_val += node->val * pow(2, len-i);
        i++;
        node = node->next;
    }
    return dec_val;
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
    printf("%d\n", getDecimalValue(list));
    // end main

    clock_t end = clock();
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n(The elapsed time is %f seconds)\n\n", time_spent);

    return 0;
}