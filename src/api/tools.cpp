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

void write_file(const std::string& filename, const std::string& text) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file '" << filename << "' for writing\n";
        return;
    }
    file << text << "\n";
    file.close();
    std::cout << "Successfully wrote to '" << filename << "'\n";
}

string read_file (std::string filename){
    std::ifstream file(filename);
    string data;
    if(file){
       getline(file, data);
    }
    return data;
}

vector<string> seperate_each_value(string s){
  vector<string> res;
  int count =0;
  for(int i =0; i<s.size(); i++){
    if(s[i] == ';' || i== s.size()-1){
      if(i== s.size()-1) i++;
      int size = i - count;
      res.push_back(s.substr(count,size));
      count = i+2;
    }
  }
  return res;
}