#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    void *data;
    struct node *prev;
    struct node *next;
    
    
} Node;

/*typedef struct Node * nodep;*/

void printList(Node *list){
    Node *cur_Node = list;
    if(list == NULL){
        printf("Liste ist Leer \n");
        return;
    }
    while (cur_Node != NULL) {
        printf("%p \n", cur_Node->data);
        cur_Node = cur_Node -> next;
    }
}

Node* insertAt(Node *list, int pos, void *data){
    Node *new_Node = NULL, *cur_Node = NULL, *next_node = NULL;
    int i;
    new_Node = malloc(sizeof(Node));
    cur_Node = list;
    if(list == NULL){
        new_Node -> next = NULL;
        new_Node -> prev = list;
        new_Node -> data = data;
        return new_Node;
    }
    if(pos == -1){
        while(cur_Node -> next != NULL){
            cur_Node = cur_Node->next;
        }
    }else if(pos == 0){
        new_Node -> next = cur_Node;
        new_Node -> prev = cur_Node -> prev;
        new_Node -> data = data;
        cur_Node -> prev = new_Node;
        return new_Node;
    }else{
        pos = pos-1;
        for(i = 0; i < pos; i++){
            cur_Node = cur_Node->next;
        }
    }
    if(cur_Node == NULL){
        printf("Fehler: es wurde ein zu hoher Index eingegeben.");
        return list;
    }
    new_Node->next = cur_Node->next;
    new_Node->prev = cur_Node;
    new_Node->data = data;
    cur_Node->next = new_Node;
    if(new_Node->next != NULL){
        new_Node->next->prev = new_Node;
    }
    return list;
}

Node* copyList(Node *list){
    Node *curr_Node = NULL;
    Node *head = NULL;
    Node *new_Node = NULL;
    curr_Node = list;
    
    new_Node = malloc(sizeof(Node));
    new_Node -> prev = NULL;
    new_Node -> data = curr_Node->data;
    head = new_Node;
    while (curr_Node->next != NULL)
    {
        curr_Node = curr_Node -> next;
        new_Node -> next = malloc(sizeof(Node));
        new_Node -> next -> prev = new_Node;
        new_Node ->next -> data = curr_Node -> data;
        new_Node = new_Node -> next;
    }
    return head;

    while(list != NULL){

    }
}

Node* resetPointer(Node *list){
    while(list->prev != NULL){
        list = list -> prev;
    }
    return list;
}

Node* deleteAt(Node *list, int pos){
    int i;
    Node *curr_Node = list;
    Node *loschmich = NULL, *befor_Node= NULL, *after_Node= NULL;
    if(curr_Node == NULL){
        printf("Wenn nichts drinn ist, kann nichts gelöscht werden :(");
    }
    if(pos == 0){
        loschmich = curr_Node;
        curr_Node = curr_Node -> next;
        curr_Node -> prev = NULL;
        free(loschmich);
        return curr_Node;
    }else if(pos == -1){
        while(curr_Node ->next!= NULL){
            curr_Node = curr_Node -> next;
        }
    }else{
        for(i = 0; i < pos; i++){
            curr_Node = curr_Node -> next;
        }
    }
    if(curr_Node == NULL){
        printf("Fehler: es wurde ein zu hoher Index eingegeben.");
        return list;
    }
    loschmich = curr_Node;
    curr_Node -> prev -> next = curr_Node -> next;
    if(curr_Node -> next != NULL){
        curr_Node -> next -> prev = curr_Node -> prev;
    }
    free(loschmich);
    return list;

}
void deleteList(Node **list){
    Node *freeMe = NULL;
    Node *curr_Node = *list;

    while (curr_Node != NULL){
        freeMe = NULL;
        freeMe = curr_Node;
        curr_Node -> prev = NULL;
        curr_Node = curr_Node -> next;
        free(freeMe);
    }
    curr_Node -> prev = NULL;
    freeMe = NULL;
    *list = NULL;
}

int main(void){
    int a, b, c, d;
    Node *head;
    void *vp, *vp2, *vp3, *vp4;
    head = NULL;

    a = 100;
    b = 20;
    c = 40;
    d = 60;

    vp = &a;
    vp2 = &b;
    vp3 = &c;
    vp4 = &d;

    head = insertAt(head, -1, vp);
    /*resetPointer(head);*/
    
    head = insertAt(head, -1, vp2);
    /*resetPointer(head);*/
    head = insertAt(head, 0, vp3);
    
    head = insertAt(head, 2, vp4);
    
    printf("addAll\n");
    printList(head);
    /*printf("Delete\n");
    head = deleteAt(head, 2);
    printList(head);
    printf("Delete\n");
    head = deleteAt(head, -1);
    printList(head);*/
    deleteList(&head);

    printf("alles ist weg\n");
    printList(head);
    return 0;

}
