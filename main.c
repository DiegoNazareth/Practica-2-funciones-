//Ejercicio 2
//2. Tomar su ejercicio de Blackjack y transformarlo a funciones y vectores/matrices segun sea necesario



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void llenar_baraja();
int imprime_baraja(int b[52]);

int palo[13] = {2,3,4,5,6,7,8,9,10, 11, 12, 13, 14};
int baraja[52];   

int main() {
    srand(time(NULL));
    
    char respuesta;
    char carta1=' ';
    char carta2=' ';


     llenar_baraja();
    
     imprime_baraja(baraja);

    
    
    int min = 0;
    int max = 51;
    int valor_as = 0;
    
    int rand1 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    int rand2 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    int rand3 = 0;
    
   
    int valor1 = baraja[rand1];
    int valor2 = baraja[rand2];
    
    baraja[rand1] = 0;
    baraja[rand2] = 0;
    
    int carta_extra = 0;
    char carta_extra_ch = ' ';
    

    if((valor1 == 14 && valor2 >9 && valor2 < 14) || (valor1 < 14 && valor1 > 9 && valor2 == 14)){
        printf("\n!! Felicidades obtuviste un BlackJack!!\n");
        return EXIT_SUCCESS;
    }
    
    printf("\nTu primer carta es: ");
    if(valor1 > 10){
        switch(valor1){
            case 11:
                carta1 = 'J';
                valor1 = 10;
                break;
            case 12:
                carta1 = 'Q';
                valor1 = 10;
                break;
            case 13:
                carta1 = 'K';
                valor1 = 10;
                break;
            case 14:
                carta1 = 'A';
                do{
                    printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
                    scanf("%d", &valor_as);
                }while(valor_as != 1 && valor_as != 11);
                valor1 = valor_as;
                break;
        }
        printf("%c\n", carta1);
    }else{
        printf("%d\n", valor1);
    }

     
    
    printf("Tu segunda carta es: ");
     if(valor2 > 10){
        switch(valor2){
            case 11:
                carta2 = 'J';
                valor2 = 10;
                break;
            case 12:
                carta2 = 'Q';
                valor2 = 10;
                break;
            case 13:
                carta2 = 'K';
                valor2 = 10;
                break;
            case 14:
                carta2 = 'A';
                do{
                    printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
                    scanf("%d", &valor_as);
                }while(valor_as != 1 && valor_as != 11);
                valor2 = valor_as;
                break;
        }
        printf("%c\n", carta2);
    }else{
        printf("%d\n", valor2);
    }
    
    
    
    int suma = valor1 + valor2;
    printf("La suma es: %d \n", suma);
    
    do{
        fflush(stdin);
        printf("\nQuieres otra carta? \n");
        scanf(" %c", &respuesta);
        if (respuesta == 's' || respuesta == 'S') {
            do{
                rand3 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
            }while(baraja[rand3] == 0);
            
            carta_extra = baraja[rand3];
            baraja[rand3] = 0;
            
            printf("Tu carta es: ");
            
            if(carta_extra > 10){
                switch(carta_extra){
                    case 11:
                        carta_extra_ch = 'J';
                        carta_extra = 10;
                        break;
                    case 12:
                        carta_extra_ch = 'Q';
                        carta_extra = 10;
                        break;
                    case 13:
                        carta_extra_ch = 'K';
                        carta_extra = 10;
                        break;
                    case 14:
                        carta_extra_ch = 'A';
                        do{
                            printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
                            scanf("%d", &valor_as);
                        }while(valor_as != 1 && valor_as != 11);
                        carta_extra = valor_as;
                        break;
                }
                printf("%c\n", carta_extra_ch);
            }else{
                printf("%d\n", carta_extra);
            }
            
            suma = suma + carta_extra;
            printf("La suma es: %d \n", suma);
            
            if(suma > 21){
                printf("!PERDISTE!!! \n");
                /// temporal
                int count = 0;
                for(int i=0;i<52;i++){
                    printf("%d ", baraja[i]);
                    if(count == 12){
                        printf("\n");
                        count = 0;
                        continue;
                    }
                    count ++ ;
                }

                return EXIT_SUCCESS;
            }
            
        } else {
            break;
        }
    }while(1);
    
    int flag = 1;
    int flag2 = 1;
    
    rand1 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    rand2 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    
    do{
        if(baraja[rand1] != 0 && flag){
            valor1 = baraja[rand1];
            baraja[rand1] = 0;
            flag = 0;
        }else{
            rand1 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
        }
        
        if(baraja[rand2] !=0 && flag2 ){
            valor2 = baraja[rand2];
            baraja[rand2] = 0;
            flag2 = 0;
        }else{
            rand2 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
        }
        
    }while(flag || flag2);
    
    rand3 = 0;
    

    carta_extra = 0;
    carta_extra_ch = ' ';

    if((valor1 == 14 && valor2 >9 && valor2 < 14) || (valor1 < 14 && valor1 > 9 && valor2 == 14)){
        printf("\n!! Gano la computadora con un BlackJack!!\n");
        return EXIT_SUCCESS;
    }
    int bandera_AS1 = 0;
    int bandera_AS2 = 0;
    
    printf("\nPrimer carta de la computadora es: ");
    if(valor1 > 10){
        switch(valor1){
            case 11:
                carta1 = 'J';
                valor1 = 10;
                break;
            case 12:
                carta1 = 'Q';
                valor1 = 10;
                break;
            case 13:
                carta1 = 'K';
                valor1 = 10;
                break;
            case 14:
                carta1 = 'A';
                bandera_AS1 = 1;
                do{
                    printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
                    scanf("%d", &valor_as);
                }while(valor_as != 1 && valor_as != 11);
                valor1 = valor_as;
                break;
        }
        printf("%c\n", carta1);
    }else{
        printf("%d\n", valor1);
    }
    
    
    printf("Segunda carta de la computadora es: ");
    if(valor2 > 10){
        switch(valor2){
            case 11:
                carta2 = 'J';
                valor2 = 10;
                break;
            case 12:
                carta2 = 'Q';
                valor2 = 10;
                break;
            case 13:
                carta2 = 'K';
                valor2 = 10;
                break;
            case 14:
                carta2 = 'A';
                bandera_AS2 =1;
                do{
                    printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
                    scanf("%d", &valor_as);
                }while(valor_as != 1 && valor_as != 11);
                valor2 = valor_as;
                break;
        }
        printf("%c\n", carta2);
    }else{
        printf("%d\n", valor2);
    }
    
    int suma_compu = valor1 + valor2;
    printf("La suma de la computadora es: %d \n", suma_compu);
    
    do{

        if (suma > suma_compu) {
            do{
                rand3 = min + rand() / (RAND_MAX / (max - min + 1) + 1);
            }while(baraja[rand3] == 0);
            
            carta_extra = baraja[rand3];
            baraja[rand3] = 0;

            printf("Tu carta es: ");
            
            if(carta_extra > 10){
                switch(carta_extra){
                    case 11:
                        carta_extra_ch = 'J';
                        carta_extra = 10;
                        break;
                    case 12:
                        carta_extra_ch = 'Q';
                        carta_extra = 10;
                        break;
                    case 13:
                        carta_extra_ch = 'K';
                        carta_extra = 10;
                        break;
                    case 14:
                        carta_extra_ch = 'A';
                        do{
                            printf("!Obtuviste un As!, Que valor quieres para el As 1 u 11? \n");
                            scanf("%d", &valor_as);
                        }while(valor_as != 1 && valor_as != 11);
                        carta_extra = valor_as;
                        break;
                }
                printf("%c\n", carta_extra_ch);
            }else{
                printf("%d\n", carta_extra);
            }
            
            suma_compu = suma_compu + carta_extra;
            printf("La suma de la compu es: %d \n", suma_compu);
            
            if(suma_compu > 21){
                printf("!PERDIO LA COMPUTADORA!!! \n");
                
                
                int count = 0;
                for(int i=0;i<52;i++){
                    printf("%d ", baraja[i]);
                    if(count == 12){
                        printf("\n");
                        count = 0;
                        continue;
                    }
                    count ++ ;
                }
                return EXIT_SUCCESS;
            }
            
        } else {
            break;
        }
    }while(1);
    
    if(suma > suma_compu ){
        printf("!GANASTE!!! \n");
    }else{
        printf("!PERDISTE!!! \n");
    }
    
    /// temporal
    int count = 0;
    for(int i=0;i<52;i++){
        printf("%d ", baraja[i]);
        if(count == 12){
            printf("\n");
            count = 0;
            continue;
        }
        count ++ ;
    }
   
    return EXIT_SUCCESS;
}

int imprime_baraja(int b[52])
{
    int i=0;
    for(int i=0;i<52;i++){
        printf("%d ", b[i]);
        if(b[i] == 14)
            printf("\n");
    }
    
}

void llenar_baraja()
{  int i=0,j=0,h=0;
         for(int i=0; i<4; i++){
        for(int j=0; j<13; j++){
            baraja[h] = palo[j];
            h++;
        }
    }
     }
