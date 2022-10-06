#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main() {
int n,q,i;
string line;
vector<string> extract, tag;

cin>>n>>q;
cin.ignore();

string aux="";
for(i=0;i<n;i++){
    getline(cin,line);
    string ss(line);
        ss.pop_back();
        ss.erase(0,1);
    int pos = ss.find('=',0);
    int bar = ss.find('/',0);
    if(bar == -1){
        ss.pop_back();
        int e0=ss.find('\"',pos);
        int posi = ss.find(' ',0);
        ss.replace(posi,1,"~");
        string tagvalue=ss.substr(0,pos-1);
        extract.push_back(ss.substr(e0+1,ss.size()-1));
        tag.push_back((aux+tagvalue));
        posi = tagvalue.find('~',0);
        
        string::iterator iter=tagvalue.begin();
        string tagger;
        while(iter!=tagvalue.end()){
            int ind=iter-tagvalue.begin();
            if(tagvalue[ind]=='~'){
                tagger=tagvalue.substr(0,ind);
                break;
            }
            iter++;
        }
        aux=tagger+"."+aux;
        
    }
    else{
        ss.erase(0,1);
        bar = aux.find(ss);
        //aux.erase(bar,ss.size());
    }
}

map<string,string>m;
for(int i=0;i<tag.size();i++){
    m.insert(pair<string,string>(tag[i],extract[i]));
}

string query;
for(i=0;i<q;i++){
    getline(cin,query);
    if(m[query]!=""){
        cout<<m[query]<<endl;
    }
    else{
        cout<<"Not Found!"<<endl;
    }
}

return 0;

}
