#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

void insererTeteCirculaire(CNode **last, int val) {
    CNode *newNode = malloc(sizeof(CNode));
    newNode->data = val;

    if (*last == NULL) {
        *last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
    }
}

void insererQueueCirculaire(CNode **last, int val) {
    CNode *newNode = malloc(sizeof(CNode));
    newNode->data = val;

    if (*last == NULL) {
        *last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = (*last)->next;
        (*last)->next = newNode;
        *last = newNode;
    }
}

void afficherListe(CNode *last) {
    if (!last) return;
    CNode *temp = last->next;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("(circulaire)\n");
}

int main() {
    CNode *last = NULL;

    insererTeteCirculaire(&last, 2);
    insererTeteCirculaire(&last, 1);
    insererQueueCirculaire(&last, 3);
    insererQueueCirculaire(&last, 4);

    printf("Liste circulaire simplement chaînée : ");
    afficherListe(last);

    return 0;
}
