#include "../tools.hpp"
using namespace std;

void http::send_delete(string url, optional<string> headers, optional<string> body){
   CURL *curl;
   CURLcode res;
   curl_global_init(CURL_GLOBAL_ALL);
   curl = curl_easy_init();
   if (curl)
   {
    struct curl_slist *header = NULL;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    header = curl_slist_append(header, "Content-Type: application/json");

    if(headers){
        auto data = seperate_each_value(headers->c_str());
        for(string h : data){
            header = curl_slist_append(header, h.c_str());
        }
    }
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body->c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
      std::cout << curl_easy_strerror(res);
    curl_easy_cleanup(curl); 
   }
   curl_global_cleanup();
}