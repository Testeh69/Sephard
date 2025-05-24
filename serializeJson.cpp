#include "serializeJson.hpp"







rapidjson::Document serializeJsonPrompt(const std::string& request){
    const char* json = R"({
        "model": "tinyllama",
        "prompt":"",
        
    })";

    rapidjson::Document document;
    document.Parse(json);

    if (document.HasMember("prompt")){
        document["prompt"].SetString(request.c_str(),static_cast<rapidjson::SizeType>(request.length()), document.GetAllocator());
    };

    return document;

}
