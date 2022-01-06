#ifndef COMPILER_MAIN_H
#define COMPILER_MAIN_H
#include<iostream>
#endif // COMPILER_MAIN_H
using namespace std;

struct code {
    string mot;
    string type;
    int lines;  // c'est le numero de ligne
};

class mot_cle_auto
{
private:
    int mot_cle[100][50];
public:
    mot_cle_auto() { remplire(); }
    void remplire();
    bool is_mot_cle(string s);

};

code* Tabcode;
bool ereur;
string TC;
int par;
int Tab_analyse[34][50];
bool isseperateur(string s);
bool is_commentaire(string s);
bool est_mot(string s);
code* openfile(string s);
void S(), Z(), program(), vardefinition(), functiondefinition(), vardef(), type(), var(), varextra(), idnum(), funcdef(), parmlist();
void parm(), parmextra(), body(), statlist(), aorf(), assignorfunc(), funccall(), inparamlist(), inparms(), assignstat(), expression();
void exp1(), exp2(), exp(), factor(), judgement(), relop(), ifelsestate(), elsestat(), forstat(), assignstatfor(), whilestate();
