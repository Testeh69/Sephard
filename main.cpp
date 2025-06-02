#include <iostream>
#include <string>
#include "utils/json_utils.hpp"
#include "utils/curl_utils.hpp"
#include "rapidjson/document.h"
#include <optional>

int main() {
    
    std::string prompt = "What is the color of the sky ?";
    std::string file_context = serializeJsonPrompt(prompt);
    std::cout<<file_context<<std::endl;
    std::string answer = requestHttp(file_context);


       rapidjson::Document json_doc = convertStrInToJson(answer);

    if (json_doc.HasParseError()) {
        std::cerr << "Erreur de parsing JSON." << std::endl;
        return 1;
    }

    if (json_doc.IsObject() && json_doc.HasMember("response") && json_doc["done"].IsBool()) {
        std::string value_answer = json_doc["response"].GetString();
        std::cout << std::boolalpha << value_answer << std::endl;
    } else {
        std::cerr << "Champ 'done' absent ou invalide." << std::endl;
        std::cout << "Réponse JSON brute : " << answer << std::endl;
    }
    
    return 0;
}
