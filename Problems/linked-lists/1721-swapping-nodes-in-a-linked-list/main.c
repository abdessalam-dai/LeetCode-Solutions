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

struct ListNode* swapNodes(struct ListNode* head, int k){
    struct ListNode *node1, *node2, *dummy_node;

    dummy_node = head;
    int i = 1;
    while (dummy_node != NULL && i < k+1) {
        node1 = dummy_node;
        dummy_node = dummy_node->next;
        i++;
    }

    node2 = head;
    while (dummy_node != NULL) {
        dummy_node = dummy_node->next;
        node2 = node2->next;
    }

    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;

    return head;
}

int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);
    printList(list);
    list = swapNodes(list, 1);
    printList(list);

    return 0;
}