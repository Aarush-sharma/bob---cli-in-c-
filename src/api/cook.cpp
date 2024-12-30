#include "../tools.hpp"
using namespace std;

std::string cook(std::string query)
{
  CURL *curl;
  CURLcode res;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  std::string data = "";
  if (curl)
  {
    std::cout<<"thinking..."<<std::endl;
    struct curl_slist *header = NULL;
    curl_easy_setopt(curl, CURLOPT_URL, "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=YOUR_API_KEY");
    std::string body = defaultquery(query);

    header = curl_slist_append(header, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,  getresponse);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, header);
    res = curl_easy_perform(curl);
    
    if (res != CURLE_OK)
      std::cout << curl_easy_strerror(res);
    data = filter(data);
    curl_easy_cleanup(curl); 
  }
  curl_global_cleanup();
  return data;
}   