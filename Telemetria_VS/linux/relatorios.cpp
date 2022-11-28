#pragma once
#include <iostream>
#include <chrono>
#include <thread>
#include <queue>
#include <map>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

template<typename T, typename Container = deque<T>>
void print_log(queue<T,Container> queue){
    
    cout << " Relatório : [";
    while(!queue.empty()){
        T item = queue.front();
        cout << " " << item ;
        queue.pop();
    }
    cout << "]" << std::endl;
    
}

vector<string> returnTime(){
    auto now = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(now);
    struct tm *horarioLocal=localtime(&time);
    
    string dia = to_string(horarioLocal->tm_mday);
    string mes = to_string(horarioLocal->tm_mon + 1);
    string ano = to_string(horarioLocal->tm_year + 1900);

    string hora = to_string(horarioLocal->tm_hour);
    string min  = to_string(horarioLocal->tm_min);
    string sec  = to_string(horarioLocal->tm_sec);

    string d={ dia + "/" + mes + "/" + ano };
    string h={ hora + ":" + min + ":" + sec };

    return {d,h};
}

void displayTime(){
        cout<<endl<<endl<<endl;
    auto now = chrono::system_clock::now();
    time_t end_time = chrono::system_clock::to_time_t(now);
    
    cout << "Relógio: " << ctime(&end_time) << endl;
}


template <typename T,typename K>
 void print_map(const std::map<T,K> & map){
    
    auto it = map.begin();
    
    std::cout << " map of elements : [" ;
    while(it != map.end()){
        
        std::cout << " [" << it->first << "," << it->second << "]" ;
        ++it;
    }
    std::cout << " ]" << std::endl;
}

class Hour{
    string hour;
    map<string,int> relo;
    public:
        Hour(string h){
            cout<<"New Hour: "<<h<<endl;
            hour=h;
        }
        void setHour(string e, int l){
            cout<<"set Hour"<<endl;
            relo.insert(make_pair(e,l));
        }
        friend std::ostream& operator<<(std::ostream& os, const Hour& hr){
            cout<<"No horário "<<hr.hour<<" ocorreu o evento:"<<endl;
            print_map(hr.relo);
        }
        friend bool operator==(const Hour& hr, string hour){
            bool result=false;
            if(hr.hour==hour) result=true;
            return result;
        }
};

class Date{
    string date;
    vector<Hour> hour;
    public:
        Date(string d){
            cout<<"New Date: "<<d<<endl;
            date=d;
        }
        void setDate(string h, string e, int l){
            vector<Hour>::iterator itr=hour.begin();
            itr=hour.begin();
            cout<<"iterator hour"<<endl;
            while(itr!=hour.end()){
                if(hour[itr-hour.begin()]==h){
                    break;
                }
                itr++;
            }
            cout<<"ok"<<endl;
            Hour hr(h);
            hr.setHour(e,l);
            if(itr!=hour.end()) hour.push_back(hr);
        }
        friend std::ostream& operator<<(std::ostream& os, const Date& date){
            cout<<"Na data "<<date.date<<" ocorreram os seguintes eventos:"<<endl;
            for(Hour h: date.hour){
                cout<<h<<endl;
            }
        }
        friend bool operator==(const Date& date1, const Date& date){
            bool result=false;
            if(date1.date==date.date) result=true;
            return result;
        }
};

class Relatorio{
    vector<Date> date;
    public:
        Relatorio(){
            cout<<"O Relatório de Eventos foi iniciado com sucesso"<<endl;
        }
        ~Relatorio(){
            cout<<"O Relatório de Eventos foi excluído com sucesso"<<endl;
        }
        void display(){
            for(Date d: date){
                cout<<"eventos ocorridos"<<endl;
                cout<<d<<endl;
            }
        }
        void make(Date d){
            cout<<"iterator date"<<endl;
            vector<Date>::iterator itr=date.begin();
            while(itr!=date.end()){
                if(date[itr-date.begin()]==d){
                    break;
                }
                itr++;
            }
            cout<<"ok"<<endl;  
            if(itr!=date.end()) date.push_back(d);
        }
};