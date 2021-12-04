#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct listEle {
    char suchwort[25];
    char ersetzungswort[25];
    struct listEle *next;

} ListEle;



extern ListEle *wordList;

typedef struct Fundstelle { 
    char *stelleImSuchstring; 
    ListEle *ersetzung; 
} Fundstelle;


void addPair(const char *such, const char *ersatz){
    ListEle *newPair = NULL;
    ListEle *actPair = wordList;
    newPair = malloc(sizeof(ListEle));
    *newPair -> suchwort = *such;
    *newPair -> ersetzungswort = *ersatz;
    newPair -> next = NULL;
    if(wordList == NULL){
        wordList = newPair;
    }
    
    while(actPair->next != NULL){
        actPair = actPair->next;
    }
    actPair -> next = newPair;

}

void clearList(void){
    
    ListEle *actPair = wordList;
    ListEle *loeschmisch = NULL;
    
    while(actPair!=NULL){
        loeschmisch = actPair;
        actPair = actPair ->next;
        loeschmisch -> next = NULL;
        free(loeschmisch);
    }
    
    wordList = NULL;    

}
struct Fundstelle find(const char *s){
    int gefunden = 0, counter= 0;;
    ListEle *actlist = wordList;
    Fundstelle *fundstelle = NULL;
        fundstelle = malloc(sizeof(Fundstelle));

        while(*s != "\0"){
            while(actlist != NULL){
                counter = 0;
                gefunden = 0;
                if(s == (actlist->suchwort[counter])){
                    s++;
                    counter++;
                    while(actlist->suchwort[counter]!= "\0"){
                        if(actlist->suchwort[counter] != s){
                            gefunden = 0;
                            break;
                        }
                        counter++;
                        s++;
                        gefunden = 1;
                    } 
                }
                if(gefunden == 1){
                    s = s-counter;
                    fundstelle->stelleImSuchstring = s;
                    fundstelle->ersetzung = actlist ->ersetzungswort;
                }else{
                    s = s-counter;
                    actlist = actlist->next;  

                }
            }
            if(gefunden == 1){
                break;
            }
            s++;
        }
    

    return *fundstelle;
}
int replaceAll(char *s){
    int ersetztcount,gefunden, sCounter ,suchwortCounter,i = 0;
    char newString[200] = {0};
    char *newS = newString;
    ListEle *actlist = wordList;

    while(*s != "\0"){
        gefunden = 0;
        while(actlist != NULL){
            if(s == (actlist->suchwort[suchwortCounter])){
                s++;
                suchwortCounter++;

                while(actlist->suchwort[suchwortCounter]!= "\0"){
                        if(actlist->suchwort[suchwortCounter] != s){
                            gefunden = 0;
                            break;
                        }
                        suchwortCounter++;
                        s++;
                        
                        gefunden = 1;
                }
                if(gefunden = 1){
                    i = 0;
                    while(actlist->suchwort[i] != "\0"){
                        newS = actlist->suchwort[i];
                        i++;
                    }
                    ersetztcount ++;

                }else{
                    s = s-suchwortCounter;
                }
            }else{
                newS = s;
                newS ++;
                s ++;
            }
            if(gefunden == 1){
                break;
            }
        }
        actlist = wordList;
    }
    s = newS;
}