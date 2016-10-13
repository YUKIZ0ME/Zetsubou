//归并排序

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
class Vector {
private:
    int size, length;
    int * data, * temp;
    void merge_sort(int l, int r){
        if(l == r){
            return;
        }
        int mid = (l + r) / 2;
        merge_sort(l,mid);
        merge_sort(mid + 1,r);
        int x = l, y = mid + 1, loc = l;
        while(x <= mid || y <= r){
            if(x <= mid && (y > r || data[x] <= data[y])){
                temp[loc] = data[x];
                x++;
            }
            else{
                temp[loc] = data[y];
                y++;
            }
            loc++;
        }
        for(int i = l; i <= r; i++){
            data[i] = temp[i];
        }
    }
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new int[size];
        temp = new int[size];
    }
    ~Vector() {
        delete[] data;
        delete[] temp;
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
        merge_sort(0,length -1);
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
