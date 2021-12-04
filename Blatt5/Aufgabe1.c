#include <stdio.h>

typedef union
{
    unsigned int split[2];
    double d_value;
} double_or_split;

void schreibbit(int zahl){
    int i;
    
    for(i=(sizeof(zahl) * 8) - 1; i >= 0;i--){
        
        printf("%d",(zahl & (0x01 << i)) > 0);
    }
    
}

int main(void){
    int x,y;
    double_or_split my_union = {0};
    
    my_union.d_value = 3.5717178E-12;
    x = my_union.split[0];
    y = my_union.split[1];
    
    schreibbit(y);
    schreibbit(x);
    printf ("\n");
    return 0;
}
