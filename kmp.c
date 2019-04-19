#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define COUNT 100
void prefixTable(char subString[], int prefix[], int n){// 创建前缀表
    prefix[0] = 0;
    int i = 0, j = 1;// i 为subString元素下表, j 为prefix元素下标
    while (j < n){
        if (subString[i] == subString[j]){
            i++;
            prefix[j] = i;// prefix[j]填的是i的下一位
            j++;
        } else{
            if (i > 0){
                i = prefix[i - 1];// j一直都在往前走，i回到前一位的prefix指向的位置
            } else{
                prefix[j] = 0;// i在0号位，而一直与j匹配不上时，prefix[j]就为0
                j++;// 然后j再往后比较
            }
        }
    }
    for (int l = 0; l < n; ++l) {
        printf("%d ", prefix[l]);
    }
    printf("\n");
    for (int k = n - 1; k > 0; --k) {// prefix初次创建完成后，元素依次往后串一位，第0位填-1
        prefix[k] = prefix[k - 1];
    }
    prefix[0] = -1;
    for (int l = 0; l < n; ++l) {
        printf("%d ", prefix[l]);
    }
    printf("\n");
}

void kmp(char text[], char subString[], int prefix[], int n){
    int m = strlen(text);// m 位text的长度， n 为subString的长度
    int i = 0, j = 0;// i 为text下标，j 为subString下标
    while (i < m){
        if (j == n - 1 && text[i] == subString[j]){// 完全匹配时，输出位置，然后继续
            printf("Position: %d\n", i - j);
            j = prefix[j];
        }
        if (text[i] == subString[j]){// 若匹配，i、j都往后
            i++;
            j++;
        } else{
            j = prefix[j];// j回溯
            if (j == -1){// 若j回溯到0，从下一位开始比较
                i++;
                j++;
            }
        }
    }
}

int main(){
    char text[] = "babaabaabaaabba";
    char subString[] = "abaaba";
    int n = strlen(subString);
    char prefix[n];
    prefixTable(subString, prefix, n);
    kmp(text, subString, prefix, n);
    return 0;
}
