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
                cout<<"here1 ";
            }
            else if (left(i)==size-1)
            {
                if (A[i]->freq>A[left(i)]->freq)
                {
                    cout<<"here6 ";
                    swap(A[i],A[left(i)]);
                    minheapify(left(i));
                }
            }
            else{
                if (A[left(i)]->freq>A[right(i)]->freq)
                {
                    cout<<"here2 ";
                    if (A[i]->freq>A[right(i)]->freq)
                    {
                        cout<<"here3 ";
                        swap(A[i],A[right(i)]);
                        minheapify(right(i));
                    }
                    cout<<"here4 ";
                }
                else
                {
                    cout<<"here5 ";
                    if (A[i]->freq>A[left(i)]->freq)
                    {
                        cout<<"here6 ";
                        swap(A[i],A[left(i)]);
                        minheapify(left(i));
                    }
                    cout<<"here7 ";
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
        void print(){
            int count=1;
            for (int i = 0; i < size; i++)
            {
                if (i+1==pow(2,count))
                {
                    cout<<endl;
                    count++;
                }
                cout<<A[i]->x<<" "<<A[i]->freq<<" ";
            }
        }
};
int main(){
    create B(6);
    for (int i = 0; i < 6; i++)
    {
        B.A[i]=new datas;
        cin>>(B.A[i]->freq);
        cout<<"taking inputs "<<B.A[i]->freq<<endl;
    }
    for (int i = 0; i < 6; i++)
    {
        cin>>(B.A[i]->x);
        cout<<"taking inputs "<<B.A[i]->x<<endl;
    }
    cout<<"out of loop"<<endl;
    B.size=6;
    cout<<"size set to 6"<<endl;
    B.heapify();
    cout<<"heapified"<<endl;
    B.print();
}