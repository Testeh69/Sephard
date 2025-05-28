#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"
#include <string>
#include <optional>

#pragma once




//transforme le prompt en request Json
std::string serializeJsonPrompt(const std::string& request);



std::optional<rapidjson::Document> convertStrInToJson(const std::string& target);



std::string getDataFromTargetField(const rapidjson::Document& json_struct, const std::string& target_field);



bool getBoolFromTargetField(const rapidjson::Document& json_struct, const std::string& target_field);
