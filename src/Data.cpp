#include "Data.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/*
    Valida se os valores estao de acordo com o calendario
*/
void valida_dd_mm_yyyy(int d,int m,int y)
{
    if(y < 0) throw "ERRO: Ano nao pode ser negativo";
    if(m < 0 && m > 12) throw "ERRO: Mes nao pode ser menor que zero ou maior que 12" ;
    if(d < 0 || d > 31) throw "ERRO: Dia nao pode ser menor que zero ou maior que 31";

    if(( m == 4 || m == 6 || m == 9
       || m == 11 ) && (d > 30)) throw "ERRO: Este mes nao tem mais de 30 dias";

    if(m == 2 && d > 29) throw "ERRO: Fevereiro tem no maximo 29 dias";

}

Data::Data()
{
   dia = 10;
   mes = 06;
   ano = 1994;
}

Data::Data(int d, int m, int y)
{
    try
    {
        valida_dd_mm_yyyy(d,m,y);

        dia = d;
        mes = m;
        ano = y;

    }catch(char* msg)
    {
        throw msg;
    }
}

/* Construtor Data(string)
    O construtor pega uma string com o estilo dd/mm/yyyy e transforma em um objeto data
*/
Data::Data(string data)
{
    if(data.empty() || data == " ") throw "Erro, data nao inicializada";

    string buff{""};
	vector<string> v;

	for(auto n:data)
	{
		if(n != '/')
        {
         buff += n;
		}else{
            if((n == '/') && buff != "")
            {
                 v.push_back(buff);
                  buff = "";
            }
        }
	}
	if(buff != "") v.push_back(buff);

	//convertendo string para int
    int dia_aux = stoi(v.at(0));
	int mes_aux = stoi(v.at(1));
	int ano_aux = stoi(v.at(2));

	try
	{
        valida_dd_mm_yyyy(dia_aux,mes_aux,ano_aux);

	}catch(char* msg)
	{
	    //propagando a excecao
	    cout << msg;
        delete msg;
	}

    //se passou, a data esta correta
    dia = dia_aux;
    mes = mes_aux;
    ano = ano_aux;
}

string Data::get_data()
{
    string data = Data::get_dia() + "/";
    data += Data::get_mes() + "/";
    data += Data::get_ano();

    return data;
}

string Data::get_dia()
{
    return to_string(dia);
}

string Data::get_mes()
{
    return to_string(mes);
}

string Data::get_ano()
{
    return to_string(ano);
}





