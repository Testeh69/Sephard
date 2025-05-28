#include <iostream>
#include <string>
#include "json_utils.hpp"
#include "curl_utils.hpp"

int main() {
    
    std::string prompt = "What is the color of the sky ?";
    std::string file_context = serializeJsonPrompt(prompt);
    std::cout<<file_context<<std::endl;
    std::string answer = requestHttp(file_context);
    std::cout<<answer<<std::endl;
    return 0;
}
