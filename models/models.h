#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Patient{
    char name[255];
    int day;
    char month[101];
    int year;
    Patient *next;
} *head,*tail,*curr;


Patient *createPatient(char name,int day, char month, int year){
    Patient *temp = (Patient*) malloc(sizeof(Node));
    strcpy(temp->name,name);
    strcpy(temp->month,month);
    temp -> day = day;
    temp -> year = year;
    temp -> next = temp -> prev = NULL;
}


void deletePatient (Patient *m){
    free(m);
    return;
}

void pushHead(char name,int day,char month,int year){
    Patient *temp = createPatient (name,day,month,year);
    if(!head){
        head = tail = temp;
    }
    else{
        temp -> next = head;
        head = temp;
    }
}

void pushTail (char name,int day , char month , int year){
    Patient *temp = createPatient(name,day,month,year);
    if (!head){
        head = tail = temp;
    }
    else{
        tail -> next = temp;
        tail = temp;
    }
}

void popHead (){
    if(!head){
        return;
    }
    else if (head == tail){
        head = tail = NULL;
        free(head);
    }
    else{
        curr = head;
        while (curr){
            if (curr -> next == tail){
                curr -> next = NULL;
                free(tail);
                tail = curr;
                break;
            }
            curr = curr -> next;   
        }
    }
}