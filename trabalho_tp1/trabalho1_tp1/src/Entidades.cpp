#include "Entidades.h"

void Usuario::set_identificador(string valor)
{
    identificador.set_identificador(valor);
}

void Usuario::set_nome(string valor)
{
    nome.set_nome(valor);
}

void Usuario::set_senha(string valor)
{
    senha.set_senha(valor);
}

void Acomodacao::set_capacidade(int valor)
{
    capacidade.set_capacidade_acomodacao(valor);
}

void Acomodacao::set_cidade(string valor)
{
    cidade.set_nome(valor);
}

void Acomodacao::set_data_inicio(string valor)
{
    data_de_inicio.set_data(valor);
}

void Acomodacao::set_data_termino(string valor)
{
    data_de_termino.set_data(valor);
}

void Acomodacao::set_diaria(float valor)
{
    diaria.set_diaria(valor);
}

void Acomodacao::set_estado(string valor)
{
    estado.set_estado(valor);
}

void Acomodacao::set_identificador(string valor)
{
    identificador.set_identificador(valor);
}

void Acomodacao::set_tipo(int valor)
{
    tipo.set_tipo_acomodacao(valor);
}

void Cartao_de_Credito::set_numero(string valor)
{
    numero.set_numero_cartao(valor);
}

void Cartao_de_Credito::set_data_validade(string valor)
{
    data_validade.set_data_validade(valor);
}

void Conta_corrente::set_agencia(int valor)
{
    agencia.set_agencia(valor);
}

void Conta_corrente::set_banco(int valor)
{
    banco.set_banco(valor);
}

void Conta_corrente::set_numero(string valor)
{
    numero.set_numero_conta_corrente(valor);
}
