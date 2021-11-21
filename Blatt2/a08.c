#include <stdio.h>
#include <string.h>
#include <math.h>
unsigned liesbit(void){
    char zeile[20];
    unsigned a = 0;
    int i, j, x;
    j = 0;
    x = 0;
    printf("gebe eine Binärzahl ein\n");
    fgets(zeile, 20, stdin);
    printf("%s",zeile);
    for(i = strlen(zeile)-1; i >= 0; i--){
        if(zeile[i] == '0' || zeile[i] == '1'){
            if(zeile[i] == '1'){
                a = a + pow(2,j);
            }
            j++;  
        }
    }
    printf("die zahl ist: %u\n", a);

    return a;
}
void schreibtbit(unsigned z){
    int i;
    for(i = 15; i >= 0; i--){
        printf("%d", (z & 1<<i) != 0);
    }
    printf("\n");
    /*
    enum{BYTE = 16};
    char binar[BYTE+1];
    int qutient;
    int point = (BYTE -1);
    binar[BYTE] = '\0';
    while(point >= 0){
    while(z != 0){
        if((z % 2) == 1){
            binar[point] = '1';
        }else{
            binar[point] = '0';
        }
        point --;
        z = z/2;
    }
    binar[point] = '0';
    point --;
    }
    printf("hallo %s\n", binar);
    */

}
int main(void){
    unsigned a, b;
    a = liesbit();
    b = liesbit();
    printf("a & b\n");
    schreibtbit(a & b);
    printf("a | b: \n");
    schreibtbit(a | b);
    printf("a ^ b: \n");
    schreibtbit(a ^ b);
    printf("\n");

    return 0;
}
