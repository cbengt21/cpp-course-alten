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

void removeNodeFront(Node_t *&list){

}

void print(Node_t *list){
    Node_t *temp = list;
    while (list->next!=nullptr){
        std::cout << list->value << std::endl;
        temp=temp->next;
    }
    return;
}



int main(){
    Node_t *linked_list = nullptr;
    addNodeEnd(linked_list, 5);
    addNodeEnd(linked_list, 6);
    addNodeEnd(linked_list, 7);
    addNodeEnd(linked_list, 3);

    //removeNodeFront(linked_list);

    print (linked_list);


    return 0;
}