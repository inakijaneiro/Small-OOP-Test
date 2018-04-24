//
//  Material.h
//  claseFecha
//
//  Created by Inaki Janeiro Olague on 4/22/18.
//  Copyright © 2018 Inaki Janeiro Olague. All rights reserved.
//

#ifndef Material_h
#define Material_h

class Material{
protected:
    int idMaterial;
    string titulo;
public:
    Material();
    Material(int, string);
    int getIdMaterial(){return idMaterial;}
    string getTitulo(){return titulo;}
    void setIdMaterial(int idMaterial){this->idMaterial = idMaterial;}
    void setTitulo(string titulo){this->titulo = titulo;}
    virtual void muestra() = 0;
    virtual int cantidadDiasDePrestamo() = 0;
};

Material::Material(){
    idMaterial = 0;
    titulo = "n/a";
}

Material::Material(int idMaterial, string titulo){
    this->idMaterial = idMaterial;
    this->titulo = titulo;
}



#endif /* Material_h */
