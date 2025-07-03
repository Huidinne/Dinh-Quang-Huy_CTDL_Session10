#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *next;
}Node;
Node* addNoteAtLast(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void findMiddle(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong!\n");
        return;
    }

    Node* slow = head;
    Node* fast = head;
    int count = 0;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        count += 2;
    }

    if (fast != NULL) {
        count += 1;
        printf("Danh sach le, node giua: %d\n", slow->data);
    } else {
        printf("Danh sach chan, node giua: %d\n", slow->data);
    }
}

int main() {
    Node* head = NULL;
    int arr[] = {5,4,3,6,2,1,5};
    for (int i = 0; i < 6; i++) {
        head = addNoteAtLast(head, arr[i]);
    }
    printList(head);
    findMiddle(head);
    return 0;
}