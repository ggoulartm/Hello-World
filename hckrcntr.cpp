#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hackerCountry' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts 2D_INTEGER_ARRAY tolls as parameter.
 */
 int min(vector<int> num){
     int minimo = num[0];
     for(size_t i=0;i<num.size();i++){
         if(minimo<num[i] && num[i]!=0){
             minimo=num[i];
         }
     }
     return minimo;
 }
 
 int minKey(vector<float> num){
     float minimo = num[0];
     int n=0;
     for(size_t i=0;i<num.size();i++){
         if(minimo<num[i] && num[i]!=0){
             minimo=num[i];
             n=i;
         }
     }
     return n;
 }
 
 void imprimeVetor(vector<vector<int>> vetor){
     for(vector<int> i: vetor){
         for(int j: i){
             cout<<" "<<j<<" ";
         }
         cout<<endl;
     }
 }

string hackerCountry(vector<vector<int>> tolls) {
    vector<vector<int>> vec = tolls;
    vector<int> sumTotal(vec.size()-1);
    int soma{};
    int nIter{}, nLinhas{0}, nColunas{},auxLinhas{};
    int n=0;
    vector<float> chave(tolls.size()-1);
    while(n<(tolls.size()-1)){
        vector<int> sum(vec.size());
        while(nLinhas<(tolls.size()-n)){
            auxLinhas=nLinhas;
            nIter=0;
            while(nIter<vec.size()){
                int tollCost = 200;
                bool ok=false;
                for(size_t j = 0; j<vec.size();j++){
                    if(vec[nLinhas][j]<tollCost && vec[nLinhas][j]!=0 && j!=auxLinhas){
                        tollCost = vec[nLinhas][j];
                        nColunas=j;
                    }
                    if(j==auxLinhas && nIter==(vec.size()-1)){
                        tollCost = vec[nLinhas][j];
                    }
                }
                for(size_t i=0;i<vec.size();i++){
                    vec[i][nColunas]=0;
                }
                nIter++;
                nLinhas=nColunas;
                sum[auxLinhas]=sum[auxLinhas]+tollCost;
            }
            nLinhas = auxLinhas+1;
            vec=tolls;
        }
        sumTotal[n] = min(sum);
        chave[n]=sumTotal[n]/(tolls.size()-n);
        n++;
        cout<<chave[n]<<" "<<n<<endl;
    }
    n=minKey(chave);
    string s{};
    int x=sumTotal[n];
    int y=tolls.size()-n;
    int d;
    d = __gcd(x, y);
    x = x / d;
    y = y / d;
    s = to_string(x);
    s.append("/");
    s.append(to_string(y));
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> tolls(n);

    for (int i = 0; i < n; i++) {
        tolls[i].resize(n);

        string tolls_row_temp_temp;
        getline(cin, tolls_row_temp_temp);

        vector<string> tolls_row_temp = split(rtrim(tolls_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int tolls_row_item = stoi(tolls_row_temp[j]);

            tolls[i][j] = tolls_row_item;
        }
    }

    string result = hackerCountry(tolls);

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

