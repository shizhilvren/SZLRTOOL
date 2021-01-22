#ifndef __DEBUG__
#define __DEBUG__
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <iostream>

///用于是否输出调试信息
#define __DEBUG_ON__
#define __TIME_ON__
#define __ERROR_ON__
#define __WARNING_ON__
#define __INFO_ON__
#define __DEBUG_CODE_ON__

#define NONE "\033[m"
#define LIGHT_NONE "\033[1;37m"
#define RED "\033[0;32;31m"
#define LIGHT_RED "\033[1;31m"
#define GREEN "\033[0;32;32m"
#define LIGHT_GREEN "\033[1;32m"
#define BLUE "\033[0;32;34m"
#define LIGHT_BLUE "\033[1;34m"
#define DARY_GRAY "\033[1;30m"
#define CYAN "\033[0;36m"
#define LIGHT_CYAN "\033[1;36m"
#define PURPLE "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[1;33m"
#define LIGHT_GRAY "\033[0;37m"
#define WHITE "\033[1;37m"

#define filename(x) strrchr(x, '/') ? strrchr(x, '/') + 1 : x

#ifdef __ERROR_ON__
#define ERROR(...)                                                                                                       \
    do                                                                                                                   \
    {                                                                                                                    \
        fprintf(stderr, NONE "[" RED "ERROR" NONE "  ]" LIGHT_NONE "%s %s:%d->" NONE, __FILE__, __FUNCTION__, __LINE__); \
        fprintf(stderr, __VA_ARGS__);                                                                                    \
    } while (0)
#else
#define ERROR(...)
#endif

#ifdef __WARNING_ON__
#define WARNING(...)                                                                                                        \
    do                                                                                                                      \
    {                                                                                                                       \
        fprintf(stdout, NONE "[" PURPLE "WARING" NONE " ]" LIGHT_NONE "%s %s:%d->" NONE, __FILE__, __FUNCTION__, __LINE__); \
        fprintf(stdout, __VA_ARGS__);                                                                                       \
    } while (0)
#else
#define WARNING(...)
#endif

#ifdef __INFO_ON__
#define INFO(...)                                                                                         \
    do                                                                                                    \
    {                                                                                                     \
        fprintf(stdout, NONE "[INFO   ]" LIGHT_NONE "%s %s:%d->" NONE, __FILE__, __FUNCTION__, __LINE__); \
        fprintf(stdout, __VA_ARGS__);                                                                     \
    } while (0)
#else
#define INFO(...)
#endif

#ifdef __TIME_ON__
#define SHOW_TIME(...)                                                                                                                      \
    do                                                                                                                                      \
    {                                                                                                                                       \
        fprintf(stdout, NONE "[" BLUE "TIME" NONE "   ]" LIGHT_NONE "%s %s:%d %s->" NONE, __FILE__, __FUNCTION__, __LINE__, __TIMESTAMP__); \
        fprintf(stdout, __VA_ARGS__);                                                                                                       \
    } while (0)
#else
#define SHOW_TIME(...)
#endif

#ifdef __DEBUG_ON__
#define DEBUG(...)                                                                                                                    \
    do                                                                                                                                \
    {                                                                                                                                 \
        fprintf(stdout, NONE "[" YELLOW "DEBUG" NONE "  ]" LIGHT_NONE "%s %s:%d->" NONE, filename(__FILE__), __FUNCTION__, __LINE__); \
        fprintf(stdout, __VA_ARGS__);                                                                                                 \
    } while (0)
#else
#define DEBUG(...)
#endif

#ifdef __DEBUG_CODE_ON__
#define DEBUG_CODE(...) \
    do                  \
    {                   \
        __VA_ARGS__     \
    } while (0)
#else
#define DEBUG_CODE(...)
#endif
#ifdef __DEBUG_CODE_ON__
#define DEBUG_CODE_CLASS(type, name) \
    type name;
#else
#define DEBUG_CODE_CLASS(...)
#endif
#ifdef __DEBUG_CODE_ON__
#define DEBUG_CODE_ALL(...) \
    __VA_ARGS__
#else
#define DEBUG_CODE_ALL(...)
#endif

#endif //__DEBUG__