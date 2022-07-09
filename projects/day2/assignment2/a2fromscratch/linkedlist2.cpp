#include <iostream>


typedef struct Node{
    int value=0;
    Node *next=nullptr;
} Node_t;

Node_t *findLast(Node_t *list){
    if(list==nullptr){
        return list;
    }
    while (list->next!=nullptr){
        list=list->next;
    }
    return list;
}

void addNodeEnd(Node_t *&list, const int &value){
    if(list==nullptr){
        list = new Node_t;
        list->value=value;
        list->next=nullptr;
        return;
    } else{
       Node_t *newNode= new Node_t;
       Node_t *last= findLast(list);
       newNode->next=nullptr;
       newNode->value=value;
       last->next=newNode;
    }
    return;
}

void addIndex(Node_t *list, const int &value, const int &index){
    if(list==nullptr){
        list = new Node_t;
        list->value=value;
        list->next=nullptr;
        return;
    } else{
        for (int i = 0; i < index ; i++){
            if(list != nullptr){
                list = list->next;
            }
        }
        list->value=value;
    }
    return;
}

void removeNodeFront(Node_t *&list){
    if (list==nullptr){
        return;
    }

    Node_t *next = list->next;
    delete list;
    list = next;
    return;
}

void print(Node_t *list){
    if (list==nullptr){
        return;
    }

    Node_t *temp = list;
    while (list != nullptr){
        std::cout << list->value << std::endl;
        list = list->next;
    }
    return;
}

int main(){
    Node_t *linked_list = nullptr;
    addNodeEnd(linked_list, 5);
    addNodeEnd(linked_list, 6);
    addNodeEnd(linked_list, 7);
    addNodeEnd(linked_list, 3);
    addIndex(linked_list, 8, 2);

    removeNodeFront(linked_list);

    print (linked_list);


    return 0;
}