//
//  thirdBattle.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//
// Students can remove the final initial return of the functions

#ifndef thirdBattle_h
#define thirdBattle_h

#include "SLLDataController.h"
#include "ArrayDataController.h"
#include <vector>
#include <string>
//You can write your own functions here
    //TASK 4: Compare 2 lists' data
bool behon(SoldierNode *temp1, SoldierNode *temp2){
    if (temp1->data.HP < temp2->data.HP) return true;
    else if (temp1->data.HP == temp2->data.HP){
        if (temp1->data.isSpecial < temp2->data.isSpecial) return true;
        else if (temp1->data.isSpecial == temp2->data.isSpecial){
            if (temp1->data.ID < temp2->data.ID) return true;
            else if (temp1->data.ID == temp2->data.ID) return false;
            else if (temp1->data.ID > temp2->data.ID) return false;
        }
        else if (temp1->data.isSpecial > temp2->data.isSpecial) return false;
    }
    else if (temp1->data.HP > temp2->data.HP) return false;
    return true;
}
    //TASK 4: Merge the SoldierNode
SoldierNode *Unity(SoldierNode *temp1, SoldierNode *temp2){
    SoldierNode *res = new SoldierNode;
    if (temp1 == NULL) return temp2;
    if (temp2 == NULL) return temp1;
    if (behon(temp1,temp2) == 1){
        res->data = temp1->data;
        temp1 = temp1->next;
    }
    else {
        res->data = temp2->data;
        temp2 = temp2->next;
    }
    SoldierNode *sort = res;
    while (temp1 != NULL && temp2 != NULL){
        SoldierNode *newTail = new SoldierNode;
        if (behon(temp1,temp2) == 1){
            newTail->data = temp1->data;
            temp1 = temp1->next;
        }
        else {
            newTail->data = temp2->data;
            temp2 = temp2->next;
        }
        sort->next = newTail;
        sort = newTail;
    }
    if (temp1 == NULL) {
        while (temp2 != NULL){
            SoldierNode *newTail = new SoldierNode;
            newTail->data = temp2->data;
            temp2 = temp2->next;
            sort->next = newTail;
            sort = newTail;
        }
    }
    if (temp2 == NULL) {
        while (temp1 != NULL){
            SoldierNode *newTail = new SoldierNode;
            newTail->data = temp1->data;
            temp1 = temp1->next;
            sort->next = newTail;
            sort = newTail;
        }
    }
    return res;
}
//End your own functions

//////////////////////////////////////////////////////
/// TASK 1
//////////////////////////////////////////////////////

bool push(Array& array, Soldier soldier){
    if (array.arr == NULL){
        initArray(array , 1);
        array.size++;
        array.arr[0] = soldier;
        return true;
    }
    else return insertAt(array,soldier,array.size);
}

bool pop(Array& array){
    if (array.size > 0){
        array.size--;
        return true;
    }
    return false;
}

Soldier top(Array& array){
    if (array.size > 0) {
        return array.arr[array.size-1];
    }
    return Soldier();//return this if cannot get top
}

//////////////////////////////////////////////////////
/// TASK 2
//////////////////////////////////////////////////////

bool enqueue(SLinkedList& list, Soldier soldier){
    return insertAt(list , soldier , list.size);
}

bool dequeue(SLinkedList& list){
    return removeAt(list,0);
}

Soldier front(SLinkedList& list){
    if (list.size > 0) return list.head->data;
    return Soldier();//Return this if cannot get front
}

//////////////////////////////////////////////////////
/// TASK 3
//////////////////////////////////////////////////////

void reverse(SLinkedList& list){
    if (list.size > 0){
        SoldierNode *p = list.head;
        SoldierNode *res = initNode(list.head->data);
        list.head = list.head->next;
        delete p;
        while (list.head != NULL){
            SoldierNode *p = list.head;
            SoldierNode *temp = initNode(list.head->data);
            temp->next = res;
            res = temp;
            list.head = list.head->next;
            delete p;
        }
        delete list.head;
        list.head = res;
    }
}

//////////////////////////////////////////////////////
/// TASK 4
//////////////////////////////////////////////////////

SLinkedList merge(SLinkedList& list1, SLinkedList& list2){
    SLinkedList res(Unity(list1.head , list2.head) , list1.size+list2.size);
    clear(list1); clear(list2);
    return res;
}


#endif /* thirdBattle_h */
