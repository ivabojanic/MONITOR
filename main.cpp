#include <iostream>

using namespace std;

enum ScreenStates {ssON,ssOFF};

class Screen
{
private:
    ScreenStates state;
    int brightness;
public:
    Screen() {state = ssOFF; brightness = 0;}

    bool incB()
    {
        if(state == ssON)
        {
            brightness+=2;
            if(brightness>20)
            {
                brightness = 20;
            }
            return true;
        }else{
            return false;
        }
    }
     bool decB()
    {
        if(state == ssON)
        {
            brightness-=2;
            if(brightness<0)
            {
                brightness = 1;
            }
            return true;
        }else{
            return false;
        }
    }
    void setState(ScreenStates ss)
    {
        ss = state;
    }
    ScreenStates getState()const
    {
        return state;
    }
    int getBrightness()const
    {
        return brightness;
    }
};

enum MonitorStates {sON,sOFF,sOUT,sTEST,sSTANDBY};

class Monitor
{
private:
    MonitorStates state;
    Screen screen;
public:
    Monitor():screen(){state=sOFF;}

    bool turnOn()
    {
        if(state == sOFF || state == sSTANDBY || state == sOUT)
        {
            state = sON;
            screen.setState(ssON);
            return true;
        }
        else
            return false;
    }
    bool turnOff()
    {
        if(state != sOFF)
        {
            state=sOFF;
            screen.setState(ssOFF);
            return true;
        }
        else
            return false;
    }
    bool turnOut()
    {
        if(state != sOUT)
        {
            state = sOUT;
            screen.setState(ssOFF);
            return true;
        }
        else
            return false;
    }
    bool turnTest()
    {
        if(state == sON)
        {
            state = sTEST;
            screen.setState(ssON);
            return true;
        }
        else
            return false;
    }
    bool turnStandby()
    {
        if(state == sON)
        {
            state = sSTANDBY;
            screen.setState(ssOFF);
            return true;
        }
        else
            return false;
    }
    bool repair()
    {
        if(state == sOUT){
            state = sOFF;
            screen.setState(ssOFF);
            return true;
        }
        else
            return false;
    }

    bool incB(){
        return screen.incB();
    }
    bool decB(){
        return screen.decB();
    }

    MonitorStates getMonitorState()const
    {
        return state;
    }
    int getBrightness()const
    {
        return screen.getBrightness();
    }
    ScreenStates getScreenState()const
    {
        return screen.getState();
    }
};

void printfInfo(const Monitor &m)
{
    cout<<"---------------"<<endl;

      if(m.getScreenState() == ssON)
        cout<<"ON"<<endl;
    else
        cout<<"OFF"<<endl;

    cout<<"---------------"<<endl;

    if(m.getMonitorState() == sON)
        cout<<"ON mode"<<endl;
    else if(m.getMonitorState() == sOFF)
        cout<<"OFF mode"<<endl;
    else if(m.getMonitorState() == sOUT)
        cout<<"OUT mode"<<endl;
    else if(m.getMonitorState()==sTEST)
        cout<<"TEST mode"<<endl;
    else if(m.getMonitorState()==sSTANDBY)
        cout<<"STANDBY mode"<<endl;

    cout<<"---------------"<<endl;

    cout<<" "<<m.getBrightness()<<endl;

    cout<<"---------------"<<endl;
}
int meni()
{
    int op;

    cout<<"1. Turn ON"<<endl;
    cout<<"2. Turn OFF"<<endl;
    cout<<"3. Turn OUT"<<endl;
    cout<<"4. Turn TEST"<<endl;
    cout<<"5. Turn STANDBY"<<endl;
    cout<<"6. Repair"<<endl;
    cout<<"7. Brightness up"<<endl;
    cout<<"8. Brightness down"<<endl;
    cout<<"9. Kraj"<<endl;
    cin>>op;

    return op;
}

int main()
{
    int option;
    Monitor M;
    bool prom;

    do
    {

    option = meni();

    switch(option)
    {
    case 1:
        prom = M.turnOn();
        break;
    case 2:
        prom = M.turnOff();
        break;
    case 3:
        prom = M.turnOut();
        break;
    case 4:
        prom = M.turnTest();
        break;
    case 5:
        prom = M.turnStandby();
        break;
    case 6:
        prom = M.repair();
        break;
    case 7:
        prom = M.incB();
        break;
    case 8:
        prom = M.decB();
        break;
    }
    if (option<1 || option>9)
        cout<<"The option does not exist!"<<endl;
    else if(prom == true)
        printfInfo(M);

    }while(option>=1 && option<=8);

    return 0;
}
