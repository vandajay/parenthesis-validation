#include<stdio.h>
#include<stdlib.h>

#define WORDCNT 20

int main (void) {

    char *sptr;
    sptr = (char *) malloc(sizeof(char)*20);

    int res = 1+EOF;
    int cnt = 0;
    while (res != EOF) {
        res = scanf("%c", &sptr[cnt]);
        cnt++;
    }

    for(int j=0; j<cnt; j++) {
        printf("%c", sptr[j]);
    }
    return 0;
}
