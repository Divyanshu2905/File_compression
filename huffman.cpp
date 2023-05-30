#include<bits/stdc++.h>
using namespace std;
class datas{
    public:
        char x;
        int freq;
        datas* lefts;
        datas* rights;
        datas(){
            lefts=rights=NULL;
        }
        datas(int y){
            freq=y;
            lefts=rights=NULL;
        }
        datas(char l, int y){
            x=l;
            freq=y;
            lefts=rights=NULL;
        }
};
class create{
    public:
        int size;
        int cap;
        datas **A;
        create(int c){
            A=new datas*[c];
            size=0;
            cap=c;
        }
        int left(int i){
            return((2*i)+1);
        }
        int right(int i){
            return((2*i)+2);
        }
        int parent(int i){
            return ((i-1)/2);
        }
        void minheapify(int i){
            if (left(i)>size-1)
            {
                return;
                
            }
            else if (left(i)==size-1)
            {
                if (A[i]->freq>A[left(i)]->freq)
                {
                    
                    swap(A[i],A[left(i)]);
                    minheapify(left(i));
                }
            }
            else{
                if (A[left(i)]->freq>A[right(i)]->freq)
                {
                    
                    if (A[i]->freq>A[right(i)]->freq)
                    {
                        swap(A[i],A[right(i)]);
                        minheapify(right(i));
                    }
                    
                }
                else
                {                    
                    if (A[i]->freq>A[left(i)]->freq)
                    {                       
                        swap(A[i],A[left(i)]);
                        minheapify(left(i));
                    }
                }
            }
        }
        void heapify(){
            int roots=parent(size-1);
            for (int i = roots; i > -1; i--)
            {
                minheapify(i);
            }
        }
        datas*extractmin(){
            datas *min=new datas;
            min=A[0];
            swap(A[0],A[size-1]);
            size--;
            minheapify(0);
            return min;
        }
        datas *huffmantree(){
            int n=size-1;
            for (int i = 0; i < n; i++)
            {
                datas*newnode= new datas;
                newnode->lefts=extractmin();
                newnode->rights=A[0];  
                newnode->freq=((newnode->lefts->freq)+(newnode->rights->freq));
                A[0]=newnode;
                minheapify(0);
            }
            return A[0];
        }
        void generatecodes(datas*root,string code,unordered_map<char,string>& X){
            if (root==NULL)
            {
                return;
            }
            else if (root->lefts==NULL and root->rights==NULL)
            {
                X[root->x]=code;
                return;
            }
            generatecodes(root->lefts,code+'0',X);
            generatecodes(root->rights,code+'1',X); 
        }
};
