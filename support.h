#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>
#include <boost/algorithm/string.hpp>

using std::ofstream;using std::ifstream;using std::vector;
using std::string;using std::tuple;using std::ios;
using std::cout; using std::cin;using boost::split;

struct File
{
    private:

    string file_name;
    bool New=false;
    vector<string>line;
    bool is_empty(ifstream &file);
    void read_file();

    public:

    File(string file_name):file_name(file_name){}
    
    vector<string>get();
    void write_file(tuple<string,int>&data);
};

// template function 
template<typename T>
void input(string out,T &data)
{
    cout<<out;
    cin>>data;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

#endif