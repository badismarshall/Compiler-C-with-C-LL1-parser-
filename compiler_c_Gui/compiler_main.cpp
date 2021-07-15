#include <iostream>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include"compiler_main.h"
using namespace std;
struct code {
    string mot;
    string type;
    int lines;  // c'est le numero de ligne
};
code* Tabcode = new code[1000]; // vecteur de code
bool ereur = false;
string TC = "";
int par=0;
void S(), Z(), program(), vardefinition(), functiondefinition(), vardef(), type(), var(), varextra(), idnum(), funcdef(), parmlist();
void parm(), parmextra(), body(), statlist(), aorf(), assignorfunc(), funccall(), inparamlist(), inparms(), assignstat(), expression();
void exp1(), exp2(), exp(), factor(), judgement(), relop(), ifelsestate(), elsestat(), forstat(), assignstatfor(), whilestate();*/

int Tab_analyse[34][50];
class mot_cle_auto
{
private:
    int mot_cle[100][50];
public:
    mot_cle_auto() { remplire(); }
    void remplire();
    bool is_mot_cle(string s);

};
void mot_cle_auto::remplire()
{
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 50; j++)
            mot_cle[i][j] = -1;

    mot_cle[0]['b' - 'a'] = 1;
    mot_cle[0]['v' - 'a'] = 7;
    mot_cle[0]['f' - 'a'] = 28;
    mot_cle[0]['e' - 'a'] = 23;
    mot_cle[0]['c' - 'a'] = 13;
    mot_cle[0]['r' - 'a'] = 38;
    mot_cle[0]['s' - 'a'] = 33;
    mot_cle[0]['i' - 'a'] = 26;
    mot_cle[0]['w' - 'a'] = 10;
    mot_cle[1]['o' - 'a'] = 2;
    mot_cle[1]['r' - 'a'] = 4;
    mot_cle[2]['o' - 'a'] = 3;
    mot_cle[3]['l' - 'a'] = 43;
    mot_cle[4]['e' - 'a'] = 5;
    mot_cle[5]['a' - 'a'] = 6;
    mot_cle[6]['k' - 'a'] = 43;
    mot_cle[7]['o' - 'a'] = 8;
    mot_cle[8]['i' - 'a'] = 9;
    mot_cle[9]['d' - 'a'] = 43;
    mot_cle[10]['h' - 'a'] = 11;
    mot_cle[11]['i' - 'a'] = 12;
    mot_cle[12]['l' - 'a'] = 22;
    mot_cle[22]['e' - 'a'] = 43;
    mot_cle[13]['o' - 'a'] = 14;
    mot_cle[14]['n' - 'a'] = 15;
    mot_cle[15]['t' - 'a'] = 16;
    mot_cle[16]['i' - 'a'] = 17;
    mot_cle[17]['n' - 'a'] = 18;
    mot_cle[18]['u' - 'a'] = 19;
    mot_cle[19]['e' - 'a'] = 43;
    mot_cle[13]['h' - 'a'] = 20;
    mot_cle[20]['a' - 'a'] = 21;
    mot_cle[21]['r' - 'a'] = 43;
    mot_cle[23]['l' - 'a'] = 24;
    mot_cle[24]['s' - 'a'] = 25;
    mot_cle[25]['e' - 'a'] = 43;
    mot_cle[26]['n' - 'a'] = 27;
    mot_cle[27]['t' - 'a'] = 43;
    mot_cle[28]['o' - 'a'] = 32;
    mot_cle[28]['l' - 'a'] = 29;
    mot_cle[29]['o' - 'a'] = 30;
    mot_cle[30]['a' - 'a'] = 31;
    mot_cle[31]['t' - 'a'] = 43;
    mot_cle[32]['r' - 'a'] = 43;
    mot_cle[33]['t' - 'a'] = 34;
    mot_cle[34]['r' - 'a'] = 35;
    mot_cle[35]['i' - 'a'] = 36;
    mot_cle[36]['n' - 'a'] = 37;
    mot_cle[37]['g' - 'a'] = 43;
    mot_cle[38]['e' - 'a'] = 39;
    mot_cle[39]['t' - 'a'] = 40;
    mot_cle[40]['u' - 'a'] = 41;
    mot_cle[41]['r' - 'a'] = 42;
    mot_cle[42]['n' - 'a'] = 43;



}
bool mot_cle_auto::is_mot_cle(string s)
{
    int i = 0;
    string tc;
    tc = s[0];
    int Ec = 0;
    while (i<s.size() && Ec!=-1)
    {
        Ec = mot_cle[Ec][s[i] - 'a'];
        i++;
    }
    if (Ec == -1 || Ec!=43)
        return false;
    return true;
}
bool isseperateur(string s)
{
    if (s == "(") return true;
    else if (s == ")")return true;
    else if (s == "]")return true;
    else if (s == "[")return true;
    else if (s == ">")return true;
    else if (s == "<")return true;
    else if (s == "=")return true;
    else if (s == "==") return true;
    else if (s == "!=")return true;
    else if (s == "<=")return true;
    else if (s == ">=")return true;
    else if (s == "+=")return true;
    else if (s == "-=")return true;
    else if (s == "/=")return true;
    else if (s == "*=")return true;
    else if (s == "%")return true;
    else if (s == "+")return true;
    else if (s == "-")return true;
    else if (s == "*")return true;
    else if (s == "/")return true;
    else if (s == "&&")return true;
    else if (s == "||")return true;
    else if (s == ";")return true;
    else if (s == ".")return true;
    else if (s == "{")return true;
    else if (s == "}")return true;
    else if (s == ",")return true;
    else if (s == "!")return true;
    else return false;
}
bool is_commentaire(string s) {
    if (s == "//")
        return true;
    else
        return false;
}
bool est_mot(string s) {

    if ((s[0] >= 'a' && s[0] <= 'z') || (s[0]>='A' && s[0]<='Z'))
    {
        for (int i = 1; i < s.size(); i++)
        {
            if ((s[i]<'a' || s[i]>'z') && (s[i]<'A' || s[i]>'Z') && s[i] != '_' && (s[i]<'0' || s[i]>'9'))
                return false;
        }
        return true;
    }
    return false;
}
code* openfile(string s)   // return Null si il ya une erreur lexicale
{
    string line;
    mot_cle_auto MOT_CLE;
    for (int i = 0; i < 1000; i++)
        Tabcode[i].lines = 0;
    fstream f;
    f.open(s);
    if (f.is_open())
    {

        int count_line = 1; // conteur des lignes
        int i = 0;  // index denas le vecteur de code
        while (getline(f, line)) {
            istringstream iss(line);
            string word;
        while (iss >> word)
        {
            int index_of_word = 0;
            while (index_of_word < word.size())
            {
                string TC;
                TC = word[index_of_word];
                if (isseperateur(TC))
                {
                    string Tc_1;
                    if ((index_of_word + 1) < word.size())
                    {
                        Tc_1 = word[index_of_word + 1];
                        string Tc_2;
                        Tc_2 = TC + Tc_1;
                        if (isseperateur(Tc_1))
                        {
                            if (Tc_2 == "//")
                            {
                                break;
                            }
                            if (Tc_2 == "<=" || Tc_2 == "&&" || Tc_2 == "||" || Tc_2 == "<=" || Tc_2 == ">=" || Tc_2 == "+=" || Tc_2 == "-=" || Tc_2 == "*=" || Tc_2 == "/=" || Tc_2 == "==")
                            {
                                Tabcode[i].lines = count_line;
                                Tabcode[i].mot = Tc_2;
                                Tabcode[i].type = "separateur";
                                i++;
                                index_of_word = index_of_word + 2;
                                continue;
                            }
                        }
                    }
                    Tabcode[i].lines = count_line;
                    Tabcode[i].mot = TC;
                    Tabcode[i].type = "separateur";
                    index_of_word = index_of_word + 1;
                    i++;
                }
                else
                {
                    char tc_char = TC[0];
                    if (isdigit(tc_char))
                    {
                        string motconstruit;
                        while ((index_of_word < word.size()) && isdigit(word[index_of_word]))
                        {
                            motconstruit = motconstruit + word[index_of_word];
                            index_of_word++;
                        }
                        if (index_of_word < word.size())
                        {
                            string Tc_1;
                            Tc_1 = word[index_of_word];
                            if (isseperateur(Tc_1))
                            {
                                string Tc_2;
                                if (index_of_word + 1 < word.size())
                                {
                                    Tc_2 = word[index_of_word + 1];
                                    Tc_1 = Tc_1 + Tc_2;
                                    if (isseperateur(Tc_1))
                                    {
                                        Tabcode[i].lines = count_line;
                                        Tabcode[i].mot = motconstruit;
                                        Tabcode[i].type = "constant";
                                        i++;
                                        continue;
                                    }
                                }
                                Tabcode[i].lines = count_line;
                                Tabcode[i].mot = motconstruit;
                                Tabcode[i].type = "constant";
                                i++;
                                continue;
                            }
                            else
                            {
                                cout << " il y a une ereur lexicale dans la ligne : " << count_line;
                                return NULL;
                            }
                        }
                        Tabcode[i].lines = count_line;
                        Tabcode[i].mot = motconstruit;
                        Tabcode[i].type = "constant";
                        i++;
                    }
                    else
                    {
                        string motconstruit;
                        while (index_of_word < word.size() && !isseperateur(TC))
                        {
                            motconstruit = motconstruit + word[index_of_word];
                            if (index_of_word < word.size())
                                TC = word[index_of_word + 1];
                            index_of_word++;
                        }
                        if(est_mot(motconstruit))
                        {
                            if (MOT_CLE.is_mot_cle(motconstruit))
                            {
                                Tabcode[i].mot = motconstruit;
                                Tabcode[i].type = "motcle";
                                Tabcode[i].lines = count_line;
                                i++;
                            }
                            else
                            {
                                Tabcode[i].mot = motconstruit;
                                Tabcode[i].type = "identificateur";
                                Tabcode[i].lines = count_line;
                                i++;
                            }
                        }
                        else
                        {
                            cout << "il a une ereur lexicale dans la ligne : " << count_line << " dans le mot " << motconstruit << endl;
                            return NULL;
                        }
                    }
                }
            }
        }
            count_line++;
    }
        Tabcode[i].mot = "$";
        Tabcode[i].type = "stop";
        Tabcode[i].lines = count_line;
        i = 0;
        while (Tabcode[i].lines != 0)
        {
            cout << Tabcode[i].mot << " "<<Tabcode[i].type <<" "<<Tabcode[i].lines<<endl;
            i++;
        }
        return Tabcode;
    }
    else
    {
        cout << "il a une erreur d'ouverture de fichier";
        return NULL;
    }

}
void Z()
{
    TC = Tabcode[0].mot;
    S();
    if (!ereur)
    {
        if (TC == "$")
            cout << "chaine accepter" << endl << " Analyse syntaxsique teminer" << endl;
        else
            cout << "chaine non accepter";
    }
    else
    {
        cout << "chaine non accepter";
    }
}
void S()
{
    program();
}
void program()
{
    vardefinition();
    if (!ereur)
    {
        if (TC == "main" || TC == "int")
        {
            par++;
            TC = Tabcode[par].mot;
            if (TC == "(")
            {
                par++;
                TC = Tabcode[par].mot;
                if (TC == ")")
                {
                    par++;
                    TC = Tabcode[par].mot;
                    if (TC == "{")
                    {
                        par++;
                        TC = Tabcode[par].mot;
                        body();
                        if (!ereur)
                        {
                            if (TC == "}")
                            {
                                par++;
                                TC = Tabcode[par].mot;
                                functiondefinition();
                            }
                            else
                            {
                                ereur = true;
                                cout << "manque de } " << "dans la ligne " << Tabcode[par].lines << endl;
                            }
                        }
                    }
                    else
                    {
                        ereur = true;
                        cout << "erreur manque de { dans la  ligne : " << Tabcode[par].lines << endl;
                    }
                }
                else
                {
                    ereur = true;
                    cout << "manque de ) " << "dans la ligne " << Tabcode[par].lines << endl;
                }
            }
            else
            {
                ereur = true;
                cout << "manque de ( " << "dans la ligne " << Tabcode[par].lines << endl;
            }
        }
        else
        {
            ereur = true;
            cout << "manque de fonction d'entree main " << "dans la ligne" << Tabcode[par].lines << endl;
        }
    }
}
void vardefinition()
{
    if (!ereur)
    {
        code* p;
        p = Tabcode + par;
        if (p->mot == "int" || p->mot == "float" || p->mot == "char" || p->mot == "bool")
        {
            vardef();
            if (!ereur)
            {
                vardefinition();
            }
        }
    }
}
void functiondefinition()
{
    if (!ereur)
    {
        code* p;
        p = Tabcode + par;
        if (p->type == "identificateur")
        {
            funcdef();
            if (!ereur)
            {
                functiondefinition();
            }
        }
    }
}
void vardef()
{
    if (!ereur)
    {
        type();
        if (!ereur)
        {
            var();
            if (!ereur)
            {
                if (TC == ";")
                {
                    par++;
                    TC = Tabcode[par].mot;
                }
                else
                {
                    ereur = true;
                    cout << "erreur manque de ; dans la ligne " << Tabcode[par].lines << endl;
                }
            }
        }
    }
}
void type()
{
    if (!ereur)
    {
        if (TC == "int" || TC == "float" || TC == "bool" || TC == "char") {
            par++;
            TC = Tabcode[par].mot;
        }
        else
        {
            ereur = true;
            cout << TC << "  n'est pas un motclé " << "declaration fausse dans la ligne : " << Tabcode[par].lines << endl;
        }
    }
}
void var()
{
    if (!ereur)
    {
        idnum();
        if (!ereur)
        {
            varextra();
        }
    }
}
void varextra()
{
    if (!ereur)
    {
        if (TC == ",")
        {
            par++;
            TC = Tabcode[par].mot;
            var();
        }
        else
        {
            if (TC == "[")
            {
                par++;
                TC = Tabcode[par].mot;
                idnum();
                if (!ereur)
                {
                    if (TC == "]")
                    {
                        par++;
                        TC = Tabcode[par].mot;
                        varextra();
                    }
                    else
                    {
                        ereur = true;
                        cout << "ereur manque de ] dans la ligne " << Tabcode[par].lines << endl;
                    }
                }
            }
        }
    }
}
void idnum()
{
    if (!ereur)
    {
        code* p;
        p = Tabcode + par;
        if (p->type == "identificateur")
        {
            par++;
            TC = Tabcode[par].mot;
        }
        else
        {
            if (p->type == "constant")
            {
                par++;
                TC = Tabcode[par].mot;
            }
            else
            {
                ereur = true;
                cout << "erreur ' " << TC << " ' n'est pas un identificcateur ou constant dans la ligne " << Tabcode[par].lines << endl;
            }
        }
    }
}
void funcdef()
{
    if (!ereur)
    {
        code* p;
        p = Tabcode + par;
        if (p->type == "identificateur")
        {
            par++;
            TC = Tabcode[par].mot;
            if (TC == "(")
            {
                par++;
                TC = Tabcode[par].mot;
                parmlist();
                if (!ereur)
                {
                    if (TC == ")")
                    {
                        par++;
                        TC = Tabcode[par].mot;
                        if (TC == "{")
                        {
                            par++;
                            TC = Tabcode[par].mot;
                            body();
                            if (!ereur)
                            {
                                if (TC == "}")
                                {
                                    par++;
                                    TC = Tabcode[par].mot;
                                }
                                else
                                {
                                    ereur = true;
                                    cout << "erreur manque de } dans la ligne " << Tabcode[par].lines << endl;
                                }
                            }
                        }
                        else
                        {
                            ereur = true;
                            cout << "erreur manque de { dans la ligne " << Tabcode[par].lines << endl;
                        }
                    }
                    else
                    {
                        ereur = true;
                        cout << "erreur manque de ) dans la ligne " << Tabcode[par].lines << endl;
                    }
                }
            }
            else
            {
                ereur = true;
                cout << "erreur manque de ( dans la ligne " << Tabcode[par].lines << endl;
            }
        }
        else
        {
            ereur = true;
            cout <<"erreur de declaration de la fonction "<< Tabcode[par].lines << endl;
        }
    }
}
void parmlist()
{
    if (!ereur)
    {
        code* p;
        p = Tabcode + par;
        if (p->mot == "int" || p->mot == "float" || p->mot == "char" || p->mot == "bool")
        {
            par++;
            TC = Tabcode[par].mot;
            type();
            if (!ereur)
            {
                parm();
            }
        }
    }
}
void parm()
{
    if (!ereur)
    {
        code* p;
        p = Tabcode + par;
        if (p->type == "identificateur" || p->type == "constant")
        {
            par++;
            TC = Tabcode[par].mot;
            parmextra();
        }
        else
        {
            ereur = true;
            cout << "erreur" << Tabcode[par].mot << " n'est pas un identificateur ou un counstant dans la ligne : " << Tabcode[par].lines << endl;
        }
    }
}
void parmextra()
{
    if (!ereur)
    {
        if (TC == ",")
        {
            par++;
            TC = Tabcode[par].mot;
            parmlist();
        }
    }
}
void body()
{
    if (!ereur)
    {
        vardefinition();
        if (!ereur)
        {
            statlist();
        }
    }
}
void statlist()
{
    if (!ereur)
    {
        if (TC == "if")
        {
            ifelsestate();
            if (!ereur)
            {
                statlist();
            }

        }
        else
        {
            if (TC=="for")
            {
                forstat();
                if (!ereur)
                {
                    statlist();
                }
            }
            else
            {
                if (TC=="while")
                {
                    whilestate();
                    if (!ereur)
                    {
                        statlist();
                    }
                }
                else
                {
                    code* p;
                    p = Tabcode + par;
                    if (p->type == "identificateur")
                    {
                        aorf();
                        if (!ereur)
                        {
                            statlist();
                        }
                    }
                }
            }
        }

    }
}
void aorf()
{
    code* p;
    p = Tabcode + par;
    if (p->type == "identificateur")
    {
        par++;
        TC = Tabcode[par].mot;
        assignorfunc();
    }
    else
    {
        ereur = true;
        cout << TC << "  n'est pas identificateur erreur!" << endl;
    }
}
void assignorfunc()
{
    if (!ereur)
    {
        if (TC == "(")
        {
            funccall();
        }
        else
        {
            if (TC == "=")
            {
                assignstat();
            }
            else
            {
                ereur = true;
                cout << "erreur affectation fausse " << endl;
            }
        }
    }
}
void funccall()
{
    if (!ereur)
    {
        if (TC == "(")
        {
            par++;
            TC = Tabcode[par].mot;
            inparamlist();
            if (!ereur)
            {
                if (TC == ")")
                {
                    par++;
                    TC = Tabcode[par].mot;
                    if (TC == ";")
                    {
                        par++;
                        TC = Tabcode[par].mot;
                    }
                    else
                    {
                        ereur = true;
                        cout << "erreur manque de ; dans la ligne" << Tabcode[par].lines << endl;
                    }
                }
                else
                {
                    ereur = true;
                    cout << "erreur manque de ) dans la ligne " << Tabcode[par].lines << endl;
                }
            }
        }
        else
        {
            ereur = true;
            cout << "erreur manque de ( dans la ligne " << Tabcode[par].lines << endl;
        }
    }
}
void inparamlist()
{
    if (!ereur)
    {
        code* p;
        p = Tabcode + par;
        if (TC=="(" || p->type == "constant" || p->type == "identificateur")
        {
            factor();
            if (!ereur)
            {
                inparms();
            }
        }

    }
}
void inparms()
{
    if (!ereur)
    {
        if (TC == ",")
        {
            par++;
            TC = Tabcode[par].mot;
            inparamlist();
        }
    }
}
void assignstat()
{
    if (!ereur)
    {
        if (TC == "=")
        {
            par++;
            TC = Tabcode[par].mot;
            expression();
            if (!ereur)
            {
                if (TC == ";")
                {
                    par++;
                    TC = Tabcode[par].mot;
                }
            }
        }
        else
        {
            ereur = true;
            cout << "erreur expression fausse manque de = dan la ligne : " << Tabcode[par].lines << endl;
        }
    }
}
void expression()
{
    if (!ereur)
    {
        exp();
        if (!ereur)
        {
            exp1();
        }
    }
}
void exp1()
{
    if (!ereur)
    {
        if (TC == "+" || TC =="-")
        {
            par++;
            TC = Tabcode[par].mot;
            exp();
            if (!ereur)
            {
                exp1();
            }
        }
    }
}
void exp()
{
    if (!ereur)
    {
        factor();
        if (!ereur)
        {
            exp2();
        }
    }
}
void exp2()
{
    if (!ereur)
    {
        if (TC == "*" || TC == "/")
        {
            par++;
            TC = Tabcode[par].mot;
            factor();
            if (!ereur)
            {
                exp2();
            }
        }
    }
}
void factor()
{
    if (!ereur)
    {
        code* p;
        p = Tabcode + par;
        if (TC == "(")
        {
            par++;
            TC = Tabcode[par].mot;
            expression();
            if (!ereur)
            {
                if (TC == ")")
                {
                    par++;
                    Tabcode[par].mot;
                }
                else
                {
                    ereur = true;
                    cout << "erreur manque de ( dans la ligne : " << Tabcode[par].lines;
                }
            }
        }
        else
        {
            if (p->type == "constant" || p->type == "identificateur")
            {
                idnum();
            }
            else
            {
                ereur = true;
                cout << "erreur expression fausse dans la ligne : " << Tabcode[par].lines << endl;
            }
        }
    }
}
void judgement()
{
    if (!ereur)
    {
        factor();
        if (!ereur)
        {
            relop();
            if (!ereur)
            {
                factor();
            }
        }
    }
}
void relop()
{
    if (!ereur)
    {
        if (TC == "!=" || TC == ">=" || TC == "<=" || TC == "==" || TC == "<" || TC == ">")
        {
            par++;
            TC = Tabcode[par].mot;
        }
        else
        {
            ereur = true;
            cout << TC << " n'est pas un separatuer boolen dans la ligne : " << Tabcode[par].lines;
        }
    }
}
void ifelsestate()
{
    if (!ereur)
    {
        if (TC == "if")
        {
            par++;
            TC=Tabcode[par].mot;
            if (TC == "(")
            {
                par++;
                TC = Tabcode[par].mot;
                judgement();
                if (!ereur)
                {
                    if (TC == ")")
                    {
                        par++;
                        TC = Tabcode[par].mot;
                        if (TC == "{")
                        {
                            par++;
                            TC = Tabcode[par].mot;
                            body();
                            if (!ereur)
                            {
                                if (TC == "}")
                                {
                                    par++;
                                    TC = Tabcode[par].mot;
                                    elsestat();
                                }
                                else
                                {
                                    ereur = true;
                                    cout << "erreur manque de } dans la ligne " << Tabcode[par].lines << endl;
                                }
                            }
                        }
                        else
                        {
                            ereur = true;
                            cout << "erreur manque de { dans la ligne : " << Tabcode[par].lines << endl;
                        }
                    }
                    else
                    {
                        ereur = true;
                        cout << "erreur manque de ) dans la ligne : " << Tabcode[par-1].lines << endl;
                    }
                }

            }
            else
            {
                ereur = true;
                cout << "erreur manque de ( dans la ligne : " << Tabcode[par].lines << endl;
            }
        }
    }
}
void elsestat()
{
    if (!ereur)
    {
        if (TC == "else")
        {
            par++;
            TC = Tabcode[par].mot;
            if (TC == "{")
            {
                par++;
                TC = Tabcode[par].mot;
                body();
                if (!ereur)
                {
                    if (TC == "}")
                    {
                        par++;
                        TC = Tabcode[par].mot;
                    }
                    else
                    {
                        ereur = true;
                        cout << "erreur manque de } dans la ligne : " << Tabcode[par].lines << endl;
                    }
                }
            }
            else
            {
                ereur = true;
                cout << "erreur manque de { dans la ligne : " << Tabcode[par].lines << endl;
            }
        }
    }
}
void forstat()
{
    if (!ereur)
    {
        if (TC == "for")
        {
            par++;
            TC = Tabcode[par].mot;
            if (TC == "(")
            {
                par++;
                TC = Tabcode[par].mot;
                code* p;
                p = Tabcode + par;
                if (p->type == "identificateur")
                {
                    par++;
                    TC = Tabcode[par].mot;
                    assignstatfor();
                    if (!ereur)
                    {
                        if (TC == ";")
                        {
                            par++;
                            TC = Tabcode[par].mot;
                            judgement();
                            if (!ereur)
                            {
                                if (TC == ";")
                                {
                                    par++;
                                    TC = Tabcode[par].mot;
                                    code* p;
                                    p = Tabcode + par;
                                    if (p->type == "identificateur")
                                    {
                                        par++;
                                        TC = Tabcode[par].mot;
                                        assignstatfor();
                                        if (!ereur)
                                        {
                                            if (TC == ")")
                                            {
                                                par++;
                                                TC = Tabcode[par].mot;
                                                if (TC == "{")
                                                {
                                                    par++;
                                                    TC = Tabcode[par].mot;
                                                    body();
                                                    if (!ereur)
                                                    {
                                                        if (TC == "}")
                                                        {
                                                            par++;
                                                            TC = Tabcode[par].mot;
                                                        }
                                                        else
                                                        {
                                                            ereur = true;
                                                            cout << "erreur manque de } dans la ligne : " << Tabcode[par].lines << endl;
                                                        }
                                                    }
                                                }
                                                else
                                                {
                                                    ereur = true;
                                                    cout << "erreur manque de { dans la ligne : " << Tabcode[par].lines << endl;
                                                }
                                            }
                                            else
                                            {
                                                ereur = true;
                                                cout << "erreur manque de ) dans la ligne : " << Tabcode[par-1].lines << endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        ereur = true;
                                        cout << "erreur " << TC << " n'est pas identificateur dans la ligne : " << Tabcode[par].lines << endl;
                                    }
                                }
                                else
                                {
                                    ereur = true;
                                    cout << "erreur manque de ; dans la ligne : " << Tabcode[par].lines << endl;
                                }
                            }
                        }
                        else
                        {
                            ereur = true;
                            cout << "erreur manque de ; dans la ligne : " << Tabcode[par].lines << endl;
                        }
                    }
                }
                else
                {
                    ereur = true;
                    cout << Tabcode[par].mot << "  n'est pas un identificateur dans la ligne : " << Tabcode[par].lines << endl;
                }
            }
            else
            {
                ereur = true;
                cout << "erreur manque de ) dans la ligne : " << Tabcode[par].lines << endl;
            }
        }
    }
}
void assignstatfor()
{
    if (!ereur)
    {
        if (TC == "=")
        {
            par++;
            TC = Tabcode[par].mot;
            expression();
        }
        else
        {
            ereur = true;
            cout << "manque de = dans la ligne : " << Tabcode[par].lines << endl;
        }
    }
}
void whilestate()
{
    if (!ereur)
    {
        if (TC == "while")
        {
            par++;
            TC = Tabcode[par].mot;
            if (TC == "(")
            {
                par++;
                TC = Tabcode[par].mot;
                judgement();
                if (!ereur)
                {
                    if (TC == ")")
                    {
                        par++;
                        TC = Tabcode[par].mot;
                        if (TC == "{")
                        {
                            par++;
                            TC = Tabcode[par].mot;
                            body();
                            if (!ereur)
                            {
                                if (TC == "}")
                                {
                                    par++;
                                    TC = Tabcode[par].mot;
                                }
                                else
                                {
                                    ereur = true;
                                    cout << "erreur manque de } dans la ligne : " << Tabcode[par].lines << endl;
                                }
                            }
                        }
                        else
                        {
                            ereur = true;
                            cout << "erreur manque de { dans la ligne : " << Tabcode[par].lines << endl;
                        }

                    }
                    else
                    {
                        ereur = true;
                        cout << "erreur manque de ) dans la ligne : " << Tabcode[par-1].lines << endl;
                    }
                }
            }
            else
            {
                ereur = true;
                cout << "erreur manque de ( dans la ligne : " << Tabcode[par].lines << endl;
            }
        }
    }
}
/*int main() {
    cout << endl;
    code *p=openfile("C:\\Users\\Badis\\Desktop\\badis.txt");
    if(p!=NULL)
        Z();



    return 0;
}
*/
