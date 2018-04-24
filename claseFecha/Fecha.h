//
//  Fecha.h
//  claseFecha
//
//  Created by Inaki Janeiro Olague on 4/9/18.
//  Copyright © 2018 Inaki Janeiro Olague. All rights reserved.
//

#ifndef Fecha_h
#define Fecha_h

class Fecha
{
    // como friend la sobrecarga del operador >
    friend bool operator>(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador >=
    friend bool operator>=(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador <
    friend bool operator<(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador <=
    friend bool operator<=(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador ==
    friend bool operator==(Fecha f1, Fecha f2);
    // como friend la sobrecarga del operador +
    friend Fecha operator+(Fecha f1, int i1);
    // que recibe como parametro una fecha y un numero entero
    // que representa una cantidad de dias y regresa
    // la fecha a la que se le agregaron los dias indicados
    friend istream& operator>>(istream &is, Fecha &f1);
    // como friend la sobrecarga del operador >>
    // que lee 3 valores enteros: dia, mes, anio con 4 digitos
    
    // como friend la sobrecarga del operador <<
    // que muestra la fecha en el formato dd/mm/aaaa
    // no incluyas espacios ni enter
    friend ostream& operator<<(ostream &os, Fecha f1);
    
public:
    Fecha() { dd = 0; mm = 0; aa = 0; }
    Fecha(int d, int m, int a) { dd = d; mm = m; aa = a; }
    int getDia() { return dd; }
    int getMes() { return mm; }
    int getAnio() { return aa; }
    void setFecha(int d, int m, int a) { dd = d; mm = m; aa = a; }
private:
    // atributos
    int dd, mm, aa;
    string nombreMes();
};

bool operator>(Fecha f1, Fecha f2){
    if (f1.aa > f2. aa){
        return true;
    }
    else if (f1. aa == f2. aa){
        if (f1.mm > f2.mm)
            return true;
        else if (f1.mm == f2.mm)
            if (f1.dd > f2.dd)
                return true;
    }
    return false;
}

bool operator==(Fecha f1, Fecha f2){
    if ((f1.aa == f2.aa) && (f1.mm == f2.mm) && (f1.dd == f2.dd))
        return true;
    return false;
}

bool operator>=(Fecha f1, Fecha f2){
    if (f1 > f2)
        return true;
    if (f1 == f2)
        return true;
    return false;
}

bool operator<(Fecha f1, Fecha f2){
    if (f1.aa < f2. aa){
        return true;
    }
    else if (f1. aa == f2. aa){
        if (f1.mm < f2.mm)
            return true;
        else if (f1.mm == f2.mm)
            if (f1.dd < f2.dd)
                return true;
    }
    return false;
}

bool operator<=(Fecha f1, Fecha f2){
    if (f1 < f2)
        return true;
    if (f1 == f2)
        return true;
    return false;
}

Fecha operator+(Fecha f1, int i1){
    int sumaMes;
    int sumaAno;
    int mes;
    int dia = f1.dd + i1;
    switch (f1.mm) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (dia > 31){
                sumaMes = dia / 31;
                f1.dd = dia % 31;
                mes = f1.mm += sumaMes;
                if (mes > 12){
                    sumaAno = mes / 12;
                    f1.mm = mes % 12;
                    f1.aa += sumaAno;
                }
                else{
                    f1.mm = mes;
                }
            }
            else{
                f1.dd = dia;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (dia > 30){
                sumaMes = dia / 30;
                f1.dd = dia % 30;
                mes = f1.mm += sumaMes;
                if (mes > 12){
                    sumaAno = mes / 12;
                    f1.mm = mes % 12;
                    f1.aa += sumaAno;
                }
                else{
                    f1.mm = mes;
                }
            }
            else{
                f1.dd = dia;
            }
            break;
        case 2:
            if ((f1.aa % 4 == 0 && f1.aa % 100 != 0) || ( f1.aa % 400 == 0)){
                if (dia > 29){
                    sumaMes = dia / 29;
                    f1.dd = dia % 29;
                    mes = f1.mm += sumaMes;
                    if (mes > 12){
                        sumaAno = mes / 12;
                        f1.mm = mes % 12;
                        f1.aa += sumaAno;
                    }
                    else{
                        f1.mm = mes;
                    }
                }
                else{
                    f1.dd = dia;
                }
            }
            else{
                if (dia > 28){
                    sumaMes = dia / 28;
                    f1.dd = dia % 28;
                    mes = f1.mm += sumaMes;
                    if (mes > 12){
                        sumaAno = mes / 12;
                        f1.mm = mes % 12;
                        f1.aa += sumaAno;
                    }
                    else{
                        f1.mm = mes;
                    }
                }
                else{
                    f1.dd = dia;
                }
                
            }
        default:
            break;
    }
    
    return f1;
}

istream& operator>>(istream &is, Fecha &f1){
    is >> f1.dd;
    is >> f1.mm;
    is >> f1.aa;
    return is;
}

ostream& operator<<(ostream &os, Fecha f1){
    os << f1.dd << "/" <<  f1.nombreMes() << "/" << f1.aa;
    return os;
}

string Fecha::nombreMes(){
    switch (mm) {
        case 1:
            return "Ene";
            break;
        case 2:
            return "Feb";
            break;
        case 3:
            return "Mar";
            break;
        case 4:
            return "Abr";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "Jun";
            break;
        case 7:
            return "Jul";
            break;
        case 8:
            return "Ago";
            break;
        case 9:
            return "Sep";
            break;
        case 10:
            return "Oct";
            break;
        case 11:
            return "Nov";
            break;
        case 12:
            return "Dec";
            break;
    }
    return "";
}

#endif /* Fecha_h */
