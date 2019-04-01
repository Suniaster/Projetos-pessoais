#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include "number.h"

/* Free data */

void free_img_struct(IMG_PGM*N){
    int i,j,chn;
    for(chn=0;chn<N->chns;chn++){
        for(i=0;i<N->Vertical;i++){
            free(N->matriz[chn][i]);
        }
        free(N->matriz[chn]);
    }
    free(N->matriz);
    free(N->name);
}
void free_Matriz2D(Matriz2D* N){
    int i,j;
    for(i=0;i<N->linhas;i++)free(N->data[i]);
    free(N->data);
}

/* Other */
int positivo(int i){
    if(i<0){
        return 0;
    }
    else return i;
}
int modulo(int i){
    if(i<0)return -1*i;
    else return i;
}
int partic(int V[],int idx[],int inic, int fim){
    int i=inic-1, j=inic;
    int pivo=0;
    float swap1;
    int swap2;
    for(j=inic;j<fim;){
        if(V[j]<V[fim]){
            j++;
        }
        else{
            i++;
            swap1=V[j];
            V[j]=V[i];
            V[i]=swap1;

            swap2=idx[j];
            idx[j]=idx[i];
            idx[i]=swap2;
            j++;
        }
    }
    if(fim>i){
    swap1=V[i+1];
    V[i+1]=V[fim];
    V[fim]=swap1;

    swap2=idx[i+1];
    idx[i+1]=idx[fim];
    idx[fim]=swap2;
    pivo=i+1;
    }
    return pivo;
}
void quicksort(int vetor[], int idx[],int inic, int fim){
    int pivo;
    if(inic<fim){
        pivo=partic(vetor, idx, inic, fim);
        quicksort(vetor, idx, inic, pivo-1);
        quicksort(vetor, idx, pivo+1, fim);
    }
}
void ilumination_mean(IMG_PGM *Dest){
    int i,j,chn, aux=0;
    Dest->ilum_mean=0;
    for(chn=0;chn<Dest->chns;chn++){
        for(i=0;i<Dest->Vertical;i++){
            for(j=0;j<Dest->Horizontal;j++){
                Dest->ilum_mean+=Dest->matriz[chn][i][j];
                if(Dest->matriz[chn][i][j]>0)aux++;
            }
        }
    }
    Dest->ilum_mean/=aux;
}
Matriz2D* create_blur_matriz(int blur){
    Matriz2D* N=malloc(sizeof(Matriz2D));
    int i,j;
    
    N->linhas=3;
    N->colunas=3;
    N->data=(float**)malloc(N->linhas*sizeof(float*));
    for(i=0;i<N->linhas;i++)N->data[i]=calloc(N->colunas,sizeof(float));
    if(blur==1){
        N->data[0][0]=1;
        N->data[0][1]=1;
        N->data[0][2]=1;
        N->data[1][0]=1;
        N->data[1][1]=1;
        N->data[1][2]=1;
        N->data[2][0]=1;
        N->data[2][1]=1;
        N->data[2][2]=1;
    }
    if(blur==2){
        N->data[0][0]=1;
        N->data[0][1]=2;
        N->data[0][2]=1;
        N->data[1][0]=2;
        N->data[1][1]=4;
        N->data[1][2]=2;
        N->data[2][0]=1;
        N->data[2][1]=2;
        N->data[2][2]=1;
    }
    return N;
}
/* Reading and Writing Images */
void cpyhead_image(IMG_PGM N, IMG_PGM *Dest){
    strcpy(Dest->modo,N.modo);
    Dest->chns=N.chns;
    Dest->Vertical=N.Vertical;
    Dest->Horizontal=N.Horizontal;
    Dest->Cor=N.Cor;
}
void read_image_name(char Nome_imagem[]){
    printf("Insira o nome da imagem a ser usada: ");
    char dir[50]={0};
    scanf("%s",Nome_imagem);
        /* Testando pra ver se a imagem existe */
    strcpy(dir,"./imgs/");
    strcat(dir,Nome_imagem);
    FILE* test;
    test=fopen(dir,"r");
    if(test==NULL){
        printf("Arquivo inexistente...\n");
        exit(1);
    }
        /* Acha qual a é a extensão da imagem */
    int i,j,bol=0,cont=0,aux=0;
    char ext[4];
    for(i=0;i<strlen(Nome_imagem);i++){
        if(bol){
            ext[cont]=Nome_imagem[i];
            cont++;
        }
        if(Nome_imagem[i]=='.')bol=1;
    }
    ext[i]='\0';
    
    if(!strcmp(ext,"pgm")||!strcmp(ext,"pbm")||!strcmp(ext,"ppm")){
        return;
    }

        /* Comandos para terimanal de Linux para conversão de imagem */
    printf("Fazendo conversão da Imagem...\n");
    char comando[100];
    strcpy(comando,"convert ./imgs/");
    strcat(comando, Nome_imagem);
    strcat(comando," ./imgs/temp.ppm");
    system(comando);
    for(i=0;i<strlen(Nome_imagem);i++)Nome_imagem[i]='\0';
    strcpy(Nome_imagem,"temp.ppm\0");
}
void read_image_pgm_B(char *nome,IMG_PGM *N){
    FILE *number;

    char line[256];
    char caminho[50]={0};
    strcpy(caminho,"./imgs/");
    strcat(caminho,nome);
    number=fopen(caminho,"rb");

    N->name=(char*)calloc(strlen(nome),sizeof(char));
    strcpy(N->name,nome);
    if(number==NULL){
        printf("Arquivo inexistente...\n");
        return;
    }

    do{ /* Ignore comment lines. */
        fgets(line, 256, number);
    }while (line[0]=='#');
    sscanf(line, "%s", N->modo);

    if(N->modo[1]=='2'||N->modo[1]=='5')N->chns=1;
    if(N->modo[1]=='3'||N->modo[1]=='6')N->chns=3;
    if(N->modo[1]=='1'||N->modo[1]=='4')N->chns=8;

    do{ /* Ignore comment lines. */
        fgets(line, 256, number);
    }while (line[0]=='#');
    sscanf(line, "%d %d", &N->Horizontal ,&N->Vertical);
    fscanf(number,"%d", &N->Cor);

    /************************************************/
        /* Alocating space for the matrix */
    int i,j,alloc,alsocB,chn;
    N->matriz=(int***)malloc(N->chns*sizeof(int**));
    if(N->matriz==NULL){
        printf("Problema na criação da imagem...\n");
        exit(1);
    }
    for(alloc=0;alloc<N->chns;alloc++){
        N->matriz[alloc]=(int**)malloc(N->Vertical*(sizeof(int*)));
        if(N->matriz[alloc]==NULL){
            printf("Problema na criação da imagem...\n");
            exit(1);
        }
        for(i=0;i<N->Vertical;i++){
            N->matriz[alloc][i]=(int*)calloc(N->Horizontal,sizeof(int));
            if(N->matriz[alloc][i]==NULL){
                printf("Problema na criação da imagem...\n");
                exit(1);
            }
        }
    }
    /************************************************/
        /* Reading pixels matrix */
    int aux;
    N->ilum_mean=0;
    for(i=0;i<N->Vertical;i++){
        for(j=0;j<N->Horizontal;j++){
            for(chn=0;chn<N->chns;chn++){
                fread(&N->matriz[chn][i][j],1,1,number);
                N->ilum_mean+=N->matriz[chn][i][j];
                if(N->matriz[chn][i][j]>0)aux++;
            }
        }
    }
    printf("Image is %d X %d\n", N->Vertical,N->Horizontal);
    /************************************************/
    N->ilum_mean/=aux;
    printf("Ilumination Mean is: %.0f\n",N->ilum_mean);
    fclose(number);
    
}
void create_image(IMG_PGM Base,IMG_PGM *N){
    int i,j,alloc,alsocB,chn;
    N->matriz=(int***)malloc(Base.chns*sizeof(int**));
    if(N->matriz==NULL){
        printf("Problema na criação da imagem...\n");
        exit(1);
    }
    for(alloc=0;alloc<Base.chns;alloc++){
        N->matriz[alloc]=(int**)malloc(Base.Vertical*(sizeof(int*)));
        if(N->matriz[alloc]==NULL){
            printf("Problema na criação da imagem...\n");
            exit(1);
        }
        for(i=0;i<Base.Vertical;i++){
            N->matriz[alloc][i]=(int*)calloc(Base.Horizontal,sizeof(int));
            if(N->matriz[alloc][i]==NULL){
                printf("Problema na criação da imagem...\n");
                exit(1);
            }
        }
    }
    N->name=(char*)calloc(strlen(Base.name),sizeof(char));
    if(N->name==NULL){
        printf("Problema na criação da imagem...\n");
        exit(1);
    }
    cpyhead_image(Base,N);
}
void write_image(IMG_PGM N){
    FILE *novo;
    char dir[50]={0};
    strcpy(dir,"./imgs/");
    strcat(dir,N.name);
    novo=fopen(dir,"wb");
    fprintf(novo,"%s\n",N.modo);
    fprintf(novo,"%d %d\n", N.Horizontal ,N.Vertical);
    fprintf(novo,"%d\n", N.Cor);
    int i,j,chn;
    for(i=0;i<N.Vertical;i++){
        for(j=0;j<N.Horizontal;j++){
            for(chn=0;chn < N.chns; chn++){
                fwrite(&N.matriz[chn][i][j],1,1,novo);
            }
        }
    }
    fclose(novo);
} 
void convert_img_pgm(IMG_PGM *N){
    char comando[100];
    strcpy(comando,"convert ./imgs/");
    strcat(comando, N->name);
    strcat(comando," ./imgs/temp.pgm");
    system(comando);
    free_img_struct(N);
    read_image_pgm_B("temp.pgm",N);
}
/*******************/
/* Processing Images */

    /*  */
void normalize_image(IMG_PGM N, IMG_PGM *Dest){    
        int i,j,chn;
    for(chn=0;chn<N.chns;chn++){
        for(i=0;i<N.Vertical;i++){
            for(j=0;j<N.Horizontal;j++){
                if(N.matriz[chn][i][j]>N.ilum_mean){
                    Dest->matriz[chn][i][j]=255;
                }
                else {Dest->matriz[chn][i][j]=0;}
            }
        }
    }
    ilumination_mean(Dest);
}

    /*  */
void whiting_image(IMG_PGM N, IMG_PGM *Dest){
    int i,j,chn;
    for(chn=0;chn<N.chns;chn++){
        for(i=0;i<N.Vertical;i++){
            for(j=0;j<N.Horizontal;j++){
                if(N.matriz[chn][i][j]>100){
                    Dest->matriz[chn][i][j]=255;
                }
                else {Dest->matriz[chn][i][j]=0;}
            }
        }
    }
    ilumination_mean(Dest);
}
    /* Invert Black and White Colors */
void invertBW_image(IMG_PGM N,IMG_PGM *Dest){
    int i,j,chn;
    for(chn=0;chn<N.chns;chn++){
        for(i=0;i<N.Vertical;i++){
            for(j=0;j<N.Horizontal;j++){
                if(N.matriz[chn][i][j]>128){
                    Dest->matriz[chn][i][j]=N.matriz[chn][i][j]-128;
                }
                else Dest->matriz[chn][i][j]=N.matriz[chn][i][j]+128;
            }
        }
    }
    ilumination_mean(Dest);
}
    /* Not Ready */
void cut_image(IMG_PGM N, IMG_PGM *Dest){
    free_img_struct(&N);
    free_img_struct(Dest);
    printf("Função não funciona....\n");
    exit(1);
    ilumination_mean(Dest);
}

    /*  */
void find_corner(IMG_PGM N, IMG_PGM *Dest){
    int matrizX[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
    int matrizY[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
    int i,j,i_b,j_b,chn;
    int somaX,somaY;
    int cornerX;
    int cornerY;
    int meanX,meanY;
    
    Dest->chns=1;
    Dest->modo[1]='5';    
    for(i=0; i < N.Vertical; i++){
        for(j=0; j < N.Horizontal; j++){
            somaX=0;
            somaY=0;
            meanX=0;
            meanY=0;
            for(i_b = i-1; i_b < i+2 ; i_b++){
                for(j_b = j-1; j_b < j+2 ; j_b++){
                    for(chn=0;chn<N.chns;chn++){
                        if( (i_b<0) || (i_b>N.Vertical-2) ){
                            continue;
                        }
                        if(j_b<0 || (j_b>N.Horizontal-2)){
                            continue;
                        }
                        somaX+=(N.matriz[chn][i_b][j_b]*matrizX[i_b-i+1][j_b-j+1]);
                        somaY+=(N.matriz[chn][i_b][j_b]*matrizY[i_b-i+1][j_b-j+1]);
                        meanX+=modulo(matrizX[i_b-i+1][j_b-j+1]);
                        meanY+=modulo(matrizX[i_b-i+1][j_b-j+1]);
                    }
                }
            }
            /*
            cornerX=(somaX+4*255)/meanX;
            cornerY=(somaY+4*255)/meanY;
            */
            cornerX=somaX/meanX;
            cornerY=somaY/meanY;
            Dest->matriz[0][i][j]=sqrt(pow(cornerX,2)+pow(cornerY,2));
            if(i<2||i>N.Vertical-3||j<2||j>N.Horizontal-3){
                Dest->matriz[0][i][j]=0;
            }
        }
    }
    ilumination_mean(Dest);
}

    /* Blur the image if it's Black ad White */
void blur_image(IMG_PGM N, IMG_PGM *Dest){
    int i, j;
    int ib,jb,media,Pixel=0,chn,aux;
    Matriz2D *matrix;
    int BLUR;
    //printf("\t(1)Mean Blur\t\t\t(2)Gaussian Blur\n");
    //scanf("%d",&BLUR);
    matrix=create_blur_matriz(2);
    for(i=0;i<N.Vertical;i++){
        for(j=0;j<N.Horizontal;j++){
            for(chn=0;chn<N.chns;chn++){
                Pixel=0;
                aux=0;
                for(ib=i-1;ib<i+2;ib++){
                    for(jb=j-1;jb<j+2;jb++){
                        if(ib<0||jb<0||ib>N.Vertical-2||jb>N.Horizontal-2)continue;
                        Pixel+=N.matriz[chn][ib][jb]*matrix->data[ib-i+1][jb-j+1];
                        aux+=matrix->data[ib-i+1][jb-j+1];
                    }
                }
                Dest->matriz[chn][i][j]=Pixel/aux;
            }
        }
    }
    free_Matriz2D(matrix);
}

    /* Finding other image */
void find_otherimg(IMG_PGM N ,IMG_PGM *Dest){
    char nome[100];
    IMG_PGM Other;
    read_image_name(nome);
    read_image_pgm_B(nome,&Other);
    if(Other.Vertical>N.Vertical||Other.Horizontal>N.Horizontal){
        printf("Imagem invalida\n");
        exit(1);
    }
    if(N.chns!=Other.chns){
        printf("There is diference in the format images...closing...\n");
        exit(1);
    }
    int i,j,i_1,j_1;
    int resultX,resultY,loops=0,chn;
    int i_min,j_min;
    double dist,dist_min,dist_max, min=INT_MAX,max=0;
    resultY=N.Horizontal-Other.Horizontal;
    resultX=N.Vertical-Other.Vertical;
    
    /* 4 loops here*/
    /*The first 2 are for passing through the original image*/
    /*The other 2 pass in the image selected to find and make the distance between the pixels in the image */
    /*After a simple "if" to find the minimun distance */
    /* Be aware that in some images that program will be slow because the size of the images choosen can make this loops last for like forever pokdskapo :c */

    for(i=0; i < resultX ;i++){
        for(j=0; j < resultY ;j++){
            dist=0;
            for(chn=0;chn<N.chns;chn++){
                for(i_1=0; i_1 < Other.Vertical ;i_1++){
                    for(j_1=0; j_1 < Other.Horizontal ;j_1++){
                        dist+=abs(N.matriz[chn][i_1+i][j_1+j]-Other.matriz[chn][i_1][j_1]);
                    }
                }
            }
            if(dist<min){
                min=dist;
                i_min=i;
                j_min=j;
            }
            if(dist>max){
                max=dist;
            }
        }
    }
    printf("The most likely image was found in :%d %d\n",i_min,j_min);
    /* This part is just to cut the image in the right place */
    cpyhead_image(N,Dest);
    for(i=0; i < N.Vertical; i++){
        for(j=0;j < N.Horizontal; j++){
            for(chn=0;chn<N.chns;chn++){
                Dest->matriz[chn][i][j]=N.matriz[chn][i][j];
                if(i>i_min&&i<(i_min+Other.Vertical)&&j>j_min&&j<(j_min+Other.Horizontal)){
                    continue;
                }   
                else{
                    Dest->matriz[chn][i][j]-=128;
                    if( Dest->matriz[chn][i][j]<0)Dest->matriz[chn][i][j]=0;
                }
            }
        }
    }
    free_img_struct(&Other);
}

void finding_structures(IMG_PGM N,IMG_PGM *Dest){
    int i,j,i_aux,j_aux,quad_size,chn;
    float Pixeis_brancos=0;
    int Larger_side;
    char nome_antigo[100];
    if(N.Horizontal<N.Vertical)Larger_side=N.Horizontal;
    else Larger_side=N.Vertical;
    if(N.chns!=1){
        strcpy(nome_antigo,N.name);
        convert_img_pgm(&N);
    }

    double Quad;
    double Greater_Values,Greater_Value_before=0;
    double Better_Value=0;
    int i_larger,j_larger;
    int i_better,j_better;
    int quad_better;
    int inic;
    double inc_rate;
    /* Findind the amount of white pixels in the image */
    for(i=0;i<N.Vertical;i++){
        for(j=0;j<N.Horizontal;j++){
            if(N.matriz[0][i][j]>0)Pixeis_brancos++;
        }
    }

    inic=Larger_side/5;
    inc_rate = 1.20;

    for(quad_size=inic;quad_size<Larger_side;quad_size*=inc_rate){
        Greater_Values=0;
        for(i=0;i<N.Vertical-quad_size;i++){
            for(j=0;j<N.Horizontal-quad_size;j++){
                Quad=0;
                for(i_aux=i;i_aux<quad_size+i;i_aux++){
                    for(j_aux=i;j_aux<quad_size+j;j_aux++){
                        if(N.matriz[0][i_aux][j_aux]>0){
                            Quad++;
                        }
                    }
                }
                if(Quad>Greater_Values){
                    Greater_Values=Quad;
                    i_larger=i;
                    j_larger=j;
                }
            }
        }
        printf("Percentage: %.2f%%\n",100*(double)quad_size/Larger_side);
        printf("\tLuminosity Percentage:\t%.3f%% \n",(Greater_Values*100/(quad_size*Pixeis_brancos)));
        printf("\tPercentage of Pixels:\t%.3f%%\n",Greater_Values*100/Pixeis_brancos);
        if((Greater_Values/quad_size)>(Better_Value/quad_better)){
            Better_Value=Greater_Values;
            i_better=i_larger;
            j_better=j_larger;
            quad_better=quad_size;
            printf("\tThe best fitness was found on (%d;%d)\n",i_better,j_better);
        }
        else{
            break;
        }
    }
    printf("\nThe best fitness is on %d,%d\n",i_better,j_better);
    printf("New Image is %d X %d\n",quad_better,quad_better);

    if(N.chns!=1)read_image_pgm_B(nome_antigo,&N);

    strcpy(Dest->modo,N.modo);
    Dest->Vertical=quad_better;
    Dest->Horizontal=quad_better;
    Dest->Cor=N.Cor;
    for(chn=0;chn<N.chns;chn++){
        for(i=i_better;i<i_better+quad_better;i++){
            for(j=j_better;j<j_better+quad_better;j++){
                Dest->matriz[chn][i-i_better][j-j_better]=N.matriz[chn][i][j];
            }
        }
    }

}

void separate_maximuns(IMG_PGM N, IMG_PGM *Dest){
    int i,j,i_aux,j_aux;
    int i_max,j_max,max;
    for(i=0;i<N.Vertical;i++){
        for(j=0;j<N.Horizontal;j++){
            max=0;
            for(i_aux=i-1;i_aux<i+2;i_aux++){
                for(j_aux=j-1;j_aux<j+2;j_aux++){
                    if(i_aux<0 || i_aux>(N.Vertical-2) || j_aux<0 || j_aux>(N.Horizontal-2)){
                            continue;
                        }
                    if(N.matriz[0][i_aux][j_aux]>max){
                        max=N.matriz[0][i_aux][j_aux];
                        i_max=i_aux;
                        j_max=j_aux;
                    }
                }
            }
            if((i_max==i && j_max==j) || N.matriz[0][i][j]==N.matriz[0][i_max][j_max]){
                Dest->matriz[0][i][j]=N.matriz[0][i][j];
            }
            else{
                Dest->matriz[0][i][j]=0;
            }
        }
    }
}
void separating_structures(IMG_PGM N ,IMG_PGM *Dest){
    int i,j,j_aux,i_aux,bol;
    ilumination_mean(&N);
    for(i=0;i<N.Vertical;i++){
        for(j=0;j<N.Horizontal;j++){
            if(N.matriz[0][i][j]>N.ilum_mean){
                Dest->matriz[0][i][j]=N.matriz[0][i][j];
                continue;
            }
            else{
                bol=0;
                for(i_aux=i-1;i_aux<i+2;i_aux++){
                    for(j_aux=j-1;j_aux<j+2;j_aux++){
                        if(i_aux<0 || i_aux>(N.Vertical-2) || j_aux<0 || j_aux>(N.Horizontal-2)){
                            continue;
                        }
                        else{
                            if(N.matriz[0][i_aux][j_aux]>N.ilum_mean){
                                bol=1;
                            }   
                        }
                    }
                }
                if(bol){
                    Dest->matriz[0][i][j]=N.matriz[0][i][j];
                }
                else{
                    Dest->matriz[0][i][j]=0;
                }
            }
        }
    }
}
/****************/
/* Processing Metodes */

void process_1(IMG_PGM N, IMG_PGM *Dest){
    int i;
    whiting_image(N,Dest);
    for(i=0;i<5;i++)blur_image(*Dest, Dest);
    normalize_image(*Dest,Dest);
}
    /* Highlight the darkest space on image */
void process_2(IMG_PGM N, IMG_PGM *Dest){
    whiting_image(N,Dest);
    find_corner(*Dest,Dest);
}