#include <stdio.h>

int border(int i, int n){
    if(i == n){
        
    }
}


int main(void){
    int n,i,j1,i1,j, zaeler, z;
    n = 0;
    int a[21][21]={0};
                 
    printf("gebe ein n an: \n");
    scanf("%d", &n);
    if((n%2) != 1){
        return 1;
    }

    /*mittleres Feld Belegen*/
    z = 1;
    i = n/2;
    j = n/2;
    a[i][j] = z;
    z++;
    /*Aufüllen*/
    while((z <= n*n)){
        i++;
        j--;
        if(j == -1){
            j = (n-1);
        }
        if(i == n){
            i = 0;
        }
        if(a[i][j] == 0){
            a[i][j] = z;
            z++;
        }else{
            j++;
            i++;
            if(i == n){
                i = 0;
            }
            if(j == n){
                j = 0;
            }
            if(a[i][j] == 0){
                a[i][j] = z;
                z++;
            }else{
                while(a[i][j] != 0){
                    i = i + 2;
                    if(i == n){
                        i = 0;
                    }
                    if(i == (n+1)){
                        i = 1;
                    }
                    if(a[i][j] == 0){
                        a[i][j] = z;
                        z++;
                    }
                }
            }   
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n;j++){
            printf(" %d ",a[i][j]);
        }
        printf("\n");
        printf("\n");
    }
    printf("\n");
    return 0;

}
