//
//  DyArray.h
//  Learning data structure and algorithm
//
//  Created by mac on 2019/12/3.
//  Copyright © 2019年 mac20191122. All rights reserved.
//

#ifndef DyArray_H
#define DyArray_H

#include <iostream>

//一维数组
void oneDimensionalArray()
{
    //定义一个长度为10的数组
    int* array = new int[10];
    //赋值
    for(int i = 0; i < 10; i++)
    {
        array[i] = i*2;
    }
    //打印
    for(int i = 0; i < 10; i++)
    {
        std::cout << i << " : " << array[i] << std::endl;
    }
    //释放内存
    delete[] array;
}

//二维数组
void twoDimensionalArray()
{
    //定义一个2*10的二维数组
    int** array = new int*[2];
    for(int i = 0; i < 2; i++)
    {
        array[i] = new int[10];
    }
    //赋值
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            array[i][j] = i*10 + j;
        }
    }
    //打印
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            std::cout << "(" << i << ", " << j << ")" << array[i][j] << std::endl;
        }
    }
    //释放内存
    for(int i = 0; i < 2; i++)
    {
        delete[] array[i];
    }
    
    delete[] array;
}

//三维数组
void threeDimensionalArray()
{
    //定义一个3*10*20的数组
    int*** array = new int** [3];
    
    for(int i = 0; i < 3; i++)
    {
        array[i] = new int*[10];
        for(int j = 0; j < 10; j++)
        {
            array[i][j] = new int[20];
        }
    }
    //赋值
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 20; k++)
            {
                array[i][j][k] = i*100 + j*10 + k;
            }
        }
    }
    //打印
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 20; k++)
            {
                char str[64];
                sprintf(str, "(%d, %d, %d): ", i, j, k);
                std::cout << str << array[i][j][k] <<std::endl;
            }
        }
    }
    //释放内存
    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            delete[] array[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        delete[] array[i];
    }
    
    delete[] array;
    
}


#endif /* DyArray_H */
