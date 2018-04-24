//
//  main.cpp
//  fechasTutoring
//
//  Created by Yolanda Martinez on 4/8/18.
//  Copyright Â© 2018 com.itesm. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Reserva.h"
#include "Material.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

int main() {
    
    Material *ptMat[20];
    Reserva reservacion[50];
    Fecha fechaReserva, fechaFin, fechaFinRes;
    int sizeMat = 0, sizeRes = 0;
    int idMaterial, idCliente;
    int dd, mm, aa;
    string titulo;
    char tipoMaterial[20], opc, buscaMat;
    int numPagDura;
    int cantDias = 0;
    string sistemaAutor, nombreMat;
    ifstream archMat, archRes;
    ofstream archSal;
    bool idMatEncontrado, primFech, segFech;
    
    
    
    archMat.open("Material.txt");
    while(archMat >> idMaterial >> titulo >> tipoMaterial[sizeMat]){
        if (tipoMaterial[sizeMat] == 'L'){
            archMat >> numPagDura >> sistemaAutor;
            //No se puede usar el set (?)
            ptMat[sizeMat++] = new Libro(idMaterial, titulo, numPagDura, sistemaAutor);
        }
        else if(tipoMaterial[sizeMat] == 'D'){
            archMat >> numPagDura;
            ptMat[sizeMat++] = new Disco(idMaterial, titulo, numPagDura);
        }
        else{
            archMat >> sistemaAutor;
            ptMat[sizeMat++] = new Software(idMaterial, titulo, sistemaAutor);
        }
    }
    archMat.close();
    
    archRes.open("reserva.txt");
    while(archRes >> dd >> mm >> aa >> idMaterial >> idCliente){
        fechaReserva.setFecha(dd, mm, aa);
        reservacion[sizeRes].setIdMaterial(idMaterial);
        reservacion[sizeRes].setIdCliente(idCliente);
        reservacion[sizeRes++].setFechaReservacion(fechaReserva);
        
    }
    archRes.close();
    
    do{
        cout << "=====================================\n";
        cout << "LISTA DE OPCIONES\n";
        cout << "a) Consultar la lista de Materiales\n";
        cout << "b) Consultar la lista de reservaciones\n";
        cout << "c) Consultar las reservaciones de un material dado\n";
        cout << "d) Consular las reservaciones de una fecha dada\n";
        cout << "e) Hacer una reservación\n";
        cout << "f) Terminar\n";
        cout << "=====================================\n";
        
        cin >> opc;
        opc = tolower(opc);
        
        switch (opc){
            case 'a':
                for (int i = 0; i < sizeMat; i++){
                    ptMat[i]->muestra();
                }
                break;
            case 'b':
                for (int i = 0; i < sizeRes; i++){
                    for (int j = 0; j < sizeMat; j++){
                        if (reservacion[i].getIdMaterial() == ptMat[j]->getIdMaterial()){
                            cantDias = ptMat[j]->cantidadDiasDePrestamo();
                            fechaReserva = reservacion[i].calculaFechaFinReserva(cantDias);
                            nombreMat = ptMat[j]->getTitulo();
                        }
                    }
                    cout << "Reservacion " << i + 1 << ": " << endl;
                    cout << "Fecha de Inicio: " << reservacion[i].getFechaReservacion() << endl;;
                    if (cantDias == 10){
                        cout << "El material es un libro llamado " << nombreMat <<  endl;
                    }
                    else if (cantDias == 3){
                        cout << "El material es un disco llamado " << nombreMat << endl;
                    }
                    else{
                        cout << "El material es un software llamado " << nombreMat << endl;
                    }
                    cout << "ID del Cliente: " << reservacion[i].getidCliente() << endl;
                    cout << endl;
                }
                break;
            case 'c':
                cout << "Que material quieres consultar? (L = Libro, D = Disco, S = Software) ";
                cin >> buscaMat;
                buscaMat = toupper(buscaMat);
                
                for (int i = 0; i < sizeRes; i++){
                        for (int j = 0; j < sizeMat; j++){
                            if (reservacion[i].getIdMaterial() == ptMat[j]->getIdMaterial()){
                                nombreMat = ptMat[j]->getTitulo();
                                if (buscaMat == tipoMaterial[j]){
                                if (tipoMaterial[j] == 'L'){
                                    cout << "El material es un libro llamado " << nombreMat << endl;
                                    cout << "Fecha de inicio: " << reservacion[i].getFechaReservacion() << endl;
                                    fechaReserva = reservacion[i].calculaFechaFinReserva(10);
                                    cout << "Fecha fin: " << fechaReserva << endl;
                                    cout << endl;
                                }
                                else if (tipoMaterial[j] == 'D'){
                                    cout << "El material es un disco llamado " << nombreMat << endl;
                                    cout << "Fecha de inicio: " << reservacion[i].getFechaReservacion() << endl;
                                    fechaReserva = reservacion[i].calculaFechaFinReserva(3);
                                    cout << "Fecha fin: " << fechaReserva << endl;
                                    cout << endl;
                                }
                                else if (tipoMaterial[j] == 'S'){
                                    cout << "El material es un software llamdo " << nombreMat << endl;
                                    cout << "Fecha de inicio: " << reservacion[i].getFechaReservacion() << endl;
                                    fechaReserva = reservacion[i].calculaFechaFinReserva(1);
                                    cout << "Fecha fin: " << fechaReserva << endl;
                                    cout << endl;
                                }
                            }
                        }
                    }
                }
                
                break;
            case 'd':
                cout << "Introduce la fecha a revisar (dd, mm, aaaa) ";
                cin >> dd >> mm >> aa;
                
                fechaReserva.setFecha(dd, mm, aa);
                
                
                for (int i = 0; i < sizeRes; i++){
                    for (int j = 0; j < sizeMat; j++){
                        if (reservacion[i].getIdMaterial() == ptMat[j]->getIdMaterial()){
                            cantDias = ptMat[j]->cantidadDiasDePrestamo();
                            fechaFin = reservacion[i].calculaFechaFinReserva(cantDias);
                            nombreMat = ptMat[j]->getTitulo();
                        }
                    }
                    if (fechaReserva >= reservacion[i].getFechaReservacion() && fechaReserva <= fechaFin){
                        if (cantDias == 10){
                            cout << "El material es un libro llamado " << nombreMat << endl;
                        }
                        else if (cantDias == 3){
                            cout << "El material es un disco llamado " << nombreMat << endl;
                        }
                        else{
                            cout << "El material es un software llamado " << nombreMat << endl;
                        }
                        cout << "ID del Cliente: " << reservacion[i].getidCliente() << endl;
                        cout << endl;
                    }
                }

                
                
                break;
            case 'e':
                cout << "Favor de introducir su ID de cliente ";
                cin >> idCliente;
                do{
                    cout << "Favor de introducir el ID del material ";
                    cin >> idMaterial;
                    idMatEncontrado = false;
                    for (int i = 0; i < sizeMat; i++){
                        if (idMaterial == ptMat[i]->getIdMaterial()){
                            idMatEncontrado = true;
                            cantDias = ptMat[i]->cantidadDiasDePrestamo();
                            
                        }
                    }
                }while (!idMatEncontrado);
                
                cout << "Favor de introducir la fecha en la que se desea reservar (dd, mm, aaaa) ";
                cin >> dd >> mm >> aa;
                
                fechaReserva.setFecha(dd, mm, aa);
                fechaFin = fechaReserva + cantDias;
                
                for (int i = 0; i < sizeRes; i++){
                    if (idMaterial == reservacion[i].getIdMaterial()){
                        fechaFinRes = reservacion[i].calculaFechaFinReserva(cantDias);
                        primFech = fechaReserva >= reservacion[i].getFechaReservacion() && fechaReserva <= fechaFinRes;
                        segFech = fechaFin >= reservacion[i].getFechaReservacion() && fechaFin <= fechaFin;
                        if (primFech || segFech){
                            cout << endl;
                            cout << "Material ocupado en ese fecha" << endl;
                            cout << endl;
                            i = sizeRes;
                        }
                        else{
                            reservacion[sizeRes].setIdCliente(idCliente);
                            reservacion[sizeRes].setFechaReservacion(fechaReserva);
                            reservacion[sizeRes++].setIdMaterial(idMaterial);
                            i = sizeRes;
                        }
                    }
                    else{
                        reservacion[sizeRes].setIdCliente(idCliente);
                        reservacion[sizeRes].setFechaReservacion(fechaReserva);
                        reservacion[sizeRes++].setIdMaterial(idMaterial);
                        i = sizeRes;
                    }
                }
                
                break;
            case 'f':
                archSal.open("reserva.txt");
                for (int i = 0; i < sizeRes; i++){
                    archSal << reservacion[i].getFechaReservacion().getDia() << " ";
                    archSal << reservacion[i].getFechaReservacion().getMes() << " ";
                    archSal << reservacion[i].getFechaReservacion().getAnio() << " ";
                    archSal << reservacion[i].getIdMaterial() << " ";
                    archSal << reservacion[i].getidCliente() << endl;
                }
                archSal.close();
                break;
        }
    }while(opc!='f');
    
    
    return 0;
}




