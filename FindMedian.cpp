#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector <int> &arr, int left, int right){
    int pivotValue = arr[left];
    int leftMark = left + 1;
    int rightMark = right;
    bool done = false;

    while (!done){
        while (leftMark <= rightMark && (arr[leftMark] <= pivotValue) ){
            leftMark += 1;
        }//endwhile

        while (leftMark <= rightMark && (arr[rightMark] >= pivotValue) ){
            rightMark -= 1;
        }//endwhile

        if (rightMark < leftMark){
            done = true;
        } else{
            int temp = arr[leftMark];
            arr[leftMark] = arr[rightMark];
            arr[rightMark] = temp;
            
        }

    }//endwhile

    int temp2 = arr[left];
    arr[left] = arr[rightMark];
    arr[rightMark] = temp2;

    return rightMark;

}

void quicksort(vector <int> &arr, int left, int right){
    if (left < right){
        int split = partition(arr,left,right);
        quicksort(arr,left,split-1);
        quicksort(arr,split+1,right);

    }//endif

}

void printArray(vector <int> &arr){
    for (int i=0; i < arr.size();i++){
        cout<< arr[i] <<" ";
    }
}

double findMedian(vector <int> &arr){
    int m = arr.size()/2;
    double median;

    if (arr.size() % 2 == 0){  
        median = (arr[m] + arr[m-1])/2;
    } else{
        median = arr[m];
    }

    return median;
}

int main(){
    int size = 4;
    int input[size]  = {7,3,5,2};
    double med;

    vector <int> arr;

    for (int i = 0; i < size;i++){
        arr.push_back(input[i]);
        quicksort(arr,0,arr.size()-1);
        med = findMedian(arr);
        cout.setf(ios::fixed);
        cout << setprecision(1)<< med << endl;

    }

}