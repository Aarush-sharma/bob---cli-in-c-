#include "../tools.hpp"
using namespace std;

using json = nlohmann::json;

std::string filter(const std::string& response) {
    json parsedResponse = json::parse(response);
    try {  
        std::string t= parsedResponse["candidates"][0]["content"]["parts"][0]["text"];
        return t;
    } catch (const json::exception& e) {
        std::cerr << "Error extracting text: " << e.what() << std::endl;
        return "";
    }
}

size_t getresponse(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    ((std::string*)userp)->append((char*)contents, totalSize);
    return totalSize;
}

std::string defaultquery (std::string query){
  return  R"({
  "contents": [{
    "parts":[{"text":")" + query + R"("}]
  }],
  "systemInstruction": {
    "role": "user",
    "parts": [
      {
        "text": "you are a command-line based assistant, so keep your responses as short and don't use emojis\n"
      }
    ]
  }
})";
}