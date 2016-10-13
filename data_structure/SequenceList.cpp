#include <iostream>
#include <cstring>
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
        for (int i = 0; i < length; ++i) {
            if (data[i] == value) {
                return i;
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
        for (int i = 0; i < length; i++)
        {
            if(i > 0)
            {
                cout<<" ";
            }
            cout<<data[i];
        }
        cout<<endl;
    }
};
int main() {
    Vector a(2);
    cout << a.insert(0, 1) << endl;
    cout << a.insert(0, 2) << endl;
    a.print();
    cout << a.remove(1) << endl;
    a.print();
    cout << a.search(0) << endl;
    cout << a.search(1) << endl;
    return 0;
}
