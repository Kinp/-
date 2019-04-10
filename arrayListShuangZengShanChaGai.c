/*************
 * @author: JiKunxhi
 * @date: 2019/04/10
 * @finalDate: 2019/04/10
 * @function: 创建(creatArrayList)，输出(printArrayList)，增加(addNode)，删除(delateNode), 查和改(findOrChangeNode)
**************/
#include <stdio.h>
#include <stdlib.h>

typedef struct arrayList {
    struct arrayList *before;
    int num;
    struct arrayList *next;
};

int main() {
    int n = 5;
    struct arrayList *head;
    struct arrayList *creatArrayList(int n);
    struct arrayList *creatArrayList(int n);
    struct arrayList *addNode(struct arrayList *head, int n);
    struct arrayList *delateNode(struct arrayList *head, int n);
    void findOrChangeNode(struct arrayList *head);
    void printArrayList(struct arrayList *head);
    head = creatArrayList(n);
    printArrayList(head);
    //head = addNode(head, n);
    //head = delateNode(head, n);
    findOrChangeNode(head);
    printArrayList(head);
    return 0;
}

struct arrayList *creatArrayList(int n){
    struct arrayList *head = NULL, *node = NULL, *tail = NULL;
    head = (struct arrayList*)malloc(sizeof(struct arrayList));
    scanf("%d", &head->num);
    head->before = NULL;
    tail = head;
    for (int i = 1; i < n; ++i) {
        node = (struct arrayList*)malloc(sizeof(struct arrayList));
        scanf("%d", &node->num);
        node->before = tail;
        tail->next = node;
        tail = node;
    }
    node->next = NULL;
    return head;
}

void printArrayList(struct arrayList *head){
    struct arrayList *node = NULL;
    node = head;
    while (node->next != NULL){
        printf("%x <- %x: %d -> %x\n", node->before, node, node->num, node->next);
        node = node->next;
    }
    printf("%x <- %x: %d -> %x\n", node->before, node, node->num, node->next);
}

struct arrayList *addNode(struct arrayList *head, int final){
    int n = 0;
    struct arrayList *node = NULL, *temp = NULL, *behind = NULL, *before = NULL;
    node = head;
    printf("Which position do you want to add?: ");
    scanf("%d", &n);
    if (n == 1){
        temp = head;
        node = (struct arrayList*)malloc(sizeof(struct arrayList));
        scanf("%d", &node->num);
        node->next = temp;
        node->before = NULL;
        temp->before = node;
        head = node;
        return head;
    }
    for (int i = 0; i < n - 2; ++i) {
        node = node->next;
    }
    if (n == ++final){//和单链表不同，单链表最后一项的下一项是NULL，但是没有node->before，而双链表这里会报错
        struct arrayList *addFinalNode = NULL;
        addFinalNode = (struct arrayList*)malloc(sizeof(struct arrayList));
        scanf("%d", &addFinalNode->num);
        node->next = addFinalNode;
        addFinalNode->next = NULL;
        addFinalNode->before = node;
        return head;
    }
    before = node;
    behind = node->next;
    node = (struct arrayList*)malloc(sizeof(struct arrayList));
    scanf("%d", &node->num);
    before->next = node;
    behind->before = node;
    node->before = before;
    node->next = behind;
    return head;
}

struct arrayList *delateNode(struct arrayList *head, int final){
    int n = 0;
    struct arrayList *node = NULL, *temp = NULL, *before = NULL, *behind = NULL;
    node = head;
    printf("Which node do you want to delate?: ");
    scanf("%d", &n);
    if (n == 1){
        temp = head;
        head = head->next;
        head->next->before = NULL;
        free(temp);
        return head;
    }
    for (int i = 0; i < n - 2; ++i) {
        node = node->next;
    }
    if (n == final){
        temp = node->next;
        node->next = NULL;
        free(temp);
        return head;
    }
    before = node;
    behind = node->next->next;
    free(node->next);
    before->next = behind;
    behind->before = before;
    return head;
}

void findOrChangeNode(struct arrayList *head){
    int n = 0;
    struct arrayList *node = NULL;
    node = head;
    printf("Which position do you want to find?: ");
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        node = node->next;
    }
    printf("%x <- %x: %d -> %x\n", node->before, node, node->num, node->next);
    printf("Do you want to change the number?(1/0): ");
    scanf("%d", &n);
    if (n == 1){
        printf("What number do you want to change to?: ");
        scanf("%d", &node->num);
    }
}