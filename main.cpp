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

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
