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
void sortList(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* i, *j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
int main() {
    Node* head = NULL;
    int arr[] = {5,4,3,6,2,1};
    for (int i = 0; i < 6; i++) {
        head = addNoteAtLast(head, arr[i]);
    }
    printList(head);
    sortList(head);
    printList(head);
    return 0;
}