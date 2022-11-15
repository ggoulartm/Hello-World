#include <list>

class CanMsg {
    int adress;
    unsigned char msg[8]{};
    public:
    void setAdress(int id);
    virtual void readMsg();
    virtual void displayMsg();
    virtual void saveMsg();
};

class Voltage: public CanMsg{
    public:
    Voltage();
    void readMsg();
    virtual void saveMsg();
    void displayMsg();
};

class Temperature: public CanMsg{
    public:
    Temperature();
    void readMsg();
    void displayMsg();
    virtual void saveMsg();
};

class SoC: public CanMsg{
    public:
    SoC();
    void readMsg();
    void display();
};