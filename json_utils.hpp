#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>


#pragma once




//transforme le prompt en request Json
std::string serializeJsonPrompt(const std::string& request);





