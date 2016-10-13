#include <stdio.h>
#include <malloc.h>
int main()
{
    int n;
    int final;
    int num = 0;
    scanf("%d",&n);
    final = n -1;
    int* arr = (int *)calloc(n,sizeof(int));
    for(int i = 0;i < n;i++)
        scanf("%d",&arr[i]);
    for(int k = 0;k < n;k++)
    {
        for(int j = 0;j < final;j++)
        {
            if(j + arr[j] >= final)    //从第一个点往后找到第一个能跳到终点的点，跳越次数+1，把这个店当做新的终点，循环
            {
                num += 1;
                final = j;
                break;
            }
        }
    }
    printf("%d\n",num);
    return 0;
}
