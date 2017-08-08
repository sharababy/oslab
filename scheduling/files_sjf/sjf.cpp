#include <iostream>
#include "refinedsjf.h"

using namespace std;

refinedsjf::refinedsjf() {

}

void refinedsjf::swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void refinedsjf::calculateEverything(refinedsjf *obj, int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (obj[i].at > obj[j].at) {
                swap(&obj[i].at , &obj[j].at);
                swap(&obj[i].bt , &obj[j].bt);
            }
        }
    }

    //calculate ct tat and wt

    for (int i = 0; i < n; ++i) {
        int minimum = 1000;
        int position = i;

        if (i==0) {                         //for the first completion time
            obj[i].ct = obj[i].bt + obj[i].at;
        } else {
            for (int j = i; j < n; ++j) {
                if ((obj[j].at <= obj[i-1].ct) && (obj[i].bt<minimum)) {
                    minimum = obj[i].bt;
                    position = j;
                }
            }

            int temp1 = obj[i].at;
            obj[i].at = obj[position].at;
            obj[position].at = temp1;

            int temp2 = obj[i].bt;
            obj[i].bt = obj[position].bt;
            obj[position].bt = temp2;

            if (obj[i].at > obj[i-1].ct) {
                obj[i].ct = obj[i].at + obj[i].bt;
            } else {
                obj[i].ct = obj[i-1].ct + obj[i].bt;
            }
        }

        obj[i].findtat();
        obj[i].findwt();
    }
}

void refinedsjf::display(refinedsjf obj[], int n) {

    for (int i = 0; i < n; ++i) {
        cout << i << "\t\t" << obj[i].at << "\t" << obj[i].bt << "\t\t" << obj[i].ct << "\t" << obj[i].tat << "\t\t" << obj[i].wt<<endl;
    }

}
