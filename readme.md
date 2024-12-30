# Bob CLI

a simple and fast command-line curl client written in c++, performs CRUD operations in the terminal and can as well answer queries using ai. 👾

## Build from source
To run Bob CLI locally, ensure you have the following installed on your system: 

- [gcc](https://code.visualstudio.com/docs/cpp/config-mingw) (v17 or later)
- [make](https://gcc.gnu.org/install/build.html)

Clone the repository:
   ```bash
   git clone https://github.com/Aarush-sharma/bob-cli.git
   ```

- Go to api folder:
 ```bash 
cd src/api
   ```
- Open index.cpp
- Add your api key from [gemini_docs](https://aistudio.google.com/apikey)
- Move to the root folder
- Run 
```bash
make bob
```
- finally 
```bash
bob 
```
- now help menu will look like this if everything goes correct.

> help:-
      command-structre: bob <tags || keywords> <values> must be seperated by spaces if n
      To test: greet
      
  >  -q : query (value must be included in quotes)
      sort: sort n numbers [limitations: integers only]
      roll: generates a random number with size of given value 
      add: adds n values (just enter the values)
      mul: multiplies n values (just enter the values)

-> Add the path to this exe file in your enviorement variables to use it globally :)