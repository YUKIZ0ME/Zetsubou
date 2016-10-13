//快速排序

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::swap;
class Vector {
private:
    int size, length;
    int * data;
    void quick_sort(int left, int right){
        if(left > right){
            return;
        }
        int pivot = data[left], low = left, high = right;
        while(low < high){
            while(low < high && data[high] >= pivot){
                high--;
            }
            data[low] = data[high];
            while(low < high && data[low] <= pivot){
                low++;
            }
            data[high] = data[low];
        }
        data[low] = pivot;
        quick_sort(left, low - 1);
        quick_sort(low + 1,right);
    }
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
    void print() {
        for (int i = 0; i < length; ++i) {
            if (i > 0) {
                cout << " ";
            }
            cout << data[i];
        }
        cout << endl;
    }
    void sort() {
        quick_sort(0,length - 1);
    }
};
int main() {
    int n;
    cin >> n;
    Vector arr(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.insert(i, x);
    }
    arr.sort();
    arr.print();
    return 0;
}
