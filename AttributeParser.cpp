#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
int n,q,i;
string line, aux;
map<string,string>m;
cin>>n>>q;
vector<string> extract, tag;
cin.ignore();
for(i=0;i<n;i++){
    getline(cin,line);
    string ss(line);
    int pos = ss.find("<",0);
    int bar = ss.find("/",0);
    if(pos != -1){
        if(bar == -1){
            int poso = ss.find("=", pos);
            int poso2 = ss.find("\"",poso);
            int posf = ss.find(">", poso);
            int posf2=ss.find("\"",poso2+1);
            extract.push_back(ss.substr(poso2+1,posf2));
            extract[i].pop_back();
            extract[i].pop_back();
            tag.push_back(ss.substr(pos+1, pos+4)+"~"+ss.substr(pos+6,poso-7));
        }
        else{
            aux=ss.substr(bar+1,bar+3);
            vector<string>::iterator itr=tag.begin();
            while(itr!=extract.end()){
                int index=itr-tag.begin();
                pos=tag[index].find(aux);
                if(pos!=-1){
                    for(int i=index+1; i<tag.size();i++){
                        tag[i]=aux+"."+tag[i];
                    }
                    break;
                }
                itr++;
            }
        }
    }
}
for(int i=0;i<tag.size();i++){
    m.insert(pair<string,string>(tag[i],extract[i]));
}
string query;
for(i=0;i<q;i++){
    getline(cin,query);
    map<string,string>::iterator itr=m.find(query);
    if(itr!=m.end()){
        cout<<itr->second<<endl;
    }
    else{
        cout<<"Not Found!"<<endl;
    }
}

return 0;

}
