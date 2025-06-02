#include <iostream>
#include <string>
#include "utils/json_utils.hpp"
#include "utils/curl_utils.hpp"
#include "rapidjson/document.h"
#include <optional>
#include "cpp-httplib/httplib.h"



int main() {


// HTTP
httplib::Server svr;


    svr.Get("/sheperd", [](const httplib::Request &req, httplib::Response &res) {
        auto request = req.get_param_value("prompt");

        std::string prompt = request;
        std::string file_context = serializeJsonPrompt(prompt);
        std::cout<<file_context<<std::endl;
        std::string answer = requestHttpIntern(file_context);


        rapidjson::Document json_doc = convertStrInToJson(answer);

        if (json_doc.HasParseError()) {
            std::cerr << "Erreur de parsing JSON." << std::endl; 
            return 1;
        }

        if (json_doc.IsObject() && json_doc.HasMember("response") && json_doc["done"].IsBool()) {
            std::string value_answer = json_doc["response"].GetString();
            std::cout << std::boolalpha << value_answer << std::endl;
            res.set_content("{\"response\": \"" + value_answer + "\"}", "application/json");

        } else {
            std::cerr << "Champ 'done' absent ou invalide." << std::endl;
            std::cout << "Réponse JSON brute : " << answer << std::endl;
            res.set_content("failed to load the answer of the llm", "text/plain");

        }
    });
    

    svr.listen("0.0.0.0", 8080);
    
   
    
    return 0;
}
