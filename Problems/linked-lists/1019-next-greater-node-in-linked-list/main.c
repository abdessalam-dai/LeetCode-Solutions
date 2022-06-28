#include <stdio.h>
#include <stdlib.h>

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

int* nextLargerNodes(struct ListNode* head, int *returnSize){
    int *arr=malloc(sizeof(int));
    *returnSize = 0;
    struct ListNode *node = head;

    while (node != NULL) {
        int curr_val = node->val;
        struct ListNode *next_node = node->next;
        int max_val = 0;

        while (next_node != NULL) {
            if ((next_node->val > curr_val && max_val == 0) || (next_node->val > max_val && max_val != 0)) {
                max_val = next_node->val;
            }
            next_node = next_node->next;
        }
        arr[*returnSize] = max_val;
        (*returnSize)++;

        node = node->next;
    }

    return arr;
}

int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);

    printList(list);
    int returnSize;
    int *arr = nextLargerNodes(list, &returnSize);

    for (int i=0; i<returnSize; i++) {
        printf("%d, ", arr[i]);
    }

    return 0;
}