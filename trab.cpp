/*
    THAINÁ CAGLIONI                 MATRICULA 158286
    VITOR LANGARO BALOTIN           MATRICULA 163252
*/
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


struct nmi{
        string CPF;
        string nome;
        string datan;
        string datac;
        string func;
};

int menu()
{
    cout <<"1.Cadastrar: \n"
         <<"2.Consultar: \n"
         <<"3.Excluir: \n"
         <<"4.Alterar: \n"
         <<"5.Consultar por Funcao: \n"
         <<"6.Salvar e sair: \n"
         <<"Escolha uma opcao: ";

    int op;
    cin >> op;
    cout << "****************************\n";
    return op;
}

void cadastrar(list<nmi>& jenga)
{
    nmi aux;
    cout << "Digite o CPF: ";
    cin >> aux.CPF;
    cin.ignore();
    cout << "Digite o nome completo: ";
    getline(cin, aux.nome);
    cout << "Digite a data de nascimento: ";
    cin >> aux.datan;
    cin.ignore();
    cout << "Digite a data que foi contradado: ";
    cin >> aux.datac;
    cout << "Digite a funcao: ";
    getline(cin, aux.func);
    cin.ignore();

    if(jenga.empty())
        jenga.push_back(aux);
    else{
        for(auto it=jenga.begin(); it!=jenga.end(); it++){
            if(aux.CPF == it->CPF){
                cout << "Funcionario ja esta cadastrado." << endl;
                cout << "Nome:" << it->nome << endl;
                     //<< "CPF: " << it->CPF << endl
                cout << "****************************\n";
                break;
            }
        }
        jenga.push_back(aux);
        cout << "****************************\n";
    }
}

void excluir(list<nmi>& jenga)
{
    string cpfex;
    cout << "Digite o CPF do funcionario a ser terminado: "; //always wanted to use that word
    cin >> cpfex;
    if(jenga.empty()){
        cout << "Nao ha funcionarios cadastrados.\n";
        cout << "****************************\n";
        return;
    }
    for(auto it=jenga.begin(); it!=jenga.end(); it++){
        if(cpfex == it->CPF){
            char a;
            cout << "Deseja mesmo terminar? Digite S para confirmar ou N para cancelar a operacao."<< endl;
            cin >> a;
            if(a == 'S' || a == 's'){
                jenga.erase(it);
                cout << "Terminado com sucesso.\n";
                cout << "****************************\n";
                return;
            }
            else{
                cout << "Funcionario nao foi removido.\n";
                cout << "****************************\n";
                return;
            }
        }

    }
    cout << "Funcionario nao foi encontrado.\n";
    cout << "****************************\n";
}

void consultar(const list<nmi>& jenga)
{

        if (jenga.empty()){
            cout << "Nao ha funcionarios cadastrados.\n";
            return;
        }
        for( auto it=jenga.begin(); it!=jenga.end(); it++){
            cout << it->nome << endl
                 << it->CPF << endl
                 << it->datan << endl
                 << it->datac << endl
                 << it->func << endl
                 << "**********************" << endl;
        }

}



int salvar_e_sair(list<nmi>& jenga, int a)
{
    cout << "Deseja sair? Digite 0 para sair ou 1 para continuar.\n";
    cin  >> a;

    if(jenga.empty()){
        //a=0;
        cout << "****************************\n";
        return a;
    }

    if(a==0){
        ofstream doge;
        doge.open("funcionarios.txt");

        if(!doge){
            cout << "Nao foi possivel criar o arquivo\n";
            a=1;
            return a;
        }
        else{
            for(auto it=jenga.begin(); it!=jenga.end(); it++){
                doge << it->nome << endl
                     << it->CPF << endl
                     << it->datan << endl
                     << it->datac << endl
                     << it->func << endl;
            }

        cout << "Finalizado com sucesso.\n";
        cout << "****************************\n";
        doge.close();
        //a=0;
        return a;
        }
    }
    else{
        cout << "****************************\n";
        return a;
    }
}

void ler_base_de_dados(list<nmi>& jenga)
{
    string s;
    vector<string> pepe;
    nmi aux;
    ifstream birb;
    birb.open("funcionarios.txt");

    if(!birb)
        return;
    else
    {
        while(getline(birb, s)){
            while (true){
                pepe.push_back(s);
                break;
            }
        }
    }
    int i=0;
    for(i; i < pepe.size(); i++){
        aux.nome=pepe[i];
        i=i+1;
        aux.CPF=pepe[i];
        i=i+1;
        aux.datan=pepe[i];
        i=i+1;
        aux.datac=pepe[i];
        i=i+1;
        aux.func=pepe[i];
        i=i+1;
        jenga.push_back(aux);
    }
    //remove("hope.txt"); queria a apagar o arquivo depois de ler, didn't work...
}

void alterar(list<nmi>& jenga)
{
    nmi aux;
    cout << "Digite o CPF do funcionario a ser alterado: ";
    cin >> aux.CPF;

    if(jenga.empty())
        jenga.push_back(aux);
    else{
        for(auto it=jenga.begin(); it!=jenga.end(); it++){
            if(aux.CPF == it->CPF){
                cout << "Digite a nova funcao: /n";
                cin >> it->func;
                cout <<"*****************************" << endl;
                return;
            }
        }
    }
    cout << "Nao ha nenhum funcionario com esse CPF.\n";
    cout << "******************" << endl;
}

void consultarfuncao(list<nmi> jenga)
{
    if(jenga.empty()){
        cout << "Nao ha funcionarios cadastrados.\n";
        cout << "************************\n";
        return;
    }
    nmi aux;
    string funcao;
    cout << "Digite a funcao: ";
    cin >> funcao;

    for(auto it=jenga.begin(); it!=jenga.end(); it++){
        if(it->func == funcao){
            cout << it->nome << endl
                 << it->CPF << endl
                 << it->datan << endl
                 << it->datac << endl
                 << it->func << endl;
            cout << endl;
        }
    }
    cout << "*************************************\n";
}

int main()
{
    list<nmi> jenga;
    int a=1;

    ler_base_de_dados(jenga);

    int op;
       do{
        op = menu();
        switch(op){
            case 1:cadastrar(jenga);
            break;
        }
        switch(op){
            case 2:consultar(jenga);
            break;
        }
        switch(op){
            case 3:excluir(jenga);
            break;
        }
        switch(op){
            case 4:alterar(jenga);
            break;
        }
        switch(op){
            case 5:consultarfuncao(jenga);
            break;
        }
        switch(op){
            case 6:a=salvar_e_sair(jenga, a);
            break;
        }
        }while(a==1);
}
