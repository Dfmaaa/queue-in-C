#include "main.c"
void normal_traverse(_LINKED_LIST_QUEUE *head){
    _LINKED_LIST_QUEUE *selected=head;
    while(selected!=NULL){
        printf("%d\t",(*selected).data);
        selected=(*selected).next;
    }
    puts("");
}
int main(){
    _LINKED_LIST_QUEUE *head, *tail;
    int end=0;
    head=NULL;
    enqueue(1,&head,&tail);
    enqueue(2,&head,&tail);
    enqueue(3,&head,&tail);
    enqueue(4,&head,&tail);
    normal_traverse(head);
    printf("%d\t",(dequeue(&tail,&end)).data);
    printf("%d\t",(dequeue(&tail,&end)).data);
    printf("%d\t",(dequeue(&tail,&end)).data);
    printf("%d\t",(dequeue(&tail,&end)).data);
    puts("");
    return 0;
}