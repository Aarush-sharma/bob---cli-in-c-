
#include "src/tools.hpp"
using namespace std;

int main(int argc, char *argv[])
{
   string query = argv[1];
   if (query == "-q")
   {
      string task = argv[2];
      string res = cook(task);
      cout << res << endl;
   }
   else if (query == "get")
   {
      string url = argv[2];
      string t = argv[3];
      string headers;
      if (t == "-h")
      {
         headers = argv[4];
      };
      http::send_get(url, headers);
   }
   else if (query == "post")
   {
      string url = argv[2];
      string t = argv[3];
      string headers;
      string body;
      if (t == "-h")
      {
         headers = argv[4];
      }
      else if (t == "-b")
      {
         body = argv[4];
      }
      http::send_post(url, headers, body);
   }
   else if (query == "put")
   {
      string url = argv[2];
      string t = argv[3];
      string headers;
      string body;
      if (t == "-h")
      {
         headers = argv[4];
      }
      else if (t == "-b")
      {
         body = argv[4];
      }
      http::send_put(url, headers, body);
   }
   else if (query == "delete")
   {

      string url = argv[2];
      string t = argv[3];
      string headers;
      string body;

      if (t == "-h")
      {
         headers = argv[4];
      }
      else if (t == "-b")
      {
         body = argv[4];
      }
      http::send_put(url, headers, body);
   }
   else if (query == "greet")
   {
      cout << magic::greet() << endl;
   }
   else if (query == "roll")
   {
      int s = stoi(argv[2]);
      int k = magic::roll(s);
      cout << k << endl;
   }
   else if (query == "sort")
   {
      vector<int> nums;
      for (int i = 2; i < argc; i++)
      {
         nums.push_back(stoi(argv[i]));
      }
      magic::sort(nums, 0, nums.size() - 1);
      for (int num : nums)
      {
         cout << num << " ";
      }
      cout << endl;
   }
   else if (query == "add")
   {
      vector<int> nums;
      for (int i = 2; i < argc; i++)
      {
         nums.push_back(stoi(argv[i]));
      }
      int sum = magic::sum(nums);
      cout << sum << endl;
   }
   else if (query == "mul")
   {
      vector<int> nums;
      for (int i = 2; i < argc; i++)
      {
         nums.push_back(stoi(argv[i]));
      }
      int product = magic::mul(nums);
      cout << product << endl;
   }
   else
   {
      string help = R"(
      help:-
      command-structre: bob <tags || keywords> <values> must be seperated by spaces if n
      To test: greet
      
      -q : query (value must be included in quotes)
      sort: sort n numbers [limitations: integers only]
      roll: generates a random number with size of given value 
      add: adds n values (just enter the values)
      mul: multiplies n values (just enter the values)
      )";
      cout << help << endl;
   }
   return 0;
}