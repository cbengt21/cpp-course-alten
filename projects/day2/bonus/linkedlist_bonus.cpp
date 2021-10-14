#include <iostream>

typedef struct list{
    int value=0;
    struct list *next=nullptr;
} list_t;

list_t *findlast(list_t *linkedlist){
    while(linkedlist->next!=nullptr){
        linkedlist=linkedlist->next;
    }
    return linkedlist;
}
void addLast(list_t *&linkedlist, const int &val){
    if (linkedlist==nullptr){
        linkedlist= new list_t;
        linkedlist->value=val;
        linkedlist->next=nullptr;
    } else if(linkedlist!=nullptr){
        list_t *last=findlast(linkedlist);
        list_t *newNode= new list_t;
        newNode->next=nullptr;
        newNode->value=val;
        last->next=newNode;
    }
    return;
}
void addAtIndex(list_t *&linkedlist, const int &val, const int &index){
    if (linkedlist==nullptr){
        linkedlist= new list_t;
        linkedlist->value=val;
        linkedlist->next=nullptr;
    } else {
        
    }

}

void print(list_t *linkedlist){
    if(linkedlist==nullptr){
        return;
    }
    while(linkedlist!=nullptr){
        std::cout << linkedlist->value << std::endl;
        linkedlist=linkedlist->next;
    }
}
void remove(list_t *&linkedlist){
    if(linkedlist==nullptr){
        return;
    }
    list_t *temp=linkedlist->next;
    delete linkedlist;
    linkedlist=temp;
    return;
}



int main(){
    list_t *LINKED_LIST=nullptr;
    addLast(LINKED_LIST, 3);
    addLast(LINKED_LIST, 4);
    addLast(LINKED_LIST, 6);

    print(LINKED_LIST);
    remove(LINKED_LIST);
    print(LINKED_LIST);
    addAtIndex(LINKED_LIST, 7, 2);
    print(LINKED_LIST);
    //TODO: delete

    return 0;
}