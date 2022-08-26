#include <stdio.h>
#include <stdlib.h>
/*uncomment the 4th line of size is more important to you than speed. The program will then take
more cpu cycles to read certain members of the structure, but it wont use padding, which wastes memory 
but increases speed.*/
//#define SIZE_OVER_SPEED
#ifdef SIZE_OVER_SPEED
    #pragma pack(1)
#endif
struct node{
    int data;
    struct node *next;
    struct node *parent;
};
#ifdef SIZE_OVER_SPEED
    #pragma pack(0)
#endif
typedef struct node _LINKED_LIST_QUEUE;
void enqueue(int,_LINKED_LIST_QUEUE**,_LINKED_LIST_QUEUE**);
_LINKED_LIST_QUEUE dequeue(_LINKED_LIST_QUEUE**, int*);
void enqueue(int value, _LINKED_LIST_QUEUE **queue_head, _LINKED_LIST_QUEUE **tail){
    if(*queue_head==NULL){
        *queue_head=(_LINKED_LIST_QUEUE*)malloc(sizeof(_LINKED_LIST_QUEUE));
        if(*queue_head==NULL){
            perror("[malloc]");
            exit(EXIT_FAILURE);
        }
        (**queue_head).data=value;
        (**queue_head).parent=NULL;
        (**queue_head).next=NULL;
        *tail=*queue_head;
        return;
    }
    _LINKED_LIST_QUEUE *save_head=*queue_head;
    *queue_head=(_LINKED_LIST_QUEUE*)malloc(sizeof(_LINKED_LIST_QUEUE));
    if(*queue_head==NULL){
            perror("[malloc]");
            exit(EXIT_FAILURE);
    }
    (**queue_head).data=value;
    (**queue_head).parent=NULL;
    (**queue_head).next=save_head;
    (*save_head).parent=*queue_head;
}
_LINKED_LIST_QUEUE dequeue(_LINKED_LIST_QUEUE **tail, int *SIGEND){
    _LINKED_LIST_QUEUE retstruct=**tail;
    if((**tail).parent==NULL){
        free(*tail);
        *SIGEND=1;
    }
    else{
        *tail=(**tail).parent;
        free((**tail).next);
    }
    return retstruct;
}
