#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */


int formingMagicSquare(vector<vector<int>> s) {
vector<int> sum(6);
int ind=0;
for(vector<int> i:s){
    for(size_t k=0; k<3;k++){
        sum[3+k]=i[k]+sum[k+3];
    }
    for(int j: i){
        sum[ind]=sum[ind]+j;
    }
    ind++;
}

int a=0;
vector<int> magicSqr(6);
for(int i:sum) {magicSqr[a++]=15-i;}
vector<vector<int>> itr=s;
int b=0;
vector<int> fcost(3);
size_t k=0;
    while(k<3){
        itr=s;
        for(size_t i=0; i<6; i++){
            sum[i]=0;
        }
        for(size_t i=0; i<3; i++){
                b=rand()%3;
                itr[i][b]=s[i][b]+magicSqr[i];
        }   
        ind=0;
        for(vector<int> i:  itr){
            for(size_t z=0; z<3;z++){
                sum[3+z]=i[z]+sum[z+3];
            }
            for(int j: i){
                sum[ind]=sum[ind]+j;
            }
            ind++;
        }
        bool valid = false;
        for(size_t i=0; i<6; i++){
            cout<<sum[i]<<endl;
            if(sum[i]==15){
                valid=true;
            }
            else{
                valid=false;
                cout<<"wow"<<endl;
                break;
            }
        }
        if(valid){
            for(size_t i=0; i<3; i++){
                for(size_t j=0; j<3; j++){
                    fcost[k]=fcost[k]+abs(itr[i][j]-s[i][j]);
                    cout<<"custo: "<<fcost[k]<<endl;
                }
            }
            k++;
        }
    }
    int cost=1000;
    for(int i=0; i<=k; i++){
        if(cost>fcost[i] && fcost[i]!=0){
            cost = fcost[i];
        }
    }

return cost;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
