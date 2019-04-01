/* Made by Thiago Chaves */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "number.h"
#include <sys/io.h>
/* Compilar com -lm */
/* IMAGENS PRECISAM ESTAR EM PGM PRA SEREM USADAS SE O PROGRAMA ESTIVER EM WINDOWS*/

int main(){
    IMG_PGM N;
    IMG_PGM N_2;
    char nome[100];
    int i,j;
    char c;
    char dest[30];
    /*Creat Image Structure */
    read_image_name(nome);
    system("clear");
    read_image_pgm_B(nome,&N);
    
    create_image(N,&N_2);
    /* Wrinting choices */
    printf("Escolha o como usar a imagem:\n");
    printf("\t(1)Blur Image\t\t\t(2)Normalize Image\n");
    printf("\t(3)Whitining Image\t\t(4)Find Corner\n");
    printf("\t(5)Invert Color\t\t\t(6)Cut Image\n");
    printf("\t(7)Find Other Img\t\t(8)Separar Estrutura\n");
    printf("\t(9)Padrão\n");

    /* Processing Images */
    getchar();
    fflush(stdin);
    c=getchar();
    // scanf("%c",&c);
    switch((int)c){
        case 49:
        blur_image(N,&N_2);
        break;
        case 50:
        normalize_image(N,&N_2);
        break;
        case 51:
        whiting_image(N,&N_2);
        break;
        case 52:
        find_corner(N,&N_2);
        break;
        case 53:
        invertBW_image(N,&N_2);
        break;
        case 54:
        cut_image(N,&N_2);
        break;
        case 55:
        find_otherimg(N,&N_2);
        break;
        case 56:
        separating_structures(N,&N_2);
        break;
        case 57:
        default:
        process_2(N,&N_2);
        break;
    }

    strcpy(dest,"dest.");
    if(N_2.modo[1]=='2'||N_2.modo[1]=='5')strcat(dest,"pgm\0");
    if(N_2.modo[1]=='3'||N_2.modo[1]=='6')strcat(dest,"ppm\0");
    if(N_2.modo[1]=='1'||N_2.modo[1]=='4')strcat(dest,"pbm\0");
    strcpy(N_2.name,dest);
    write_image(N_2);
    printf("Nova foto \"%s\" foi criada.\n",N_2.name);
    /*Free Space Alocated in structures that were made */
    free_img_struct(&N);
    free_img_struct(&N_2);

    return 0;
}