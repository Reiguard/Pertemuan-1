//Given a sorted (ascending) linked list, manipulate it to become a sorted (descending) linked list.

#include<stdio.h> 
#include<stdlib.h>
 
struct Node{ 
    int data; 
    struct Node *next; 
};

void TheBegin(struct Node **start_ref, int data){ 
    struct Node *ptr1 = (struct Node*)malloc(sizeof(struct Node)); 
    ptr1->data = data; 
    ptr1->next = *start_ref; 
    *start_ref = ptr1; 
} 

void swap(struct Node *a, struct Node *b){ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 
  
void bubbleSort(struct Node *start){

    int swapped, i; 
    struct Node *ptr1; 
    struct Node *lptr = NULL; 

    if (start == NULL) 
        return; 
  
    do{
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr){ 
            if (ptr1->data < ptr1->next->data){  
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while(swapped); 
} 

void printList(struct Node *start){ 
    struct Node *temp = start; 
    printf("\n"); 
    while (temp!=NULL){ 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
} 
  
int main(){ 
    int arr[] = {3, 888, 9999, 10000, 1002000, 10080802};
    int list_size; 
    struct Node *start = NULL; 
  
    for(int U=0; U<6; U++){
    	TheBegin(&start, arr[U]);
	}

    bubbleSort(start); 
    printf("Linked list sorting: "); 
    printList(start);
    printf("\n");
    return 0; 
}
