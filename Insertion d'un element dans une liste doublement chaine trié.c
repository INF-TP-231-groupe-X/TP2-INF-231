#include <stdio.h>
#include <stdlib.h>

typedef struct DNode {
    int data;
    struct DNode *prev, *next;
} DNode;

void insererTrieDouble(DNode **head, int val) {
    DNode *newNode = malloc(sizeof(DNode));
    newNode->data = val;
    newNode->prev = newNode->next = NULL;

    if (*head == NULL || (*head)->data >= val) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    DNode *temp = *head;
    while (temp->next && temp->next->data < val) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void afficherListe(DNode *head) {
    DNode *temp = head;
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    DNode *head = NULL;

    insererTrieDouble(&head, 10);
    insererTrieDouble(&head, 3);
    insererTrieDouble(&head, 7);
    insererTrieDouble(&head, 1);
    insererTrieDouble(&head, 5);

    printf("Liste double triée : ");
    afficherListe(head);

    return 0;
}
