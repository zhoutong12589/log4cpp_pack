


#include "log4cpp/Category.hh"
#include "log4cpp/PropertyConfigurator.hh"


#ifndef _H_LOG4LIB_
#define _H_LOG4LIB_


enum CLog_Level{
    CLog_DEBUG,
    CLog_INFO,
    CLog_WARN,
    CLog_ERROR,
    CLog_FATAL
};

class CLog{
public:
    ~CLog();
    void init(std::string cfg_file);
    static CLog* getIns();
    
    void write(CLog_Level level, std::string str);
private:
    CLog();

    std::string _cfg_file;
    static CLog* _ins;
};

#endif //_H_LOG4LIB_
