#include <iostream>
using namespace std;

class MyArray {
private:
    int* data;      // pointer to the actual array in memory
    int capacity;   // how much space we've allocated
    int size;       // how many elements are actually used

public:
    // Constructor: starts with a small array
    MyArray(int cap = 4) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    // Add an element to the end
    void push(int value) {
        if (size == capacity) {
            resize();
        }
        data[size] = value;
        size++;
    }

    // Double the capacity when full
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        cout << "Resized! New capacity: " << capacity << endl;
    }

    // Print all elements
    void print() {
        cout << "[ ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }

    // Destructor: free memory
    ~MyArray() {
        delete[] data;
    }
};

int main() {
    MyArray arr;
    arr.push(10);
    arr.push(20);
    arr.push(30);
    arr.push(40);
    arr.push(50); // this will trigger a resize

    arr.print();

    return 0;
}
