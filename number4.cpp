//Given a sorted linked list, remove all the duplicates.

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int num;
    Node *next;

}*head,*tail;

Node *createNode(int num){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->num=num;
    newNode->next=NULL;

    return newNode;
}

void pushHead(int num){
    Node *temp = createNode(num);

    if(!head){
        head = tail= temp;
    } else {
        temp ->next = head;
        head = temp;
    }
}

void pushTail(int num){
    Node *temp = createNode(num);

    if(!head){ 
        head = tail= temp; 
    } else {
        tail ->next = temp; 
        tail = temp; 
    }
}

void popHead(){
    if (!head){
        return;
    } else if (head==tail){
        free (head);
        head = tail = NULL;
    } else{
        Node *temp = head->next;
        head->next= NULL;
        free (head);
        head = temp;
    }
}

void removeDuplicates(Node *head){
    Node *current = head;
    Node* temp; 
   
    if (current == NULL){
        return;
    }
    while (current->next != NULL){
        if (current->num == current->next->num) {         
            temp = current->next->next;
            free(current->next);
            current->next = temp;  
        } else{
            current = current->next; 
        }
    }
}

void printList (Node *node){
    while (node){
        printf("%d ", node->num);
        node = node->next;
    }
}

int main (){

    pushHead(20);
    pushTail(33);
    pushTail(33);
    pushTail(48);
    pushTail(49);
    pushTail(59);
    pushTail(59);
    pushTail(66);
    pushTail(98);
    pushTail(98);

    printf("Linked List Before:\n");
    printList(head);
    printf("\n");

    popHead();
    removeDuplicates(head);
    printf("Linked List After:\n");
    printList(head);

    return 0;
}

