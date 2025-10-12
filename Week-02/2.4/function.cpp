#include "function.h"

bool acsending(const int& a, const int& b){
    return a <= b;
}
bool desending(const int& a, const int& b){
    return a >= b;
}
void Array::input(){
    cout << "Input array size: ";
    cin >> size;
    if (size <= 0) {
        throw runtime_error("Error of size array!");
    }
    arr = new int [size];
    cout << "Input " << size << " element of array: ";
    for (int i = 0; i < size; i++){
        if (!(cin >> arr[i])) {
            throw runtime_error("Error of element array!");
        }
    }
}
void Array::output(){
    for (int i = 0; i< size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int Array::getSize(){
    return size;
}
void Array::setSize(int newSize){
    if (newSize < 0) {
        throw runtime_error("Error new size array!");
    }
    else if (newSize == 0) {
        deleteArray();
        return;
    }
    else if (newSize == size) {
        return;
    }

    int* newArray = new int [newSize];
    if (newSize < size){
        for (int i = 0; i < newSize; i++){
            newArray[i] = arr[i];
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            newArray[i]  = arr[i];
        }
        for (int i = size; i < newSize; i++){
            //Phần tử chưa gán giá trị sẽ có giá trị mặc định là INT_MIN
            newArray[i] = INT_MIN;
        }
    }
    
    delete[] arr;
    arr = newArray;
    size = newSize;
}
int Array::getElement(int idx) {
    if (idx < 0 || idx >= size) {
        throw runtime_error("Error index!");
    }
    return arr[idx];
}
void Array::setElement(int idx, int val){
    if (idx < 0 || idx >= size) {
        throw runtime_error("Error index!");
    }
    arr[idx] = val;
}
int Array::find(int val){
    for (int i = 0; i < size; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}
void Array::sort(sortCriteria cmp){
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && !cmp(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void Array::deleteArray(){
    delete[] arr;
    arr = nullptr;
    size = 0;
}