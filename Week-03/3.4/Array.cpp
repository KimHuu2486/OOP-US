#include "Array.h"

template<class T>
Array<T>::Array():
    m_arr(nullptr),
    m_size(0) {}

template<class T>
Array<T>::Array(const int& size) {
    if (size <= 0) {
        std::cout << "Invalid at size of array!" << std::endl;
        m_arr = nullptr;
        m_size = 0;
        return;
    }
    
    m_size = size;
    m_arr = new T[m_size];
    
    for (int i = 0; i < m_size; i++) {
        m_arr[i] = 0;
    }
}

template<class T>
Array<T>::Array(const T arr[], const int& size) {
    m_size = size;
    m_arr = new T[m_size];
    
    for (int i = 0; i < m_size; i++) {
        m_arr[i] = arr[i];
    }
}

template<class T>
Array<T>::Array(const Array& arr) {
    m_size = arr.m_size;
    m_arr = new T[m_size];
    
    for (int i = 0; i < m_size; i++) {
        m_arr[i] = arr.m_arr[i];
    }
}

template<class T>
Array<T>::~Array() {
    m_size = 0;
    delete []m_arr;
}

template<class T>
void Array<T>::print(){
    for (int i = 0; i < m_size; i++) {
        std::cout << m_arr[i] << " ";
    }
    std::cout << std::endl;
}