#include <iostream>
using namespace std;

class Estado{
    int saldo;
    public:
		Estado();
		~Estado();
        virtual void inserir();
        void devolver();
        virtual	void get_meet();
        virtual void get_etirps();
};

//a função inserir chama o destrutor do estado atual e o construtor do próximo estado

class SX: public Estado{
	void get_meet(){
	    cout << "Saldo insuficiente." << endl;
	}
	void get_etirps(){
	    cout << "Saldo insuficiente." << endl;
	}
};

class S000: public Estado, public SX{
	public:
	void inserir(int valor);
	S000(){
	    cout<<"O saldo atual é nulo"<<endl;
	};
	~S000();
};
	

class S025: public Estado, public SX{
	public:
	void inserir(int valor);
	S025(){
	    cout<<"O saldo atual é: 25 centavos."<<endl;
	};
	~S025();
};

class S050: public Estado, public SX{
	public:
	void inserir(int valor);
	S050(){
	    cout<<"O saldo atual é: 50 centavos."<<endl;
	};
	~S050();
};

class S075: public Estado, public SX{
	public:
	void inserir(int valor);
	S075(){
	    cout<<"O saldo atual é: 75 centavos."<<endl;
	};
	~S075();
};

class S100: public Estado, public SX{
	public:
	void inserir(int valor);
	S100(){
	    cout<<"O saldo atual é: R$ 1,00"<<endl;
	};
	~S100();
};

class S125: public Estado, public SX{
	public:
	void inserir(int valor);
	S125(){
	    cout<<"O saldo atual é: R$ 1,25"<<endl;
	};
	~S125();
};

class S150: public Estado, public SX{
	public:
	void inserir(int valor);
	S150(){
	    cout<<"O saldo atual é: R$ 1,50"<<endl;
	};
	~S150();
};