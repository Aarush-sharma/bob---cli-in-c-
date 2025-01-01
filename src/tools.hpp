#include <bits/stdc++.h>
#include <curl/curl.h>
#include "../modules/json.hpp"
using namespace std;

std::string filter(const std::string &response);
size_t getresponse(void *contents, size_t size, size_t nmemb, void *userp);
std::string cook(std::string query);
std::string defaultquery(std::string query);
void write_file(const std::string& filename, const std::string& text);
string read_file (std::string filename);
vector<string> seperate_each_value(string s);

class http {
    public: static void send_get(string url, optional<string> headers);
    public: static void send_post(string url, optional<string> headers, optional<string> body);
    public: static void send_put(string url, optional<string> headers, optional<string> body);
    public: static void send_delete(string url, optional<string> headers, optional<string> body);
};

class magic {
    public: static int roll(int size);
    public: static void sort(std::vector<int> &nums,int low,int high);
    public: static std::string greet();
    public: static int sum(vector<int> &nums);
    public: static int mul(vector<int> &nums);
};