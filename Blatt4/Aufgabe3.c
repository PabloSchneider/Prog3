#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum{MAXLEN = 200};

void transformstring(char eingabe[20][20],char *argv[], int argc){
    char (*strpEin)[20] = eingabe;
    int counter= 0, i = 0;
    for(i = 1; i < argc; i++){
        if(strcmp(strpEin[counter],argv[i])){
            
        }
    }



}


int main(int argc, char *argv[]){

    char eingabe[MAXLEN]= {0};
    char eingebenstring[20][20] = {0};
    char wort[20] = {0};
    int i = 0;
    int j = 0;
    int z = 0;
    printf("gebe was ein\n");
    while(fgets(eingabe,MAXLEN,stdin)!= NULL){
        printf("%s\n", eingabe);
        for(i = 0; i < strlen(eingabe); i++){
            if(eingabe[i] == '\n'){
                eingabe[i] = '\0';
            }
            if(eingabe[i] != ' ' || eingabe[i] != '\0' ){
                j = 0;
                
                while(eingabe[i] != ' ' && eingabe[i] != '\n'){
                    wort[j] = eingabe[i];
                    i++;
                    j++;
                }
                wort[j] = '\0';
                strcpy(eingebenstring[z], wort);
                printf("Wort: %s\n", wort);
                z++;  
                }
        }    
        printf("gebe was ein\n");
        transformstring(eingebenstring, argv, argc);
    }
    printf("ende\n");

}
