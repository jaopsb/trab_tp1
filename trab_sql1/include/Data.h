#ifndef DATA_H
#define DATA_H
#include <string>

using namespace std;

class Data
{
    public:
        Data();
        Data(string);
        Data(int,int,int);


        //devolve a data completa
        string get_data();

        //devolve apenas o dia,o mes e o ano respectivamente
        string get_dia();
        string get_mes();
        string get_ano();
    protected:

    private:
        int dia,mes,ano;
};

#endif // DATA_H
