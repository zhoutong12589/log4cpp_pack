
//#include "log4cpp/Appender.hh"
//#include "log4cpp/FileAppender.hh"
//#include "log4cpp/OstreamAppender.hh"
//#include "log4cpp/Layout.hh"
//#include "log4cpp/BasicLayout.hh"
//#include "log4cpp/Priority.hh"
//
//#include "log4cpp/Category.hh"
//#include "log4cpp/PropertyConfigurator.hh"

#include <iostream>
#include <string>
#include <unistd.h>
#include "lib/log4lib.h"
#include <sstream>

using namespace std;



int main(int argc, char** argv) {
    /*
	log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console", &std::cout);
	appender1->setLayout(new log4cpp::BasicLayout());

	log4cpp::Appender *appender2 = new log4cpp::FileAppender("default", "program.log");
	appender2->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category& root = log4cpp::Category::getRoot();
	root.setPriority(log4cpp::Priority::WARN);
	root.addAppender(appender1);

	log4cpp::Category& sub1 = log4cpp::Category::getInstance(std::string("sub1"));
	sub1.addAppender(appender2);

	// use of functions for logging messages
	root.error("root error");
	root.info("root info");
	sub1.error("sub1 error");
	sub1.warn("sub1 warn");

	// printf-style for logging variables
	root.warn("%d + %d == %s ?", 1, 1, "two");

	// use of streams for logging messages
	root << log4cpp::Priority::ERROR << "Streamed root error";
	root << log4cpp::Priority::INFO << "Streamed root info";
	sub1 << log4cpp::Priority::ERROR << "Streamed sub1 error";
	sub1 << log4cpp::Priority::WARN << "Streamed sub1 warn";

	// or this way:
	root.errorStream() << "Another streamed error";
    */
    
    /*
    std::string initFileName = "../log4cpp.conf";
    log4cpp::PropertyConfigurator::configure(initFileName);

    log4cpp::Category& root = log4cpp::Category::getRoot();
    
    //log4cpp::Category& sub1 = log4cpp::Category::getInstance();
    root.info("test console");
    
    sleep(1);
    
    */
    
    CLog::getIns()->init("../log4cpp.conf");
    TLOG(CLog_INFO, "test NLOG::LOG");
    
    ostringstream os;
    os<<"hgftftrfyvg";
    TLOG(CLog_FATAL, os.str());
    sleep(1);
	return 0;
}
