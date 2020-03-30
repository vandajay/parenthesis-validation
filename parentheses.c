#include<stdio.h>
#include<stdlib.h>

// prototypes

int main() {
    char valid[] = "(djfk[kfdsj{012}hello]world)";
    char invalid[] = "(hello[how{are]youtoday})";

    printf("%s\n", valid);
    printf("%s\n", invalid);
}

// functions
