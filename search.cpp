#include <set>
#include <bits/stdc++.h>
#include <iostream>
#include <unistd.h>
#include <algorithm>

using namespace std;
int bin_search(vector<int>& v, int element, int high, int low); 
int main() {
    vector <int> v={5,6,1,2,4,3,9,12,30,24,26,31};

    // sort STL
    sort(v.begin(), v.end());

    // searching
    // Binary search
    int e; //element to be searched
    cin >> e;
    int ret = bin_search(v, e, v.size(), 0);

    // display
    auto itr = v.begin();
    while(itr != v.end()) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
    cout << ret << endl;
}

int bin_search(vector<int>& v, int element, int high, int low) {
    int mid = (low+high)/2;

    while(high >= low) {
        if(v[mid] > element) { // search low to mid-1
            high = mid -1;
            mid = (low+high)/2;
        } else if(v[mid] < element) {
            low = mid +1;
            mid = (low+high)/2;
        } else {
            return mid+1;   
        }
    }
    return -1;
}