#include <iostream>
#include <string>
#include "utils/json_utils.hpp"
#include "utils/curl_utils.hpp"
#include "rapidjson/document.h"


int main() {
    
    std::string prompt = "What is the color of the sky ?";
    std::string file_context = serializeJsonPrompt(prompt);
    std::cout<<file_context<<std::endl;
    std::string answer = requestHttp(file_context);
    while (true){
        auto answer_done = convertStrInToJson(answer);
        if (answer_done){
            auto stream_llm = getBoolFromTargetField(*answer_done, "done");
            std::cout<<stream_llm<<" ";

        }

    }
    return 0;
}
