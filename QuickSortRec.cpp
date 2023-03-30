#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <fstream>

using namespace std;

// Partition function to divide the array about a pivot
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

// Quicksort Algorithm
void quicksort(vector <int> &arr, int left, int right){
    if (left < right){
        int split = partition(arr,left,right);
        quicksort(arr,left,split-1);
        quicksort(arr,split+1,right);

    }//endif

}


// Random Array generator
vector <int> generateRandomArray(int size){
    vector <int> arr;
    for(int i=0; i < size; i++){
        arr.push_back(rand());
    }

    return arr;
}

// Finding the execution time
double getExecutionTime(vector <int> &arr){
    auto start = chrono::high_resolution_clock::now();
    quicksort(arr, 0, (arr.size() - 1));
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration.count()/ 1000000.0;
}

// Take the execution times to a csv file
void writeToFile(int sizes[], double times[]){
    ofstream file;
    file.open("ResulttimesRec.csv");
    cout << file.is_open() <<endl;
    file << "Array Size, Quick Sort Recursive" << endl;
    for(int i = 0; i < 10; i++){
        file << sizes[i] << "," << times[i] << endl;
    }
    cout<< "Written to file" << endl;
    file.close();
}


int main(){
    int size = 8;
    int sizes[size] = {100,1000,3000,5000,10000,15000,20000,30000};

    double executionTimes[size];

    for (int i=0; i<size; i++){
        vector <int> arr = generateRandomArray(sizes[i]);
        double time = getExecutionTime(arr);
        executionTimes[i] = time;
    }

    writeToFile(sizes,executionTimes);

}