#include <stdio.h>

int eingabe;
int i;
int main(void){
printf("Bitte gebe eine Zahl ein!");    
scanf("%d",&eingabe);
printf("ihre Zahl lautet: ");
if (eingabe/100 != 0) /* für hunderter */
{
    for(i = 0; i < eingabe/100; i++){
        printf("C");
    }
    eingabe = eingabe % 100;
}
if(eingabe/50 != 0)
{
    for(i = 0; i < eingabe/50; i++){
        printf("L");
    }
    eingabe = eingabe % 50;

}
if(eingabe/10 != 0)
{
    for(i = 0; i < eingabe/10; i++){
        printf("X");
    }
    eingabe = eingabe % 10;

}
if(eingabe/5 != 0)
{
    for(i = 0; i < eingabe/5; i++){
        printf("V");
    }
    eingabe = eingabe % 5;

}
if(eingabe/1 != 0)
{
    for(i = 0; i < eingabe/1; i++){
        printf("I");
    }
    eingabe = eingabe % 1;

}
    printf("\n-------------------\n");
}
