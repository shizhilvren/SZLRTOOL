#ifndef __TOOL__
#define __TOOL__
#include "../Debuger/debug.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
namespace TOOL {
constexpr double PI = atan(1.0) * 4;
// 常规get
#define CLASSGETBUILD(type, name)        \
public:                                  \
    inline const type& get##name() const \
    {                                    \
        return this->name;               \
    }
// 常规无const修饰get 可更改 请慎用
#define CLASSGETBUILD_NOCONST(type, name) \
public:                                   \
    type& get##name##_change()            \
    {                                     \
        return this->name;                \
    }

#define CLASSGETBUILD_NOY(type, name) \
public:                               \
    type get##name() const            \
    {                                 \
        return this->name;            \
    }
// 标准生成set
#define CLASSSETBUILD(type, name)        \
public:                                  \
    inline void set##name(const type& v) \
    {                                    \
        this->name = v;                  \
    }

template <typename T>
T norm1(const std::vector<T>& vec, int len = 0)
{
    if (len == 0) {
        len = vec.size();
    }
    assert(static_cast<int>(vec.size()) >= len);
    double ret = 0;
    for (int i = 0; i < len; i++) {
        ret += std::abs(vec[i]);
    }
    return ret;
}

template <typename T>
T norm2(const std::vector<T>& vec, int len = 0)
{
    if (len == 0) {
        len = vec.size();
    }
    assert(static_cast<int>(vec.size()) >= len);
    double ret = 0;
    for (int i = 0; i < len; i++) {
        ret += std::pow(vec[i], 2.0);
    }
    return std::sqrt(ret);
}

bool isFileCanRead(std::string filenname);
//请慎用 无法批量注释
void showInfo(const std::string info);

// 列表分割 吧line 按空格分割存储再list中
// @gara [0ut] list
void line_split(const std::string& line, std::vector<std::string>& list);

template <typename OUT>
void output(OUT& out)
{
    out << std::endl;
}
template <typename OUT, typename T>
void output(OUT& out, const T& value)
{
    out << value << std::endl;
}

// 按空格分割输出
// @gara [in] out 保证由<<重载
// @gara [in] value 保证有<<输出
template <typename OUT, typename T, typename... Args>
void output(OUT& out, const T& value, const Args&... args)
{
    out << value << " ";
    TOOL::output(out, args...);
}

const std::string debug = NONE "[" YELLOW "DEBUG" NONE "  ]" NONE ":";
const std::string info = NONE "[INFO   ]" NONE ":";
const std::string waring = NONE "[" PURPLE "WARING" NONE " ]" NONE ":";
const std::string error = NONE "[" RED "ERROR" NONE "  ]" NONE ":";

} // namespace  TOOL

#endif /*__TOOL__*/
