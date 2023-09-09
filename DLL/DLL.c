#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* insertAtBegin(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));    
    ptr -> prev = NULL;
    ptr -> data = data;
    ptr -> next = NULL;
    if(head!=NULL){
        head->prev = ptr;
        ptr->next = head;
    }
    head = ptr;
    return ptr;
}
struct node* insertAtEnd(struct node* head, int data){
    if(head == NULL){
        head = insertAtBegin(head, data);
        return head;
    }
    else{
        struct node* temp = head;
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr-> prev = NULL;
        ptr-> data = data;
        ptr-> next = NULL;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        ptr -> prev = temp;
        temp -> next = ptr;

        return head;
    }
}
struct node* insertAtPos(struct node* head, int data, int pos){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->prev = NULL;
    ptr->data = data;
    ptr->next = NULL;
    struct node* temp = head;
    int i=1;
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    ptr->next->prev = ptr;
    temp->next = ptr;
    ptr->prev = temp;
    return head;
}
struct node* deleteAtBegin(struct node* head){
    struct node* temp = head;
    head = head-> next;
    head -> prev = NULL;
    free(temp);
    return head;
}
struct node* deleteAtEnd(struct node* head){
    struct node* p1 = head;
    
    while(p1->next->next!=NULL){
        p1 = p1->next;
    }
    struct node* p2 = p1->next;
    p1 -> next = NULL;
    free(p2);
    return head;
}
struct node* deleteAtPos(struct node* head, int pos){
    struct node* p1 = head;
    int i = 1;
    while(i < pos-1){
        p1= p1->next;
        i++;
    }
    struct node* p2 = p1->next;
    p1->next = p2->next;
    p2->next->prev = p1;
    free(p2);
    return head;
    
}
void display(struct node* head){
    struct node* temp = head;
    while(temp!= NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}
void displayReverse(struct node* head){
    struct node* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    while(temp!= NULL){
        printf("%d\n",temp->data);
        temp = temp->prev;
    }
}
void search(struct node* head, int element){
    struct node* p = head;
    int count = 0;
    while(p->next!=NULL){
        count++;
        if(p->data == element){
            printf("Element found at position %d\n",count);
            return;
        }
        p = p->next;
    }
    printf("Element Not found!\n");
}
struct node* reverseDLL(struct node* head){
    struct node* p1 = head;
    struct node* p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while(p2!=NULL){
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    head = p1;
    return head;
}
int main(){
    struct node* head = NULL;
    int choice;
    int data;
    int pos;
    bool flag = true;
    while(flag){

        printf("1. Insert at begin\n2. Insert at end\n3. Insert at position\n4. Delete at begin\n5. Delete at end\n6. Delete at position\n7. Display\n8. Display in reverse\n9. Search\n10. Reverse DLL\n11.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                printf("Enter the element: ");
                scanf("%d", & data);
                head = insertAtBegin(head, data);
                printf("\n");
                break;
            case 2:
                printf("Enter the element: ");
                scanf("%d", & data);
                head = insertAtEnd(head, data);
                printf("\n");
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter the element: ");
                scanf("%d", & data);
                head = insertAtPos(head, data, pos);
                printf("\n");
                break;
            case 4:
                head = deleteAtBegin(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d",& pos);
                head = deleteAtPos(head, pos);
                break;
            case 7:
                display(head);
                break;
            case 8:
                displayReverse(head);
                break;
            case 9:
                printf("Enter the element: ");
                scanf("%d",& data);
                search(head, data);
                break;
            case 10:
                head = reverseDLL(head);
                break;
            case 11:
                printf("Program Terminated!");
                flag = false;
                break;
            default:
                printf("Invalid choice!");
                break;
        }
    }
    return 0;
}