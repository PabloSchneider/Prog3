#include <stdio.h>



int main(void){
char string[20];
char i;
int z = 0;
printf("Bitte geben sie ihren Text ein, den sie verschluesseln wollen.\n");
scanf("%s", &string[0]);
i = string[z];
while(i != '\0'){
    if(string[z] >= 65 && string[z] <= 90){
        string[z] = string[z] - 65;
        string[z] = ((string[z] + 13)%26) + 65;
    }

    if(string[z] >= 97 && string[z] <= 122){
        string[z] = string[z] - 97;
        string[z] = (string[z] + 13)%26 + 97;
    }
    z++;
    i = string[z];

}

printf("ihre ausgabe ist: %s\n", string);
printf("\n");
}