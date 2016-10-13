//三分查找，适用于序列的凹凸性保持一致的情况。

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
class Vector {
private:
    int size, length;
    int * data;
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new int[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, int value) {
        if (loc < 0 || loc > length) {
            return false;
        }
        if (length >= size) {
            return false;
        }
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    int search() {
        int left = 0, right = length - 1;
        while(right - left >= 2){
            int m1 = left + (right - left) / 3;
            int m2 = right - (right - left + 2) / 3; 
            if(data[m1] >= data[m2]){
                right = m2;
            }
            else{
                left = m1 + 1;
            }
        }
        
        if(data[left] > data[right]){
            return left;
        }
        else{
            return right;
        }
    }
    bool remove(int index) {
        if (index < 0 || index >= length) {
            return false;
        }
        for (int i = index + 1; i < length; ++i) {
            data[i - 1] = data[i];
        }
        length = length - 1;
        return true;
    }
    void print() {
        for (int i = 0; i < length; ++i) {
            if (i > 0) {
                cout << " ";
            }
            cout << data[i];
        }
        cout << endl;
    }
};
int main() {
    Vector a(10);
    a.insert(0, 1);
    a.insert(1, 2);
    a.insert(2, 7);
    a.insert(3, 5);
    a.insert(4, 4);

    cout << a.search() << endl;
    return 0;
}
