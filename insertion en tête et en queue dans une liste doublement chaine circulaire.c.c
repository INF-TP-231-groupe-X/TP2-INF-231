#include <stdio.h>
#include <stdlib.h>

typedef struct DCNode {
    int data;
    struct DCNode *prev, *next;
} DCNode;

void insererTeteDCirculaire(DCNode **head, int val) {
    DCNode *newNode = malloc(sizeof(DCNode));
    newNode->data = val;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        DCNode *last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insererQueueDCirculaire(DCNode **head, int val) {
    DCNode *newNode = malloc(sizeof(DCNode));
    newNode->data = val;

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
    } else {
        DCNode *last = (*head)->prev;
        newNode->next = *head;
        newNode->prev = last;
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

void afficherListe(DCNode *head) {
    if (!head) return;
    DCNode *temp = head;
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(circulaire)\n");
}

int main() {
    DCNode *head = NULL;

    insererTeteDCirculaire(&head, 2);
    insererTeteDCirculaire(&head, 1);
    insererQueueDCirculaire(&head, 3);
    insererQueueDCirculaire(&head, 4);

    printf("Liste doublement chaînée circulaire : ");
    afficherListe(head);

    return 0;
}
