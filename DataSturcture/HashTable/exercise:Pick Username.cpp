/*某天，蒜头君发现计蒜客上的用户名好多都长一样，蒜头君看着差点看晕了。为了区分用户名，蒜头君打算好好地清理清理。他将筛选出用户名一样的用户信息，然后

给这些用户发邮件，提醒他们改一改用户名。需要注意的是，蒜头君不分大小写字母，所以他认为两个长度相等，每个字符对应一样的用户名是一样的，例如他认为用

户名jisuanke和JiSuanKe是一样的。现在蒜头君手里有 N 个用户名，他想知道哪些用户名是重复的。蒜头君按从前往后的顺序依次查看，如果用户名在前面出现

过则输出Yes，否则输出No。现在蒜头君想请你帮他完成这项艰巨的任务，聪明的你能帮他完成吗？

输入第一行是一个正整数 N ，表示一共有 N 个用户名。接下来有 N 行，每一行是一个用户名，长度不超过 100100，均由大写字母和小写字母组成。*/

#include <iostream>
#include <string>
using namespace std;
class HashTable {
private:
    string *elem;
    int size;
public:
    HashTable() {
        size = 200000;
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
            if(index[i] <= 90)
                index[i] += 32;
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
                //return true;
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
            cout << "No" << endl;
        } else if (ans == 2) {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
