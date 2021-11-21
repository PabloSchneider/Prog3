#include <stdio.h>

int main(void){
    enum{MAX_LENGHT = 20};
    int size,i,j, input, smallest, indexfromSmallest, placeholder;
    int arr[MAX_LENGHT];
    size = 0;
    printf("gebe Zahlen ein!!!! \n");
    while(size < MAX_LENGHT && (scanf("%d", &input) != EOF)){
        arr[size] = input;
        size++; 
    }
    for(i = 0; i < size; i++){
        smallest = arr[i];
        indexfromSmallest = i;
        for(j = i+1; j < size; j++){
           if(arr[j] < smallest){
               smallest = arr[j];
               indexfromSmallest = j;
           } 
        }
        placeholder = arr[i];
        arr[i] = arr[indexfromSmallest];
        arr[indexfromSmallest] = placeholder;
    }
    for(i = 0;i < size; i++){
        printf("%d",arr[i]);
    }
    printf("\n");

    
    return 0;

}
