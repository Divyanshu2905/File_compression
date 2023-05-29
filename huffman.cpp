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
        void buildheap(int i, char c){
            A[size]->freq=i;
            A[size]->x=c;
            int child1=(size);
            int parent1=parent(child1);
            while (child1!=0 and A[parent1]->freq>A[child1]->freq)
            {
                swap(A[parent1],A[child1]);
                child1=parent1;
                parent1=parent(parent1);
            }
            size++;
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
            cout<<"entered heapify"<<endl;
            int roots=parent(size-1);
            cout<<"found root"<<endl;
            for (int i = roots; i > -1; i--)
            {
                cout<<"entered loop"<<endl;
                minheapify(i);
                cout<<"completed loop"<<endl;
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
                print();
            }
            cout<<"success"<<endl;
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
        void print(){
            int count=1;
            for (int i = 0; i < size; i++)
            {
                if (i+1==pow(2,count))
                {
                    cout<<endl;
                    count++;
                }
                cout<<" "<<A[i]->freq<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
};
