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
void addAtIndex(list_t *linkedlist, const int &val, const int &index){
    if (linkedlist==nullptr){
        linkedlist= new list_t;
        linkedlist->value=val;
        linkedlist->next=nullptr;
    } else {
        for (int i=0; i<index ; i++){
            if (linkedlist->next!=nullptr){
                linkedlist=linkedlist->next;
            }
        }
        linkedlist->value=val;
    }
    return;
}

void print(list_t *linkedlist){
    if(linkedlist==nullptr){
        return;
    }
    while(linkedlist!=nullptr){
        std::cout << linkedlist->value << std::endl;
        linkedlist=linkedlist->next;
    }
    return;
}
void removeBeginning(list_t *&linkedlist){
    if(linkedlist==nullptr){
        return;
    }
    list_t *temp=linkedlist->next;
    delete linkedlist;
    linkedlist=temp;
    return;
}
void removeIndex(list_t *&linkedlist, const int &index){
    if (linkedlist==nullptr){
        return;
    }
    
    list_t *previous=nullptr;
    list_t *after=nullptr;
    list_t *current = linkedlist;
    if (index==0){
        current=linkedlist;
        linkedlist=linkedlist->next;
        delete current;
    } else { 
        for (int i=1; i<(index+1) ; i++){
            if (current->next!=nullptr){
                previous=current;
                current=current->next;
            } else {
                return;
            }
        }
        after=current->next;
        previous->next=after;
        delete current;
    }
    return;
}
void reverseOrder(list_t *&LINKED_LIST){
    list_t *previous = nullptr;
    list_t *current = LINKED_LIST;
    list_t *next = nullptr;
    while (current !=nullptr){
        // Store next 
        next = current->next; 
        // Reverse current node's pointer 
        current->next = previous; 
        // Move pointers one position ahead. 
        previous = current; 
        current = next; 
    }
    LINKED_LIST=previous;
    return;
}

int main(){
    list_t *LINKED_LIST=nullptr;
    addLast(LINKED_LIST, 3);
    addLast(LINKED_LIST, 4);
    addLast(LINKED_LIST, 6);

    //print(LINKED_LIST);
    //removeBeginning(LINKED_LIST);
    //print(LINKED_LIST);
    //addAtIndex(LINKED_LIST, 7, 1);
    //print(LINKED_LIST);
    //removeIndex(LINKED_LIST, 2);
    reverseOrder(LINKED_LIST);
    print(LINKED_LIST);
    
    //delete list:
    while(LINKED_LIST!=nullptr){
        list_t *temp=LINKED_LIST;
        LINKED_LIST=LINKED_LIST->next;
        delete temp;
    }
    //print(LINKED_LIST);
    return 0;
}