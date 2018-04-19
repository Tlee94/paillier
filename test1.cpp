#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <vector>
#include <sstream>
using namespace std;

int add(int a,int b){
  int result;
  result = a + b;
  return result;
}

int multiply(int a, int b){
  int result;
  result = a * b;
  return result;
}

int store(int a){
  int result;
  result = a;
  return result;
}


//To compile use g++ test1.cpp -o test1 -std=c++11
//execute ./test1
int main()
{
    string str = "add number 1 number 2";

    // Tokens
    vector<pair <string, string>> v
    {
        {"[0-9]+" , "NUMBER"} ,
        {"add", "ADDITION"},
        {"multiply", "MULTIPLY"},
        {"save", "SAVE"},
        {"load", "LOAD"},
        {"number", "NUMBERS"}
    };

    string reg;

    for(const auto x : v)
      reg += "(" + x.first + ")|";

    reg.pop_back();

    cout << "Tokens: " << reg << endl;

    regex re(reg);
    cout << "String: " << str << endl;
    //look for through string and compare with elements in re
    sregex_iterator words_begin = sregex_iterator(str.begin(), str.end(), re);
    sregex_iterator words_end = sregex_iterator();

    for(sregex_iterator i = words_begin; i != words_end; i++)
    {
        size_t index = 0;

        for(index = 0; index < i->size(); ++index)
        {
            if(!i->str(index + 1).empty())
                break;
        }

        //cout << i->str() << " " << v[index].second << endl;

        // string  str= "add number 1 number 2"
        if (i->str() == "add")
        {
          //skip over the next the "whitespace" and "number"
          *i++;
          *i++;
          cout << "first number: " <<(*i).str() << endl;
          //convert string to int process
          stringstream test((*i).str());
          int t;
          test >> t;
          // int g = (*i).str();
          *i++;
          *i++;
          cout << "second number: " << (*i).str() << endl;
          //convert string to int
          stringstream test2((*i).str());
          int t2;
          test2 >> t2;
          cout << "t: " << t << " " << "t2: " << t2 << endl;
          //call add function
          cout << "Operation: " << v[index].second << " " << add(t,t2) << endl;
        }

        if (v[index].second == "MULTIPLY")
        {
          *i++;
          *i++;
          cout << "first number: " <<(*i).str() << endl;
          //convert string to int process
          stringstream test((*i).str());
          int t;
          test >> t;
          // int g = (*i).str();
          *i++;
          *i++;
          cout << "second number: " << (*i).str() << endl;
          //convert string to int
          stringstream test2((*i).str());
          int t2;
          test2 >> t2;
          cout << "t: " << t << " " << "t2: " << t2 << endl;
          //call multiply function
          cout << "Operation: " << v[index].second << " Answer: " << multiply(t,t2) << endl;
        }

        if (v[index].second == "SAVE")
        {
         //skip over the whitespace
         *i++;
         cout << "Number being stored: " << (*i).str() << endl;
         stringstream test((*i).str());
         int t;
         test >> t;
         //call save function
         cout << "Operation: " << v[index].second << " Answer: " << store(t) << endl;
        }

        if (v[index].second == "LOAD")
        {
          *i++;
          cout << "Load value: " << (*i).str() << endl;
          stringstream test((*i).str());
          int t;
          test >> t;
          cout << t << endl;
          //call load function
        }
    }


    return 0;
}
