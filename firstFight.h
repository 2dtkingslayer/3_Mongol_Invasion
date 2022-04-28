/*
    * Ho Chi Minh City University of Technology
    * Faculty of Computer Science and Engineering
    * Initial code for Assignment 0
    * Programming Fundamentals Spring 2021
    * Author: Truong Duc Dang
    * Date: 08.02.2021
*/

//The library here is concretely set, students are not allowed to include any other libraries.
#ifndef firstFight_h
#define firstFight_h

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

void limit(int& x){
    if (x > 1000) x = 1000;
    else if (x < 0) x = 0;
}

bool checkPrimeNumber(int x){
    int i = 2, check = 1;
    if ((x == 1) || (x == 0)) {
        check = 0;
    }
    else {
        for (i = 2; i <= x/2; i++) {
            if (x % i == 0) {
                check = 0;
                break;
            }
        }
    }
    return check;
}

int getReady(int& HP, const int& ID, int& M, const int& E1){
    // TH1
    if ((E1 >= 100) && (E1 <= 199)){
        int h, J;
        h = (E1 - 100) % 64;
        J = HP % 100;
        switch(ID){
            case 0:
            if (J > h){
                // WP1
                if ((HP >= 500) && (M % 2 == 1) && (M >= 300)){ 
                    HP = HP + 50;
                    M = M - 300;
                }
                // WP2
                else if ((M % 2 == 0) && (M >= 200)){
                    HP = HP + 25;
                    M = M - 200;
                }
            }
            break;

            case 1:
            HP = HP + 75; // 50 + 25, no money reduced
            break;

            case 2:
            break;
        }
        limit(HP);
        limit(M);
        return HP + M; 
    }
    // TH2
    else if ((E1 >= 200) && (E1 <= 299)){
        int x;
        x = E1 % 4 + 1;
        switch(ID){
            case 0:
            switch(x){
                // MG1
                case 1:
                if ((M % 2 == 1) && (M >= 190)){
                    HP = HP + 5;
                    M = M - 190;
                }
                break;

                // MG2
                case 2:
                if ((M % 2 == 0) && (M >= 195)){
                    HP = HP + 7;
                    M = M - 195;
                }
                break;

                // MG3
                case 3:
                if ((M % 2 == 1) && (M >= 200)){
                    HP = HP + 9;
                    M = M - 200;
                }
                break;

                // MG4
                case 4:
                if ((M % 2 == 0) && (M >= 205)){
                    HP = HP + 11;
                    M = M - 205;
                }
                break;
            }
            break;

            case 1: // We are commanded, no condition
            switch(x){
                // MG1
                case 1:
                HP = HP + 5;
                M = M - 190;
                break;

                // MG2
                case 2:
                HP = HP + 7;
                M = M - 195;
                break;

                // MG3
                case 3:
                HP = HP + 9;
                M = M - 200;
                break;

                // MG4
                case 4:
                HP = HP + 11;
                M = M - 205;
                break;
            }
            break;

            case 2: // Enemies are commanded, no condition
            switch(x){
                // MG1
                case 1:
                HP = HP + 5;
                M = M - 190;
                break;

                // MG2
                case 2:
                HP = HP + 7;
                M = M - 195;
                break;

                // MG3
                case 3:
                HP = HP + 9;
                M = M - 200;
                break;

                // MG4
                case 4:
                HP = HP + 11;
                M = M - 205;
                break;
            }
            break;
        }
        limit(HP);
        limit(M);
        return HP + M;
    }
    // TH3
    else if ((E1 >= 300) && (E1 <= 399)){
        double a;
        if (checkPrimeNumber(E1 % 10) == 1) a = 2 * (E1 % 10);
        else a = 1;
        switch(ID){
            case 0:
            // Thuong
            if ((HP >= 600) && (checkPrimeNumber(HP % 10) == 1) && (M >= 500)){
                HP = ceil((double)HP * (1 + 2 * a / 100));
                M = M - 500;
            }
            // Dao
            else if ((HP >= 600) && (checkPrimeNumber(HP % 10) == 0) && (M >= 300)){
                HP = ceil((double)HP * (1 + a / 100));
                M = M - 300;
            }
            break;

            case 1:
            // Thuong
            if ((HP >= 600) && (checkPrimeNumber(HP % 10) == 1) && (M >= 500)){
                HP = HP + 200;
                M = M - 500;
            }
            // Dao
            else if ((HP >= 600) && (checkPrimeNumber(HP % 10) == 0) && (M >= 300)){
                HP = ceil((double)HP * (1 + a / 100));
                M = M - 300;
            }
            break;

            case 2:
            // Thuong
            if ((HP >= 600) && (checkPrimeNumber(HP % 10) == 1) && (M >= 500)){
                HP = ceil((double)HP * (1 + 2 * a / 100));
                M = M - 500;
            }
            // Dao
            else if ((HP >= 600) && (checkPrimeNumber(HP % 10) == 0) && (M >= 300)){
                HP = ceil((double)HP * (1 + a / 100));
                M = M - 300;
            }
            break;
        }
        limit(HP);
        limit(M);
        return HP + M;
    }
    // TH4
    else if ((E1 >= 400) && (E1 <= 499)){
        if ((E1 % 5) == 0) HP = ceil((double)HP * 9 / 10);
        return HP + M;
    }
    // TH5
    else if (E1 == 500){
        HP = ceil((double)HP * 3 / 4);
        M = ceil((double)M * 3 / 4);
        return HP + M;
    }
    else if ((E1 < 100) || (E1 > 500)) return -999; // out of range
    return -1;
}

int firstBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E2){
    int u, a; // a is the HP1 before estimating u
    if ((E2 < 100) || (E2 >= 500)) return -999; // out of range
    // TH1
    else if ((E2 >= 100) && (E2 <= 199)){
        HP2 = ceil((double)HP2 * 13 / 10);
        HP1 = ceil((double)HP1 * 11 / 10);
        limit(HP1);
        limit(HP2);
        a = HP1;
        if ((ID1 == 1) && (ID2 == 2)) {
            HP1 = ceil((double)HP1 * 8 / 10); // TH5
            return 0; // Both are commanded => draw
        } 
        else if ((ID1 == 1) && (ID2 == 0)) {
            HP1 = ceil((double)HP1 * 8 / 10); // TH5
            HP2 = 0;
            return 1; // We are commanded => win
        } 
        else if ((ID1 == 0) && (ID2 == 2)) {
            HP1 = 0;
            return -1; // Enemies are commanded => lose
        }
        else if ((ID1 == 0) && (ID2 == 0)){ 
            u = ceil(2 * (double)HP1 * HP2 / (HP1 + HP2));
            HP1 = HP1 - abs(HP2 - u);
            HP2 = HP2 - abs(a - u);
            limit(HP1);
            limit(HP2);
            if (HP1 > HP2) {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return 1;
            }
            else if (HP1 == HP2) {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return 0;
            }
            else {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return -1;
            }
        }
    }
    // TH2
    else if ((E2 >= 200) && (E2 <= 299)){
        HP1 = ceil((double)HP1 * 17 / 10);
        HP2 = ceil((double)HP2 * 12 / 10);
        limit(HP1);
        limit(HP2);
        a = HP1;
        if ((ID1 == 1) && (ID2 == 2)) return 0; // Both are commanded => draw
        else if ((ID1 == 1) && (ID2 == 0)) {
            HP2 = 0;
            return 1;} // We are commanded => win
        else if ((ID1 == 0) && (ID2 == 2)) {
            HP1 = 0;
            return -1;} // Enemies are commanded => lose
        else if ((ID1 == 0) && (ID2 == 0)){ 
            u = ceil(2 * (double)HP1 * HP2 / (HP1 + HP2));
            HP1 = HP1 - abs(HP2 - u);
            HP2 = HP2 - abs(a - u);
            limit(HP1);
            limit(HP2);
            if (HP1 > HP2) {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return 1;
            }
            else if (HP1 == HP2) {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return 0;
            }
            else {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return -1;
            }
        }
    }
    // TH3
    else if ((E2 >= 300) && (E2 <= 399)){
        if (E2 < 350) HP1 = HP1 + 30;
        else if (E2 >= 350) HP1 = HP1 + E2 % 100;
        limit(HP1);
        a = HP1;
        if ((ID1 == 1) && (ID2 == 2)) return 0; // Both are commanded => draw
        else if ((ID1 == 1) && (ID2 == 0)) {
            HP2 = 0;
            return 1; // We are commanded => win
        }
        else if ((ID1 == 0) && (ID2 == 2)) {
            HP1 = 0;
            return -1; // Enemies are commanded => lose
        }
        else if ((ID1 == 0) && (ID2 == 0)){
            u = ceil(2 * (double)HP1 * HP2 / (HP1 + HP2));
            HP1 = HP1 - abs(HP2 - u);
            HP2 = HP2 - abs(a - u);
            limit(HP1);
            limit(HP2);
            if (HP1 > HP2) {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return 1;
            }
            else if (HP1 == HP2) {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return 0;
            }
            else {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return -1;
            }
        }
    }
    // TH4
    else if ((E2 >= 400) && (E2 <= 499)){
        HP1 = ceil((double)HP1 * 13 / 10);
        HP2 = ceil((double)HP2 * 8 / 10);
        limit(HP1);
        HP1 = ceil((double)HP1 / 2);
        a = HP1;
        if ((ID1 == 1) && (ID2 == 2)) {
            HP1 = ceil((double)HP1 * 8 / 10); // TH5
            return 0; // Both are commanded => draw
        }
        else if ((ID1 == 1) && (ID2 == 0)) {
            HP1 = ceil((double)HP1 * 8 / 10); // TH5
            HP2 = 0;
            return 1; // We are commanded => win
        } 
        else if ((ID1 == 0) && (ID2 == 2)) {
            HP1 = 0;
            return -1; // Enemies are commanded => lose
        } 
        else if ((ID1 == 0) && (ID2 == 0)){
            u = ceil(2 * (double)HP1 * HP2 / (HP1 + HP2));
            HP1 = HP1 - abs(HP2 - u);
            HP2 = HP2 - abs(a - u);
            limit(HP1);
            limit(HP2);
            if (HP1 > HP2) {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return 1;
            }
            else if (HP1 == HP2) {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return 0;
            }
            else {
                HP1 = ceil((double)HP1 * 8 / 10); // TH5
                return -1;
            }
        }
    }
    return -1;
}

int secondBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E3){
    int u, a; // a is HP1 before the battle, HP1 equals a iff it returns -1
    int b; // b is HP1 before estimating u
    if ((E3 < 100) || (E3 > 300)) return -999;
    else {
        HP1 = ceil((double)HP1 * 14 / 10);
        HP2 = ceil((double)HP2 * 16 / 10);
        limit(HP1);
        limit(HP2);
        if (ID1 == 1) HP1 = HP1 * 2; // If we are commanded, HP1 is twice
        limit(HP1);
        a = HP1;
        b = HP1;
    }
    // TH1
    if ((E3 >= 100) && (E3 <= 199)){
        if ((ID1 == 1) && (ID2 == 2)) return 0; // Both are commanded => draw
        else if ((ID1 == 1) && (ID2 == 0)) {
            HP2 = 0;
            return 1; // We are commanded => win
        } 
        else if ((ID1 == 0) && (ID2 == 2)) {
            HP1 = 0;
            return -1; // Enemies are commanded => lose
        }
        else if ((ID1 == 0) && (ID2 == 0)){ 
            HP2 = ceil((double)HP2 * 95 / 100);
            u = ceil(2 * (double)HP1 * HP2 / (HP1 + HP2));
            HP1 = HP1 - abs(HP2 - u);
            HP2 = HP2 - abs(b - u);
            limit(HP1);
            limit(HP2);
            if (HP1 > HP2) return 1;
            else if (HP1 == HP2) return 0;
            else {
                HP1 = a;
                return -1;
            }
        }
    }
    // TH2
    else if ((E3 >= 200) && (E3 <= 299)){
        if (ID2 == 0) HP2 = ceil((double)HP2 * 95 / 100);
        return 0; // Auto draw
    }
    return -1;
}

int finalBattle(int& HP1, int& HP2, const int& ID1, const int& ID2, const int& E4){
    // TH1
    if ((E4 >= 100) && (E4 <= 199)){
        if (ID2 == 0) HP2 = ceil((double)HP2 * 10 / 100);
        else if (ID2 == 2) HP2 = ceil((double)HP2 * 30 / 100);
        return 0;
    }
    // TH2
    else if ((E4 >= 200) && (E4 <= 299)){
        HP2 = 0;
        return 1;
    }
    else if ((E4 < 100) || (E4 >= 300)) return -999; // out of range
    return -1;
}

#endif /* firstFight_h */