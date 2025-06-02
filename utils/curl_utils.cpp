#include "curl_utils.hpp"


size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


std::string requestHttpIntern(const std::string& request){
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    if (curl){
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        std::string string_response;
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:11434/api/generate");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        CURLcode msg = curl_easy_perform(curl);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        if (msg !=CURLE_OK){
            std::cerr << "Erreur lors de la requete -> "<< curl_easy_strerror<<std::endl;
        }
        else {
            return readBuffer;
        }
    }
    return "Err";


}



std::string requestHttpExtern(const std::string& request)
    {
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    if (curl){
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        std::string string_response;
        curl_easy_setopt(curl, CURLOPT_URL, "http://0.0.0.0:5000/api");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, request.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        CURLcode msg = curl_easy_perform(curl);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
        if (msg !=CURLE_OK){
            std::cerr << "Erreur lors de la requete -> "<< curl_easy_strerror(msg)<<std::endl;
        }
        else {
            return readBuffer;
        }
    }
    return "Err";

    }