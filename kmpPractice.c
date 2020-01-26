#include <stdio.h>
#include <string.h>

void makePrefix(char pi[], int prefix[], int piLength)
{
    prefix[0] = 0;
    int i = 0, j = 1;
    while (j < piLength)
    {
        if (pi[i] == pi[j])
        {
            prefix[j++] = ++i;
        } else
        {
            if (i > 0)
            {
                i = prefix[i - 1];
            } else
            {
                prefix[j] = 0;
                ++j;
            }
        }
    }
    for (int k = piLength - 1; k > 0; k--)
    {
        prefix[k] = prefix[k - 1];
    }
    prefix[0] = -1;
}

void kmp(char text[], char pi[], int prefix[], int textLength, int piLength)
{
    
}

int main(int argc, char const *argv[])
{
    int prefix[100];
    char text[] = "akdbhabaabaabaaefab";
    char pi[] = "abaaba";
    int textLength = strlen(text);
    int piLength = strlen(pi);
    void makePrefix(char pi[], int prefix[], int piLength);
    void kmp(char text[], char pi[], int prefix[], int textLength, int piLength);
    makePrefix(pi, prefix, piLength);
    kmp(text, pi, prefix, textLength, piLength);
    return 0;
}
