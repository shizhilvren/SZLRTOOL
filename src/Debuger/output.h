#ifndef __OUTPUT__
#define __OUTPUT__
#include<iostream>
#include<fstream>
#include <vector>
namespace Output {    
    // 按照python格式输出数据
    bool print_2d_file(const std::string file_name,const std::vector<std::vector<double>>& data,int n,int m);
    bool print_2d_file(const std::string file_name, double** p, int n, int m);
};




#endif