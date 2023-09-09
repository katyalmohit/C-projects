#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* next;
};
struct node* insertAtBegin(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    head = ptr;
    return head;
}
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
struct node* insertAtBetween(struct node* head, int data, int pos){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = NULL;
    pos--;
    struct node* t = head;
    while(pos!=1){
        t = t->next;
        pos--;
    }
    ptr->next = t->next;
    t->next = ptr;
    return head;

}
struct node* deleteAtBegin(struct node* head){
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}
struct node* deleteAtEnd(struct node* head){
    struct node* temp = head;
    struct node* t = head;
    while(temp->next != NULL){
        t = temp;
        temp = temp->next;
    }
    t->next = NULL;
    free(temp);
    return head;
}
struct node* deleteAtBetween(struct node* head, int pos){
    struct node* temp = head;
    struct node* t = head; 
    while(pos!=1){
        t = temp;
        temp = temp->next;
        pos--;
    }
    t->next = temp->next;
    free(temp);
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
struct node* printReverse(struct node* head){
    if (head == NULL){
        return NULL;
    }
    printReverse(head->next);
    printf("%d ", head->data);
    return head;
}
int main(){
    struct node* head = NULL;
    bool flag = true;
    int choice, data, pos;
    while(flag){
        printf("\n1. Insert at begin\n2. Insert at end\n3. Insert at between\n4. Delete at begin\n5. Delete at end\n6. Delete at between\n7. Display\n8. Reverse\n9. Print Reverse\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBegin(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                head = insertAtBetween(head, data, pos);
                break;
            case 4:
                head = deleteAtBegin(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                head = deleteAtBetween(head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                head = reverse(head);
                break;
            case 9:
                head = printReverse(head);
                break;
            case 10:
                flag = false;
                break;
            default:
                printf("Invalid choice!");
        }
    }
}