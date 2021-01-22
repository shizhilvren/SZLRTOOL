#include "output.h"
#include "debug.h"
#include <string>
bool Output::print_2d_file(const std::string file_name,
    const std::vector<std::vector<double>>& data, int n, int m)
{
    std::ofstream fout;
    fout.open(file_name + ".py", std::ios::out);
    // DEBUG("维数 %d %d\n",n,m);
    if (!fout.is_open()) {
        WARNING("打开文件:%s失败\n", file_name.c_str());
        return false;
    }
    fout << " # -*- coding: UTF-8 -*-" << std::endl;

    fout << "from mpl_toolkits.mplot3d import Axes3D" << std::endl;
    fout << "import matplotlib.pyplot as plt" << std::endl;
    //fout<<"from matplotlib import cm"<<std::endl;
    //fout<<"from matplotlib.ticker import LinearLocator, FormatStrFormatter"<<std::endl;
    fout << "import numpy as np" << std::endl;
    fout << "plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签" << std::endl;
    fout << "plt.rcParams['axes.unicode_minus']=False #用来正常显示负号" << std::endl;
    fout << "fig = plt.figure()" << std::endl;
    fout << "ax = Axes3D(fig)" << std::endl;
    fout << "X = np.arange(0," << n << ", 1)" << std::endl;
    fout << "Y = np.arange(0," << m << ", 1)" << std::endl;
    fout << "X, Y = np.meshgrid(X, Y)" << std::endl;
    fout << "Z=np.array([" << std::endl;
    for (int i = 0; i < m; i++) {
        if (i != 0) {
            fout << ",";
        }
        fout << "[";
        for (int j = 0; j < n; j++) {
            if (j != 0) {
                fout << ",";
            }
            fout << data[j][i];
        }
        fout << "]" << std::endl;
    }
    fout << "])" << std::endl;
    // fout<<"surf = ax.plot_surface(X, Y, Z, cmap='rainbow', vmin=np.min(Z),vmax=np.max(Z),linewidth=0, antialiased=False)"<<std::endl;
    fout << "surf = ax.plot_surface(X, Y, Z, cmap='rainbow')" << std::endl;
    //fout << "ax.set_zlim(np.min(Z), np.max(Z))" << std::endl;
    //fout<<"ax.zaxis.set_major_locator(LinearLocator(10))"<<std::endl;
    //fout<<"ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))"<<std::endl;
    fout << "fig.colorbar(surf, shrink=0.5, aspect=10)" << std::endl;
    fout << "plt.xlabel('x')" << std::endl;
    fout << "plt.ylabel('y')" << std::endl;
    fout << "plt.title('tetal')" << std::endl;
    fout << "plt.show()" << std::endl;
    fout.close();
    return true;
}
bool Output::print_2d_file(const std::string file_name, double** p, int n, int m)
{
    std::vector<std::vector<double>> vp;
    vp.resize(n);
    for (int i = 0; i < n; i++) {
        vp[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vp[i][j] = p[i][j];
        }
    }
    return Output::print_2d_file(file_name, vp, n, m);
}