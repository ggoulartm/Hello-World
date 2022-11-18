class CanMsg{
	byte n;
	int adress[n];
	byte data[8*n];
	list history(byte);
	public:
		CanMsg();
		virtual void readMsg();
		virtual void getMsg();
		virtual void saveMsg();
		virtual void display();
};

classe BMS: public CanMsg{
	unsigned char Power;
	byte Warning;
	byte Version_BMS;
	byte DeltaVcell;
	public:
		BMS(){
			address=0x186455F4;
		}
		void getMsg(){
			Power = data[0]|(data[1]<<8);   
	    		Warning = data[3]
       			DeltaVcell = data[4]|(data[5]<<8);
		        Version_BMS = data[6]|(data[7]<<8);
		        display();
		}
		void readMsg(byte* Buffer){
			data=Buffer;
		}
		void saveMsg(){
			history.push_back(data);
		}
		void display(){
			print(data);
			if(Warning ==1 || Warning == 2) print("overTemperature);
			if(Warning == 4 || Warning == 8) print("overCurrent");
			if(Warning == 16) print("Charging");
			if(Warning == 32) print("Discharging");
			if(Warning == 64) print("UnderVoltage");
			if(Warning == 128) print("OverVoltage");
		}
};

class BMS_Generic: public CanMsg{
	unsigned char SoC;
	unsigned char Vpack;
	unsigned char Current[2];
	public:
		BMS_Generic(){
			adress = 0x186555F4;
			n=8;
		}
		void getMsg(){
			Vpack= data[0]|(data[1]<<8);   
	    		Current1= data[2]|(data[3]<<8);
       			Current2= data[4]|(data[5]<<8);
		        SoC= data[6]|(data[7]<<8);
		}
		void readMsg(byte* Buffer){
			data=Buffer;
		}
		void saveMsg(){
			history.push_back(data);
		}
		void display(){
			print(data);
		}
};

class BMS_Temperature: public CanMsg{
	int adress1;
	int adress2;
	unsigned char temp[8];
	public:
		BMS_Temperature(){
			adress1 = 0x186755F4;
			adress2 = 0x186955F4;
			n=16;
			
		}
		void getMsg(){
			temp[0]= data[0]|(data[1]<<8);   
	    		temp[1]= data[2]|(data[3]<<8);
       			temp[2]= data[4]|(data[5]<<8);
		        temp[3]= data[6]|(data[7]<<8);
			
			temp[4]= data[8]|(data[9]<<8);   
	    		temp[5]= data[10]|(data[11]<<8);
       			temp[6]= data[12]|(data[13]<<8);
		        temp[7]= data[14]|(data[15]<<8);

		}
		void readMsg(byte Buffer1; byte Buffer2){
			for(size_t i=0; i<8; i++){
				data[i]=Buffer1[i];
			}
			for(size_t i=0; i<16;i++){
				data[i+8]=Buffer2[i];
			}
		}
		void saveMsg(){
			for(int i: data){
				history.push_back(i);
			}
		}
		void display(){
			print(data);
		}
};

class BMS_Voltage: public CanMsg{
	int adress1;
	int adress2;
	unsigned char volt[8];
	public:
		BMS_Voltage(){
			adress1 = 0x186B55F4;
			adress2 = 0x186C55F4;
			n=16;
			
		}
		void getMsg(){
			volt[0]= data[0]|(data[1]<<8);   
	    		volt[1]= data[2]|(data[3]<<8);
       			volt[2]= data[4]|(data[5]<<8);
		        volt[3]= data[6]|(data[7]<<8);
			
			volt[4]= data[8]|(data[9]<<8);   
	    		volt[5]= data[10]|(data[11]<<8);
       			volt[6]= data[12]|(data[13]<<8);
		        volt[7]= data[14]|(data[15]<<8);

		}
		void readMsg(byte Buffer1; byte Buffer2){
			for(size_t i=0; i<8; i++){
				data[i]=Buffer1[i];
			}
			for(size_t i=0; i<16;i++){
				data[i+8]=Buffer2[i];
			}
		}
		void saveMsg(){
			for(int i: data){
				history.push_back(i);
			}
		}
		void display(){
			print(data);
		}
};
