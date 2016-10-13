//折半查找
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
    int search(int value) {
        int left = 0,right = length - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(data[mid] == value){
                return mid;
            }
            else if(data[mid] < value){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return -1;
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
    Vector a(100);
    a.insert(0, 2);
    a.insert(1, 4);
    a.insert(2, 6);
    a.insert(3, 8);
    a.insert(4, 10);

    cout << a.search(4) << endl;
    cout << a.search(5) << endl;
    return 0;
}
