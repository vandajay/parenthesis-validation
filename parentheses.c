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
       
       if (ssize == -1)
           return 0;
       else if (isParenthesisValid(sptr, ssize) == 1)
           printf("VALID\n\n");
       else
           printf("NOT VALID\n\n");
    }
    return 0;
}

int isParenthesisValid(char *s, int size) {
    printf("string size = %d\n", size);
    char *arr;
    arr = (char *) malloc(sizeof(char)*size);
    int cnt = 0;
    int i = 0;

    for (i = 0; i < size; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            printf("-> arr[%d] = %c\n", i, s[i]);
            arr[cnt] = s[i];
            cnt++;
        }
        if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (cnt == 0) {
                printf("1 length of arr %d\n", (int) strlen(arr));
                printf("arr = %s\n", arr);
                printf("s[%d] = %c\n", i, s[i]);
                return 0;
            }
            else {
                if (arr[cnt-1] == '(' && s[i] == ')') {
                    printf("a -> s[%d] = %c\n", i, s[i]);
                    cnt--;
                }
                else if (arr[cnt-1] == '[' && s[i] == ']') {
                    printf("b -> s[%d] = %c\n", i, s[i]);
                    cnt--;
                }
                else if (arr[cnt-1] == '{' && s[i] == '}') {
                    printf("c -> s[%d] = %c\n", i, s[i]);
                    cnt--;
                }
                else {
                    printf("2 length of arr %d\n", (int) strlen(arr));
                    printf("arr[%d] = %c\n", cnt, arr[cnt]);
                    printf("s[%d] = %c\n", i, s[i]);
                    return 0;
                    }
            }
        }
    }
    arr[cnt] = '\0';
    printf("3 length of arr %d\n", (int) strlen(arr));
    printf("arr = %s\n", arr);
    printf("s[%d] = %c\n", i, s[i]);
    return 1;
}
