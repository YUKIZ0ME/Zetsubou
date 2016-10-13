//哈希表的建立，一种hash值算法，查找，插入和重建
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
class HashTable {
private:
    string *elem;
    int size;
public:
    HashTable() {
        size = 2000;
        elem = new string[size];
        for (int i = 0; i < size; i++) {
            elem[i] = "#";
        }
    }
    ~HashTable() {
        delete[] elem;
    }
    int hash(string &index) {
        int code = 0;
        for (size_t i = 0; i < index.length(); i++) {
            code = (code * 256 + index[i] + 128) % size;
        }
        return code;
    }
    bool search(string &index, int &pos, int &times) {
        pos = hash(index);
        times = 0;
        while (elem[pos] != "#" && elem[pos] != index) {
            times++;
            if (times < size) {
                pos = (pos + 1) % size;
            } else {
                return false;
            }
        }
        if (elem[pos] == index) {
            return true;
        } else {
            return false;
        }
    }
    int insert(string &index) {
        int pos, times;
        if (search(index, pos, times)) {
            return 2;
        } else if (times < size / 2) {
            elem[pos] = index;
            return 1;
        } else {
            recreate();
            return 0;
        }
    }
    // 请在下面实现重建方法 recreate
    void recreate(){
        string *temp_elem;
        temp_elem = new string[size];
        for(int i = 0; i < size; i++){
            temp_elem[i] = elem[i];
        }
        int copy_size = size;
        size = size * 2;
        delete[] elem;
        elem = new string[size];
        for(int i = 0; i < size; i++){
            elem[i] = "#";
        }
        for(int i = 0; i < copy_size; i++){
            if(temp_elem[i] != "#"){
                insert(temp_elem[i]);
            }
        }
        delete[] temp_elem;
    }
};
int main() {
    HashTable hashtable;
    string buffer;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> buffer;
        int ans = hashtable.insert(buffer);
        if (ans == 0) {
            cout << "insert failed!" << endl;
        } else if (ans == 1) {
            cout << "insert success!" << endl;
        } else if (ans == 2) {
            cout << "It already exists!" << endl;
        }
    }
    int temp_pos, temp_times;
    cin >> buffer;
    if (hashtable.search(buffer, temp_pos, temp_times)) {
        cout << "search success!" << endl;
    } else {
        cout << "search failed!" << endl;
    }
    return 0;
}
