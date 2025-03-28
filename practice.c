#include<stdio.h>;

int main() {

    int me = 35;
    int *teu = &me;
    int ass = *teu;
    printf("%d", ass);
}