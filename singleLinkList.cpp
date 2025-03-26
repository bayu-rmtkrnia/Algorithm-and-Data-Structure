#include<iostream>
using namespace std;

struct nodes{
  int number;
  nodes *next;
};

//INSERTION

void insertFront(nodes*& head,int value){
  nodes* nodebaru = new nodes{value, nullptr};
    if(head == nullptr){
      head = nodebaru;
    }else{
      nodebaru -> next = head;
      head = nodebaru;
    }
}

void insertBack(nodes*& head,int value){
  nodes* nodebaru = new nodes{value, nullptr};
  if(head == nullptr){
    head = nodebaru;
  }else{
    nodes* walker = head;
    while(walker -> next){walker = walker->next;}
    walker->next = nodebaru;
  }
}

void insertAfterNode(nodes*& head, int currentvalue, int value){
  nodes* nodebaru = new nodes{value, nullptr};
  nodes* walker = head;
  while(walker -> number != currentvalue){walker = walker->next;}
  nodebaru -> next = walker -> next;
  walker -> next = nodebaru;
}

//DELETION
void deletionFront(nodes*& head){
  nodes* temp = head -> next;
  head -> next = NULL;
  head = temp;
}

void deletionBack(nodes*& head){
  nodes* walker = head;
  nodes* temp = NULL;
  while(walker ->  next != NULL){
    temp = walker;
    walker = walker -> next;
  }
  temp -> next = NULL;
} 

void deletionAfternode(nodes*& head, int currentValue){
  nodes* walker = head;
  nodes* prevNode = NULL;
  while(walker -> number != currentValue){
    prevNode = walker;
    walker = walker -> next;
  }
  prevNode -> next = walker -> next;
  walker -> next = NULL;
}

void deletionAll(nodes*& head){
  head ->  next = NULL;
  head->number = 0;
}

//SEARCHING
void searchNode(nodes*& head, int currentValue){
  nodes* walker = head;
  nodes* prev = NULL;
  nodes* after = NULL;
  bool ketemu = false;

  while(walker-> next != NULL){
    if(walker->number == currentValue){
      ketemu = true;
      break;
    }else{
      ketemu = false;
    }
    prev = walker;
    walker = walker->next;
  }
  //check the last node
  if(walker->number == currentValue){
    ketemu = true;
  }else{
    ketemu = false;
  }

  if(ketemu == true){
    if(walker->next == NULL){
      cout << "\n" << currentValue << " Located at the last position and after " << prev->number;
    }else if(prev == NULL){
      after = walker->next;
      cout << "\n" << currentValue << " Located at the fisrt position and before " << after->number;
    }else{
      after = walker->next;
      cout << "\n" << currentValue << " Located between " << prev->number << " and " << after->number;
    }
  }else{
    cout << '\n' << "Data not found";
  }
}

//DISPLAY

void display(nodes*& head){
  nodes* walker = head;
  while(walker -> next){
    cout << "[ " << walker -> number << " ], ";
    walker = walker -> next;
  }
  cout << "[ " << walker -> number << " ] ";
}

void displayEach(nodes*& head, bool& exit){
  nodes* walker = head;
  int choice;
  cout << "[ " << walker-> number << " ]\n";
  while(exit == false){
    cout << "1. Next\n2. Exit\nChoice:";
    cin >> choice;
    if(choice == 1){
      bool keluar;
      if(walker->next == NULL){
        cout << "\nNo next number\n";
        exit == false;
      }else{
        walker = walker->next;
        cout << "[ " << walker-> number << " ]\n ";
        exit == false;
      }
    }else if(choice == 2){
      
      exit = true;
    }
  }
};

int main(){
  bool exit = false;
  nodes* kepala = NULL;
  insertBack(kepala, 1);
  insertBack(kepala, 2);
  insertBack(kepala, 3);
  insertBack(kepala, 4);
  insertFront(kepala, 0);
  insertFront(kepala, -1);
  insertFront(kepala, -2);
  insertAfterNode(kepala, 2, 25);
  deletionAfternode(kepala, 25);
  displayEach(kepala, exit);
  return 0;
}
