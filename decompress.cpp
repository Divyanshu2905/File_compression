#include<bits/stdc++.h>
#include "huffman.cpp"
using namespace std;
string calculatefreq(string& file,unordered_map<string,char>& codes){
    ifstream inputfile(file,ios::binary);
    int n;
    char c;
    size_t mapsize;
    size_t stringsize;
    inputfile.read(reinterpret_cast<char*>(&stringsize), sizeof(size_t));
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
    string compressdata;
    bitset<8> bits;
    char byte;
    while (inputfile.read(&byte,sizeof(char)))
    {
        bits=static_cast<unsigned char>(byte);
        compressdata=compressdata+bits.to_string();
    }
    int i=0;
    string code;
    string decode;
    for(char bit: compressdata){
        code=code+bit;
        if (codes.find(code)!=codes.end())
        {
            decode=decode+codes[code];
            code.clear();
        }
        i++;
        if (i==stringsize)
        {
            break;
        }
    }
    cout<<decode;
    inputfile.close();
    return decode;
}
void processdata(string& file,string& file2){
            unordered_map<string,char>codes;
            string decode=calculatefreq(file,codes);
            for (const auto& pair : codes) {
                cout<< pair.first << ": " << pair.second <<endl;
            }
            ofstream outputfile(file2,ios::binary);
            outputfile.write(decode.c_str(),decode.size());
            outputfile.close();
}
int main(){
    string input="compress.bin";
    string output="output.txt";
    processdata(input,output);
}