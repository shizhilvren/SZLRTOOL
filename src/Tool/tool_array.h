#ifndef __TOOL_ARRAY__
#define __TOOL_ARRAY__
namespace TOOL {
template <typename T>
class Array {
public:
    T* ptr;
    Array();
    Array(const int n);
    ~Array();
    Array(const Array& a) = delete;
    inline T& operator[](int i);
    void resize(const int n);
};

template <typename T>
class Array2d {
private:
    int size;

public:
    T** ptr;
    Array2d();
    Array2d(const int n1, const int n2);
    ~Array2d();
    Array2d(const Array2d& a) = delete;
    inline T* operator[](int i);
    void resize(const int n1, const int n2);
};
}

template <typename T>
TOOL::Array2d<T>::Array2d()
    : size(0)
    , ptr(nullptr)
{
}
template <typename T>
TOOL::Array2d<T>::Array2d(const int n1, const int n2)
    : size(0)
    , ptr(nullptr)
{
    if (n1 <= 0 || n2 <= 0) {
        return;
    }
    size = n1;
    ptr = new T*[n1];
    for (int i = 0; i < n1; i++) {
        ptr[i] = new T[n2];
    }
}

template <typename T>
TOOL::Array2d<T>::~Array2d()
{
    if (ptr != nullptr) {
        for (int i = 0; i < size; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
        ptr = nullptr;
        size = 0;
    }
}
template <typename T>
inline T* TOOL::Array2d<T>::operator[](int i)
{
    return ptr[i];
}

template <typename T>
void TOOL::Array2d<T>::resize(const int n1, const int n2)
{
    if (n1 <= 0 || n2 <= 0) {
        return;
    }
    if (ptr != nullptr) {
        for (int i = 0; i < n1; i++) {
            delete[] ptr[i];
        }
        delete[] ptr;
        ptr = nullptr;
    }
    ptr = new T*[n1];
    for (int i = 0; i < n1; i++) {
        ptr[i] = new T[n2];
    }
    size = n1;
}
template <typename T>
TOOL::Array<T>::Array()
{
    ptr == nullptr;
}

template <typename T>
TOOL::Array<T>::Array(const int n)
{
    if (n < 0) {
        ptr = nullptr;
        return;
    }
    ptr = new T[n];
}
template <typename T>
TOOL::Array<T>::~Array()
{
    if (ptr != nullptr) {
        delete[] ptr;
        ptr = nullptr;
    }
}
template <typename T>
void TOOL::Array<T>::resize(const int n)
{
    if (n <= 0) {
        return;
    }
    if (ptr != nullptr) {
        delete[] ptr;
        ptr = nullptr;
    }
    ptr = new T[n];
}

template <typename T>
inline T& TOOL::Array<T>::operator[](const int i)
{
    return ptr[i];
}
#endif