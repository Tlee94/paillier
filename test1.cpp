#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <vector>
using namespace std;

//To compile use g++ test1.cpp -o test1 -std=c++11
//execute ./test1
int main()
{
    string str = "add number 1 number 2";

    // Tokens
    vector<pair <string, string>> v
    {
        {"[0-9]+" , "NUMBERS"} ,
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

    sregex_iterator words_begin = sregex_iterator(str.begin(), str.end(), re);
    sregex_iterator words_end = sregex_iterator();

    for(sregex_iterator i = words_begin; i != words_end; i++)
    {
        size_t index = 0;

        for(index = 0; index < i->size(); ++index)
            if(!i->str(index + 1).empty())
                break;

        cout << i->str() << " " << v[index].second << endl;
    }
    return 0;
}
