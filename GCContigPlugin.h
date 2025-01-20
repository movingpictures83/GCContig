#ifndef GCContigPLUGIN_H
#define GCContigPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include "Tool.h"
#include <string>

class GCContigPlugin : public Plugin, public Tool
{
public: 
 std::string toString() {return "GCContig";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string inputfile;
 std::string outputfile;
};

#endif
