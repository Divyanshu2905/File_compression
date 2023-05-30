#include<bits/stdc++.h>
#include "huffman.cpp"
using namespace std;

//Function to read,decode data in file
string read_decode(string& file,unordered_map<string,char>& codes){
    ifstream inputfile(file,ios::binary);
    int n;
    char c;
    size_t mapsize;
    size_t stringsize;
    inputfile.read(reinterpret_cast<char*>(&stringsize), sizeof(size_t));       //reads string size that is to be decoded
    inputfile.read(reinterpret_cast<char*>(&mapsize), sizeof(size_t));          //reads encoding mapsize
    for (size_t i = 0; i < mapsize; ++i)                                        //reads map
    {
        char c;
        size_t codesize;
        inputfile.read(&c,sizeof(char));
        inputfile.read(reinterpret_cast<char*>(&codesize),sizeof(size_t));
        string code(codesize, ' ');
        inputfile.read(&code[0],codesize);
        codes[code]=c;
    }
    string compressdata;                                                        //reads compressed data
    bitset<8> bits;
    char byte;
    while (inputfile.read(&byte,sizeof(char)))
    {
        bits=static_cast<unsigned char>(byte);
        compressdata=compressdata+bits.to_string();
    }
    int i=0;                                                                    //decodes data untilstring size is reached and ignores extra bits
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
    inputfile.close();
    return decode;
}

//Main Decompressing Function to call other funnctions
void processdata(string& file,string& file2){
            unordered_map<string,char>codes;
            string decode=read_decode(file,codes);
            ofstream outputfile(file2,ios::binary);
            outputfile.write(decode.c_str(),decode.size());
            outputfile.close();
}

//Driver Function
int main(){
    string s;
    string t;
    cout<<"File to decompress: ";
    cin>>s;
    cout<<"Enter destination: ";
    cin>>t;
    string input=s;
    string output=t;
    cout<<"processing..!"<<endl;
    processdata(input,output);
    cout<<"Completed";
}
