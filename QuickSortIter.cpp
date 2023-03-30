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

void quicksort(vector <int> &arr, int left, int right){

    int stack[right - left + 1]; // Create a Stack to store left and right values

    int top = -1;

    stack[++top] = left;
    stack[++top] = right;

    while (top >= 0){
        right = stack[top--];
        left = stack[top--];

        int split = partition(arr,left,right);

        // Check whether there are elements in the left of the pivot point
        if (split-1 > left){
            stack[++top] = left;
            stack[++top] = split-1;
        }

        // Check whether there are elements in the right of the pivot point
        if (split+1 < right){
            stack[++top] = split+1;
            stack[++top] = right;
        }


    }


}

// Generate a array with random elements of give size
vector <int> generateRandomArray(int size){
    vector <int> arr;
    for(int i=0; i < size; i++){
        arr.push_back(rand());
    }

    return arr;
}

double getExecutionTime(vector <int> &arr){
    auto start = chrono::high_resolution_clock::now();
    quicksort(arr, 0, (arr.size() - 1));
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    return duration.count()/ 1000000.0;
}

void writeToFile(int sizes[], double times[]){
    ofstream file;
    file.open("ResulttimesIter.csv");
    cout << file.is_open() <<endl;
    file << "Array Size, Quick Sort Iterative" << endl;
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