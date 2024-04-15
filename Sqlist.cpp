#include "Sqlist.h"
void SL_Ini(sl &L)
{
    L.data=(int *)malloc(MAXSIZE*sizeof(int));      //为表分配空间
    if(!L.data)
       printf("分配失败");
    L.length=0;
}
void SL_Print(sl &L)
{
    for(int i=0;i<L.length;i++)
        printf(" %d ",L.data[i]);
}
void SL_Find(sl &L,int e)
{
    for(int i=0;i<L.length;i++)
    {
        if (L.data[i] == e) {
            printf("找到元素%d在第%d位", e,i);
            return;
        }
        if (i == L.length - 1)
            printf("未找到元素%d", e);
    }
}
void SL_PopBack(sl &L,int e)//尾插
{
    L.data[L.length]=e;
    L.length++;
}
void SL_Insert(sl &L,int i,int e)
{
    if(i<1||i>L.length+1)
        printf("插入位置错误");
    if(L.length==MAXSIZE)
        printf("表已满");
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.data[j+1]=L.data[j];
        L.data[i-1]=e;
    }
    L.length++;
}
void SL_Delete(sl &L,int i)
{
    if(i<1||i>L.length)
        printf("删除位置错误");
    for(int j=i-1;j<L.length;j++)
        L.data[j]=L.data[j+1];
    L.length--;
}
void SL_Destroy(sl &L)
{
    free(L.data);
}
void SL_Union(sl L1,sl L2,sl &L3)//交集
{
    for(int i=0;i<L2.length;i++)
    {
        for(int j=0;j<L1.length;j++)
        {
            if(L2.data[i]==L1.data[j])
            {
                SL_PopBack(L3, L2.data[i]);
                break;
            }
        }
    }
    SL_Print(L3);
}
void bubble_sort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}
void SL_Union1(sl L1,sl L2,sl &L3)//并集升序排列
{
    for(int i=0;i<L2.length;i++)
    {
        int flag=0;
        for(int j=0;j<L1.length;j++)
        {
            if(L2.data[i]==L1.data[j])
            {
                flag=1;     //存在相等元素
                break;
            }
        }
        if(flag==0)
            SL_PopBack(L3,L2.data[i]);
    }
    for(int i=0;i<L1.length;i++)
        SL_PopBack(L3,L1.data[i]);
    bubble_sort(L3.data,L3.length);
    SL_Print(L3);
}