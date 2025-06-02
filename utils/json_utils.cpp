#include "json_utils.hpp"






std::string serializeJsonPrompt(const std::string& request){
    const char* json = R"({
        "model": "tinyllama",
        "prompt":"",
        "stream":false
        
    })";

    rapidjson::Document document;
    rapidjson::StringBuffer buffer; //Crée une mémoire temporaire pouvant stocker des string


    document.Parse(json);

    document["prompt"].SetString(request.c_str(),static_cast<rapidjson::SizeType>(request.length()), document.GetAllocator());
    

    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer); // ecrit dans cette mémoire
    document.Accept(writer); 

    return buffer.GetString();

}



rapidjson::Document convertStrInToJson(const std::string& target) {
    rapidjson::Document document;
    document.Parse(target.c_str());
    return document;
}


std::string getDataFromTargetField(const rapidjson::Document& json_struct, const std::string& target_field){
    
    if (json_struct.HasMember(target_field.c_str()) && json_struct[target_field.c_str()].IsString()){
        const rapidjson::Value& value = json_struct[target_field.c_str()];
        return value.GetString();

    }
    else{
        return "Err";
    }
}


bool getBoolFromTargetField(const rapidjson::Document& json_struct, const std::string& target_field){
    
    if (json_struct.HasMember(target_field.c_str()) && json_struct[target_field.c_str()].IsString()){
        const rapidjson::Value& value = json_struct[target_field.c_str()];
        return value.GetBool();
    }
    return true;
    
}