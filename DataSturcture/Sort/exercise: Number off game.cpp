/*蒜头君在和他的朋友们一起玩一个游戏。由于蒜头君的机智，这个游戏由蒜头君担任裁判。

首先，蒜头君会给他们一人一个编号，并且每个人的编号都不相同。接下来的每一回合，蒜头君会给一个数，编号不超过它的最大编号的人要报出自己的编号。

如果没有人的编号比蒜头君给出的数要小，那么编号最小的人要报出自己的编号。每个人可以重复报号。蒜头君会按照一个列表顺次报出每个回合的数，

他的朋友们想知道每回合报出的编号应该是多少。你能帮帮他们吗？

输入数据共 3 行。第一行有两个整数 n, m，分别表示参与游戏的蒜头君朋友的个数，和游戏的回合数。

第二行 n 个整数，表示朋友们每个人的编号。

第三行 m 个整数，表示每回合蒜头君给的数字。*/

#include <iostream>
 void quick_sort(int *data, int left, int right){                     //快速排序
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
        quick_sort(data,left, low - 1);
        quick_sort(data,low + 1,right);
    }

int search(int value,int n,int *data){                                //二分查找
    int left = 0, right = n - 1;
    while(right - left >= 1){
        int mid = (left + right) / 2;
        if(data[mid] == value){
            return data[mid];
        }
        else if(data[mid] < value){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    if(left == right)
    {
        left--;
    }
    if(data[right] <= value){
        return data[right];
    }
    else{
        return data[left];
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int *data = new int[n];
    int *num = new int[m];
    for(int i = 0; i < n; i++){
        scanf("%d",&data[i]);
    }
    quick_sort(data,0,n - 1);
    for(int i = 0; i < m; i++){
        scanf("%d",&num[i]);
    }
    
    if(data[0] > num[0]){
            printf("%d",data[0]);
        }
    
    else{
        int k = search(num[0],n,data);
        printf("%d",k);
    }
        
        
    for(int i = 1; i < m; i++){
        if(data[0] > num[i]){
            printf(" %d",data[0]);
        }

        else{
            int k = search(num[i],n,data);
            printf(" %d",k);
        }
    }
    
    
    return 0;
}
