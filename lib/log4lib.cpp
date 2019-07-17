

#include "log4lib.h"


CLog* CLog::_ins = new CLog;

CLog::CLog(){
    
}

CLog::~CLog(){

}

bool CLog::init(std::string cfg_file){
    _cfg_file = cfg_file;
    log4cpp::PropertyConfigurator::configure(_cfg_file);
    g_CLog_init = true;
    return true;
}

CLog* CLog::getIns(){
    return _ins;
};

void CLog::write(CLog_Level level, std::string str){
    log4cpp::Category& root = log4cpp::Category::getRoot();
    
    switch(level){
    case CLog_DEBUG:
        root.debug(str);
        break;
    case CLog_INFO:
        root.info(str);
        break;
    case CLog_WARN:
        root.warn(str);
        break;
    case CLog_ERROR:
        root.error(str);
        break;
    case CLog_FATAL:
        root.fatal(str);
        break;
    }
    
}
        
       
        