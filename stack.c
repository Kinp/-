#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef int ElemType;

typedef struct stackNode{
    ElemType *top;
    ElemType *base;
    int stackSize;
}firstStack;

void initStack(struct stackNode *firstStack){
    //firstStack *firstStack;
    firstStack->base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    //firstStack->base = firstStack;
    if (!firstStack){
        printf("Initial Error");
        exit(0);
    }
    firstStack->top = firstStack->base;
    firstStack->stackSize = STACK_INIT_SIZE;
    //return firstStack->base;
}

void pushStack(firstStack *firstStack, ElemType element){
    if (firstStack->top - firstStack->base > STACK_INIT_SIZE){
        int tempSize = firstStack->top - firstStack->base;
        firstStack->base = (ElemType*)realloc(firstStack->base, firstStack->stackSize + STACKINCREMENT);
        if (!firstStack->base){
            printf("Add stack size error");
            exit(0);
        }
        firstStack->top = firstStack->base + tempSize;
        firstStack->stackSize = firstStack->stackSize + STACKINCREMENT;
    }
    *(firstStack->top) = element;
    ++firstStack->top;
}

void popStack(firstStack *firstStack){
    if (firstStack->base == firstStack->top){
        printf("This stack is empty");
        return;
    }
    firstStack->top--;
    printf("%d ", *(firstStack->top));
}

int lenth(firstStack *firstStack){
    return firstStack->top - firstStack->base;
}

int main(){
    printf("This is a stack\nInput your element to push: ");
    ElemType element;
    struct stackNode *firstStack;
    void initStack(struct stackNode *firstStack);
    void pushStack(struct stackNode *firstStack, ElemType element);
    void popStack(struct stackNode *firstStack);
    void showStack(struct stackNode *firstStack);
    initStack(firstStack);
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &element);
        pushStack(firstStack, element);
    }
    for (int i = 0; i < 5; ++i) {
        popStack(firstStack);
    }
}