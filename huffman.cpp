#include<bits/stdc++.h>
using namespace std;
class datas{
    public:
        char x;
        int freq;
};
class create{
    public:
        int size;
        int cap;
        datas *A;
        create(int c){
            A=new datas [c];
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
            A[size].freq=i;
            A[size].x=c;
            int child1=(size);
            int parent1=parent(child1);
            while (child1!=0 and A[parent1].freq>A[child1].freq)
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
            if (A[left(i)].freq>A[right(i)].freq)
            {
                if (A[i].freq>A[right(i)].freq)
                {
                    swap(A[i],A[right(i)]);
                    minheapify(right(i));
                }
            }
            else
            {
                if (A[i].freq>A[left(i)].freq)
                {
                    swap(A[i],A[left(i)]);
                    minheapify(left(i));
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
        void print(){
            int count=1;
            for (int i = 0; i < size; i++)
            {
                if (i+1==pow(2,count))
                {
                    cout<<endl;
                    count++;
                }
                cout<<A[i].x<<" "<<A[i].freq<<" ";
            }
        }
};
int main(){
    create B(6);
    for (int i = 0; i < 6; i++)
    {
        cin>>B.A[i].freq;
    }
    for (int i = 0; i < 6; i++)
    {
        cin>>B.A[i].x;
    }
    B.size=6;
    B.heapify();
    B.print();
}