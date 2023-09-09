#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void display(struct node*head){
    if (head== NULL){
        printf("List is empty!");
    }
    else{
        struct node* t = head;
        while(t != NULL){
            printf("%d ",t->data);
            t=t->next;
        }
        printf("\n");
    }
}

bool isempty(struct node* head){
    if (head==NULL){
        return true;
    }
    else {
        return false;
    }
}

struct node* insertatbegin(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = head;
    head = ptr;
    return head;
}
struct node* insertatend(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = data;
    ptr -> next = NULL;
    
    if (head == NULL){
        head = ptr;
        return head;
    }
    struct node* t= head;
    while(t!=NULL){
        t = t-> next;
    }
    t-> next = ptr;
    return head;
}

struct node* deleteatbegin(struct node* head){
    if (head == NULL){
        printf("List is empty!");
        return NULL;
    }
    else{
        struct node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
}
struct node* deleteatend(struct node* head){
    if (head == NULL){
        printf("List is empty!");
        return NULL;
    }
    else{
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
}
struct node* deleteatpos(struct node* head, int pos){
    if (head == NULL){
        printf("List is empty!");
        return NULL;
    }
    else{
        struct node* temp = head;
        struct node* t = head;
        int i = 1;
        while(i<pos){
            t = temp;
            temp = temp->next;
            i++;
        }
        t->next = temp->next;
        free(temp);
        return head;
    }
}
struct node* reverse(struct node* head){
    struct node* p = head; 
    struct node* t = head;
    while(t->next != NULL){
        insertatbegin(head, t->data);
    }
    return head;
}

int main(){
    struct node* head=NULL;
    bool flag = true;
    int e;
    while(flag){
        int ch, choice;
        printf("1. Insert at beginning\n");
        printf("2. Display\n");
        printf("3. Delete at beginning\n");
        printf("4. Exit\n");
        printf("5. Insert at end\n");
        printf("6. Reverse\n");
        printf("Enter choice : ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice){
            case 1: 
                {
                    printf("Enter element : ");
                    scanf("%d",&e);
                    head = insertatbegin(head, e);
                }
                break;

            case 2:
                display(head);
                break;
            
            case 3:
                head = deleteatbegin(head);
                break;

            case 4:
                flag = false;
                break;

            case 5:
                printf("Enter element : ");
                scanf("%d",&e);
                head = insertatend(head, e);
                break;
            case 6:
                head = reverse(head);
                break;
                
            default:
                printf("Invalid choice!");

        }    
        
    }
    return 0;    
}
