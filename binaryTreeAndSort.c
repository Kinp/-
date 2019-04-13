/****************
 * @author: JiKunzhi
 * @date: 2019/04/11
 * @finalDate: 2019/04/11
 * @function: 创建一个二叉树，从小到大输出值
 ***************/
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int num;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode* initNode(){
    struct treeNode *node = NULL;
    node = (struct treeNode*)malloc(sizeof(struct treeNode));
    scanf("%d", &node->num);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertNode(struct treeNode *root, struct treeNode *node){
    struct treeNode *middle = NULL;
    middle = root;
    while (middle != NULL){
        if (middle->num >= node->num){
            if (middle->left == NULL){
                middle->left = node;
                return;
            } else{
                middle = middle->left;
            }
        } else{
            if (middle->right == NULL){
                middle->right = node;
                return;
            } else{
                middle = middle->right;
            }
        }
    }
}

void printTree(struct treeNode *root){
    if (root != NULL)
    {
        printTree(root->left);
        printf("%d ",root->num);
        printTree(root->right);
    }
}

int main() {
    int n = 0;//初始化个数
    struct treeNode *root = NULL, *node = NULL;//main函数中有两个指针
    struct treeNode* initNode();//申明初始化节点函数
    void insertNode(struct treeNode *root, struct treeNode *node);//申明插入节点函数
    printf("How many numbers do you want to sort?: ");
    scanf("%d", &n);
    printf("Please input your numbers: ");
    root = (struct treeNode*)malloc(sizeof(struct treeNode));//初始化根节点
    scanf("%d", &root->num);
    root->left = NULL;
    root->right = NULL;
    for (int i = 1; i < n; ++i) {//创建和插入其他节点
        node = initNode();
        insertNode(root, node);
    }
    printTree(root);
    return 0;
}