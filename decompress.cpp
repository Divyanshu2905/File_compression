#include<bits/stdc++.h>
#include "huffman.cpp"
using namespace std;
void calculatefreq(string& file,unordered_map<string,char>& codes){
    ifstream inputfile(file,ios::binary);
    int n;
    char c;
    size_t mapsize;
    inputfile.read(reinterpret_cast<char*>(&mapsize), sizeof(size_t));
    for (size_t i = 0; i < mapsize; ++i)
    {
        char c;
        size_t codesize;
        inputfile.read(&c,sizeof(char));
        inputfile.read(reinterpret_cast<char*>(&codesize),sizeof(size_t));
        string code(codesize, ' ');
        inputfile.read(&code[0],codesize);
        codes[code]=c;
    }
    inputfile.close();
}
void processdata(string& file,string& file2){
            unordered_map<string,char>codes;
            calculatefreq(file,codes);
            for (const auto& pair : codes) {
                cout<< pair.first << ": " << pair.second <<endl;
            }
}
int main(){
    string input="compress.bin";
    string output="output.txt";
    processdata(input,output);
}