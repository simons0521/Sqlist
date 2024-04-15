#include <stdio.h>
#include <stdlib.h>
#pragma once
#define MAXSIZE 100
typedef struct SL
{
    int *data;
    int length;
}sl;
//引用不是定义一个新的变量或对象，因此内存不会为引用开辟新的空间存储这个引用
void SL_Ini(sl &L);//初始化
void SL_Print(sl &L);//打印
void SL_Find(sl &L,int e);//查找
void SL_Insert(sl &L,int i,int e);//插入
void SL_PopBack(sl &L,int e);//尾插
void SL_Delete(sl &L,int i);//删除
void SL_Destroy(sl &L);//销毁
void SL_Union(sl L1,sl L2,sl &L3);//交集
void SL_Union1(sl L1,sl L2,sl &L3);//合集并按升序排列
