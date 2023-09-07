//
//  SLLDataControler.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef SLLDataController_h
#define SLLDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>
//You can write your own functions here
    //TASK FULL: Create new Node
    SoldierNode* initNode(Soldier element){
        SoldierNode* p = new SoldierNode;
        p->data = element;
        p->next = NULL;
        return p;
    }
//End your own functions

//Functions used to manage Singly Linked List
void print(SLinkedList& list){
    if (!list.size) {
        std::cout << "List is empty" << endl;
        return;
    }
    SoldierNode* head = list.head;
    while (head){
        std::cout << head->data.ID << "->";
        head = head->next;
    }
    std::cout << "NULL"<<endl;
}

bool insertAt (SLinkedList& list, Soldier element, int pos){
    if (pos == 0){
        SoldierNode *p = initNode(element);
        if (list.head == NULL) list.head = p;
        else {
            p->next = list.head;
            list.head = p;
        }
        list.size++;
        return true;
    }
    else if (pos == list.size){
        SoldierNode *p = list.head;
        while (p->next != NULL) p = p->next;
        p->next = new SoldierNode;
        p = p->next;
        p->data = element;
        list.size++;
        return true;
    }
    else if (pos > 0 && pos < list.size){
        SoldierNode *p = list.head;
        int i = 1;
        while (p != NULL && i != pos){
            p = p->next;
            i++;
        }
        if (i == pos){
            SoldierNode *New = initNode(element);
            New->next = p->next;
            p->next = New;
            list.size++;
            return true;
        }
    }
    return false;
}

bool removeAt (SLinkedList& list, int idx){ 
    if (list.head == NULL || list.size == 0) return false;
    if (idx > 0 && idx < list.size){
        SoldierNode *p = list.head;
        SoldierNode *temp = p; // temp at index, p before index
        for (int i = 0; i < list.size; i++){
            if (i == idx){
                while (p->next != temp){
                    p = p->next;
                }
            p->next = temp->next;
            delete temp;
            list.size--;
            return true;          
            }
            temp = temp->next;
        }
    }
    else if (idx == 0){
        SoldierNode *p = list.head;
        list.head = p->next;
        delete p;
        list.size--;
        return true;
    }
    return false;
}

bool removeFirstItemWithHP (SLinkedList& list, int HP){
    if (list.size == 0) return false;
    SoldierNode *p = list.head;
    int i = 0;
    while (p != NULL){
        if (p->data.HP == HP) return removeAt(list,i);
        p = p->next;
        i++;
    }
    return false;
}

int indexOf(SLinkedList& list, Soldier soldier){
    if (list.size == 0) return -1;
    SoldierNode *p = list.head;
    int idx = 0;
    while (p != NULL){
        if ((p->data.HP == soldier.HP) && (p->data.ID == soldier.ID) && (p->data.isSpecial == soldier.isSpecial)) return idx;
        p = p->next;
        idx++;
    }
    return -1;   
}

int size(SLinkedList& list){
    return list.size;
}

bool empty(SLinkedList& list){
    if (list.size == 0) return true;
    return false;
}

void clear(SLinkedList& list){
    SoldierNode *p = list.head;
    for (int i = 0; i < list.size; i++){
        SoldierNode* temp = p;
        p = p->next;
        delete temp;
    }
    list.head = NULL;
    list.size = 0;
}

string getIDAt(SLinkedList& list, int pos){
    if (list.size == 0 || pos < 0 || pos >= list.size) return "-1";
    SoldierNode *p = list.head;
    for (int i = 0; i < list.size; i++){
        if (i == pos) return p->data.ID;
        p = p->next;
    }
    return "-1";
}

int getHPAt(SLinkedList& list, int pos){
    if (list.size == 0) return -1;
    SoldierNode *p = list.head;
    for (int i = 0; i < list.size; i++){
        if (p != NULL){
            if (i == pos) return p->data.HP;
        }
        p = p->next;
    }
    return -1;
}

bool setHPAt(SLinkedList& list, int HP, int pos){
    SoldierNode *p = list.head;
    int size = list.size;
    for (int i = 0; i < size; i++){
        if (i == pos){
            p->data.HP = HP;
            return true;
        }
        p = p->next;
    }
    return false;
}

bool contains (SLinkedList& list, Soldier soldier){
    SoldierNode *p = list.head;
    int size = list.size;
    for (int i = 0; i < size; i++){
        if ((p->data.HP == soldier.HP) && (p->data.ID == soldier.ID) && (p->data.isSpecial == soldier.isSpecial)) return true;
        p = p->next;
    }
    return false;
}


#endif /* SLLDataControler_h */
