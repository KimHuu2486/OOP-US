#pragma once

#include <iostream>

template<class T>
class Array {
private:
    T* _arr;
    size_t _len;
public:
    Array(): _arr(nullptr), _len(0) {}
    Array(size_t len): _len(len) {
        _arr = new T[_len];
    }
    Array(const Array<T>& other): _len(other._len) {
        _arr = new T[_len];
        for (size_t i = 0; i < _len; ++i) {
            _arr[i] = other._arr[i];
        }
    }
    ~Array() {
        if (_arr != nullptr) {
            delete[] _arr;
            _arr = nullptr;
            _len = 0;
            std::cout << "Array destroyed!" << std::endl;
        }
    }
public:
    Array<T>& operator=(const Array<T>& other) {
        if (this != &other) {
            delete[] _arr;
            _len = other._len;
            _arr = new T[_len];
            for (size_t i = 0; i < _len; ++i) {
                _arr[i] = other._arr[i];
            }
        }
        return *this;
    }
    T& operator[](size_t index) {
        if (index < _len) {
            return _arr[index];
        }
        std::cout << "Index out of bounds!" << std::endl;
        exit(EXIT_FAILURE);
    }
    operator T*() const {
        return _arr;
    }
public:
    template<class U>
    friend std::ostream& operator<<(std::ostream& out, const Array<U>& arr) {
        out << "[ ";
        for (size_t i = 0; i < arr._len; ++i) {
            out << arr._arr[i] << " ";
        }
        out << "]";
        return out;
    }
    template<class U>
    friend std::istream& operator>>(std::istream& in, Array<U>& arr) {
        for (size_t i = 0; i < arr._len; ++i) {
            in >> arr._arr[i];
        }
        return in;
    }
};

