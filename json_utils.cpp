#include "json_utils.hpp"







std::string serializeJsonPrompt(const std::string& request){
    const char* json = R"({
        "model": "tinyllama",
        "prompt":""
        
    })";

    rapidjson::Document document;
    rapidjson::StringBuffer buffer; //Crée une mémoire temporaire pouvant stocker des string


    document.Parse(json);

    document["prompt"].SetString(request.c_str(),static_cast<rapidjson::SizeType>(request.length()), document.GetAllocator());
    

    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer); // ecrit dans cette mémoire
    document.Accept(writer); 

    return buffer.GetString();

}
