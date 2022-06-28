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

// my Dump solution
// struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
//     int size = 0;
//     struct ListNode *node = head, *prev = NULL;

//     while (node != NULL) {
//         size++;
//         node = node->next;
//     }   

//     if (size == 1) {
//         head = NULL;
//         free(node);
//     }
//     else if (size-n == 0) {
//         head = head->next;
//         free(node);
//     } else {
//         node = head;
//         int i = 0;
//         while (node != NULL && i < size-n) {
//             prev = node;
//             node = node->next;
//             i++;
//         }
//         prev->next = node->next;
//         free(node);
//     }

//     return head;
// }

// Best solution
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int size = 0;
    struct ListNode *node, *prev, *fast;

    int i = 1;
    fast = head;
    while (fast != NULL && i < n+1) {
        fast = fast->next;
        i++;
    }

    node = head;
    while (fast != NULL && node != NULL) {
        fast = fast->next;
        prev = node;
        node = node->next;
    }

    if (node == head) {
        head = head->next;
        free(node);
    } else {
        prev->next = node->next;
        free(node);
    }

    return head;
}

int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);
    printList(list);
    list = removeNthFromEnd(list, 3);
    printList(list);


    return 0;
}