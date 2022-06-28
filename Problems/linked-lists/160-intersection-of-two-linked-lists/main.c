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

// My dump solution:
// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
//     struct ListNode *nodeA = headA, *nodeB;

//     while (nodeA != NULL) {
//         nodeB = headB;
//         while (nodeB != NULL) {
//             if (nodeA == nodeB) {
//                 return nodeA;
//             }
//             nodeB = nodeB->next;
//         }
//         nodeA = nodeA->next;
//     }

//     return NULL;
// }


// Faster solution:
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if( headA == NULL || headB == NULL )
			return NULL;
		
		struct ListNode *curA = headA, *curB = headB;
		while( curA!=curB){
			curA = curA==NULL?headB:curA->next;
			curB = curB==NULL?headA:curB->next;
		}
    return curA;
}


int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    struct ListNode *list = initList(n);
    printList(list);
    printf("%d", getIntersectionNode(list, list)->val);


    return 0;
}