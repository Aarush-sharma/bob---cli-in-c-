# Bob CLI

a simple and fast command-line curl client written in c++, performs CRUD operations in the terminal, supports custom request headers, request body and params. 
it can answer queries using ai. 👾
## Examples
- Http
cmd structure : `bob <method-name> "url" -h "headers (each header must be seperated by ';' )" -b "request body (not available for get method)" `
 
  - Get
    `bob get "http://localhost:3000/" -h "token: abcxyz; authenticated: true" `
   - Post
     `bob post "http://localhost:3000/login" -h "Content-Type: application/json" -b "data:{email: xyz@emample.com, password: abc}" `

- Ai queries
cmd structure : `bob -q <query in double quotes ("")> `
    - such as 
      `bob -q "show nlp in python"`

       ![image](https://github.com/user-attachments/assets/77393b7f-de51-4359-a39d-07086bea15ca)



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