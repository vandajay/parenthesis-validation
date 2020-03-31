#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isParenthesisValid(char *p);

int main (void) {

    char *sptr[10];
    int cnt = 0;
    int res = 1+EOF;

   while (res != EOF) { 
        char input[30];
        sptr[cnt] = (char *) malloc(sizeof(char)*30);
        res = scanf("%s", input);
        strcpy(sptr[cnt], input);
        cnt++;
    }

//    for(int j = 0; j < cnt-1; j++) {
//        printf("%s", sptr[j]);
//    }


    for(int j=0; j < cnt-1; j++) {
        if (isParenthesisValid(*(sptr+j)) == 0)
            printf("VALID");
        else
            printf("NOT VALID");
    }
    return 0;
}

int isParenthesisValid(char *p) {
    return 0;
}
