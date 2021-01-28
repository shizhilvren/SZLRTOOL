#ifndef __SHOWDEBUG__
#define __SHOWDEBUG__
#include<string>
#include"../Tool/tool.h"
namespace Loger {

class Log {
public:
    enum Level {
        Debug = 0,
        Info,
        Warring,
        Error
    };

private:
    Level _level;
    std::string name; 
public:
    Log(const Level level);
    ~Log();
    void show(const Level Level,std::string& somestr);
    void info(const std::string& info);
    void debug(const std::string& debug);
    void warring(const std::string& warring);
    void error(const std::string& error);
    CLASSSETBUILD(Level,name);
};
}

#endif /*__SHOWDEBUG__*/