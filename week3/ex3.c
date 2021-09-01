#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct SLL{
    struct Node* head;
    struct Node* tail;
    int size;
};

void initialize(struct SLL* sll){
    sll->size=0;
    sll->tail=NULL;
    sll->head=sll->tail;
}

void insert(struct SLL* sll, int val, int index){
    if (index == 0){
        struct Node *node = malloc (sizeof (struct Node));
        node->value = val;
        node->next = sll->head;
        sll->head = node;
        sll->size++;
        return;
    }
    if (index > sll->size || index < 0){
        printf("Invalid index!\n");
        return;
    }
    struct Node* temp = sll->head;

    for (int i = 0; i < index - 1; i++){
        temp = temp->next;
    }

    struct Node *node = malloc (sizeof (struct Node));
    node->value = val;
    node->next = temp->next;
    temp->next = node;

    sll->size++;
}

void delete(struct SLL* sll, int index){
    if (index == 0 && sll->size > 0){
        struct Node* temp = sll->head->next;
        free(sll->head);
        sll->head = temp;
        sll->size--;
        return;
    }
    if (index < 0 || index >= sll->size){
        printf("Invalid index!\n");
        return;
    }

    struct Node* temp = sll->head;

    for (int i = 0; i < index - 1; i++){
        temp = temp->next;
    }

    struct Node* temp2 = temp->next;
    temp->next = temp2->next;

    free(temp2);
    sll->size--;
}

void print_list(struct SLL* sll){
    struct Node* temp = sll->head;
    while (temp != NULL){
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct SLL sll;

    initialize(&sll);
    insert(&sll, 10, 0);
    insert(&sll, 11, 0);
    insert(&sll, 12, 0);
    insert(&sll, 13, 2);
    insert(&sll, 14, 4);

    print_list(&sll);

    delete(&sll, 2);
    delete(&sll, 0);
    delete(&sll, sll.size - 1);

    print_list(&sll);

    return 0;
}