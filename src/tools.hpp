#include <bits/stdc++.h>
#include <curl/curl.h>
#include "../modules/json.hpp"
using namespace std;

class magic {
    public: static int roll(int size);

    public: static void sort(std::vector<int> &nums,int low,int high);

    public: static std::string greet();

    public: static int sum(vector<int> &nums);

    public: static int mul(vector<int> &nums);
};

std::string filter(const std::string &response);
size_t getresponse(void *contents, size_t size, size_t nmemb, void *userp);
std::string cook(std::string query);
std::string defaultquery(std::string query);