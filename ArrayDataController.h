//
//  ArrayDataController.h
//  KTLT ASS 3
//
//  Created by Nhân Nguyễn on 17/05/2021.
//

// Students can remove the final initial return of the functions

#ifndef ArrayDataController_h
#define ArrayDataController_h

#include "dataStructure.h"
#include <vector>
#include <string>

//Functions used to manage Array
void print(Array& array){
    if (!array.size) {
        std::cout << "Array is empty" << endl;
        return;
    }
    std::cout <<"[";
    for(int i=0;i<array.size;i++){
        std::cout << array.arr[i].ID << " ";
    }
    std::cout <<"]" << endl;
}

void initArray (Array& array, int cap){
    array.arr = new Soldier[cap];
    array.size = 0;
    array.capacity = cap;
}

bool insertAt(Array& array, Soldier element, int pos){
    if (array.arr != NULL && pos >= 0 && pos <= array.size){
        if (array.size == array.capacity){ //ensureCapacity
            Soldier *temp = new Soldier[array.size * 2]; 
            for (int i = 0; i < array.size; i++) temp[i] = array.arr[i];
            delete[] array.arr;
            array.capacity = array.size * 2;
            array.arr = temp;
        }
        array.size++;
        for (int i = array.size-1; i > pos; i--) array.arr[i] = array.arr[i-1];
        array.arr[pos] = element;
        return true;
    }
    return false;
}

bool removeAt (Array& array, int idx){
    if (idx < 0 || idx >= array.size) return false;
    if (array.size > 1 && idx < array.size && idx >= 0){
        for (int i = idx; i < array.size-1; i++){
            array.arr[i] = array.arr[i+1];
        }
        array.size--;
        return true;
    }
    if (array.size == 1 && idx == 0){
        array.size=0;
        return true;
    }
    return false;
}

bool removeFirstItemWithHP (Array& array, int HP){
    if (array.size == 0) return false;
    for (int i = 0; i < array.size; i++){
        if (array.arr[i].HP == HP) return removeAt(array , i);
    }
    return false;
}

void ensureCapacity(Array& array, int newCap){
    Soldier *temp = new Soldier[newCap];
    for (int i = 0; i < array.size; i++) {
        temp[i] = array.arr[i];
    }
    delete[] array.arr;
    array.capacity = newCap;
    array.arr = temp;
}

int indexOf(Array& array, Soldier soldier){
    Soldier *p = array.arr;
    int size = array.size;
    for (int i = 0; i < size; i++){
        if ((p[i].HP == soldier.HP) && (p[i].ID == soldier.ID) && (p[i].isSpecial == soldier.isSpecial)) return i;
    }
    return -1;
}

int size(Array& array){
    return array.size;
}

bool empty(Array& array){
    if (array.size == 0) return true;
    return false;
}

string getIDAt(Array& array, int pos){
    if (array.size > 0 && pos >= 0 && pos < array.size) return array.arr[pos].ID;
    return "-1";
}

int getHPAt(Array& array, int pos){
    if (pos >= 0 && pos < array.size) return array.arr[pos].HP;
    return -1;
}

bool setHPAt(Array& array, int HP, int pos){
    if (array.size > 0 && pos >= 0 && pos < array.size){
        array.arr[pos].HP = HP;
        return true;
    }
    return false;
}

void clear(Array& array){
    delete [] array.arr;
    array.arr = NULL;
    array.size = 0;
    array.capacity = 0;
}

bool contains (Array& array, Soldier soldier){
    if (array.size == 0) return false;
    for (int i = 0; i < array.size; i++){
        if (array.arr[i].HP == soldier.HP && array.arr[i].isSpecial == soldier.isSpecial && array.arr[i].ID == soldier.ID) return true;
    }
    return false;
}

//You can write your own functions here

//End your own functions

#endif /* ArrayDataController_h */
