#include<bits/stdc++.h>
#include "huffman.cpp"
using namespace std;

//Function Calculate frequency of charachters in file
void calculatefreq(string& file,unordered_map<char,int>& frequency){
            ifstream input(file,ios::binary);
            char c;
            while (input.get(c))
            {
                frequency[c]++;
            }
            input.close();
}

//Function to write encoded data in string
string compressdata(string& file,unordered_map<char,string>codes){
    ifstream input(file,ios::binary);
    string output;
    char c;
    while(input.get(c)){
        output=output+codes.at(c);
    }
    input.close();
    return output;
}

//Function to encoded data in file
string writedata(string& file2, string output, unordered_map<char,string> codes){
    ofstream writeoutput(file2,ios::binary);
    size_t map=codes.size();
    size_t stringsize=output.size();
    writeoutput.write(reinterpret_cast<const char*>(&stringsize),sizeof(size_t));       //writes string size
    writeoutput.write(reinterpret_cast<const char*>(&map),sizeof(size_t));              //writes mapsize
    for(const auto& pair :codes){                                                       //writes coding map
        char c=pair.first;
        string code=pair.second;
        size_t codeSize=code.size();
        writeoutput.write(&c,sizeof(char));
        writeoutput.write(reinterpret_cast<const char*>(&codeSize),sizeof(size_t));
        writeoutput.write(code.c_str(),codeSize);
    }
    bitset<8> byte;                                                                     //Writes encoded string in form of bytes
    int index=0;
    for (char bit : output)
    {
        if (bit=='1')
        {
            byte.set(7-index);
        }
        index++;
        if (index==8)
        {
            writeoutput.write(reinterpret_cast<const char*>(&byte),sizeof(char));
            byte.reset();
            index=0;
        }
    }
    if (index>0)
    {
        writeoutput.write(reinterpret_cast<const char*>(&byte), sizeof(char));
    }
    writeoutput.close();
}

//Main compressing function to call other function step-by-step
void processdata(string& file,string& file2){
            unordered_map<char,int> frequency;
            unordered_map<char,string>codes;
            string code;
            calculatefreq(file,frequency);
            int n=frequency.size();
            create B(n);
            int counter=0;
            for (const auto& pair : frequency){         //Assigning values to nodes 
                B.A[counter]=new datas;
                B.A[counter]->x=pair.first;
                B.A[counter]->freq=pair.second;
                counter++; 
            }
            B.heapify();
            B.huffmantree();
            B.generatecodes(B.A[0],code,codes);
            string output=compressdata(file,codes);
            writedata(file2,output,codes);
}

//Driver function
int main(){
    string s;
    string t;
    cout<<"File to compress: ";
    cin>>s;
    cout<<"Enter destination: ";
    cin>>t;
    string inputfile=s;
    string outputfile=t;
    cout<<"processing..!"<<endl;
    processdata(inputfile,outputfile);
    cout<<"Completed";
}
