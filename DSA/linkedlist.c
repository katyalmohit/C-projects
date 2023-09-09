#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* insertAtEnd(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = NULL;
    if (head == NULL){
        head = ptr;
        return head;
    }
    struct node* t = head;
    while(t->next != NULL){
        t = t->next;
    }
    t->next = ptr;
    return head;
}
void display(struct node* head){
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
struct node* reverse(struct node* head){
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* Next = NULL;
    while(curr!=NULL){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
    head = prev; 
    return head;
}
void printReverse(struct node* head){
    if(head == NULL){
        return ;
    }
    printReverse(head->next);
    printf("%d ",head->data);
    
}
struct node* addLoop(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = NULL;
    struct node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = head->next->next->next;
    return head;
}
void detectLoop(struct node* head){
    struct node* slow = head;
    struct node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            printf("Loop detected\n");
            return;
        }
    }
    printf("No loop detected\n");
    return;
}
void findMid(struct node* head){
    struct node* slow = head;
    struct node* fast = head;
    while(fast!=NULL && fast ->next  != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("The middle element of linkedlist is %d",slow->data);
}
int main(){
    struct node* head = NULL;
    head = insertAtEnd(head,11);
    head = insertAtEnd(head,12);
    head = insertAtEnd(head,13);
    head = insertAtEnd(head,14);
    head = insertAtEnd(head,15);
    head = insertAtEnd(head,16);
    head = insertAtEnd(head,17);
    //head = addLoop(head,16);
    //display(head);
    detectLoop(head);
    findMid(head);
    printf("\n");

    //printReverse(head);

    head = reverse(head);
    printf("\n");
    //display(head);
    return 0;
}