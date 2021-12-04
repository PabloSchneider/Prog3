#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
enum{MAXLEN = 200};

void zensieren(int argc, char *argv[], char *eingabe){
    int i = 0, j= 0, stellenNr = 0, wahr = 0;
    char *satz = NULL;
    argv++;    
    for(i = 1; i< argc; i++){
        satz = eingabe;
        while(*satz != '\0'){
            if(*satz =='\n'){
                break;
            }
            if(*satz == ' '){
                satz ++;
            }
            if(*satz != (*argv)[0]){
                satz++;
            }
            if(*satz == (*argv)[0]){
                j = 1;
                wahr = 0;
                stellenNr = 0;
                satz++;
                while((*argv)[j] != '\0'){
                    if(*satz == (*argv)[j]){
                        printf("%c : %c\n" , *satz, (*argv)[j]);
                        stellenNr++;
                        satz++;
                    }else{
                        wahr = 1;
                        break; 
                    }
                    j++;
                }
                if(wahr == 0){
                    satz = satz - stellenNr;
                    j = 1;
                    while ((*argv)[j] != '\0')
                    {
                        j++;
                        *satz = '*';
                        satz++;
                    }
                }else{
                    while(isalpha(*satz)){
                        satz++;
                    }
                }
                
            }
        }
        j = 0;
        argv++;
    }
    while(*eingabe != '\0'){
        printf("%c", *eingabe);
        eingabe++;
    }
    printf("\n");

}

int main(int argc, char *argv[]){    
    char eingabe[MAXLEN]= {0};
    
    while(fgets(eingabe,MAXLEN,stdin)!= NULL){
        zensieren(argc, argv, eingabe);
        
    }
    return 0;

}

