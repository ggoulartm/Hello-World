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
 
 //encontra o menor valor diferente de zero em um vetor
 int min(vector<int> num){
     int minimo = num[0];
     for(size_t i=0;i<num.size();i++){
         if(minimo<num[i] && num[i]!=0){
             minimo=num[i];
         }
     }
     return minimo;
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
//vamos trabalhar sobre um vetor auxiliar para poder excluir seus elementos
    vector<vector<int>> vec = tolls;
//vetor que soma os valores das viagens começando cada vez de uma cidade diferente
    vector<int> sum(vec.size());
//valor da menor viagem de menor custo
    int soma{};
//variáveis auxiliares
    int nIter{}, nLinhas{}, nColunas{},auxLinhas{};
    
//o objetivo dessas iterações é começar cada vez de uma cidade diferente e ir incrementando, cidade = 0,1,2...
    while(nLinhas<tolls.size()){
        auxLinhas=nLinhas;
        nIter=0;
        //realiza as iterações começando da cidade nLinhas
        while(nIter<vec.size()){
        //reinicia o valor do pedágio para o máximo
            int tollCost = 200;
            //procura qual é a próxima cidade com pedágio mais barato
            for(size_t j = 0; j<vec.size();j++){
                if(vec[nLinhas][j]<tollCost && vec[nLinhas][j]!=0){
                    tollCost = vec[nLinhas][j];
                    nColunas=j;
                }
            }
            //descarta a coluna da cidade selecionada, já que jamais iremos voltar para a mesma cidade
            for(size_t i=0;i<vec.size();i++){
                vec[i][nColunas]=0;
            }
	//adiciona o valor do pedágio na nossa viagem
            sum[auxLinhas]=sum[auxLinhas]+tollCost;
	//leva o vetor para a próxima cidade
            nLinhas=nColunas;
            nIter++;
        }
        nLinhas=auxLinhas+1;
        //reinicia o vetor;
        vec=tolls;
    }
    
    soma = min(sum);
    string s{};
    int x=soma;
    int y=tolls.size();
        
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

