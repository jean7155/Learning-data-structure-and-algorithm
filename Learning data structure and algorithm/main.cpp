//
//  main.cpp
//  Learning data structure and algorithm
//
//  Created by mac on 2019/11/22.
//  Copyright © 2019年 mac20191122. All rights reserved.
//

#include <iostream>
#include <vector>

int main(int argc, const char * argv[]) {
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
    
    //将二维数组转为稀疏数组
    //1.先遍历二维数组得到非零数据的个数
    int sum = 0;
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) {
            if(chessArr1[i][j]!=0) {
                sum++;
            }
        }
    }
    std::cout << "sum = "<<sum <<std::endl;

    //2.创建对应的稀疏数组
    int** array0 = new int*[3];
    for (int i=0; i<sum+1; i++) {
        array0[i] = new int[3]();
    }
     //3.给稀疏数组赋值
    array0[0][0] = 11;
    array0[0][1] = 11;
    array0[0][2] = sum;
    
    //3.遍历二维数组将非零值存放到稀疏数组
    int count = 0;  //  记录是第几个非零数据
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) {
            if(chessArr1[i][j]!=0) {
                count++;
                array0[count][0] = i;
                array0[count][1] = j;
                array0[count][2] = chessArr1[i][j];
            }
        }
    }
    
    //输出稀疏数组的形式
    std::cout<<"得到的稀疏数组为:" << std::endl;
    for(int i = 0; i < sum+1; i++) {
        std::cout << array0[i][0] << "\t"<<array0[i][1]<<"\t"<<array0[i][2]<<std::endl;
     }
    
    
    //将稀疏数组--->>恢复成原始的二维数组
    //1.先读取稀疏数组的第一行，根据第一行的数据，创建原始的二维数组
    int row = array0[0][0];
    int col = array0[0][1];
    int** des = new int*[row];
    for (int i=0; i<row; i++) {
        des[i] = new int[col]();
    }
    
    //2.读取稀疏数组的数据赋给二维数组
    int sun1 = array0[0][2];
    for(int i = 1; i <sun1+1; i++) {
        int x = array0[i][0];
        int y = array0[i][1];
        int value = array0[i][2];
        des[x][y] = value;
    }
    
    //输出恢复后的二维数组
    std::cout<< "恢复后的原始数组" << std::endl;
    
    for(int i = 0; i < array0[0][0]; i++) {
        for(int j = 0; j < array0[0][1]; j++) {
            std::cout << des[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout<< "稀疏数组实例完成。" << std::endl;

 /*   int a=0;
    std::cin >> a ;
    
    std::cout << "Hello, World! "<<a <<std::endl;
    */
    return 0;
}


class  SparseArray
{
public:
    void createFrom(int** srcArr,int row,int col)
    {
     //   int num = getValueNum(srcArr, row, col);
        
        
        
    }
    
    int getValueNum(int** srcArr,int row,int col)
    {
        int num =0;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++)
            {
                int value = *(*(srcArr+i) +j);
                if (value!=0) {
                    num++;
                }
            }
        }
        return num;
    }
};

