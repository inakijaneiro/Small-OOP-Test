//
//  Disco.h
//  claseFecha
//
//  Created by Inaki Janeiro Olague on 4/22/18.
//  Copyright © 2018 Inaki Janeiro Olague. All rights reserved.
//

#ifndef Disco_h
#define Disco_h

class Disco : public Material{
private:
    int duracion;
public:
    Disco();
    Disco(int, string, int);
    int getDuracion(){return duracion;}
    void setDuracion(int duracion){this->duracion = duracion;}
    void muestra();
    int cantidadDiasDePrestamo();
};


Disco::Disco() : Material(){
    duracion = 0;
}

Disco::Disco(int idMaterial, string titulo, int duracion) : Material(idMaterial, titulo){
    this->duracion = duracion;
}

void Disco::muestra(){
    cout << "El material es un disco" << endl;
    cout << "El ID del disco es: " << idMaterial << endl;
    cout << "El Titulo del disco es: " << titulo << endl;
    cout << "La Duracion del disco es: " << duracion << endl;
    cout << endl;
}

int Disco::cantidadDiasDePrestamo(){
    return 3;
}
#endif /* Disco_h */
