/*************
** @Author: JiKunzhi
** @BeginDate: 2019/04/08
** @FinalDate: 2019/04/09
** @Function: 初始化链表(initArrayList)，遍历链表(printArrayList)，(增删查改)查找或修改特定位置元素(showOrChangeElement)，插入节点(insertNode), 删除节点(delate node)
*************/
#include <stdio.h>
#include <stdlib.h>

typedef struct arrayList {
    int num;
    struct arrayList *next;
};

int main(){
    int count = 0, n = 0;//count为初始化节点的个数, n为查找，添加元素的下标(从1开始)
    struct arrayList* initArrayList(int count);
    void printArrayList(struct arrayList *head);
    void showOrChangeElement(struct arrayList *head, int n);
    struct arrayList* insertNode(struct arrayList *head, int n);
    struct arrayList* delateNode(struct arrayList *head, int n);
    struct arrayList *head;
    head = initArrayList(5);
    printArrayList(head);
    showOrChangeElement(head, n);
    head = insertNode(head, n);//插入到第一个时改变head值
    printArrayList(head);
    head = delateNode(head, n);
    printArrayList(head);
    return 0;
}

struct arrayList* initArrayList(int count){
    struct arrayList *head = NULL, *node = NULL, *tail = NULL;
    head = (struct arrayList*)malloc(sizeof(struct arrayList));
    tail = head;
    scanf("%d", &tail->num);
    for (int i = 1; i < count; ++i) {
        node = (struct arrayList*)malloc(sizeof(struct arrayList));
        scanf("%d", &node->num);
        tail->next = node;
        tail = node;
    }
    tail->next = NULL;
    return head;
}

void printArrayList(struct arrayList *head){
    printf("*******************************\n");
    struct arrayList *node;
    node = head;
    while(node->next != NULL){
        printf("%x: %d -> %x\n", node, node->num, node->next);
        node = node->next;
    }
    printf("%x: %d -> %x\n", node, node->num, node->next);
    printf("*******************************\n");
}

void showOrChangeElement(struct arrayList *head, int n){
    int isChange = 0;//输入非1则不修改，输入1修改
    printf("Plese input element's position: ");
    scanf("%d", &n);
    struct arrayList *node = NULL;
    node = head;
    for (int i = 0; i < n - 1; ++i) {
        node = node->next;
    }
    printf("%x: %d -> %x\n", node, node->num, node->next);
    printf("Do you want to change the number? (1/0): ");
    scanf("%d", &isChange);
    if (isChange == 1){
        printf("OK, which number do you want to change to: ");
        scanf("%d", &node->num);
    }
}

struct arrayList* insertNode(struct arrayList *head, int n){
    struct arrayList *node = NULL, *addNode = NULL, *previous = NULL, *behind = NULL;
    printf("Plese input node position: ");
    scanf("%d", &n);
    node = head;
    if (n == 1){
        head = (struct arrayList*)malloc(sizeof(struct arrayList));
        scanf("%d", &head->num);
        head->next = node;
        return head;
    }
    for (int i = 0; i < n - 2; ++i) {
        node = node->next;
    }
    previous = node;
    behind = node->next;
    node = (struct arrayList *)malloc(sizeof(struct arrayList));
    printf("Input number what you want to add: ");
    scanf("%d", &node->num);
    previous->next = node;
    node->next = behind;
    return head;
}

struct arrayList* delateNode(struct arrayList *head, int n){
    struct arrayList *node = NULL, *temp = NULL, *previous = NULL, *behind = NULL;
    node = head;
    printf("Which node do you want to delate: ");
    scanf("%d", &n);
    if (n == 1){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    for (int i = 0; i < n - 2; ++i) {
        node = node->next;
    }
    temp = node->next;
    previous = node;
    behind = node->next->next;
    previous->next = behind;
    free(temp);
    return head;
}