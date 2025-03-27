#include<iostream>
using namespace std;

struct Node{
  Node* prev;
  string value;
  Node* next;
};

//INSERTION
void insertFront(Node*& head, string value, Node*& tail){
  Node* newnode = new Node{NULL, value, NULL};
  if(!head){
    head = newnode;
    tail = newnode;
  }else{
    head->prev = newnode;
    newnode->next = head;
    Node* temp = head;
    head = newnode;
    tail = temp;
  }
}

void insertRear(Node*& head, string value,  Node*& tail){
  Node* newnode = new Node{NULL, value, NULL};
  if(!head){
    head = newnode;
    tail = newnode;
  }else{
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
  }
}

void insertAfternode(Node*& head, string value, string afternodeValue,  Node*& tail){
  Node* newnode = new Node{NULL,value,NULL};
  Node* walker = head;
  while(walker->value != afternodeValue){
    walker = walker->next;
  }
  Node* after = walker->next;
  walker->next = newnode;
  newnode->prev = walker;
  newnode->next = after;
  after->prev = newnode;
}

//DELETION
void removeFront(Node*& head,  Node*& tail){
  if(head == tail){
    head = NULL;
    tail = NULL;
  }else{
    Node* temp = head->next;
    head->next = NULL;
    temp->prev = NULL;
    head = temp;
  }
}

void removeRear(Node*& head,  Node*& tail){
  if(head == tail){
    head = NULL;
    tail = NULL;
  }else{
    Node* temp = tail->prev;
    tail->prev = NULL;
    temp->next = NULL;
    tail = temp;
  }
}

void removeAfterNode(Node*& head, string value,  Node*& tail){
  if(head == tail){
    head = NULL;
    tail = NULL;
  }else{
    Node* walker = head;
    while(walker->value != value)walker = walker->next;
    Node* before = walker->prev;
    Node* after = walker->next;
    before->next = after;
    after->prev = before;
    walker->next = NULL;
    walker->prev = NULL;
  }
}


//DISPLAY
void displayAll(Node*& head, Node* tail){
  Node* walker = head;
  if(head == NULL){
    cout << "List is empty\n";
  }else{
    while(walker->next != NULL){
      cout << "[ " << walker->value << " ], ";
      walker = walker->next;
    }
    cout << "[ " << walker->value << " ] ";  
  }
}


int main(){
  bool exit = true;
  int choice;
  Node* kepala = NULL;
  Node* tail = NULL;
  insertFront(kepala, "Bayu", tail);
  insertFront(kepala, "Dharu", tail);
  insertAfternode(kepala, "Rujaki Bubub", "Dharu", tail);
  insertRear(kepala, "Nabil Aufa", tail);
  removeAfterNode(kepala, "Rujaki Bubub", tail);
  displayAll(kepala, tail);
  return 0;
}