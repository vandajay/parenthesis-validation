#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isParenthesisValid(char *s, int size);

int main (void) {

    char *sptr;
    size_t maxlen = 1000;
    int ssize = 0;

   while (ssize != -1) {
       sptr = (char *) malloc(sizeof(char)*maxlen);
       ssize = getline(&sptr, &maxlen, stdin);
       
        if (isParenthesisValid(sptr, ssize) == 1)
            printf("VALID\n");
        else
            printf("NOT VALID\n");
    }
    return 0;
}

int isParenthesisValid(char *s, int size) {
    printf("string size = %d\n", size);
    char *arr;
    arr = (char *) malloc(sizeof(char)*size);
    int cnt = 0;
    arr[cnt] = '\0';

    for (int i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            printf("%c\n", s[i]);
            arr[cnt] = s[i];
            cnt++;
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (strlen(arr) == '\0') {
                printf("1 length of arr %d\n", (int) strlen(arr));
                return 0;
            }
            else {
                if (arr[cnt] == '(' && s[i] == ')')
                    cnt--;
                else if (arr[cnt] == '[' && s[i] == ']')
                    cnt--;
                else if (arr[cnt] == '{' && s[i] == '}')
                    cnt--;
                else {
                    printf("2 length of arr %d\n", (int) strlen(arr));
                    return 0;
                    }
            }
        }
    }
    printf("3 length of arr %d\n", (int) strlen(arr));
    return 1;
}
