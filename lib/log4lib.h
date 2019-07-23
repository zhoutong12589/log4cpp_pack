


#include "log4cpp/Category.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include <sstream>
using namespace std;

#ifndef _H_LOG4LIB_
#define _H_LOG4LIB_


enum CLog_Level{
    CLog_DEBUG,
    CLog_INFO,
    CLog_WARN,
    CLog_ERROR,
    CLog_FATAL
};

bool g_CLog_init = false;

class CLog{
public:
    ~CLog();
    bool init(std::string cfg_file);
    static CLog* getIns();
    
    void write(CLog_Level level, std::string str);
private:
    CLog();

    std::string _cfg_file;
    static CLog* _ins;
};

#define TLOG(level, tstr) do{\
        if(g_CLog_init){\
            std::ostringstream ostr;\
            ostr<<"{"<<__FILE__<<" - "<<__LINE__<<"}: "<<tstr;\
            CLog::getIns()->write(level, ostr.str());\
        }\
        else{\
            std::cout<<"log never init"<<std::endl;\
        }\
    }while(0);

//CLog_DEBUG
#define DTLOG(tstr) do{\
        if(g_CLog_init){\
            std::ostringstream ostr;\
            ostr<<"{"<<__FILE__<<" - "<<__LINE__<<"}: "<<tstr;\
            CLog::getIns()->write(CLog_DEBUG, ostr.str());\
        }\
        else{\
            std::cout<<"log never init"<<std::endl;\
        }\
    }while(0);

//CLog_INFO
#define ITLOG(tstr) do{\
        if(g_CLog_init){\
            std::ostringstream ostr;\
            ostr<<"{"<<__FILE__<<" - "<<__LINE__<<"}: "<<tstr;\
            CLog::getIns()->write(CLog_INFO, ostr.str());\
        }\
        else{\
            std::cout<<"log never init"<<std::endl;\
        }\
    }while(0);

//CLog_WARN
#define WTLOG(tstr) do{\
        if(g_CLog_init){\
            std::ostringstream ostr;\
            ostr<<"{"<<__FILE__<<" - "<<__LINE__<<"}: "<<tstr;\
            CLog::getIns()->write(CLog_WARN, ostr.str());\
        }\
        else{\
            std::cout<<"log never init"<<std::endl;\
        }\
    }while(0);

//CLog_ERROR
#define ETLOG(tstr) do{\
        if(g_CLog_init){\
            std::ostringstream ostr;\
            ostr<<"{"<<__FILE__<<" - "<<__LINE__<<"}: "<<tstr;\
            CLog::getIns()->write(CLog_ERROR, ostr.str());\
        }\
        else{\
            std::cout<<"log never init"<<std::endl;\
        }\
    }while(0);

//CLog_FATAL
#define FTLOG(tstr) do{\
        if(g_CLog_init){\
            std::ostringstream ostr;\
            ostr<<"{"<<__FILE__<<" - "<<__LINE__<<"}: "<<tstr;\
            CLog::getIns()->write(CLog_FATAL, ostr.str());\
        }\
        else{\
            std::cout<<"log never init"<<std::endl;\
        }\
    }while(0);
    
#endif //_H_LOG4LIB_
