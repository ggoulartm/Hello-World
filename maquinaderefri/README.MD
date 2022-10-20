# Projeto de uma FSM de Sistema Embarcado C++ para Máquina de Refrigerante

	A ideia do projeto é desenvolver o sistema da máquina de refrigerante, com duas opções de refrigerante: meet e etirps.

	A interface de usuário diz qual o saldo presente na máquina e há quatro opções de comando para o usuário:
		Inserir moedas nos valores de R$ 0,25; R$ 0,50 ou R$ 1,00
		Devolver o valor total, ou parcial, caso o saldo ultrapasse R$ 1,50
		Pegar Refrigerante Meet
		Pegar Refrigerante Etirps

![Diagrama de Estados](https://github.com/ggoulartm/embeddedSYSTEMS/blob/C++sistemasEmbarcados/maquinaderefri/Diagrama%20de%20Estados.png?raw=true)


## Problemas do Projeto

Na primeira tentativa de implementação do código utilizando polimorfismo e funções virtuais, tivemos a ideia de utilizar classes para simular os estados. 
Ou seja, toda vez que a máquina mudasse de estado, seria chamado o destrutor de classe e declarada a variável state no estado atual.

No entanto, o problema desse tipo de implementação é que ao declarar a nova instância da classe dentro do método da outra classe, criamos um objeto local, diferente do objeto global state.


