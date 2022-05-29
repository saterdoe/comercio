#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int loguearVendedor();
void mostrarDia(int);
void manejarCaja();
void vaciarBuffer();
void mostrarNombreVendedor(int);
float obtenerPrecio(int);
float calcularPrecio(int, int);
float cerrarVenta(int*);

int main(){

  int i, id, vend_mayor, codigo_producto, cantidad;
  float total, mayor_venta;
  int prendas[4] = {100, 120, 130, 140};
  int cantidades[4] = {0};
  float subtotales[4] = {0};
  float facturaciones[7] = {0};
  int promedios[7] = {0};
  int unidades_vend[3] = {0};
  int logueo;

  logueo = loguearVendedor();

  if(logueo == 1){
    printf("\n ****FUNCIONO EL LOGUEO****");
  }
  for(i=0; i < 7; i++){
    mayor_venta = 0;
    mostrarDia(i);
    manejarCaja();
    do{
      vaciarBuffer();
      printf("\n Ingrese el codigo del producto: \n100: Remera Basica \n120: Pantalon \n130: Buzo \n140: Camisa \n");
      scanf("%d", &codigo_producto);

      if(codigo_producto != 0){

        printf("\n Ingrese la cantidad vendida: ");
        scanf("%d", &cantidad);

        switch(codigo_producto){
          case 100:
            cantidades[0] += cantidad;
            break;
          case 120:
	    cantidades[1] += cantidad;
	    break;
	  case 130:
	    cantidades[2] += cantidad;
	    break;
	  case 140:
	    cantidades[3] += cantidad;
            break;
        }
      }

    }while(codigo_producto != 0);

    int k;
    for(k=0; k < 4; k++){
      subtotales[k] = calcularPrecio(prendas[k], cantidades[k]);
      total += subtotales[k];
    }

    if(mayor_venta == 0){
      mayor_venta = total;
      vend_mayor = id;
    }
    if(mayor_venta < total){
      mayor_venta = total;
      vend_mayor = id;
    }
    printf("\n La venta de mayor facturacion fue de $%.2f realizada por ", mayor_venta);
    mostrarNombreVendedor(id);
  }



  return 0;
}

void mostrarDia(int dia){
  switch(dia){
    case 0:
      printf("\n LUNES \n");
      break;
    case 1:
      printf("\n MARTES \n");
      break;
    case 2:
      printf("\n MIERCOLES \n");
      break;
    case 3:
      printf("\n JUEVES \n");
      break;
    case 4:
      printf("\n VIERNES \n");
      break;
    case 5:
      printf("\n SABADO \n");
      break;
    case 6:
      printf("\n DOMINGO \n");
      break;
  }
}

void manejarCaja(){

  int estado_caja, comando_caja;
  estado_caja = 0;
  do{
    printf("\n Seleccione una opcion: \n 1: para abrir caja \n 0: para cerrar caja \n");
    scanf("%d", &comando_caja);
    if(estado_caja == 0 && comando_caja == 0){
      printf("\n debe abrir caja primero");
    }

  }while(estado_caja == 0 && comando_caja != 1);
  printf("\n Abriendo caja...\n");
  estado_caja = comando_caja;

}

float obtenerPrecio(int prenda){
  switch(prenda){
    case 100:
      return 15;
      break;
    case 120:
      return 20;
      break;
    case 130:
      return 18;
      break;
    case 140:
      return 25;
      break;
  }
}

float calcularPrecio(int prod, int cantidad){
  float precio;
  precio = obtenerPrecio(prod);
  return precio*cantidad;
}

void mostrarNombreVendedor(int id){
  switch(id){
    case 1:
      printf("Pedro");
      break;
    case 2:
      printf("Juan");
      break;
    case 3:
      printf("Valeria");
      break;
  }
}

int loguearVendedor(){

  int id_pedro = 1;
  int id_juan = 2;
  int id_valeria = 3;
  char pass_pedro[9] = {'p','e','d','r','o','1','2','3'};
  char pass_juan[9] = {'j','u','a','n','1','2','3','4'};
  char pass_valeria[9] = {'v','a','l','e','1','2','3','4'};
  char pass[10];
  int id;

  printf("\n Por favor ingrese su ID: ");
  scanf("%d", &id);
  switch(id){
    case 1:
      iniciop: printf("\n Bienvenido Pedro, por favor ingrese su contraseña: ");
      scanf("%s", pass);
      if( strcmp(pass_pedro, pass) == 0){
        return 1;
      }else {
        printf("\n Contraseña incorrecta");
        goto iniciop;
      }
      break;
    case 2:
      inicioj: printf("\n Bienvenido Juan, por favor ingrese su contraseña: ");
      scanf("%s", pass);
      if( strcmp(pass_juan, pass) == 0){
        return 1;
      }else {
        printf("\n Contraseña incorrecta");
        goto inicioj;
      }
      break;
    case 3:
      iniciov: printf("\n Bienvenida Valeria, por favor ingrese su contraseña: ");
      scanf("%s", pass);
      if( strcmp(pass_valeria, pass) == 0){
        return 1;
      }else {
        printf("\n Contraseña incorrecta");
        goto iniciov;
      }
      break;
  }


}

/*
Esta funcion la hice para manejar el vaciado del buffer porque el código lo estoy haciendo en linux y
en este SO la función fflush(stdin) no tiene ningún efecto.
*/
void vaciarBuffer(){
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}
