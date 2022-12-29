#include "Queue.h"
#include <iostream>
#include <ostream>
/**
 * Implement Queue constructor
 */
Queue::Queue() {
    /* YOUR CODE HERE */
    head = tail = NULL;
    numElements = 0;
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
    clear();
    delete(head);
    delete(tail);
}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
    //One Node
    if(numElements == 1){
        Node *temp = head;
        head = tail = NULL;
        delete(temp);
    }
    else{ 
        while(head != NULL){
            Node *temp = head;
            head = head->next;
            delete(temp);
        }
        head = tail = NULL;
    }
    //Everything should be cleared
    numElements = 0;
}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {
     //Create new Node
    Node* newNode = new Node(s);
    if(newNode == NULL){
        cout<<"ERROR"<<endl;
        return;
    }
    newNode->next = NULL;

     if(numElements == 0){
         tail = head = newNode;
     }
     else{
         tail->next = newNode;
         tail = tail->next;
     }
     //Increase numElements
     numElements++;

}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {
    //What we will be returning
    string r;
    //pop will not be called on empty list
    //List has 1 item
    if(numElements == 1){
        Node* temp = head;
        r = head->data;
        numElements = 0;
        head = tail = NULL;
        delete(temp);
    }
    //More than 1 item
    else{
        r = head->data;
        Node *temp = head;
        //Set new head
        head = head->next;
        numElements--;
        //Delete Nodes
        delete(temp);
    }
    return(r);
}
