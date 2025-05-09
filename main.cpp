#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

short beep = 0;

string senzor10(char pr){
    pr = pr >> 1; //bit shiftamo desno 1x da pride bit ki ga gledamo na skarjno desno mesto
    if(pr&1){   //preverimo ce je setan
        return "10"; 
    }
    return "";
}
string senzor9(char pr){
    pr = pr << 6;
    pr = pr >> 7;
    if(pr&1){
        return "9";
    }
    return "";
}
string senzor8(char dr){
    dr = dr >> 7;
    if(dr&1){
        return "8";
    }
    return "";
}
string senzor7(char dr){
    dr = dr << 1;
    dr = dr >> 7;
    if(dr&1){
        return "7";
    }
    return "";
}
string senzor6(char dr){
    dr = dr << 2;
    dr = dr >> 7;
    if(dr&1){
        return "6";
    }
    return "";
}
string senzor5(char dr){
    dr = dr << 3;
    dr = dr >> 7;
    if(dr&1){
        return "5";
    }
    return "";
}
string senzor4(char dr){
    dr = dr << 4;
    dr = dr >> 7;
    if(dr&1){
        return "4";
    }
    return "";
}
string senzor3(char dr){
    dr = dr << 5;
    dr = dr >> 7;
    if(dr&1){
        return "3";
    }
    return "";
}
string senzor2(char dr){
    dr = dr << 6;
    dr = dr >> 7;
    if(dr&1){
        return "2";
    }
    return "";
}
string senzor1(char dr){
    dr = dr << 7;
    dr = dr >> 7;
    if(dr&1){
        return "1";
    }
    return "";
}


void send(string a){
    cout << a << endl;
}

string receive(){
    string a;
    cin >> a;
    return a;
}

void beepOnOff(char pr){
    pr = pr >> 7;
    if(pr&1){
        beep++;
        beep%=2; //zamenjamo bip na stanje nasprotno stanju pred menjavo
    }
}

int main(){
    while(1){
        string poslat = "";
        string navodila = receive();
        if(navodila[0]=='`'){  //preverimo podpis
            navodila.erase(navodila.begin());
            char pr = navodila[0]; //razdelimo na 1. in 2. byte
            char dr = navodila[1];
            beepOnOff(pr); 
            poslat += senzor10(pr);
            poslat += senzor9(pr);
            poslat += senzor8(dr);
            poslat += senzor7(dr);
            poslat += senzor6(dr);
            poslat += senzor5(dr);
            poslat += senzor4(dr);
            poslat += senzor3(dr);
            poslat += senzor2(dr);
            poslat += senzor1(dr);
            send(poslat);

        }
        else{
            cout <<"niso nasi podatki \n";
        }
    }
    
}


