#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;
    size_t capacity_;
    size_t size_;
    
    void realloc(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    }

public:
    MyVector() : data(nullptr), capacity_(0), size_(0) {}
    
    explicit MyVector(size_t n) : data(new T[n]), capacity_(n), size_(n) {
        for (size_t i = 0; i < n; ++i) {
            data[i] = T();
        }
    }
    
    MyVector(size_t n, const T& value) : data(new T[n]), capacity_(n), size_(n) {
        for (size_t i = 0; i < n; ++i) {
            data[i] = value;
        }
    }
    
    MyVector(const MyVector& other) : data(new T[other.capacity_]), capacity_(other.capacity_), size_(other.size_) {
        for (size_t i = 0; i < size_; ++i) {
            data[i] = other.data[i];
        }
    }
    
    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] data;
            capacity_ = other.capacity_;
            size_ = other.size_;
            data = new T[capacity_];
            for (size_t i = 0; i < size_; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }
    
    ~MyVector() {
        delete[] data;
    }
    
    void push_back(const T& value) {
        if (size_ >= capacity_) {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            realloc(new_capacity);
        }
        data[size_++] = value;
    }
    
    void pop_back() {
        if (size_ > 0) {
            --size_;
        }
    }
    
    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }
    
    T& operator[](size_t index) {
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        return data[index];
    }
    
    void insert(size_t index, const T& value) {
        if (index > size_) {
            throw std::out_of_range("Index out of range");
        }
        if (size_ >= capacity_) {
            size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
            realloc(new_capacity);
        }
        for (size_t i = size_; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size_;
    }
    
    void erase(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size_ - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size_;
    }
    
    void clear() {
        size_ = 0;
    }
    
    bool empty() const {
        return size_ == 0;
    }
    
    size_t size() const {
        return size_;
    }
    
    size_t capacity() const {
        return capacity_;
    }
    
    void reserve(size_t new_capacity) {
        if (new_capacity > capacity_) {
            realloc(new_capacity);
        }
    }
    
    void resize(size_t new_size) {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        for (size_t i = size_; i < new_size; ++i) {
            data[i] = T();
        }
        size_ = new_size;
    }
    
    void resize(size_t new_size, const T& value) {
        if (new_size > capacity_) {
            reserve(new_size);
        }
        for (size_t i = size_; i < new_size; ++i) {
            data[i] = value;
        }
        size_ = new_size;
    }
    
    T* begin() {
        return data;
    }
    
    const T* begin() const {
        return data;
    }
    
    T* end() {
        return data + size_;
    }
    
    const T* end() const {
        return data + size_;
    }
    
    T& front() {
        return data[0];
    }
    
    const T& front() const {
        return data[0];
    }
    
    T& back() {
        return data[size_ - 1];
    }
    
    const T& back() const {
        return data[size_ - 1];
    }
    
    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < size_; ++i) {
            std::cout << data[i];
            if (i < size_ - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
    }
    
    bool operator==(const MyVector& other) const {
        if (size_ != other.size_) return false;
        for (size_t i = 0; i < size_; ++i) {
            if (data[i] != other.data[i]) return false;
        }
        return true;
    }
    
    bool operator!=(const MyVector& other) const {
        return !(*this == other);
    }
};

#endif
