#include <stdio.h>
#include <stdlib.h>
#include "projekat.h"

int main()
{
    int a=100;
    int x=0;
    do{
            x = meni();
        printf("\nUnesite broj operacije: \n");
        fflush(stdin);
        scanf("%i",&a);
        if(a==1 && x == 0){
            dodaj();
        }else if(a==2 && x == 0){
            login();
        }else if(a==3 && x == 0){
            printf("\nKRAJ!\n");
            break;
        }else if(a == 1 && x == 1){
            logout();
        }else if(a == 2 && x == 1){
            izmena();
        }else if(a == 3 && x == 1){
            brisanje();
        }else if(a == 4 && x == 1){
            kreiranje_grupe();
        }else if(a == 5 && x == 1){
            izmena_grupe();

        }else if(a == 6 && x == 1){
            brisanje_grupe();

        }else if(a == 7 && x == 1){
            ulazak();

        }else if(a == 8 && x == 1){
            prijateljli();

        }else if(a == 9 && x == 1){
            akcije_grupe();

        }else if(a == 10 && x == 1){
            printf("\nKRAJ!\n");
            break;
        }
   }while(5);





    return 0;
}
