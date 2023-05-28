#include<bits/stdc++.h>
using namespace std;
class datas{
    public:
        char x;
        int freq;
        datas* left;
        datas* right;
        datas(){
            left=right=NULL;
        }
        datas(int y){
            freq=y;
            left=right=NULL;
        }
        datas(char l, int y){
            x=l;
            freq=y;
            left=right=NULL;
        }
};
