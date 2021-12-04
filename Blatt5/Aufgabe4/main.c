#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_STARS 3
#define DEFAULT_SPRACHE "Ilman kuuloleitta en kuula mitaeaen\0"

void gibsprache(char spruch[]){
    strncpy(spruch, DEFAULT_SPRACHE, 100);

    #ifdef DE
        strncpy(spruch, "Ohne Hoergeraet hoere ich nichts\0", 100);
    #endif
    #ifdef NL
        strncpy(spruch, "Zonder gehoorapparaat hoor ik niets\0", 100);
    #endif
    #ifdef FI
        strncpy(spruch, "Ilman kuuloleitta en kuula mitaeaen\0", 100); 
    #endif   
    #ifdef SE
        strncpy(spruch, "Jag hoer ingenting utan hoerselapparat\0", 100);
    #endif
    #ifdef IT
        strncpy(spruch, "Senza l'apparecchio d'autito non sento niente\0", 100);
    #endif
    #ifdef CN
        strncpy(spruch, "mei zhu ting qi jiu tingbujian\0", 100);
    #endif 
    
}
int getStars(){
    int stars = DEFAULT_STARS;
    #ifdef SIZE 
        stars = SIZE;
    #endif
    return stars;
}

void printEmpty(int stars, char spruch[]){
    int i, j = 0;
    for(i = 0; i < stars; i++){
        printf("*");
        for(j = 0; j <strlen(spruch);j++){
            printf(" ");
        }
        printf("*\n");
    }
}
void printSpruch(char spruch[]){
    int i ,j = 0;
    
    for(i = 0; i < strlen(spruch)+2; i++){
        printf("*");
    }
    printf("\n");
}

void printALL(int stars, char spruch[]){
    
    printSpruch(spruch);
    printEmpty(stars, spruch);
    
    printf("*");
    printf("%s", spruch);
    printf("*\n");
    
    printEmpty(stars, spruch);
    printSpruch(spruch);
}



int main(void){
    int stars;
    char spruch[100] = {0}; 
    stars = getStars();
    gibsprache(spruch);
    printALL(stars, spruch);
    

}
