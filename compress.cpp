#include<bits/stdc++.h>
#include "huffman.cpp"
using namespace std;
void calculatefreq(string& file,unordered_map<char,int>& frequency){
            ifstream input(file,ios::binary);
            char c;
            while (input.get(c))
            {
                frequency[c]++;
            }
            input.close();
}
string writedata(string& file2, string output, unordered_map<char,int> frequency){
    ofstream writeoutput(file2,ios::binary);
    for(const auto& pair :frequency){
        writeoutput<<pair.first;
        writeoutput.write(reinterpret_cast<const char*>(&pair.second),sizeof(int));
    }
    bitset<8> byte;
    int index=0;
    for (char bit : output)
    {
        if (bit=='1')
        {
            byte.set(index);
        }
        index++;
        if (index==8)
        {
            writeoutput.write(reinterpret_cast<const char*>(&byte), sizeof(char));
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

void processdata(string& file,string& file2){
            unordered_map<char,int> frequency;
            unordered_map<char,string>codes;
            string code;
            calculatefreq(file,frequency);
            int n=frequency.size();
            create B(n);
            int counter=0;
            for (const auto& pair : frequency) {
                B.A[counter]=new datas;
                B.A[counter]->x=pair.first;
                cout<<B.A[counter]->x;
                B.A[counter]->freq=pair.second;
                cout<<B.A[counter]->freq;
                counter++; 
            }
            B.size=n;
            B.heapify();
            B.huffmantree();
            B.generatecodes(B.A[0],code,codes);
            for (const auto& pair : codes) {
                cout<< pair.first << ": " << pair.second <<endl;
            }
            string output=compressdata(file,codes);
            writedata(file2,output,frequency);
}
int main(){
    string s;
    cout<<"file to compress"<<endl;
    cin>>s;
    string inputfile=s;
    string outputfile="compress.bin";
    processdata(inputfile,outputfile);  
}
