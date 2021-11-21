#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum{MAX_LENGHT_I = 6, MAX_LENGHT_J = 10};




int checkbefor(const char table[MAX_LENGHT_I][MAX_LENGHT_J], char aktchar){
    int i,j, count;
/*     char **(*p)[MAX_LENGHT_I][MAX_LENGHT_J]; */
    for(i = 0; i < MAX_LENGHT_I; i++){
        for(j = 0; j < MAX_LENGHT_J; j++){
            if(table[i][j] == aktchar){
                return i+1;
            }            
        }
    }
    return 0;

}

void soundex(const char s[], char res[]){
    const char *p;
    char *q;
    int r,i,j,count, bool;
    
    const char table[MAX_LENGHT_I][MAX_LENGHT_J] = {{'B','F','P','V'},{'C','G','J','K','Q','S','X','Z'},{'D','T'},{'L'},{'M','N'},{'R'}};
   
    p = s;
    q = res;
    q[0] = toupper(p[0]);
    count = 1;
    r = 1;
    /**printf("test: %s\n", p);**/
    while(r < strlen(s) || strlen(res) < 6){
        bool = 0;
        for(i = 0; i < MAX_LENGHT_I; i++){
            for(j = 0; j < MAX_LENGHT_J; j++){
                printf("test\n");
                printf("befor %c, %d, after%c, %d \n",table[i][j], q[count-1], checkbefor(table, toupper(q[count])+ 48));
                
                if(table[i][j] == toupper(p[r]) && (q[count-1] != checkbefor(table, toupper(q[count])))){
                    /* printf("\n\n i = %d \n\n", i + 1); */
                    q[count] = i+1 + 48;
                    count ++;
                    continue;
                }
            }
        }
        r++;
    }
    while(count < 6){
       q[count] = '0';
       count ++; 
    }
    q[count] = '\0';
    printf("Das Ergebnis: %s\n", q);
}

int main(void){

    char s[100];
    char res[100];
    printf("Gebe was ein:\n");
    while(scanf("%s", s) != EOF){
        soundex(s,res);
        printf("Gebe was ein:\n");
    }
    
    return 0;

}
