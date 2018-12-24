#include <set>
#include <bits/stdc++.h>
#include <iostream>
#include <unistd.h>

using namespace std;
void insertion_sort(vector <int>& v);
void insertion_sort_dec(vector <int>& v);
void merge_sort(vector <int>& v, int start, int end); 
void merge(vector <int>& v, int start, int mid, int end);
void bubble_sort(vector <int>& v);

int main() {
    vector <int> v={5,6,1,2,4,3,9,12,30,24,26,31};
    // insertion sort
    // insertion_sort(v);
    // insertion_sort_dec(v); 

    // merge sort
    merge_sort(v, 0, v.size());

    // bubble sort
    //bubble_sort(v);

    // display
    auto itr = v.begin();
    while(itr != v.end()) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
}
void swap (int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubble_sort(vector <int>& v) {
    for(int i = 0; i < v.size(); i++) {
        bool swapped = false;
        for(int j = 0; j < v.size()-i-1; j++) {
            if(v[j+1] < v[j]) {
                swap(&v[j], &v[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) {
            break;
        }
    }
}
void insertion_sort(vector <int>& v) {
    int key;
    int i;
    for(int j=1; j < v.size(); j++) {
        key = v[j];
        i = j-1;
        while(i>=0 && v[i] < key) {
            v[i+1] = v[i];
            i = i-1;
        }
        v[i+1] = key;
    }
}
void insertion_sort_dec(vector <int>& v) {
    int key;
    int i;
    for(int j=1; j < v.size(); j++) {
        key = v[j];
        i = j-1;
        while(i>=0 && v[i] > key) {
            v[i+1] = v[i];
            i = i-1;
        }
        v[i+1] = key;
    }
}
void merge(vector <int>& v, int start, int mid, int end) {
    int siz_1 = mid - start + 1;
    int siz_2 = end - mid;
    vector <int> left;
    vector <int> right;
    int i,j,k;
    for(i=0; i<siz_1; i++) {
        left.push_back(v[start+i]);
    }
    //left[siz_1+1] = 0;
    for(j=0; j<siz_2; j++){
        right.push_back(v[mid+j+1]);
    }
    //right[siz_2+1] = 0;
    i=0;
    j=0;
    k = start; // Initial index of merged subarray 
    while (i < siz_1 && j < siz_2) 
    { 
        if (left[i] <= right[j]) 
        { 
            v[k] = left[i]; 
            i++; 
        } 
        else
        { 
            v[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < siz_1) 
    { 
        v[k] = left[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < siz_2) 
    { 
        v[k] = right[j]; 
        j++; 
        k++; 
    } 
}
void merge_sort(vector <int>& v, int start, int end) {
    if(start < end) {
        int mid = start+(end-start)/2;
        merge_sort(v, start, mid);
        merge_sort(v, mid+1, end);
        merge(v, start, mid, end);
    }
}