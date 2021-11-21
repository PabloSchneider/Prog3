#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[25];
    struct person *next;

}Person_t;


Person_t* add(Person_t* root, char value[25]){
    Person_t *curr, *new_person;
    
    new_person = malloc(sizeof(Person_t));
    
    if(root == NULL){
        new_person -> next = new_person; 
        strcpy(new_person -> name, value);
        return new_person;
    }
    new_person -> next = root; 
    strcpy(new_person -> name, value);

    curr = root;
    while(curr->next != root){
        curr = curr -> next;
    }
    curr -> next = new_person;
    return new_person;
}

void del(Person_t *root, int anz){
    int i;
    Person_t *curr = root;
    Person_t *loeschmich;
    while(curr -> next != curr){
        
        for(i = 0; i < anz-1; i++){
            curr = curr -> next;
        }
        loeschmich = curr -> next;
        
        printf("%s: muss nicht spülen\n", curr->next->name);

        curr -> next = curr -> next -> next;
        
        free(loeschmich);
    }
    printf("%s: muss spülen\n", curr->name);
    free(curr);

}

int main(int argc, char *argv[]){
    
    char s[25];
    int i, j;
    Person_t* root = NULL;
    Person_t* amogus;
    
    printf("argc %d\n", argc);
    printf("Wer soll alles mitspielen?\n");
    i = 0;
    while(scanf("%s", s) != EOF){
        root = add(root, s);
        i++;
        

    }
    printf("\n");
    j = 0;
    amogus = root;
    del(root, argc-1);
}
