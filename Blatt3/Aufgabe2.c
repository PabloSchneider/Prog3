# include <stdio.h>
#include <string.h>



int main(int argc, char*argv[]){

    char aus[] =  {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char wird[] = {'w','g','s','n','q','c','d','v','m','e','y','l','u','z','o','a','b','h','r','j','f','k','x','i','p','t'};
    char eingabe[80];
    int i,j;
    char *p, *q;

    if (strcmp(argv[1],"encrypt")){
        p = aus;
        q = wird;
    }else if(strcmp(argv[1],"decrypt")){
        p = wird;
        q = aus;
    }else{
        return 1;
    }



    printf("%s: gebe ein, was du verschlüsseln willst!\n", argv[1]);
    fgets(eingabe,100,stdin);
    printf("%s",eingabe);

    for(i = 0; i < strlen(eingabe); i++){
        j = 0;

        while(eingabe[i] != p[j] && j <= 26){
            j++;
        }
        if(j < 26){
            eingabe[i] = q[j];
        }

    }
    printf("%s", eingabe);
    printf("\n");


    return 0;

}
