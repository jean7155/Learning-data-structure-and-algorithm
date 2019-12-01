//
//  SparseArray.hpp
//  Learning data structure and algorithm
//
//  Created by mac on 2019/12/1.
//  Copyright © 2019年 mac20191122. All rights reserved.
//用二维动态数组保存稀疏数组。

#ifndef SparseArray_hpp
#define SparseArray_hpp

#include <stdio.h>

class SparseArray
{
public:
    SparseArray();
    ~SparseArray();
    int getValueNum(int* scr,int row,int col);
    
    int createFrom(int* scr,int row,int col);
    void printSparseArray();
    int toArray(int* &des,int &row,int &col);
private:
    void init(int num);
    
    int** mArray;
    int mSum;
};

#endif /* SparseArray_hpp */
