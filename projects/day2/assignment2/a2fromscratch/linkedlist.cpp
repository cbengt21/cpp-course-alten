#include <iostream>

typedef struct list{
    int value;
    struct list *next=nullptr;
} list_t;

void add (list_t *&linkedList , const int &value);
void remove(list_t *&linkedList);
void print(list_t *linkedList);
list_t *findLast(list_t *linkedList);


int main(){
    list_t *LINKED_LIST=nullptr;
    add(LINKED_LIST, 5);
    add(LINKED_LIST, 6);
    add(LINKED_LIST, 9);

    print(LINKED_LIST);

    remove(LINKED_LIST);

    print(LINKED_LIST);

    /*while (LINKED_LIST->next != nullptr){
        list_t *next = LINKED_LIST->next;
        delete LINKED_LIST;
        LINKED_LIST=next;
    }*/
    return 0;
}

//Add items to the end of the list:
void add (list_t *&linkedList , const int &addedValue){

    if(linkedList==nullptr){
        linkedList=new list_t;
        linkedList->next = nullptr;
        linkedList->value = addedValue;
    } else{
        list_t *newNode = new list_t;
        list_t *lastNode = findLast(linkedList);
        newNode->value=addedValue;
        newNode->next=nullptr;
        lastNode->next=newNode;
    }
    return;
}
list_t *findLast(list_t *linkedList){
    if(linkedList==nullptr){
        return linkedList;
    }
    list_t *current = linkedList;
    while(current->next != nullptr){
        current=current->next;
    }
    return current;
}

void print(list_t *linkedList){

    if (linkedList==nullptr){
        return;
    }
    while(linkedList != nullptr){
        std::cout << linkedList->value << std::endl;
        linkedList = linkedList->next;
    }
    return;
}

void remove(list_t *&linkedList){
    if (linkedList==nullptr){
        return;
    }

    list_t *next = linkedList->next;
    delete linkedList;
    linkedList=next;
    return;
}