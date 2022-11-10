#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* link;
};

                                /********* Functions ***********/


void add_to_begg(struct node** , int);


void show_list(struct node*);


struct node* add_to_end(struct node*,int);


int counting_nodes(struct node* head);


void add_to_n_pos(struct node*,int,int);


struct node* delet_first(struct node*);


void delet_last(struct node*);


void delet_any_node(struct node** ,int);


void delet_all_nodes(struct node**);


struct node* reverse_liste(struct node*);


int main () {
    struct node* head=NULL;
    struct node* current=NULL;

    head=(struct node*)malloc(sizeof(struct node));
    if(!head){
        printf(" ********* Allocation ERROR !!!! ********");
        exit(33);
    }

    head->data=2;
    head->link=NULL;
    current=head;

    add_to_begg(&head,1);
    current=add_to_end(current,3);
    current=add_to_end(current,4);
    current=add_to_end(current,5);
    current=add_to_end(current,6);
    current=add_to_end(current,7);
    add_to_n_pos(head,1,66);

    show_list(head);
    printf("\n\t\t-> Your list countains %d element !!!! ",counting_nodes(head));

    //head=delet_first(head);
    // delet_last(head);
    // delet_any_node(&head,2);
    //printf("saliiiiima");
    //show_list(head);
    //printf("\n\t\t-> Your list countains %d element !!!! ",counting_nodes(head));

    //delet_all_nodes(&head);
    
    head=reverse_liste(head);

    show_list(head);
    
    return 0;
}



struct node* reverse_liste(struct node* head){
    struct node* next=NULL;
    struct node* previous=NULL;
    if(!head){
        printf("\n\t********* Empty list !!!!!!! **********");
        exit (33);
    while(head){
        next=head->link;
        head->link=previous;
        previous=head;
        head=next;
    }
    head=previous;
    return head;
}





void delet_all_nodes(struct node** head){
    struct node* ptr=*head;
    if(!head)
        printf("\n\n\t\t******** Your list is already EMPTY !!!!!! *********");
    else if(!(*head)->link){
        free(*head);
        *head=NULL;
    }else{
         while(*head){
             ptr=(*head);
             *head=(*head)->link;
             free(ptr);
             ptr=NULL;
         }
    }
    if(!(*head))
       printf("\n\n\t\t *********************** List has been >> DELETED << Successfully !!! **********************");
}


void delet_any_node(struct node** head,int index){
    if(counting_nodes(*head)<index || index<1 ){
        printf("\n\t******** This index >> %d << doesn't EXIST ! **********",index);
        return;
    }
    struct node* current = *head;
    struct node* previous = *head;
    int count=1;
    if(!*head)
       printf("\n\n\t\t ****** List already EMPTY !!!! *******");
    else if(index==1){
        (*head)= (*head)->link;
        free(current);
        current=NULL;
    }else{
        while(count<index && current->link){
            previous=current;
            current=current->link;
            count++;
        }
    previous->link=current->link;
    free(current);
    current=NULL;
    }
}


void delet_last(struct node* head){
    if(!head){
        printf("\n\n\t\t******** Your list is already EMPTY !!!!!! *********");
        exit(33);
    }else if(head->link == NULL){
        free(head);
        head=NULL;
    }else{
        while(head->link->link!=NULL)
            head=head->link;
        free(head->link);
        head->link=NULL;
    }
}

struct node* delet_first(struct node* head){
      if(!head){
          printf("\n\n\t\t******** Your list is already EMPTY !!!!!! *********");
          exit(33);
      }
      struct node* temp=head;
      head=head->link;
      free(temp);
      temp=NULL;
      return head;
}

void add_to_n_pos(struct node* head,int pos,int data){
    if(counting_nodes(head)<pos ||pos<1 ){
        printf("\n\t******** This index >> %d << doesn't EXIST ! **********",pos);
        return;
    }

    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(!new){
        printf("\n\n\t\t\t ********* Allocation ERROR !!!! ********");
        exit(33);
    }
    new->data=data;
    new->link=NULL;
    if(pos==1)
    {
        new->link=head;
        head=new;
    }else
    {
        int count=1;
        while(count < pos-1 && head->link){
                head=head->link;
                count++;
         }
       new->link=head->link;
       head->link=new;
    }
}

int counting_nodes(struct node* head){
    if(head==NULL)
        return 0;
    else
        return 1+counting_nodes(head->link);
}

void show_list(struct node* head){
    if(!head){
        printf("\n\t********* Empty list !!!!!!! **********");
        exit (33);
    }

    struct node* current=(struct node*)malloc(sizeof(struct node));
    if(!current){
        printf("\n\n\t\t\t ********* Allocation ERROR !!!! ********");
        exit(33);
    }

    current=head;
    printf("\n-Your list : ");
    while(current != NULL){
        printf("%d  ",current->data);
        current=current->link;
    }
}

void add_to_begg(struct node** head , int data){
    if(head==NULL){
        printf("\n\t\t\tEmpty list !!!!!!!");
        exit (33);
    }
    struct node* new=(struct node*)malloc(sizeof(struct node));
    if(!new){
        printf("\n\n\t\t\t ********* Allocation ERROR !!!! ********");
        exit(33);
    }
    new->data=data;
    new->link = *head;
    *head = new;
}

struct node* add_to_end(struct node* current ,int data){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    
    if(!new){
        printf("\n\n\t\t\t ********* Allocation ERROR !!!! ********");
        exit(33);
    }

    new->data=data;
    new->link=NULL;
    current->link=new;
    return new;
}
