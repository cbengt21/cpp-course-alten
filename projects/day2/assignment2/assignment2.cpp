#include <iostream>

typedef struct Node {
    int data;
    struct Node *next = nullptr;
} Node_t;

Node_t *findLast(Node_t *LinkedList){
    if (LinkedList == nullptr){
        return LinkedList;
    }

    Node_t *current = LinkedList;
    while(current->next !=nullptr){
        current =current->next;
    }
    return current;
}

void add(Node_t *&LinkedList, int value){
    //1) find last item
    //2) create a new node
    //3) assign & link
    if(LinkedList == nullptr){
        LinkedList = new Node_t;
        LinkedList->data = value;
        LinkedList->next = nullptr;
    } else {
        Node_t *newNode = new Node_t;
        Node_t *lastNode = findLast(LinkedList);
        newNode->next = nullptr;
        newNode->data = value;
        lastNode->next = newNode; //only exist inside this scope?
    }
    //std::cout << LinkedList->data << std::endl;
    return;
}

void remove(Node_t *&LinkedList){
    if (LinkedList == nullptr){
        //return LinkedList;
        return;
    }
    Node_t *next = LinkedList->next;
    delete LinkedList;
    LinkedList = next;
    
    return;
}

void print(Node_t *LinkedList){
    //1) loop over the list
    //2) print
    if (LinkedList == nullptr) return;

    while (LinkedList != nullptr){
        std::cout << LinkedList->data << std::endl;
        LinkedList = LinkedList->next;
    }
    return;
}

int main(){
    int a=2, b=3, c=4, d=5, e=6, f=7;

    Node_t * MY_LINKED_LIST = nullptr; //Why created in static memory?

    add (MY_LINKED_LIST,a);
    add (MY_LINKED_LIST,b);
    add (MY_LINKED_LIST,c);
    add (MY_LINKED_LIST,d);
    add (MY_LINKED_LIST,e);
    add (MY_LINKED_LIST,f);

    //std::cout << MY_LINKED_LIST->data << std::endl;
    print(MY_LINKED_LIST);

    remove(MY_LINKED_LIST);
    print(MY_LINKED_LIST);

    return 0;
}