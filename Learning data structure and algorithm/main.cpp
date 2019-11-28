//
//  main.cpp
//  Learning data structure and algorithm
//
//  Created by mac on 2019/11/22.
//  Copyright © 2019年 mac20191122. All rights reserved.
//

#include <iostream>
#include <vector>
struct spareData
{
public:
    int mRow = -1;
    int mCol = -1;
    int mValue = -1;
    void print()
    {
        std::cout << mRow << "\t"<<mCol<<"\t"<<mValue<<std::endl;
    }
};
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
    std::vector<spareData> sparseArr;
    //3.给稀疏数组赋值
    spareData data1;
    data1.mRow = 11;
    data1.mCol = 11;
    data1.mValue = sum;
    sparseArr.push_back(data1);
    
    //3.遍历二维数组将非零值存放到稀疏数组
    int count = 0;  //  记录是第几个非零数据
    for(int i = 0; i < 11; i++) {
        for(int j = 0; j < 11; j++) {
            if(chessArr1[i][j]!=0) {
                count++;
                
                spareData data3;
                data3.mRow = i;
                data3.mCol = j;
                data3.mValue = chessArr1[i][j];
                sparseArr.push_back(data3);
            }
        }
    }
    
    //输出稀疏数组的形式
    std::cout<<"得到的稀疏数组为:" << std::endl;
    for(int i = 0; i < sparseArr.size(); i++) {
        sparseArr[i].print();
    }
    
    
    //将稀疏数组--->>恢复成原始的二维数组
    //1.先读取稀疏数组的第一行，根据第一行的数据，创建原始的二维数组
    spareData data0= sparseArr.front();
    int** des = new int*[data0.mRow];
    for (int i=0; i<data0.mRow; i++) {
        des[i] = new int[data0.mCol];
        for (int j=0; j<data0.mCol; j++) {
            des[i][j] = 0;
        }
    }
    
    //2.读取稀疏数组的数据赋给二维数组
    for(int i = 1; i <data0.mValue+1; i++) {
        spareData data = sparseArr[i];
        int x = data.mRow;
        int y = data.mCol;
        int value = data.mValue;
        des[x][y] = value;
    }
    
    //输出恢复后的二维数组
    std::cout<< "恢复后的原始数组" << std::endl;
    
    for(int i = 0; i < data0.mRow; i++) {
        for(int j = 0; j < data0.mCol; j++) {
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

