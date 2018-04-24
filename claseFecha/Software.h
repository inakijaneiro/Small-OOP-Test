//
//  Software.h
//  claseFecha
//
//  Created by Inaki Janeiro Olague on 4/22/18.
//  Copyright © 2018 Inaki Janeiro Olague. All rights reserved.
//

#ifndef Software_h
#define Software_h

class Software : public Material{
private:
    string sistemaOper;
public:
    Software();
    Software(int, string, string);
    string getSistemaOper(){return sistemaOper;}
    void setSistemaOpera(string sistemaOper){this->sistemaOper = sistemaOper;}
    void muestra();
    int cantidadDiasDePrestamo();
};

Software::Software():Material(){
    sistemaOper = "n/a";
}

Software::Software(int idMaterial, string titulo, string sistemaOper):Material(idMaterial, titulo){
    this->sistemaOper = sistemaOper;
}

void Software::muestra(){
    cout << "El material es un software" << endl;
    cout << "El ID del disco es: " << idMaterial << endl;
    cout << "El Titulo del disco es: " << titulo << endl;
    cout << "El Sistema Operativo del software es: " << sistemaOper << endl;
    cout << endl;
}

int Software::cantidadDiasDePrestamo(){
    return 1;
}

#endif /* Software_h */
