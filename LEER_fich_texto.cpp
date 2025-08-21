// La idea es salvar a fichero un array nativo que contenga las asocioaciones (int, pFunc)
//Mi usuario en GMAIL es: alfo.orego
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>

using std::cout; 
using std::endl;
using std::string;
using std::vector;

//Las funciones a relacionar
void f01(){    cout << " => f01 fue llamada\n";}
void f02(){    cout << " ==> f02 fue llamada\n";}
void f03(){    cout << " ===> f03 fue llamada\n";}
void f04(){    cout << " ====> f04 fue llamada\n";}

struct asoc_t{
    int key; 
    string nombreFunc; 
};

std::map <string, void (*)(), std::less<string> > asoc_str_func_map;
vector<asoc_t> vAsociaciones{}; 
vector<int> vLlamadas{}; 

const string nombreFichConfig{"./fich_config_asoc.txt"};
const string nombreFichLlamadas{"./fich_llamadas.txt"};


int main()
{
    cout << endl; 

    //Correspondencia entre tags y funciones
    asoc_str_func_map.insert(std::make_pair("f01", f01)); 
    asoc_str_func_map["f02"] = f02; 
    asoc_str_func_map["f03"] = f03; 
    asoc_str_func_map["f04"] = f04; 

    /////////////////////////////////////
    //Leer contenido de fich de config de asociaciones entre COD y FUNC
    std::ifstream i_f1 ( nombreFichConfig, std::ios::in /* | std::ios::binary */ );
    string strAux, strAuxFunc; 
    i_f1 >> strAux; 
    i_f1 >> strAuxFunc;
    cout << "Fich CONFIG contiene: " << endl;
    while (!i_f1.eof()){
        cout << "Tecla: " << std::stoi(strAux) << ", Func a llamar: " << strAuxFunc << endl;;
        vAsociaciones.push_back({std::stoi(strAux), strAuxFunc});
        i_f1 >> strAux; 
        i_f1 >> strAuxFunc; 
    }
    i_f1.close();

    /////////////////////////////////////
    //Leer contenido de fich de config de asociaciones entre COD y FUNC
    i_f1.open(nombreFichLlamadas, std::ios::in); //Objeto IFSTREAM reutilizado
    i_f1 >> strAux; //Variable reutilizada
    cout << "\nFich de llamadas contiene: " << endl;
    while (!i_f1.eof()){
        cout << "Se pide llamar a: " << strAux << endl;
        vLlamadas.push_back(std::stoi(strAux));
        i_f1 >> strAux; 
    }
    i_f1.close();

    /////////////////////////////////////
    cout << "\nLlamar a las funcs indicadas en fich (y que ya se copiaron al vec vLlamadas): " << endl; 
    for (auto cod : vLlamadas){
        for (auto a : vAsociaciones){ //Buscar la asoc cod-func para saber la func que se debe llamar
            if (a.key == cod){
                asoc_str_func_map[a.nombreFunc]();
            }
        }
    }

    return 0; 
}
