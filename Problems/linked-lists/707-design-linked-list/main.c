#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyLinkedList MyLinkedList;

struct MyLinkedList{
    int val;
    struct MyLinkedList *next;
};

void printList(MyLinkedList *head) {
    MyLinkedList *node = head;
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


/** Initialize your data structure here. */

MyLinkedList* myLinkedListCreate() {
    return NULL;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    int i=0;

    while (obj != NULL && i < index) {
        obj = obj->next;
        i++;
    }

    if (obj == NULL) {
        return -1;
    }

    return obj->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
MyLinkedList *myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList *head = malloc(sizeof(MyLinkedList));
    head->val = val;
    head->next = obj;
    return head;
}

/** Append a node of value val to the last element of the linked list. */
MyLinkedList *myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList *tail = malloc(sizeof(MyLinkedList));
    tail->val = val;
    tail->next = NULL;

    if (obj == NULL) {
        return tail;
    }

    MyLinkedList *node = obj;
    while (node->next != NULL) {
        node = node->next;
    }
    node->next = tail;

    return obj;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
MyLinkedList *myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == 0) return myLinkedListAddAtHead(obj, val);
    
    MyLinkedList *prev, *curr = obj;
    int i = 0, len = 0;

    while (curr != NULL) {
        len++;
        curr = curr->next;
    }

    if (index > 0 && index <= len) {
        curr = obj;
        while (curr != NULL && i < index) {
            prev = curr;
            curr = curr->next;
            i++;
        }

        if (prev != NULL) {
            MyLinkedList *new_node = malloc(sizeof(MyLinkedList));
            new_node->val = val;

            prev->next = new_node;
            new_node->next = curr;
        }
    }

    return obj;
}

/** Delete the index-th node in the linked list, if the index is valid. */
MyLinkedList *myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (obj == NULL) return obj;

    MyLinkedList *to_delete = obj;
    if (index == 0) {
        obj = obj->next;
        free(to_delete);
        return obj;
    }

    if (index > 0) {
        int i = 0;
        MyLinkedList *prev;
        while (to_delete != NULL && i < index) {
            prev = to_delete;
            to_delete = to_delete->next;
            i++;
        }

        if (to_delete != NULL) {
            prev->next = to_delete->next;
            free(to_delete);
        }
    }

    return obj;
}

MyLinkedList *myLinkedListFree(MyLinkedList* obj) {
    while (obj != NULL) {
        obj = myLinkedListDeleteAtIndex(obj, 0);
    }
    return obj;
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/


int main() {
    printf("Enter the size of the linked list: ");
    int n;
    scanf("%d", &n);
    MyLinkedList *list = myLinkedListCreate(n);
    printList(list);
    list = myLinkedListAddAtTail(list, 4);
    list = myLinkedListAddAtHead(list, 1);
    list = myLinkedListAddAtHead(list, 2);
    list = myLinkedListAddAtHead(list, 3);
    list = myLinkedListAddAtIndex(list, -1, 111);
    printList(list);
    list = myLinkedListDeleteAtIndex(list, 3);
    list = myLinkedListFree(list);
    printList(list);

    return 0;
}
