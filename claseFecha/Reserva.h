//
//  Reserva.h
//  claseFecha
//
//  Created by Inaki Janeiro Olague on 4/22/18.
//  Copyright © 2018 Inaki Janeiro Olague. All rights reserved.
//

#ifndef Reserva_h
#define Reserva_h

#include "Fecha.h"

class Reserva{
private:
    int idMaterial;
    int idCliente;
    Fecha fechaReservacion;
public:
    Reserva();
    Reserva(int, int , Fecha);
    int getIdMaterial(){return idMaterial;}
    int getidCliente(){return idCliente;}
    Fecha getFechaReservacion(){return fechaReservacion;}
    void setIdMaterial(int idMaterial){this->idMaterial = idMaterial;}
    void setIdCliente(int idCliente){this->idCliente = idCliente;}
    void setFechaReservacion(Fecha fechaReservacion){this->fechaReservacion = fechaReservacion;}
    Fecha calculaFechaFinReserva(int);
};

Reserva::Reserva(){
    idMaterial = 0;
    idCliente = 0;
}

Reserva::Reserva(int idMaterial, int idCliente, Fecha fechaReservacion){
    this->idMaterial = idMaterial;
    this->idCliente = idCliente;
    this->fechaReservacion = fechaReservacion;
}


Fecha Reserva::calculaFechaFinReserva(int cantDias){
    Fecha fechaFin;
    fechaFin = fechaReservacion;
    fechaFin = fechaFin + cantDias;
    
    return fechaFin;
}

#endif /* Reserva_h */
