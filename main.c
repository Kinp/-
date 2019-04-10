#include <stdio.h>
#include <stdlib.h>

typedef struct arrayList {
    int num;
    struct arrayList *next;
};

int main() {
    int total = 10, n = 0;
    struct arrayList *head = NULL;
    struct arrayList* createArrayList(int n);
    void printArrayList(struct arrayList *head, int n);
    //struct arrayList* delateNode(struct arrayList *head, int n);
    void anwser(struct arrayList *head, int n);
    head = createArrayList(total);
    printArrayList(head, total);
    //delateNode(head, n);
    anwser(head, 3);
    return 0;
}

struct arrayList* createArrayList(int n){
    struct arrayList *head = NULL, *node = NULL, *tail = NULL;
    head = (struct arrayList*)malloc(sizeof(struct arrayList));
    head->num = 1;
    tail = head;
    for (int i = 0; i < n; ++i) {
        node = (struct arrayList*)malloc(sizeof(struct arrayList));
        tail->next = node;
        node->num = i + 2;
        tail = node;
    }
    tail->next = head;
    return head;
}

void printArrayList(struct arrayList *head, int n){
    struct arrayList *node;
    node = head;
    for (int i = 0; i < n; ++i) {
        printf("%x: %d -> %x\n", node, node->num, node->next);
        node = node->next;
    }
    printf("%x: %d -> %x\n", node, node->num, node->next);
}

void anwser(struct arrayList *head, int n){
    struct arrayList *node = NULL, *pre = NULL, *after = NULL, *temp = NULL;
    int i = 0, z = 0;
    node = head;
    while(i <= 10){
        for (int j = 1; j < 3; ++j) {
            if (z != 0){
                node = node->next;
            }
            if (j == 2){
                temp = node->next;
                pre = node;
                after = node->next->next;
                pre->next = after;
                i++;
                free(temp);
            }
            z = 1;
        }
    }
    printf("%d", node->num);
}