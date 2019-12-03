//
//  main.cpp
//  Learning data structure and algorithm
//
//  Created by mac on 2019/11/22.
//  Copyright © 2019年 mac20191122. All rights reserved.
//

#include <iostream>
#include <vector>
#include "SparseArray.hpp"

void testSparseArray(){
    //创建一个二维数组，初始化二维数组。
    int chessArr1[11][11];
    for (int i=0; i<11; i++) {
        for (int j=0; j<11; j++) {
            chessArr1[i][j] = 0;
        }
    }
    chessArr1[1][2]=1;
    chessArr1[2][3]=2;
    
    //输出原始的二维数组
    for (int i=0; i<11; i++) {
        for (int j=0; j<11; j++) {
            std::cout << chessArr1[i][j];
        }
        std::cout << std::endl;
    }
    
    
    SparseArray sa;
    int * scr = (int * )chessArr1;
    sa.createFrom(scr, 11, 11);
    //输出稀疏数组的形式
    std::cout<<"得到的稀疏数组为:" << std::endl;
    sa.printSparseArray();
    
    
    //将稀疏数组--->>恢复成原始的二维数组
    int * des = nullptr;
    int row=0,col=0;
    sa.toArray(des,row,col);
    
    //输出恢复后的二维数组
    std::cout<< "恢复后的原始数组" << std::endl;
    
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            std::cout << des[i*row+j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout<< "稀疏数组实例完成。" << std::endl;
    
    /*   int a=0;
     std::cin >> a ;
     
     std::cout << "Hello, World! "<<a <<std::endl;
     */
    return ;
}



int * getData( )
{
    static int  r[10];
    for (int i = 0; i < 10; ++i)
    {
        r[i] = i;
    }
    
    return r;
}
#include "DyArray.h"
int main(int argc, const char * argv[]) {
  //  testSparseArray();
    
    threeDimensionalArray();
    
    return 0;
}
