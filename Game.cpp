#include <iostream>
#include <vector>
#include <ctime>
#include <memory.h>
#include<memory>

using namespace std;

class Unit {
protected:
    int HP;
    int Attack;
    int Chance;
    int Defence;
    string Char;
    string name;
    int position;

public:
    int GetAttack() {
        return Attack;
    }
    int GetHP() {
        return HP;
    }
    int getposition() {
        return position;
    }
    void setposition(int a) {
        position = a;
    }
    void SetHP(int a) {
        HP = a;
    }
    void SetAttack(int a) {
        Attack = a;
    }
    void SetName(string Name) {
        name = Name;
    }
    void SetDeffence(int a) {
        Defence = a;
    }
    void SetChar(string char1) {
        Char = char1;
    }
    int GetDeffence() {
        return Defence;
    }
    int GetChance() {
        return Chance;
    }
    string GetName() {
        return name;
    }
    string GetChar() {
        return Char;
    }
    void SetChance(int a) {
        Chance = a;
    }
    void GetInfo() {
        cout << "  Name : " << GetName();
        cout << "Type : " << GetChar() << "    HP : " << GetHP();
        cout << "   Attack : " << GetAttack() << "  Defence : " << GetDeffence();
        cout << " Chance : " << GetChance();
    }
    virtual void defend(vector<shared_ptr<Unit>>& b, vector<shared_ptr<Unit>>& a, int actualdmg, string team2, string team, int position) {
        int temphp;
        temphp = GetHP();
        temphp = temphp - actualdmg;
        SetHP(temphp);
    }
    virtual void attack(vector<shared_ptr<Unit>>& a, vector<shared_ptr<Unit>>& b, string team, string team2) {
        int target;
        cout << GetName() << " will attack! Select an opponent from " << team << " to attack :";
        cin >> target;
        cout << endl;
        target -= 1;
        cout << endl;
        double actualdmg;
        actualdmg = (double)Attack - ((double)Attack * 1 / (1 + (double)b[target]->GetDeffence()));
        cout << Char << " " << name << " attack to:" << b[target]->GetChar() << " " << b[target]->GetName();
        if (rand() % 100 <= Chance) {
            cout << "I have the chance..." << endl;
            actualdmg = 2 * actualdmg;
        }
        defend(b, a, actualdmg, team2, team, getposition());
    }
};
class Defender : public Unit {
public:
    Defender(string Name) {
        name = Name;
        Char = "Defender";
        HP = rand() % (600 - 300 + 1) + 300;
        Attack = rand() % (35 - 15 + 1) + 15;
        Defence = rand() % (70 - 50 + 1) + 50;
        Chance = rand() % (13 - 10 + 1) + 10;
    }
    void defend(vector<shared_ptr<Unit>>& b, vector<shared_ptr<Unit>>& a, int actualdmg, string team2, string team, int position) {
        int temphp;
        temphp = GetHP();
        temphp = temphp - actualdmg;
        SetHP(temphp);
        if (rand() % 100 < Chance) {
            cout << GetName() << " used the special ability and struck  " << a[position]->GetName() << " back!";
            int temphp;
            double actualdmg;
            actualdmg = Attack - (Attack * 1 / (1 + a[position]->GetDeffence()));
            cout << GetName() << " " << name << " attack to:" << " " << a[position]->GetName();
            cout << " Damage : " << (int)actualdmg;
            cout << endl;
            a[position]->defend(a, b, actualdmg, team2, team, getposition());
        }
    }
    void attack(vector<shared_ptr<Unit>>& a, vector<shared_ptr<Unit>>& b, string team, string team2) {
        int target;

        cout << GetName() << " will attack! Select an opponent from " << team << " to attack :";
        cin >> target;
        target -= 1;
        cout << endl;
        int temphp;
        double actualdmg;
        actualdmg = (double)Attack - ((double)Attack * 1 / (1 + (double)b[target]->GetDeffence()));
        cout << GetName() << " " << name << " attack to: " << " " << b[target]->GetName();
        cout << " Damage : " << (int)actualdmg;
        cout << endl;
        b[target]->defend(b, a, actualdmg, team2, team, getposition());
    }
};
class Warrior : public Unit {
public:

    Warrior(string Name) {
        name = Name;
        Char = "Warrior";
        HP = rand() % (250 - 100 + 1) + 100;
        Attack = rand() % (50 - 30 + 1) + 30;
        Defence = rand() % (30 - 20 + 1) + 20;
        Chance = rand() % (16 - 12 + 1) + 12;
    }
    void GetInfo() {
        cout << "Name..:" << name << endl;
        cout << "HP..:" << HP;
    }

    void attack(vector<shared_ptr<Unit>>& a, vector<shared_ptr<Unit>>& b, string team, string team2) {
        int target;
        cout << GetName() << " will attack! Select an opponent from " << team << " to attack :";
        cin >> target;
        target -= 1;
        cout << endl;
        double actualdmg;
        actualdmg = (double)Attack - ((double)Attack * 1 / (1 + (double)b[target]->GetDeffence()));
        if (rand() % 100 <= Chance) {
            cout << "I have the chance..." << endl;
            actualdmg = 2 * actualdmg;
        }
        cout << GetName() << " " << name << " attack to:" << " " << b[target]->GetName();
        cout << " Damage : " << (int)actualdmg;
        cout << endl;
        b[target]->defend(b, a, actualdmg, team2, team, getposition());
    }
    void defend(vector<shared_ptr<Unit>>& b, vector<shared_ptr<Unit>>& a, int actualdmg, int target, string team2, string team, int position) {
        int temphp;
        temphp = b[target]->GetHP();
        temphp = temphp - actualdmg;
        b[target]->SetHP(temphp);
    }
};
class Wizard :public Unit {
public:
    Wizard(string Name) {
        name = Name;
        Char = "Wizard";
        HP = rand() % (200 - 90 + 1) + 90;
        Attack = rand() % (30 - 10 + 1) + 10;
        Defence = rand() % (25 - 15 + 1) + 15;
        Chance = rand() % (16 - 12 + 1) + 12;
    }
    void GetInfo() {
        cout << "HP..:" << "  ";
    }
    void attack(vector<shared_ptr<Unit>>& a, vector<shared_ptr<Unit>>& b, string team, string team2) {
        int target;

        cout << GetName() << " will attack! Select an opponent from " << team << " to attack :";
        cin >> target;
        target -= 1;
        cout << endl;
        double actualdmg;
        actualdmg = (double)Attack - ((double)Attack * 1 / (1 + (double)b[target]->GetDeffence()));
        cout << GetName() << " " << name << " attack to:" << " " << b[target]->GetName();
        cout << " Damage : " << (int)actualdmg;
        cout << endl;
        b[target]->defend(b, a, actualdmg, team2, team, getposition());
        if (rand() % 100 <= Chance) {
            int target2;

            cout << GetName() << " used the special ability!!!   " << endl;
            cout << GetName() << " will attack! Select an opponent from " << team << " to attack :";
            cin >> target2;
            target2 -= 1;
            if (target == target2) {
                cout << GetName() << " will attack! Select an opponent from " << team << " to attack :";
                cin >> target2;
                target2 -= 1;
            }
            actualdmg = Attack - (Attack * 1 / (1 + b[target2]->GetDeffence()));
            cout << GetName() << " " << name << " attack to:" << " " << b[target2]->GetName();
            cout << " Damage : " << (int)actualdmg;
            cout << endl;
            b[target]->defend(b, a, actualdmg, team2, team, getposition());
        }

    }
    void defend(vector<shared_ptr<Unit>>& b, vector<shared_ptr<Unit>>& a, int actualdmg, int target, string team2, string team, int position) {
        int temphp;
        temphp = b[target]->GetHP();
        temphp = temphp - actualdmg;
        b[target]->SetHP(temphp);
    }
};
class   Healer : public Unit {
public:
    Healer(string Name) {
        name = Name;
        Char = "Healer";
        HP = rand() % (250 - 100 + 1) + 100;
        Attack = rand() % (30 - 10 + 1) + 10;
        Defence = rand() % (30 - 15 + 1) + 15;
        Chance = rand() % (23 - 15 + 1) + 15;
    }
    void GetInfo() {
        cout << "HP..:" << "  ";
    }
    void defend(vector<shared_ptr<Unit>>& b, vector<shared_ptr<Unit>>& a, int actualdmg, int target, string team2, string team) {
        int temphp;
        temphp = b[target]->GetHP();
        temphp = temphp - actualdmg;
        b[target]->SetHP(temphp);
    }
    void attack(vector<shared_ptr<Unit>>& a, vector<shared_ptr<Unit>>& b, string team, string team2) {
        int target;
        cout << GetName() << " will attack! Select an opponent from " << team << " to attack :";
        cin >> target;
        target -= 1;
        double actualdmg;
        actualdmg = (double)Attack - ((double)Attack * 1 / (1 + (double)b[target]->GetDeffence()));
        cout << GetName() << " " << name << " attack to:" << " " << b[target]->GetName();
        if (rand() % 100 <= Chance) {
            for (int i = 0; i < a.size(); i++) {
                int temp = a[i]->GetHP() + 20;
                a[i]->SetHP(temp);
                cout << GetChar() << " used the special ability and healed " << a[i]->GetChar() << endl;
            }
        }
        defend(b, a, actualdmg, target, team2, team);
    }
};
class Arena :public Unit {
protected:
    int chancearena;
    string arenaname;
public:
    string getarenaname() {
        return arenaname;
    }
    virtual void arenaimpact(vector<shared_ptr<Unit>>& team1, vector<shared_ptr<Unit>>& team2, vector<shared_ptr<Unit>>& team1dead, vector<shared_ptr<Unit>>& team2dead) {
        cout << "----------------------------------------------------------------------" << endl;
        cout << "The game will be played on " << getarenaname() << "Arena" << endl;
    }
};
class Firespin :public Arena {
public:
    void arena() {
        cout << getarenaname() << endl;
    }
    void arenaimpact(vector<shared_ptr<Unit>>& team1, vector<shared_ptr<Unit>>& team2, vector<shared_ptr<Unit>>& team1dead, vector<shared_ptr<Unit>>& team2dead) {
        if (rand() & 100 < 10) {

            for (int i = 0; i < team1.size(); i++) {
                int tempattack = 20;
                int temphp;
                temphp = team1[i]->GetHP() - 20;
                team1[i]->SetHP(temphp);
            }
            for (int i = 0; i < team2.size(); i++) {
                int tempattack = 20;
                int temphp;
                temphp = team2[i]->GetHP() - 20;
                team2[i]->SetHP(temphp);
            }
            cout << "Arena performed its effect" << endl;
        }
    }

};
class Aurora :public Arena {
    void arenaimpact(vector<shared_ptr<Unit>>& team1, vector<shared_ptr<Unit>>& team2, vector<shared_ptr<Unit>>& team1dead, vector<shared_ptr<Unit>>& team2dead) {
        if (rand() & 100 < 10) {

            for (int i = 0; i < team1.size(); i++) {
                int temphp;
                temphp = team1[i]->GetHP() + 10;
                team1[i]->SetHP(temphp);
            }
            for (int i = 0; i < team2.size(); i++) {
                int temphp;
                temphp = team2[i]->GetHP() + 10;
                team2[i]->SetHP(temphp);
            }
            cout << "Arena performed its effect" << endl;
        }
    }
};
class Valhalla :public Arena {

public:
    void arena() {
        cout << getarenaname() << endl;
    }
    void arenaimpact(vector<shared_ptr<Unit>>& team1, vector<shared_ptr<Unit>>& team2, vector<shared_ptr<Unit>>& team1dead, vector<shared_ptr<Unit>>& team2dead) {
        if (rand() % 100 < 5) {
            for (int i = team1dead.size() - 1; i >= 0; i--) {
                team1.push_back(team1dead[i]);
                vector<shared_ptr<Unit>>::iterator it = team1dead.end();
                team1dead.erase(it);
            }
            for (int i = team2dead.size() - 1; i >= 0; i--) {
                team2.push_back(team2dead[i]);
                vector<shared_ptr<Unit>>::iterator it = team2dead.end();
                team2dead.erase(it);
            }
        }
    }
};
class Casual :public Arena {
public:
    void arena() {
        cout << getarenaname() << endl;
    }
    void arenaimpact(vector<shared_ptr<Unit>>& team1, vector<shared_ptr<Unit>>& team2, vector<shared_ptr<Unit>>& team1dead, vector<shared_ptr<Unit>>& team2dead) {
        if (rand() % 100 < 0) {
            cout << endl;
        }
    }
};
void choosearena(shared_ptr<Arena>& temp) {
    int choose;
    cout << "---------------------------------Arena Choose--------------------------------- " << endl;
    cout << "1 => Name : Casual     Impact:Anythink " << endl;
    cout << "2 => Name : FireSpin   Impact:has a chance(10%) to attack (20 pure damage) each unit on the field after each round." << endl;
    cout << "3 => Name : Valhalla   Impact:has a chance(5%) to brings the death unit back to the field with 10% of HP. " << endl;
    cout << "4 => Name : Aurora     Impact:has a chance(10%) to heal(10 healing point) each unit on the field after each round." << endl;
    cout << "Choose which arena you will play : " << endl;
    cin >> choose;
    if (choose == 1) {
        shared_ptr<Casual>arena(new Casual);
        temp = arena;
    }
    else if (choose == 2) {
        shared_ptr<Firespin> arena(new Firespin);
        temp = arena;
    }
    else if (choose == 3) {
        shared_ptr<Valhalla> arena(new Valhalla);
        temp = arena;
    }
    else if (choose == 4) {
        shared_ptr<Aurora> arena(new Aurora);
        temp = arena;
    }

}
void Start(vector<shared_ptr<Unit>>& Startpoint) {
    shared_ptr<Warrior> war1(new Warrior("Akali"));
    Startpoint.push_back(war1);
    shared_ptr<Warrior> war2(new Warrior("Chadwick"));
    Startpoint.push_back(war2);
    shared_ptr<Warrior> war3(new Warrior("Gunther"));
    Startpoint.push_back(war3);
    shared_ptr<Warrior> war4(new Warrior("Kenway"));
    Startpoint.push_back(war4);
    shared_ptr<Defender>def1(new Defender("Iceman"));
    Startpoint.push_back(def1);
    shared_ptr<Defender>def2(new Defender("Moondragon"));
    Startpoint.push_back(def2);
    shared_ptr<Defender>def3(new Defender("Beast"));
    Startpoint.push_back(def3);
    shared_ptr<Defender>def4(new Defender("Interloper"));
    Startpoint.push_back(def4);
    shared_ptr<Wizard>wiz1(new Wizard("Gandalf"));
    Startpoint.push_back(wiz1);
    shared_ptr<Wizard>wiz2(new Wizard("Yoda"));
    Startpoint.push_back(wiz2);
    shared_ptr<Wizard>wiz3(new Wizard("Merlin"));
    Startpoint.push_back(wiz3);
    shared_ptr<Wizard>wiz4(new Wizard("Prospero"));
    Startpoint.push_back(wiz4);
    shared_ptr<Healer> heal1(new Healer("Medicine"));
    Startpoint.push_back(heal1);
    shared_ptr<Healer> heal2(new Healer("Auriel"));
    Startpoint.push_back(heal2);
    shared_ptr<Healer> heal3(new Healer("Deckard"));
    Startpoint.push_back(heal3);
    shared_ptr<Healer> heal4(new Healer("Uther"));
    Startpoint.push_back(heal4);
}
void selectTeam(vector<shared_ptr<Unit>>& Startpoint, vector<shared_ptr<Unit>>& team1, vector<shared_ptr<Unit>>& team2) {
    for (int i = 0; i < Startpoint.size(); i++) {
        cout << i + 1 << " => ";
        Startpoint[i]->GetInfo();
        cout << endl;
    }
    cout << "----------------------------------------------------------------------" << endl;
    int choose;
    cout << "Please select first team : ";
    for (int i = 0; i < 4; i++) {
        cin >> choose;
        choose -= 1;
        team1.push_back(Startpoint[choose]);
        team1[i]->setposition(i);
    }
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Please select second team : ";
    for (int i = 0; i < 4; i++) {
        cin >> choose;
        choose -= 1;
        team2.push_back(Startpoint[choose]);
        team2[i]->setposition(i);
    }
    cout << "----------------------------------------------------------------------" << endl;
}
void ChooseTeam(vector<shared_ptr<Unit>>& team1, vector<shared_ptr<Unit>>& team2, string& name1, string& name2) {
    if (rand() % 100 < 50) {
        cout << "Team 1 starts the battle !!!" << endl;
        name1 = "TEAM 1";
        name2 = "TEAM 2";
    }
    else {
        team1.swap(team2);
        cout << "Team 2 starts the battle !!!" << endl;
        name1 = "TEAM 2";
        name2 = "TEAM 1";
    }
}
void startmenu(shared_ptr<Arena> arena, vector<shared_ptr<Unit>> team1, vector<shared_ptr<Unit>> team2) {
    cout << "The battle will be played on " << arena->getarenaname() << " Arena" << endl;
    cout << "Team 1 with attack order :" << endl;
    for (int i = 0; i < team1.size(); i++) {
        cout << i + 1 << " => ";
        team1[i]->GetInfo();
        cout << endl;
    }
    cout << "Team 2 with attack order :" << endl;
    for (int i = 0; i < team1.size(); i++) {
        cout << i + 1 << " => ";
        team1[i]->GetInfo();
        cout << endl;
    }

}
void dead(vector<shared_ptr<Unit>>& team, vector<shared_ptr<Unit>>& teamdead) {
    for (int i = 0; i < team.size(); i++) {
        if (team[i]->GetHP() <= 0) {
            cout << team[i]->GetName() << " dead" << endl;
            teamdead.push_back(team[i]);
            vector<shared_ptr<Unit>>::iterator it = team.begin() + i;
            team.erase(it);
            if (team.empty()) {
                break;
            }
            for (i; i < team.size() - 1; i++) {
                team[i]->setposition(i - 1);
            }
        }
    }
}
void info(vector<shared_ptr<Unit>>& team1, vector<shared_ptr<Unit>>& team2, string name1, string name2) {
    cout << name1 << " :" << endl;
    for (int i = 0; i < team1.size(); i++) {
        cout << i + 1 << " => ";
        team1[i]->GetInfo();
        cout << endl;
    }
    cout << name2 << " :" << endl;
    for (int i = 0; i < team2.size(); i++) {
        cout << i + 1 << " => ";
        team2[i]->GetInfo();
        cout << endl;
    }
}
int main() {
    srand(time(0));
    vector<shared_ptr<Unit>> Startpoint;
    vector<shared_ptr<Unit>> team1;
    vector<shared_ptr<Unit>> team2;
    vector<shared_ptr<Unit>> team1dead;
    vector<shared_ptr<Unit>> team2dead;
    shared_ptr<Arena> arena;
    string team1name;
    string team2name;
    Start(Startpoint);
    selectTeam(Startpoint, team1, team2);
    choosearena(arena);
    startmenu(arena, team2, team2);
    cout << "---------------------------------------------BATTLE STARTS---------------------------------------------" << endl;
    ChooseTeam(team1, team2, team1name, team2name);
    int round = 0;
    int team1order = 0;
    int team2order = 0;
    do {
        round++;
        cout << "================ROUND " << round << "================" << endl;
        info(team1, team2, team1name, team2name);

        team1[team1order]->attack(team1, team2, team1name, team2name);
        dead(team2, team2dead);
        team1order++;

        cout << "111" << endl;
        if (team2.empty()) {
            cout << team1name << " WINS!!!" << endl;
            for (int i = 0; i < team1.size(); i++) {
                cout << i + 1 << " => ";
                team1[i]->GetInfo();
                cout << endl;
            }
            break;
        }
        if (team2order >= team2.size()) {
            team2order = 0;
        }
        team2[team2order]->attack(team2, team1, team2name, team1name);
        dead(team1, team1dead);

        team2order++;

        cout << "222" << endl;

        if (team1.empty()) {
            cout << team2name << " WINS!!!" << endl;
            for (int i = 0; i < team2.size(); i++) {
                cout << (i + 1) << " => ";
                team2[i]->GetInfo();
                cout << endl;
            }
            break;
        }
        if (team1order >= team1.size()) {
            team1order = 0;
        }
        arena->arenaimpact(team1, team2, team1dead, team2dead);

    } while (!team1.empty() || team2.empty());
}


