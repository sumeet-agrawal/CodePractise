#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    string s = spell->revealScrollName();
    //Spell *sp;
    if(s == ""){
    try {
        //cout<<"Hello";
        Fireball *fb = dynamic_cast<Fireball*>(spell);
        if(fb)
        fb->revealFirepower();
    }catch(exception e){}
    try{
        //cout<<"Hello1";
        Frostbite *fb = dynamic_cast<Frostbite*>(spell);
        if(fb)
        fb->revealFrostpower();
    }catch(exception e){}
    try {
        //cout<<"Hello2";
        Waterbolt *wb = dynamic_cast<Waterbolt*>(spell);
        if(wb)
        wb->revealWaterpower();
    }catch(exception e){}
    try{
        //cout<<"Hello3";
        Thunderstorm *ts = dynamic_cast<Thunderstorm*>(spell);
        if(ts)
        ts->revealThunderpower();
    } catch(exception e){}
    }
    else {
        string str = SpellJournal::journal;
        int LCS[1005][1005] = {0};
        for(int i =1;i<=s.size();i++){
            for(int j=1;j<=str.size();j++){
                if(s[i-1] == str[j-1]){
                    LCS[i][j] = 1 + LCS[i-1][j-1];
                }
                else{
                    LCS[i][j] = LCS[i-1][j] > LCS[i][j-1] ? LCS[i-1][j] : LCS[i][j-1];
                }
            }
        }
        cout<<LCS[s.size()][str.size()]<<endl;
    }    
  /* Enter your code here */

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
