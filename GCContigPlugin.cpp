#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "GCContigPlugin.h"

void GCContigPlugin::input(std::string file) {
   readParameterFile(file);
}

void GCContigPlugin::run() {}

void GCContigPlugin::output(std::string file) {
       	std::string outputfile = file;
	
	std::string myCommand = "echo -e \"contig\\tlength\\tgc_percent\" > "+file+";";
	myCommand += "while read -r line; do gc_number=$(grep -A 1 \"${line}\" "+PluginManager::addPrefix(myParameters["reads"])+" | awk 'NR%2==0 {print}' | awk '{count += gsub(/[gcGC]/, \"\");} END {print count}'); total_bases=$(grep -A 1 \"${line}\" "+PluginManager::addPrefix(myParameters["reads"])+" | awk 'NR%2==0 {print}' | tr -d '\\n' | wc -c); gc_percent=$(awk -v total=\"$total_bases\" -v value=\"$gc_number\" 'BEGIN { printf((value/total)*100); }'); echo -e \"$line\\t$total_bases\\t$gc_percent\" >> "+file+"; done < "+PluginManager::addPrefix(myParameters["contigs"]);
 std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<GCContigPlugin> GCContigPluginProxy = PluginProxy<GCContigPlugin>("GCContig", PluginManager::getInstance());
