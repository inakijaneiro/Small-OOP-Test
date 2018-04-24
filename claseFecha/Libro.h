//
//  Libro.h
//  claseFecha
//
//  Created by Inaki Janeiro Olague on 4/22/18.
//  Copyright © 2018 Inaki Janeiro Olague. All rights reserved.
//

#ifndef Libro_h
#define Libro_h

class Libro : public Material{
private:
    int numPag;
    string autor;
public:
    Libro();
    Libro(int, string, int, string);
    int getNumPag(){return numPag;}
    string getAutor(){return autor;}
    void setNumPag(int numPag){this->numPag = numPag;}
    void setAutor(string autor){this->autor = autor;}
    void muestra();
    int cantidadDiasDePrestamo();
};

Libro::Libro() : Material(){
    numPag = 0;
    autor = "n/a";
}

Libro::Libro(int idMaterial, string titulo, int numPag, string autor): Material(idMaterial, titulo){
    this->numPag = numPag;
    this->autor = autor;
}

void Libro::muestra(){
    cout << "El material es un libro" << endl;
    cout << "El ID del libro es: " << idMaterial << endl;
    cout << "El Titulo del libro es: " << titulo << endl;
    cout << "El numero de paginas del libro es: " << numPag << endl;
    cout << "El Autor del libro es: " << autor << endl;
    cout << endl;
}

int Libro::cantidadDiasDePrestamo(){
    return 10;
}


#endif /* Libro_h */
