//
//  SparseArray.cpp
//  Learning data structure and algorithm
//
//  Created by mac on 2019/12/1.
//  Copyright © 2019年 mac20191122. All rights reserved.
//

#include "SparseArray.hpp"
#include <iostream>
SparseArray::SparseArray()
{
    mArray = NULL;
    mSum=0;
}
SparseArray::~SparseArray()
{
    if (mArray!=nullptr) {
        delete mArray;
    }
}
//将二维数组转为稀疏数组
int SparseArray::createFrom(int* scr,int row,int col)
{
    int sum = 0;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int a = *(scr+i*row+j);
            if(a!=0) {
                sum++;
            }
        }
    }
    std::cout << "sum = "<<sum <<std::endl;

    //2.创建对应的稀疏数组
    mArray = new int*[3];
    for (int i=0; i<sum+1; i++) {
        mArray[i] = new int[3]();
    }
    
    //3.给稀疏数组赋值
    mArray[0][0] = 11;
    mArray[0][1] = 11;
    mArray[0][2] = sum;
    
    //3.遍历二维数组将非零值存放到稀疏数组
    int count = 0;  //  记录是第几个非零数据
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            int a = *(scr+i*row+j);
            if(a!=0) {
                count++;
                mArray[count][0] = i;
                mArray[count][1] = j;
                mArray[count][2] = a;
            }
        }
    }
    mSum=count;
    return count;
}
//显示稀疏数组
void SparseArray::printSparseArray()
{
    for(int i = 0; i < mSum+1; i++) {
        std::cout << mArray[i][0] << "\t"<<mArray[i][1]<<"\t"<<mArray[i][2]<<std::endl;
    }
}
int SparseArray::toArray(int* &des,int &row,int &col)
{
    if (des!=nullptr) {
        return 0;
    }
    //将稀疏数组--->>恢复成原始的二维数组
    //1.先读取稀疏数组的第一行，根据第一行的数据，创建原始的二维数组
    row = mArray[0][0];
    col = mArray[0][1];
    des = new int[row*col]{};
    
    //2.读取稀疏数组的数据赋给二维数组
    int sum = mArray[0][2];
    for(int i = 1; i <sum+1; i++) {
        int x = mArray[i][0];
        int y = mArray[i][1];
        int value = mArray[i][2];
        des[x*row+y] = value;
    }
    return  sum;
}
