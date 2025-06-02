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


    svr.Get("/sheperd", [](const httplib::Request &, httplib::Response &res) {
        std::string prompt = "What is the color of the sky ?";
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
            res.set_content(value_answer, "text/plain");


        } else {
            std::cerr << "Champ 'done' absent ou invalide." << std::endl;
            std::cout << "Réponse JSON brute : " << answer << std::endl;
            res.set_content("failed to load the answer of the llm", "text/plain");

        }
    });
    

    svr.listen("0.0.0.0", 8080);
    
   
    
    return 0;
}
