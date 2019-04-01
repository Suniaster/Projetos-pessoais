#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
char tabu[3][3];
int NUM=50000;
char tabuFUT[3][3];
int acabouX(){
    int i, j, vitoria;
    for(i=0;i<3;i++){
        vitoria=((tabu[i][0]!=' ') && (tabu[i][0]==tabu[i][1] && tabu[i][0]==tabu[i][2]));  
        if(vitoria==1){
    
            return 0;
        }
        else{
            continue;
        }         
    }
    for(j=0;j<3;j++){
        vitoria=(tabu[0][j]!=' ' && tabu[0][j]==tabu[1][j] && tabu[0][j]==tabu[2][j]);  
            if(vitoria==1){
        
                return 0;
            }
            else{
                continue;
            }
    }
    if(tabu[0][0]!=' '&&tabu[0][0]==tabu[1][1] && tabu[0][0]==tabu[2][2]){

        return 0;
    }
    if(tabu[0][2]!=' ' &&tabu[0][2]==tabu[1][1] && tabu[0][2]==tabu[2][0]){

        return 0;

    }
    return 1;
}
int acabouO(){
    int i,j,vitoria;
    for(i=0;i<3;i++){
        vitoria=(tabu[i][0]!=' ' && tabu[i][0]==tabu[i][1] && tabu[i][0]==tabu[i][2]);  
            if(vitoria==1){
                
                return 0;
                
            }
            else{
                continue;
            }
    }
    for(j=0;j<3;j++){
        vitoria=(tabu[0][j]!=' ' && tabu[0][j]==tabu[1][j] && tabu[0][j]==tabu[2][j]);  
        if(vitoria==1){
            
            return 0;
            
        }
        else{
            continue;
        }
    }
    if(tabu[0][0]!=' '&&tabu[0][0]==tabu[1][1] && tabu[0][0]==tabu[2][2]){
        
        return 0;
        
    }
    if(tabu[0][2]!=' '&&tabu[0][2]==tabu[1][1] && tabu[0][2]==tabu[2][0]){
        
        return 0;
        
    }
    return 1;
}
void Inic_Random(){
    long ultime;
    time(&ultime);
    srand((unsigned)ultime);
}
int aleatorio(){
    int n=0;
    n=rand()%3;
    return n;
}
void desenho(){
    int i=0, j=0;
    printf("_____________\n");
    for(i=0;i<3;i++){
        printf("|");
        for(j=0;j<3; j++){
            printf(" %c ",tabu[i][j]);
            if(j!=2){
                printf("|");
            }
        }
        printf("|");
        printf("\n");
        if(i!=2){
            printf("----+---+----\n");
        }
    }
    printf("‾‾‾‾‾‾‾‾‾‾‾‾‾\n");
}
void frasevitoria(){
    int n;
    Inic_Random();
    n=rand()%16;
    switch(n){
        case 0:
        printf("\"A primeira e melhor vitória é conquistar a si mesmo.\" -Platão \n");
        break;
        case 1:
        printf("A Grande Conquista é o resultado de pequenas vitorias que passam despercebidas.\n");
        break;
        case 2:
        printf("Antes da vitória vem a tentação. E quanto maior os louros a conquistar, maior a tentação a que é preciso resistir\n");
        break;
        case 3:
        printf("Nunca saberemos o quão forte somos até que ser forte seja a única escolha.\n");
        break;
        case 4:
        printf("Insista, persista e nunca desista.\n");
        break;
        case 5:
        printf("Deus está morto, eu irei substitui-lo.\n");
        break;
        case 6:
        printf("Sem sacrifício não há vitória.\n");
        break;
        case 7:
        printf("O caminho é longo, mas a vitória é certa!\n");
        break;
        case 8:
        printf("Se alguém jogar pedra no seu caminho, junte-as, forme degraus e suba rumo à vitória.\n");
        break;
        case 9:
        printf("Grandes vitórias exigem grande dedicação.\n");
        break;
        case 10:
        printf("Quem teme ser vencido tem a certeza da derrota.\n");
        break;
        case 11:
        printf("Não fica desanimado, amanhã tem outra derrota.\n");
        break;
        case 12:
        printf("Muitos vão tentar me derrubar, mais muitos vão cair.\n");
        break;
        case 13:
        printf("Já ouvi falar em derrotas, mas não sei o que é!\n");
        break;
        case 14:
        printf("Vencer não é competir com o outro. É derrotar seus inimigos interiores.!\n");
        break;
        case 15:
        printf("Vencer é refazer as derrotas ao contrário.\n");
        break;
        
        
    }
}   
void frasederrota(){
    int n;
    Inic_Random();
    n=rand()%14;
    switch(n){
        case 0:
        printf("Nunca fale derrota. Use palavras como esperança, crença, fé, vitória. \n");
        break;
        case 1:
        printf("Ninguém é derrotado, a menos que comece a culpar os outros. \n");
        break;
        case 2:
        printf("As derrotas da vida conduzem às maiores vitórias. \n");
        break;
        case 3:
        printf("Existem algumas derrotas mais triunfantes que vitórias. \n");
        break;
        case 4:
        printf("É melhor uma derrota honrosa do que uma vitória indigna.\n");
        break;
        case 5:
        printf("Vencer se torna uma derrota, quando não se ganha com dignidade.\n");
        break;
        case 6:
        printf("Uma derrota não irá me deviar do caminho até o sucesso.\n");
        break;
        case 7:
        printf("A vitória tem mil pais, mas a derrota é orfã. \n");
        break;
        case 8:
        printf("Derrota após derrota até a vitória final.\n");
        break;
        case 9:
        printf("Pouco se aprende com a vitória, mas muito com a derrota.\n");
        break;
        case 10:
        printf("O que as vitórias têm de mau é que não são definitivas.\nO que as derrotas têm de bom é que também não são definitivas.\n");
        break;
        case 11:
        printf("Quantas derrotas são necessárias para compor uma vitória?\n");
        break;
        case 12:
        printf("Sempre é melhor uma derrota que salva, do que uma vitória que mata.\n");
        break;
        case 13 :
        printf("Nunca se dobre à derrota, aprenda com ela, levante a cabeça, e inicie o caminho para a vitória.\n");
        break;
    }
}
void IaX(){
    int dados[NUM][21];
    int partida[18],s=0, possibilidade[NUM], p=0;
    int i=0,j=0,l=0,k=0, i1,j1, b, m=0,x=0,o=0,e=0, maior=0, maiorl=0;
    int C=0, cont=1, f=0,v=3,u=0, opt=0, la, ka,der=0, zeta=0, lx=0, kx=0, nove[NUM], beta=0,alfa;
    int rod=0,opd=0,zin=0;
    int possibilidadeD[NUM], ichi=0, nii=0, san=0, jii=0, maiorlD,maiorD,  noveD[NUM], baz=0;
    for(l=0;l<3;l++){
        for(k=0;k<3;k++){
            tabu[l][k]=' ';
        }    
    }
    for(s=0;s<18;s++){
        partida[s]=9;
    }
    FILE *stream;
    FILE *esc;
    esc = fopen("dado.txt", "a+");
    stream = fopen ("dado.txt","r"); 
    for(i=0;i<NUM;i++){
        for(j=0;j<21;j++){
            fscanf(stream, "%d", &dados[i][j]);
            
        }
        rod++;
    }

    for(cont=1;cont<=9;){
        //jogada X
        if(cont%2==1){
            if(cont==1){
                lx=aleatorio();
                kx=aleatorio();
                tabu[lx][kx]='X';
                system("clear");
                desenho();
                partida[C]=lx;
                partida[C+1]=kx;
                C=C+2;
            }
            else{
                for(baz=0;baz<NUM;baz++){
                    noveD[baz]=0;
                    nove[baz]=0;
                }
                opt=0;
                opd=0;
                p=0;
                der=0;
                maior=0;
                maiorlD=0;
                maiorD=0;
                maiorl=0;
                for(i1=0;i1<NUM;i1++){
                    for(j1=0;j1<((cont*2)-2) && dados[i1][j1]==partida[j1];j1++){
                        if(j1 == (cont*2)-3){
                            if(dados[i1][18]==1){
                                possibilidade[p]=i1;
                                p++;
                                opt++;
                            }
                            if(dados[i1][19]==1){
                                possibilidadeD[der]=i1;
                                der++;
                                opd++;
                            }
                        else{
                           continue;
                        }
                        }
                    } 
                }
                if(opt==0 && opd==0){
                    printf("calculando..\n");
                    lx=aleatorio();
                    kx=aleatorio();
                    while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                        lx=aleatorio();
                        kx=aleatorio();
                    }
                    system("clear");
                    desenho();
                }
                else{
                    //Vê qual linha que tem vitoria tem mais 9s{
                    for(beta=0;beta<p;beta++){
                        for(alfa=17;(alfa>cont*2-2);alfa--){
                            if(dados[possibilidade[beta]][alfa]==9){
                            nove[beta]++;
                            }
                            else{
                                continue;
                            }
                        }
                    }
                    for(zeta=0; zeta<p;zeta++){
                        if(nove[zeta]>maior){
                            maior=nove[zeta];
                            maiorl=zeta;
                        }
                    }
                    //Vê qual linha que tem vitoria tem mais 9s} 
                    //Vê a linha derrota com mais 9s}
                    for(ichi=0;ichi<der;ichi++){
                        for(nii=0;nii<21;nii++){
                            if(dados[possibilidadeD[ichi]][nii] == 9){
                            noveD[ichi]++;
                            }
                            else{
                               continue;
                            }
                        }
                    }
                    for(san=0; san<der;san++){
                        if(noveD[san]>maiorD){
                            maiorD=noveD[san];
                            maiorlD=san;
                        }
                        else{
                            continue;
                        }
                    }          
                    //Vê a linha derrota com mais 9s]
               
                    //Se a Partida com mais 9s for uma derrota, ele preve o movimento do outro jogador e para ele
                    if(maiorD>maior){
                        lx=dados[possibilidadeD[maiorlD]][cont*2+0];
                        kx=dados[possibilidadeD[maiorlD]][cont*2+1];
                    }
                    else{
                        lx=dados[possibilidade[maiorl]][cont*2-2];
                        kx=dados[possibilidade[maiorl]][cont*2-1];  
                    }
                }
                //lx=dados[possibilidade[maiorl]][cont*2+1];
                //kx=dados[possibilidade[maiorl]][cont*2+2];     
                /*while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                    lx=aleatorio();
                    kx=aleatorio();
                }
                */
                tabu[lx][kx]='X';
                system("clear");
                desenho();
                partida[C]=lx;
                partida[C+1]=kx;
                C=C+2;
            }
            v=acabouX();
            if(v==0){
                x++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                return ;
            }
            else{}
        }
        //Jogada O
        else{
            //scanf("%d %d", &la, &ka);
            la=aleatorio()+1;
            ka=aleatorio()+1;
            while (la<0||la>3||ka<0||ka>3||tabu[la-1][ka-1]!=' '){
                la=aleatorio()+1;
                ka=aleatorio()+1;
                //scanf("%d %d", &la , &ka);
                //printf("cao..\n");
            }
            tabu[la-1][ka-1]='O';
            system("clear");
            desenho();
            partida[C]=la-1;
            partida[C+1]=ka-1;
            C=C+2;
            v=acabouO();
            if(v==0){
                o++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                return ;
                
            }
        }
        cont=cont+1;
    }
    e++;
    fprintf(esc, "\n");
    for(m=0; m<18;m++){
        fprintf(esc, "%d " , partida[m]);
    }
    fprintf(esc,"%d %d %d", x, o, e);
    fclose(esc);
    fclose(stream);
    return ;
}
void IaO(){
    int dados[NUM][21];
    int partida[18],s=0, possibilidade[NUM], p=0;
    int i=0,j=0,l=0,k=0, i1,j1, b, m=0,x=0,o=0,e=0, maior=0, maiorl=0;
    int C=0, cont=1, f=0,v=3,u=0, opt=0, la, ka,der=0, zeta=0, lx=0, kx=0, nove[NUM], beta=0,alfa;
    int rod=0,opd=0,zin=0;
    int possibilidadeD[NUM], ichi=0, nii=0, san=0, jii=0, maiorlD,maiorD,  noveD[NUM], baz=0;
    for(l=0;l<3;l++){
        for(k=0;k<3;k++){
            tabu[l][k]=' ';
        }    
    }
    for(s=0;s<18;s++){
        partida[s]=9;
    }
    FILE *stream;
    FILE *esc;
    esc = fopen("dado.txt", "a+");
    stream = fopen ("dado.txt","r"); 
    for(i=0;i<NUM;i++){
        for(j=0;j<21;j++){
            fscanf(stream, "%d", &dados[i][j]);
            
        }
        rod++;
    }

    for(cont=1;cont<=9;){
        //jogada O
        if(cont%2==0){
            if(cont==1){
                lx=aleatorio();
                kx=aleatorio();
                tabu[lx][kx]='O';
                system("clear");
                desenho();
                partida[C]=lx;
                partida[C+1]=kx;
                C=C+2;
            }
            else{
                for(baz=0;baz<NUM;baz++){
                    noveD[baz]=0;
                    nove[baz]=0;
                }
                opt=0;
                opd=0;
                p=0;
                der=0;
                maior=0;
                maiorlD=0;
                maiorD=0;
                maiorl=0;
                for(i1=0;i1<NUM;i1++){
                    for(j1=0;j1<((cont*2)-2) && dados[i1][j1]==partida[j1];j1++){
                        if(j1 == (cont*2)-3){
                            if(dados[i1][19]==1){
                                possibilidade[p]=i1;
                                p++;
                                opt++;
                            }
                            if(dados[i1][18]==1){
                                possibilidadeD[der]=i1;
                                der++;
                                opd++;
                            }
                        else{
                           continue;
                        }
                        }
                    } 
                }
                if(opt==0 && opd==0){
                    printf("calculando..\n");
                    lx=aleatorio();
                    kx=aleatorio();
                    while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                        lx=aleatorio();
                        kx=aleatorio();
                    }
                    system("clear");
                    desenho();
                }
                else{
                    //Vê qual linha que tem vitoria tem mais 9s{
                    for(beta=0;beta<p;beta++){
                        for(alfa=17;(alfa>cont*2-2);alfa--){
                            if(dados[possibilidade[beta]][alfa]==9){
                            nove[beta]++;
                            }
                            else{
                                continue;
                            }
                        }
                    }
                    for(zeta=0; zeta<p;zeta++){
                        if(nove[zeta]>maior){
                            maior=nove[zeta];
                            maiorl=zeta;
                        }
                    }
                    //Vê qual linha que tem vitoria tem mais 9s} 
                    //Vê a linha derrota com mais 9s}
                    for(ichi=0;ichi<der;ichi++){
                        for(nii=0;nii<21;nii++){
                            if(dados[possibilidadeD[ichi]][nii] == 9){
                            noveD[ichi]++;
                            }
                            else{
                               continue;
                            }
                        }
                    }
                    for(san=0; san<der;san++){
                        if(noveD[san]>maiorD){
                            maiorD=noveD[san];
                            maiorlD=san;
                        }
                        else{
                            continue;
                        }
                    }          
                    //Vê a linha derrota com mais 9s]
               
                    //Se a Partida com mais 9s for uma derrota, ele preve o movimento do outro jogador e para ele
                    if(maiorD>maior){
                        lx=dados[possibilidadeD[maiorlD]][cont*2+0];
                        kx=dados[possibilidadeD[maiorlD]][cont*2+1];
                    }
                    else{
                        lx=dados[possibilidade[maiorl]][cont*2-2];
                        kx=dados[possibilidade[maiorl]][cont*2-1];  
                    }
                }
                //lx=dados[possibilidade[maiorl]][cont*2+1];
                //kx=dados[possibilidade[maiorl]][cont*2+2];     
                /*while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                    lx=aleatorio();
                    kx=aleatorio();
                }
                */
                tabu[lx][kx]='O';
                system("clear");
                desenho();
                partida[C]=lx;
                partida[C+1]=kx;
                C=C+2;
            }
            v=acabouX();
            if(v==0){
                o++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                return ;
            }
            else{}
        }
        //Jogada O
        else{
            system("clear");
            desenho();
            //scanf("%d %d", &la, &ka);
            la=aleatorio()+1;
            ka=aleatorio()+1;
            while (la<0||la>3||ka<0||ka>3||tabu[la-1][ka-1]!=' '){
                la=aleatorio()+1;
                ka=aleatorio()+1;
                //scanf("%d %d", &la , &ka);
                //printf("cao..\n");
            }

            tabu[la-1][ka-1]='X';
            partida[C]=la-1;
            partida[C+1]=ka-1;
            C=C+2;
            v=acabouO();
            if(v==0){
                x++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                return ;
                
            }
        }
        cont=cont+1;
    }
    e++;
    fprintf(esc, "\n");
    for(m=0; m<18;m++){
        fprintf(esc, "%d " , partida[m]);
    }
    fprintf(esc,"%d %d %d", x, o, e);
    fclose(esc);
    fclose(stream);
    return ;
}
//BotX_contraHumano ta com mais da lógica certa(Comentado)
void BotX_contrahumano(){
    int dados[NUM][21];
    int partida[18],s=0, possibilidade[NUM], p=0, n=0, c=0, vitoria,d;
    int i=0,j=0,l=0,k=0,y,V,Z,i1,j1, b, m=0,x=0,o=0,e=0, maior=0, maiorl=0;
    int C=0, cont=1, f=0,v=3,u=0, opt=0, la, ka,der=0, zeta=0, lx=0, kx=0, nove[NUM], beta=0,alfa;
    int rod=0,opd=0,zin=0;
    float Porc;
    int jogos;
    int lolD;
    int possibilidadeD[NUM], ichi=0, nii=0, san=0, jii=0, maiorlD,maiorD,P,  noveD[NUM], iguaisD[NUM] ,baz=0,I,L,iguais[NUM],lol=0;
    //Deixa todos os espaços do tabuleiro livres
    for(l=0;l<3;l++){
        for(k=0;k<3;k++){
            tabu[l][k]=' ';
        }    
    }
    //Torna todas a jogadas da partida atual 9, já que ela não começou ainda
    for(s=0;s<18;s++){
        partida[s]=9;
    }
    //Leitura de dados e rewrite deles
    FILE *stream;
    FILE *esc;
    esc = fopen("dado.txt", "a+");
    stream = fopen ("dado.txt","r");
    for(i=0;i<NUM;i++){
        for(j=0;j<21;j++){
            fscanf(stream, "%d", &dados[i][j]);
            
        }
        rod++;
    }
    //Partida começa Aqui
    for(cont=1;cont<=9;){
        //jogada X
        if(cont%2==1){
            //Primeira jogada aleatoria(Ainda pretendo  tirar isso)
            if(cont==0){
                lx=aleatorio();
                kx=aleatorio();
                tabu[lx][kx]='X';
                system("clear");
                desenho();
                partida[C]=lx;
                partida[C+1]=kx;
                C=C+2;
            }
            else{
                //Torna 0 todos os espaços dos arrays "nove" e "noveD"
                for(baz=0;baz<NUM;baz++){
                    noveD[baz]=0;
                    nove[baz]=0;
                }
                //Essas váriaveis precisão ser resetadas toda jogada pra lógica funcionar
                b=0;
                c=0;
                y=0;
                Z=0;
                V=0;
                opt=0;
                opd=0;
                p=0;
                der=0;
                maior=0;
                maiorlD=0;
                maiorD=0;
                maiorl=0;
                n=0;
                jogos=0;
                lol=0;
                lolD=0;
                //Todo esse for(b=0;b<3... serve para ver se na prox jogada é possivel GANHAR, e se for fazer esse jogada [b][c]
                for(b=0;b<3;b=b+1){
                    for(c=0;c<3;c=c+1){
                        for(l=0;l<3;l++){
                            for(k=0;k<3;k++){
                                tabuFUT[l][k]=tabu[l][k];
                            }    
                        }
                        if(tabuFUT[b][c]==' '){
                            tabuFUT[b][c]='X';
                            for(i=0;i<3;i++){
                                vitoria=((tabuFUT[i][0]!=' ') && (tabuFUT[i][0]==tabuFUT[i][1] && tabuFUT[i][0]==tabuFUT[i][2]));  
                                if(vitoria==1){
                                    n=1;

                                }
                                else{
                                    continue;
                                }         
                            }
                            for(j=0;j<3;j++){
                                vitoria=(tabuFUT[0][j]!=' ' && tabuFUT[0][j]==tabuFUT[1][j] && tabuFUT[0][j]==tabuFUT[2][j]);  
                                    if(vitoria==1){
                                        n=1;
                                    }
                                    else{
                                        continue;
                                    }
                            }
                            if(tabuFUT[0][0]!=' '&&tabuFUT[0][0]==tabuFUT[1][1] && tabuFUT[0][0]==tabuFUT[2][2]){
                                    n=1;                     
                            }
                            else{}
                            if(tabuFUT[0][2]!=' ' &&tabuFUT[0][2]==tabuFUT[1][1] && tabuFUT[0][2]==tabuFUT[2][0]){
                                n=1;
        
                            }
                            else{}
                            if(n==1){
                                break;
                            }
                        }
                        if(n==1){
                                break;
                            }
                        else{
                        }
                        if(n==1){
                                break;
                            }
                    }
                    if(n==1){
                                break;
                            }
                }
                if(n==1){
                    tabu[b][c]='X';
                    system("clear");
                    desenho();
                    partida[C]=b;
                    partida[C+1]=c;
                    C=C+2;
                }
                else{
                    //Todo esse for(Z=0;Z<3... serve para ver se na prox jogada é possivel PERDER, e se for, jogar no lugar que faria perder [Z][V]
                    for(Z=0;Z<3;Z=Z+1){
                        for(V=0;V<3;V=V+1){
                            for(l=0;l<3;l++){
                                for(k=0;k<3;k++){
                                    tabuFUT[l][k]=tabu[l][k];
                                }    
                            }
                            if(tabuFUT[Z][V]==' '){
                                tabuFUT[Z][V]='O';
                                for(i=0;i<3;i++){
                                    vitoria=((tabuFUT[i][0]!=' ') && (tabuFUT[i][0]==tabuFUT[i][1] && tabuFUT[i][0]==tabuFUT[i][2]));  
                                    if(vitoria==1){
                                        y=1;

                                    }
                                    else{
                                        continue;
                                    }         
                                }
                                for(j=0;j<3;j++){
                                    vitoria=(tabuFUT[0][j]!=' ' && tabuFUT[0][j]==tabuFUT[1][j] && tabuFUT[0][j]==tabuFUT[2][j]);  
                                        if(vitoria==1){
                                            y=1;
                                        }
                                        else{
                                            continue;
                                        }
                                }
                                if(tabuFUT[0][0]!=' '&&tabuFUT[0][0]==tabuFUT[1][1] && tabuFUT[0][0]==tabuFUT[2][2]){
                                        y=1;                     
                                }
                                else{}
                                if(tabuFUT[0][2]!=' ' &&tabuFUT[0][2]==tabuFUT[1][1] && tabuFUT[0][2]==tabuFUT[2][0]){
                                    y=1;
            
                                }
                                else{}
                                if(y==1){
                                    break;
                                }
                            }
                            if(y==1){
                                    break;
                                }
                            else{
                            }
                            if(y==1){
                                    break;
                                }
                        }
                        if(y==1){
                                    break;
                                }
                    }
                    if(y==1){
                        tabu[Z][V]='X';
                        system("clear");
                        desenho();
                        printf("Quase HEIN!\n");
                        partida[C]=Z;
                        partida[C+1]=V;
                        C=C+2;
                    }
                    //Caso não for possivel ganhar nem perder, entra nesse else
                    else{
                        //Esse for vê qual linhas dos dados é igual a sequencia de jogadas atuais e representa uma vitoria ou uma derrota
                        //Enquanto faz isso grava o números das linhas nos arrayz possibilidade[] e possibilidadeD[](D de derrota)
                        for(i1=0;i1<NUM;i1++){
                            for(j1=0;j1<((cont*2)-2) && dados[i1][j1]==partida[j1];j1++){
                                if(j1 == (cont*2)-3){
                                    if(dados[i1][19]==1){
                                        possibilidade[p]=i1;
                                        p++;
                                        opt++;
                                        jogos++;
                                    }
                                    if(dados[i1][18]==1){
                                        possibilidadeD[der]=i1;
                                        der++;
                                        opd++;
                                        jogos++;
                                    }
                                    if(dados[i1][20]==1){
                                        jogos++;
                                    }
                                else{
                                    continue;
                                }
                                }
                            } 
                        }
                        //Se opt e opd forem ambos 0 quer dizer que não há a sequencia de jogadas atuais no banco de dados e portanto a jogada feita será aleatoria
                        if(opt==0 && opd==0){
                            printf("Partida fora dos Dados, calculando...\n");
                            lx=aleatorio();
                            kx=aleatorio();
                            while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                                lx=aleatorio();
                                kx=aleatorio();
                            }
                            system("clear");
                            desenho();
                        }
                        else{
                            //Vendo quais jogos são iguais e quantos são
                            for(P=0;P<(opt-lol);P++){
                                for(L=0;L<opt;L++){
                                    for(I=0;I<21;I++){
                                        if(dados[possibilidade[P]][I] == dados[possibilidade[L]][I] && I==20){
                                            possibilidade[L]==possibilidade[P];
                                            iguais[P]++;
                                            lol++;
                                        }
                                        else{continue;}
                                    }
                                }
                            }
                            for(P=0;P<(opd-lolD);P++){
                                for(L=0;L<opd;L++){
                                    for(I=0;I<21;I++){
                                        if(dados[possibilidadeD[P]][I] == dados[possibilidadeD[L]][I] && I==20){
                                            possibilidadeD[L]==possibilidadeD[P];
                                            iguaisD[P]++;
                                            lolD++;
                                        }
                                        else{continue;}
                                    }
                                }
                            }
                            //Grava a quantidade de 9s linha que representa vitória
                            // EXEMPLO: possibilidade[0]= 23 (linha do banco de dados)// nove[0]=6 (a linha 23 do banco de dados possui 6 '9s')
                            for(beta=0;beta<(p-lol);beta++){
                                for(alfa=17;(alfa>cont*2-2);alfa--){
                                    if(dados[possibilidade[beta]][alfa]==9){
                                    nove[beta]++;
                                    }
                                    else{
                                        continue;
                                    }
                                }
                            }
                            //Vê qual dessas linhas de vitoria possui mais 9s (ou seja, acaba mais rapido e leva pra uma vitoria mais rapida)
                            //Grava a quantidade de noves da linha com mais nove em 'maior' e a respectiva linha em 'maiorl'
                            for(zeta=0; zeta<(p-lol);zeta++){
                                if(nove[zeta]>maior){
                                    maior=nove[zeta];
                                    maiorl=zeta;
                                }
                                else{}
                                //Caso duas linhas diferentes tenham a mesma quantidade de 9s para a vitoria, é escolhida a com maior winrate
                                if(nove[zeta]==maior){
                                    if(iguais[zeta]/(double)jogos > maiorl/(double)jogos){
                                        maior=nove[zeta];
                                        maiorl=zeta;
                                    }
                                }
                                else{}
                            }
                            //Vê a linha derrota com mais 9s
                            //MESMA COISA DO QUE ACONTECEU ACIMA PORÉM SERVE PARA DERROTAS(Variaves possuem um 'D' na frente)
                            for(ichi=0;ichi<der;ichi++){
                                for(nii=0;nii<21;nii++){
                                    if(dados[possibilidadeD[ichi]][nii] == 9){
                                    noveD[ichi]++;
                                    }
                                    else{
                                    continue;
                                    }
                                }
                            }
                            for(san=0; san<der;san++){
                                if(noveD[san]>maiorD){
                                    maiorD=noveD[san];
                                    maiorlD=san;
                                }
                                else{}
                                if(noveD[san]==maiorD){
                                   if(iguaisD[san]/(double)jogos > maiorlD/(double)jogos){
                                        maiorD=nove[san];
                                        maiorlD=san;
                                    }
                                }
                                else{}
                            }          
                    
                            //Verifica se a quantidade de 9s da linha com derrota é maior que a da linha de vitória 
                            //Ou seja, se a derrota chega mais rapido que a vitória na sequencia de jogadas escolhida
                            if(maiorD>maior){
                                //Se a quantidade 9s de uma derrota for 2, o bot irá perder por causa da ultima jogada da 0
                                //Portanto aqui ele irá copiar esse jogada antes do bot faze-la
                                if(maiorD == 2){
                                    lx=dados[possibilidadeD[maiorlD]][14];
                                    kx=dados[possibilidadeD[maiorlD]][15];
                                }
                                else{
                                    if(dados[possibilidadeD[maiorlD]][cont*2+2]==9){
                                        lx=dados[possibilidadeD[maiorlD]][cont*2+0];
                                        kx=dados[possibilidadeD[maiorlD]][cont*2+1];
                                    }
                                    else{
                                        lx=dados[possibilidade[maiorl]][cont*2+2];
                                        kx=dados[possibilidade[maiorl]][cont*2+3];
                                    }
                                }
                            }
                            //Só continua com a sequencia que leva a vitória mais rapido caso nada do acima tenha acontecido
                            else{
                                lx=dados[possibilidade[maiorl]][cont*2-2];
                                kx=dados[possibilidade[maiorl]][cont*2-1];
                            }
                        }
                        if(lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                            //Medida preventiva pro bot não roubar
                             printf("Woopsy\n");
                            while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                                lx=aleatorio();
                                kx=aleatorio();
                            }
                        }
                        //Realiza a jogada de verdade a jogada escolhida
                        tabu[lx][kx]='X';
                        system("clear");
                        desenho();
                        //Guarda o logo atual em 'patida[]'
                        partida[C]=lx;
                        partida[C+1]=kx;
                        C=C+2;
                    }
                }
            }
            //Confere se a partida acabou
            v=acabouX();
            if(v==0){
                x++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                frasevitoria();
                return ;
            }
            else{}
        }
        //Jogada O
        else{
            printf("Escolha a linha e coluna da sua jogada : ");
            scanf("%d %d", &la, &ka);
            while (la<0||la>3||ka<0||ka>3||tabu[la-1][ka-1]!=' '){
                printf("Por favor digite novamente\n");
                scanf("%d %d", &la , &ka);
            }
            tabu[la-1][ka-1]='O';
            system("clear");
            desenho();
            partida[C]=la-1;
            partida[C+1]=ka-1;
            C=C+2;
            v=acabouO();
            if(v==0){
                o++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                frasederrota();
                return ;
                
            }
        }
        cont=cont+1;
    }
    e++;
    fprintf(esc, "\n");
    for(m=0; m<18;m++){
        fprintf(esc, "%d " , partida[m]);
    }
    fprintf(esc,"%d %d %d", x, o, e);
    fclose(esc);
    fclose(stream);
    return ;
}
void BotO_contrahumano(){
    int dados[NUM][21];
    int partida[18],s=0, possibilidade[NUM], p=0;
    int i=0,j=0,l=0,k=0, i1,j1, b, m=0,x=0,o=0,e=0, maior=0, maiorl=0;
    int C=0, cont=1, f=0,v=3,u=0, opt=0, la, ka,der=0, zeta=0, lx=0, kx=0, nove[NUM], beta=0,alfa, vitoria;
    int rod=0,opd=0,zin=0,n,d,c, y, Z, V;
    int possibilidadeD[NUM], ichi=0, nii=0, san=0, jii=0, maiorlD,maiorD,  noveD[NUM], baz=0;
    for(l=0;l<3;l++){
        for(k=0;k<3;k++){
            tabu[l][k]=' ';
        }    
    }
    for(s=0;s<18;s++){
        partida[s]=9;
    }
    FILE *stream;
    FILE *esc;
    esc = fopen("dado.txt", "a+");
    stream = fopen ("dado.txt","r"); 
    for(i=0;i<NUM;i++){
        for(j=0;j<21;j++){
            fscanf(stream, "%d", &dados[i][j]);
            
        }
        rod++;
    }
    system("clear");
    desenho();
    for(cont=1;cont<=9;){
        //jogada O
        if(cont%2==0){
            //Primeira jogada aleatoria(Ainda pretendo  tirar isso)
            //Pra esse bot é efeito estético kkkk
            if(cont==1){
                lx=aleatorio();
                kx=aleatorio();
                tabu[lx][kx]='O';
                system("clear");
                desenho();
                partida[C]=lx;
                partida[C+1]=kx;
                C=C+2;
            }
            else{
                //Torna 0 todos os espaços dos arrays "nove" e "noveD"
                for(baz=0;baz<NUM;baz++){
                    noveD[baz]=0;
                    nove[baz]=0;
                }
                //Essas váriaveis precisão ser resetadas toda jogada pra lógica funcionar
                b=0;
                c=0;
                y=0;
                Z=0;
                V=0;
                opt=0;
                opd=0;
                p=0;
                der=0;
                maior=0;
                maiorlD=0;
                maiorD=0;
                maiorl=0;
                n=0;
                //Todo esse for(b=0;b<3... serve para ver se na prox jogada é possivel GANHAR, e se for fazer esse jogada [b][c]
                for(b=0;b<3;b=b+1){
                    for(c=0;c<3;c=c+1){
                        for(l=0;l<3;l++){
                            for(k=0;k<3;k++){
                                tabuFUT[l][k]=tabu[l][k];
                            }    
                        }
                        if(tabuFUT[b][c]==' '){
                            tabuFUT[b][c]='O';
                            for(i=0;i<3;i++){
                                vitoria=((tabuFUT[i][0]!=' ') && (tabuFUT[i][0]==tabuFUT[i][1] && tabuFUT[i][0]==tabuFUT[i][2]));  
                                if(vitoria==1){
                                    n=1;

                                }
                                else{
                                    continue;
                                }         
                            }
                            for(j=0;j<3;j++){
                                vitoria=(tabuFUT[0][j]!=' ' && tabuFUT[0][j]==tabuFUT[1][j] && tabuFUT[0][j]==tabuFUT[2][j]);  
                                    if(vitoria==1){
                                        n=1;
                                    }
                                    else{
                                        continue;
                                    }
                            }
                            if(tabuFUT[0][0]!=' '&&tabuFUT[0][0]==tabuFUT[1][1] && tabuFUT[0][0]==tabuFUT[2][2]){
                                    n=1;                     
                            }
                            else{}
                            if(tabuFUT[0][2]!=' ' &&tabuFUT[0][2]==tabuFUT[1][1] && tabuFUT[0][2]==tabuFUT[2][0]){
                                n=1;
        
                            }
                            else{}
                            if(n==1){
                                break;
                            }
                        }
                        if(n==1){
                                break;
                            }
                        else{
                        }
                        if(n==1){
                                break;
                            }
                    }
                    if(n==1){
                                break;
                            }
                }
                if(n==1){
                    tabu[b][c]='O';
                    system("clear");
                    desenho();
                    frasevitoria();
                    partida[C]=b;
                    partida[C+1]=c;
                    C=C+2;
                }
                else{
                    //Todo esse for(Z=0;Z<3... serve para ver se na prox jogada é possivel PERDER, e se for, jogar no lugar que faria perder [Z][V]
                    for(Z=0;Z<3;Z=Z+1){
                        for(V=0;V<3;V=V+1){
                            for(l=0;l<3;l++){
                                for(k=0;k<3;k++){
                                    tabuFUT[l][k]=tabu[l][k];
                                }    
                            }
                            if(tabuFUT[Z][V]==' '){
                                tabuFUT[Z][V]='X';
                                for(i=0;i<3;i++){
                                    vitoria=((tabuFUT[i][0]!=' ') && (tabuFUT[i][0]==tabuFUT[i][1] && tabuFUT[i][0]==tabuFUT[i][2]));  
                                    if(vitoria==1){
                                        y=1;

                                    }
                                    else{
                                        continue;
                                    }         
                                }
                                for(j=0;j<3;j++){
                                    vitoria=(tabuFUT[0][j]!=' ' && tabuFUT[0][j]==tabuFUT[1][j] && tabuFUT[0][j]==tabuFUT[2][j]);  
                                        if(vitoria==1){
                                            y=1;
                                        }
                                        else{
                                            continue;
                                        }
                                }
                                if(tabuFUT[0][0]!=' '&&tabuFUT[0][0]==tabuFUT[1][1] && tabuFUT[0][0]==tabuFUT[2][2]){
                                        y=1;                     
                                }
                                else{}
                                if(tabuFUT[0][2]!=' ' &&tabuFUT[0][2]==tabuFUT[1][1] && tabuFUT[0][2]==tabuFUT[2][0]){
                                    y=1;
            
                                }
                                else{}
                                if(y==1){
                                    break;
                                }
                            }
                            if(y==1){
                                    break;
                                }
                            else{
                            }
                            if(y==1){
                                    break;
                                }
                        }
                        if(y==1){
                                    break;
                                }
                    }
                    if(y==1){
                        tabu[Z][V]='O';
                        system("clear");
                        desenho();
                        printf("Quase HEIN!\n");
                        partida[C]=Z;
                        partida[C+1]=V;
                        C=C+2;
                    }
                    //Caso não for possivel ganhar nem perder, entra nesse else
                    else{
                        //Esse for vê qual linhas dos dados é igual a sequencia de jogadas atuais e representa uma vitoria ou uma derrota
                        //Enquanto faz isso grava o números das linhas nos arrayz possibilidade[] e possibilidadeD[](D de derrota)
                        for(i1=0;i1<NUM;i1++){
                            for(j1=0;j1<((cont*2)-2) && dados[i1][j1]==partida[j1];j1++){
                                if(j1 == (cont*2)-3){
                                    if(dados[i1][19]==1){
                                        possibilidade[p]=i1;
                                        p++;
                                        opt++;
                                    }
                                    if(dados[i1][18]==1){
                                        possibilidadeD[der]=i1;
                                        der++;
                                        opd++;
                                    }
                                    else{
                                    continue;
                                    }
                                }
                            } 
                        }
                        //Se opt e opd forem ambos 0 quer dizer que não há a sequencia de jogadas atuais no banco de dados e portanto a jogada feita será aleatoria
                        if(opt==0 && opd==0){
                            printf("calculando..\n");
                            lx=aleatorio();
                            kx=aleatorio();
                            while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                                lx=aleatorio();
                                kx=aleatorio();
                            }
                            system("clear");
                            desenho();
                        }
                        else{
                            //Grava a quantidade de 9s linha que representa vitória
                            // EXEMPLO: possibilidade[0]= 23 (linha do banco de dados)// nove[0]=6 (a linha 23 do banco de dados possui 6 '9s')
                            for(beta=0;beta<p;beta++){
                                for(alfa=17;(alfa>cont*2-2);alfa--){
                                    if(dados[possibilidade[beta]][alfa]==9){
                                    nove[beta]++;
                                    }
                                    else{
                                        continue;
                                    }
                                }
                            }
                            //Vê qual dessas linhas de vitoria possui mais 9s (ou seja, acaba mais rapido e leva pra uma vitoria mais rapida)
                            //Grava a quantidade de noves da linha com mais nove em 'maior' e a respectiva linha em 'maiorl'
                            for(zeta=0; zeta<p;zeta++){
                                if(nove[zeta]>maior){
                                    maior=nove[zeta];
                                    maiorl=zeta;
                                }
                            }
                            //Vê a linha derrota com mais 9s
                            //MESMA COISA DO QUE ACONTECEU ACIMA PORÉM SERVE PARA DERROTAS(Variaves possuem um 'D' na frente)
                            for(ichi=0;ichi<der;ichi++){
                                for(nii=0;nii<21;nii++){
                                    if(dados[possibilidadeD[ichi]][nii] == 9){
                                    noveD[ichi]++;
                                    }
                                    else{
                                    continue;
                                    }
                                }
                            }
                            for(san=0; san<der;san++){
                                if(noveD[san]>maiorD){
                                    maiorD=noveD[san];
                                    maiorlD=san;
                                }
                                else{
                                    continue;
                                }
                            }          
                    
                            //Verifica se a quantidade de 9s da linha com derrota é maior que a da linha de vitória 
                            //Ou seja, se a derrota chega mais rapido que a vitória na sequencia de jogadas escolhida
                            if(maiorD>maior){
                                if(dados[possibilidadeD[maiorlD]][cont*2+2]==9){
                                    lx=dados[possibilidadeD[maiorlD]][cont*2+0];
                                    kx=dados[possibilidadeD[maiorlD]][cont*2+1];
                                }
                                else{
                                    //caso não exista possibilidade de derrota (opd==0) nessa sequencia de jogadas, ele continua com ela
                                    if(opd==0){
                                        lx=dados[possibilidade[maiorl]][cont*2-2];
                                        kx=dados[possibilidade[maiorl]][cont*2-1];
                                    }
                                    //mudar
                                    else{
                                        while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                                            lx=aleatorio();
                                            kx=aleatorio();
                                        }
                                    }
                                }
                            }
                            //Só continua com a sequencia que leva a vitória mais rapido caso nada do acima tenha acontecido
                            else{
                                //Se a quantidade 9s de uma derrota for 0, o bot irá perder por causa da ultima jogada da 0
                                //Portanto aqui ele irá copiar esse jogada antes do bot faze-la
                                if(maiorD == 0){
                                    lx=dados[possibilidadeD[maiorlD]][16];
                                    kx=dados[possibilidadeD[maiorlD]][17];
                                }
                                else{   
                                    lx=dados[possibilidade[maiorl]][cont*2-2];
                                    kx=dados[possibilidade[maiorl]][cont*2-1];
                                }  
                                
                            }
                        }
                        if(lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                                //Medida preventiva pro bot não roubar
                                printf("Woopsy\n");
                            //Medida preventiva pro bot não roubar
                            while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                                lx=aleatorio();
                                kx=aleatorio();
                            }
                        }
                        //Realiza a jogada de verdade a jogada escolhida
                        tabu[lx][kx]='O';
                        system("clear");
                        desenho();
                        //Guarda o logo atual em 'patida[]'
                        partida[C]=lx;
                        partida[C+1]=kx;
                        C=C+2;
                    }
                }
            }
            //Confere se a partida acabou
            v=acabouO();
            if(v==0){
                o++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                return ;
            }
            else{}
        }
        //Jogada X
        else{
            printf("Escolha a linha e coluna da sua jogada : ");
            scanf("%d %d", &la, &ka);
            while (la<0||la>3||ka<0||ka>3||tabu[la-1][ka-1]!=' '){
                scanf("%d %d", &la , &ka);
                printf("cao..\n");
            }
            system("clear");
            desenho();
            tabu[la-1][ka-1]='X';
            partida[C]=la-1;
            partida[C+1]=ka-1;
            C=C+2;
            v=acabouO();
            if(v==0){
                x++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                frasederrota();
                return ;
                
            }
        }
        cont=cont+1;
    }
    e++;
    fprintf(esc, "\n");
    for(m=0; m<18;m++){
        fprintf(esc, "%d " , partida[m]);
    }
    fprintf(esc,"%d %d %d", x, o, e);
    fclose(esc);
    fclose(stream);
    return ;
}
void BotbotIA(){
    
    int dados[NUM][21];
    int partida[18], possibilidade[NUM], p=0,c,vitoria;
    int partidaB[18],s=0, possibilidadeB[NUM];
    int i=0,j=0,l=0,k=0, i1,j1, b, m=0,x=0,o=0,e=0, maior=0, maiorl=0;
    int C=0, cont=1, f=0,v=3,u=0, opt=0, la, ka,der=0, zeta=0, lx=0, kx=0, nove[NUM], beta=0,alfa, V, Z, y;
    int rod=0,opd=0,zin=0,tkx=0,n, iguaisD[NUM] ,I,L,iguais[NUM],lol=0, jogos,lolD,P;
    int possibilidadeD[NUM],possibilidadeDB[NUM], ichi=0, nii=0, san=0, jii=0, maiorlD,maiorD,  noveD[NUM], baz=0;
    for(l=0;l<3;l++){
        for(k=0;k<3;k++){
            tabu[l][k]=' ';
        }    
    }
    for(s=0;s<18;s++){
        partida[s]=9;
    }
    FILE *stream;
    FILE *esc;
    esc = fopen("dado.txt", "a+");
    stream = fopen ("dado.txt","r"); 
    for(i=0;i<NUM;i++){
        for(j=0;j<21;j++){
            fscanf(stream, "%d", &dados[i][j]);
            
        }
        rod++;
    }
    for(cont=1;cont<=9;cont++){
        //jogada X
        if(cont%2==1){
            //Primeira jogada aleatoria(Ainda pretendo  tirar isso)
            if(cont==0){
                lx=aleatorio();
                kx=aleatorio();
                tabu[lx][kx]='X';
                system("clear");
                desenho();
                partida[C]=lx;
                partida[C+1]=kx;
                C=C+2;
            }
            else{
                //Torna 0 todos os espaços dos arrays "nove" e "noveD"
                for(baz=0;baz<NUM;baz++){
                    noveD[baz]=0;
                    nove[baz]=0;
                }
                //Essas váriaveis precisão ser resetadas toda jogada pra lógica funcionar
                b=0;
                c=0;
                y=0;
                Z=0;
                V=0;
                opt=0;
                opd=0;
                p=0;
                der=0;
                maior=0;
                maiorlD=0;
                maiorD=0;
                maiorl=0;
                n=0;
                jogos=0;
                lol=0;
                lolD=0;
                //Todo esse for(b=0;b<3... serve para ver se na prox jogada é possivel GANHAR, e se for fazer esse jogada [b][c]
                for(b=0;b<3;b=b+1){
                    for(c=0;c<3;c=c+1){
                        for(l=0;l<3;l++){
                            for(k=0;k<3;k++){
                                tabuFUT[l][k]=tabu[l][k];
                            }    
                        }
                        if(tabuFUT[b][c]==' '){
                            tabuFUT[b][c]='X';
                            for(i=0;i<3;i++){
                                vitoria=((tabuFUT[i][0]!=' ') && (tabuFUT[i][0]==tabuFUT[i][1] && tabuFUT[i][0]==tabuFUT[i][2]));  
                                if(vitoria==1){
                                    n=1;

                                }
                                else{
                                    continue;
                                }         
                            }
                            for(j=0;j<3;j++){
                                vitoria=(tabuFUT[0][j]!=' ' && tabuFUT[0][j]==tabuFUT[1][j] && tabuFUT[0][j]==tabuFUT[2][j]);  
                                    if(vitoria==1){
                                        n=1;
                                    }
                                    else{
                                        continue;
                                    }
                            }
                            if(tabuFUT[0][0]!=' '&&tabuFUT[0][0]==tabuFUT[1][1] && tabuFUT[0][0]==tabuFUT[2][2]){
                                    n=1;                     
                            }
                            else{}
                            if(tabuFUT[0][2]!=' ' &&tabuFUT[0][2]==tabuFUT[1][1] && tabuFUT[0][2]==tabuFUT[2][0]){
                                n=1;
        
                            }
                            else{}
                            if(n==1){
                                break;
                            }
                        }
                        if(n==1){
                                break;
                            }
                        else{
                        }
                        if(n==1){
                                break;
                            }
                    }
                    if(n==1){
                                break;
                            }
                }
                if(n==1){
                    tabu[b][c]='X';
                    system("clear");
                    desenho();
                    partida[C]=b;
                    partida[C+1]=c;
                    C=C+2;
                }
                else{
                    //Todo esse for(Z=0;Z<3... serve para ver se na prox jogada é possivel PERDER, e se for, jogar no lugar que faria perder [Z][V]
                    for(Z=0;Z<3;Z=Z+1){
                        for(V=0;V<3;V=V+1){
                            for(l=0;l<3;l++){
                                for(k=0;k<3;k++){
                                    tabuFUT[l][k]=tabu[l][k];
                                }    
                            }
                            if(tabuFUT[Z][V]==' '){
                                tabuFUT[Z][V]='O';
                                for(i=0;i<3;i++){
                                    vitoria=((tabuFUT[i][0]!=' ') && (tabuFUT[i][0]==tabuFUT[i][1] && tabuFUT[i][0]==tabuFUT[i][2]));  
                                    if(vitoria==1){
                                        y=1;

                                    }
                                    else{
                                        continue;
                                    }         
                                }
                                for(j=0;j<3;j++){
                                    vitoria=(tabuFUT[0][j]!=' ' && tabuFUT[0][j]==tabuFUT[1][j] && tabuFUT[0][j]==tabuFUT[2][j]);  
                                        if(vitoria==1){
                                            y=1;
                                        }
                                        else{
                                            continue;
                                        }
                                }
                                if(tabuFUT[0][0]!=' '&&tabuFUT[0][0]==tabuFUT[1][1] && tabuFUT[0][0]==tabuFUT[2][2]){
                                        y=1;                     
                                }
                                else{}
                                if(tabuFUT[0][2]!=' ' &&tabuFUT[0][2]==tabuFUT[1][1] && tabuFUT[0][2]==tabuFUT[2][0]){
                                    y=1;
            
                                }
                                else{}
                                if(y==1){
                                    break;
                                }
                            }
                            if(y==1){
                                    break;
                                }
                            else{
                            }
                            if(y==1){
                                    break;
                                }
                        }
                        if(y==1){
                                    break;
                                }
                    }
                    if(y==1){
                        tabu[Z][V]='X';
                        system("clear");
                        desenho();
                        printf("Quase HEIN!\n");
                        partida[C]=Z;
                        partida[C+1]=V;
                        C=C+2;
                    }
                    //Caso não for possivel ganhar nem perder, entra nesse else
                    else{
                        //Esse for vê qual linhas dos dados é igual a sequencia de jogadas atuais e representa uma vitoria ou uma derrota
                        //Enquanto faz isso grava o números das linhas nos arrayz possibilidade[] e possibilidadeD[](D de derrota)
                        for(i1=0;i1<NUM;i1++){
                            for(j1=0;j1<((cont*2)-2) && dados[i1][j1]==partida[j1];j1++){
                                if(j1 == (cont*2)-3){
                                    if(dados[i1][19]==1){
                                        possibilidade[p]=i1;
                                        p++;
                                        opt++;
                                        jogos++;
                                    }
                                    if(dados[i1][18]==1){
                                        possibilidadeD[der]=i1;
                                        der++;
                                        opd++;
                                        jogos++;
                                    }
                                    if(dados[i1][20]==1){
                                        jogos++;
                                    }
                                else{
                                    continue;
                                }
                                }
                            } 
                        }
                        //Se opt e opd forem ambos 0 quer dizer que não há a sequencia de jogadas atuais no banco de dados e portanto a jogada feita será aleatoria
                        if(opt==0 && opd==0){
                            printf("Partida fora dos Dados, calculando...\n");
                            lx=aleatorio();
                            kx=aleatorio();
                            while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                                lx=aleatorio();
                                kx=aleatorio();
                            }
                            system("clear");
                            desenho();
                        }
                        else{
                            //Vendo quais jogos são iguais e quantos são
                            for(P=0;P<(opt-lol);P++){
                                for(L=0;L<opt;L++){
                                    for(I=0;I<21;I++){
                                        if(dados[possibilidade[P]][I] == dados[possibilidade[L]][I] && I==20){
                                            possibilidade[L]==possibilidade[P];
                                            iguais[P]++;
                                            lol++;
                                        }
                                        else{continue;}
                                    }
                                }
                            }
                            for(P=0;P<(opd-lolD);P++){
                                for(L=0;L<opd;L++){
                                    for(I=0;I<21;I++){
                                        if(dados[possibilidadeD[P]][I] == dados[possibilidadeD[L]][I] && I==20){
                                            possibilidadeD[L]==possibilidadeD[P];
                                            iguaisD[P]++;
                                            lolD++;
                                        }
                                        else{continue;}
                                    }
                                }
                            }
                            //Grava a quantidade de 9s linha que representa vitória
                            // EXEMPLO: possibilidade[0]= 23 (linha do banco de dados)// nove[0]=6 (a linha 23 do banco de dados possui 6 '9s')
                            for(beta=0;beta<(p-lol);beta++){
                                for(alfa=17;(alfa>cont*2-2);alfa--){
                                    if(dados[possibilidade[beta]][alfa]==9){
                                    nove[beta]++;
                                    }
                                    else{
                                        continue;
                                    }
                                }
                            }
                            //Vê qual dessas linhas de vitoria possui mais 9s (ou seja, acaba mais rapido e leva pra uma vitoria mais rapida)
                            //Grava a quantidade de noves da linha com mais nove em 'maior' e a respectiva linha em 'maiorl'
                            for(zeta=0; zeta<(p-lol);zeta++){
                                if(nove[zeta]>maior){
                                    maior=nove[zeta];
                                    maiorl=zeta;
                                }
                                else{}
                                //Caso duas linhas diferentes tenham a mesma quantidade de 9s para a vitoria, é escolhida a com maior winrate
                                if(nove[zeta]==maior){
                                    if(iguais[zeta]/(double)jogos > maiorl/(double)jogos){
                                        maior=nove[zeta];
                                        maiorl=zeta;
                                    }
                                }
                                else{}
                            }
                            //Vê a linha derrota com mais 9s
                            //MESMA COISA DO QUE ACONTECEU ACIMA PORÉM SERVE PARA DERROTAS(Variaves possuem um 'D' na frente)
                            for(ichi=0;ichi<der;ichi++){
                                for(nii=0;nii<21;nii++){
                                    if(dados[possibilidadeD[ichi]][nii] == 9){
                                    noveD[ichi]++;
                                    }
                                    else{
                                    continue;
                                    }
                                }
                            }
                            for(san=0; san<der;san++){
                                if(noveD[san]>maiorD){
                                    maiorD=noveD[san];
                                    maiorlD=san;
                                }
                                else{}
                                if(noveD[san]==maiorD){
                                   if(iguaisD[san]/(double)jogos > maiorlD/(double)jogos){
                                        maiorD=nove[san];
                                        maiorlD=san;
                                    }
                                }
                                else{}
                            }          
                    
                            //Verifica se a quantidade de 9s da linha com derrota é maior que a da linha de vitória 
                            //Ou seja, se a derrota chega mais rapido que a vitória na sequencia de jogadas escolhida
                            if(maiorD>maior){
                                //Se a quantidade 9s de uma derrota for 2, o bot irá perder por causa da ultima jogada da 0
                                //Portanto aqui ele irá copiar esse jogada antes do bot faze-la
                                if(maiorD == 2){
                                    lx=dados[possibilidadeD[maiorlD]][14];
                                    kx=dados[possibilidadeD[maiorlD]][15];
                                }
                                else{
                                    if(dados[possibilidadeD[maiorlD]][cont*2+2]==9){
                                        lx=dados[possibilidadeD[maiorlD]][cont*2+0];
                                        kx=dados[possibilidadeD[maiorlD]][cont*2+1];
                                    }
                                    else{
                                        lx=dados[possibilidade[maiorl]][cont*2+2];
                                        kx=dados[possibilidade[maiorl]][cont*2+3];
                                    }
                                }
                            }
                            //Só continua com a sequencia que leva a vitória mais rapido caso nada do acima tenha acontecido
                            else{
                                lx=dados[possibilidade[maiorl]][cont*2-2];
                                kx=dados[possibilidade[maiorl]][cont*2-1];
                            }
                        }
                        if(lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                            //Medida preventiva pro bot não roubar
                             printf("Woopsy\n");
                            while (lx<0||lx>3||kx<0||kx>3||tabu[lx][kx]=='X'||tabu[lx][kx]=='O'){
                                lx=aleatorio();
                                kx=aleatorio();
                            }
                        }
                        //Realiza a jogada de verdade a jogada escolhida
                        tabu[lx][kx]='X';
                        system("clear");
                        desenho();
                        //Guarda o logo atual em 'patida[]'
                        partida[C]=lx;
                        partida[C+1]=kx;
                        C=C+2;
                    }
                }
            }
            //Confere se a partida acabou
            v=acabouX();
            if(v==0){
                x++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                frasevitoria();
                return ;
            }
            else{}
        }
        //Jogada O
        else{
            //Primeira jogada aleatoria(Ainda pretendo  tirar isso)
            //Pra esse bot é efeito estético kkkk
            if(cont==1){
                la=aleatorio();
                ka=aleatorio();
                tabu[la][ka]='O';
                system("clear");
                desenho();
                partida[C]=la;
                partida[C+1]=ka;
                C=C+2;
            }
            else{
                //Torna 0 todos os espaços dos arrays "nove" e "noveD"
                for(baz=0;baz<NUM;baz++){
                    noveD[baz]=0;
                    nove[baz]=0;
                }
                //Essas váriaveis precisão ser resetadas toda jogada pra lógica funcionar
                b=0;
                c=0;
                y=0;
                Z=0;
                V=0;
                opt=0;
                opd=0;
                p=0;
                der=0;
                maior=0;
                maiorlD=0;
                maiorD=0;
                maiorl=0;
                n=0;
                //Todo esse for(b=0;b<3... serve para ver se na prox jogada é possivel GANHAR, e se for fazer esse jogada [b][c]
                for(b=0;b<3;b=b+1){
                    for(c=0;c<3;c=c+1){
                        for(l=0;l<3;l++){
                            for(k=0;k<3;k++){
                                tabuFUT[l][k]=tabu[l][k];
                            }    
                        }
                        if(tabuFUT[b][c]==' '){
                            tabuFUT[b][c]='O';
                            for(i=0;i<3;i++){
                                vitoria=((tabuFUT[i][0]!=' ') && (tabuFUT[i][0]==tabuFUT[i][1] && tabuFUT[i][0]==tabuFUT[i][2]));  
                                if(vitoria==1){
                                    n=1;

                                }
                                else{
                                    continue;
                                }         
                            }
                            for(j=0;j<3;j++){
                                vitoria=(tabuFUT[0][j]!=' ' && tabuFUT[0][j]==tabuFUT[1][j] && tabuFUT[0][j]==tabuFUT[2][j]);  
                                    if(vitoria==1){
                                        n=1;
                                    }
                                    else{
                                        continue;
                                    }
                            }
                            if(tabuFUT[0][0]!=' '&&tabuFUT[0][0]==tabuFUT[1][1] && tabuFUT[0][0]==tabuFUT[2][2]){
                                    n=1;                     
                            }
                            else{}
                            if(tabuFUT[0][2]!=' ' &&tabuFUT[0][2]==tabuFUT[1][1] && tabuFUT[0][2]==tabuFUT[2][0]){
                                n=1;
        
                            }
                            else{}
                            if(n==1){
                                break;
                            }
                        }
                        if(n==1){
                                break;
                            }
                        else{
                        }
                        if(n==1){
                                break;
                            }
                    }
                    if(n==1){
                                break;
                            }
                }
                if(n==1){
                    tabu[b][c]='O';
                    system("clear");
                    desenho();
                    frasevitoria();
                    partida[C]=b;
                    partida[C+1]=c;
                    C=C+2;
                }
                else{
                    //Todo esse for(Z=0;Z<3... serve para ver se na prox jogada é possivel PERDER, e se for, jogar no lugar que faria perder [Z][V]
                    for(Z=0;Z<3;Z=Z+1){
                        for(V=0;V<3;V=V+1){
                            for(l=0;l<3;l++){
                                for(k=0;k<3;k++){
                                    tabuFUT[l][k]=tabu[l][k];
                                }    
                            }
                            if(tabuFUT[Z][V]==' '){
                                tabuFUT[Z][V]='X';
                                for(i=0;i<3;i++){
                                    vitoria=((tabuFUT[i][0]!=' ') && (tabuFUT[i][0]==tabuFUT[i][1] && tabuFUT[i][0]==tabuFUT[i][2]));  
                                    if(vitoria==1){
                                        y=1;

                                    }
                                    else{
                                        continue;
                                    }         
                                }
                                for(j=0;j<3;j++){
                                    vitoria=(tabuFUT[0][j]!=' ' && tabuFUT[0][j]==tabuFUT[1][j] && tabuFUT[0][j]==tabuFUT[2][j]);  
                                        if(vitoria==1){
                                            y=1;
                                        }
                                        else{
                                            continue;
                                        }
                                }
                                if(tabuFUT[0][0]!=' '&&tabuFUT[0][0]==tabuFUT[1][1] && tabuFUT[0][0]==tabuFUT[2][2]){
                                        y=1;                     
                                }
                                else{}
                                if(tabuFUT[0][2]!=' ' &&tabuFUT[0][2]==tabuFUT[1][1] && tabuFUT[0][2]==tabuFUT[2][0]){
                                    y=1;
            
                                }
                                else{}
                                if(y==1){
                                    break;
                                }
                            }
                            if(y==1){
                                    break;
                                }
                            else{
                            }
                            if(y==1){
                                    break;
                                }
                        }
                        if(y==1){
                                    break;
                                }
                    }
                    if(y==1){
                        tabu[Z][V]='O';
                        system("clear");
                        desenho();
                        printf("Quase HEIN!\n");
                        partida[C]=Z;
                        partida[C+1]=V;
                        C=C+2;
                    }
                    //Caso não for possivel ganhar nem perder, entra nesse else
                    else{
                        //Esse for vê qual linhas dos dados é igual a sequencia de jogadas atuais e representa uma vitoria ou uma derrota
                        //Enquanto faz isso grava o números das linhas nos arrayz possibilidade[] e possibilidadeD[](D de derrota)
                        for(i1=0;i1<NUM;i1++){
                            for(j1=0;j1<((cont*2)-2) && dados[i1][j1]==partida[j1];j1++){
                                if(j1 == (cont*2)-3){
                                    if(dados[i1][19]==1){
                                        possibilidade[p]=i1;
                                        p++;
                                        opt++;
                                    }
                                    if(dados[i1][18]==1){
                                        possibilidadeD[der]=i1;
                                        der++;
                                        opd++;
                                    }
                                    else{
                                    continue;
                                    }
                                }
                            } 
                        }
                        //Se opt e opd forem ambos 0 quer dizer que não há a sequencia de jogadas atuais no banco de dados e portanto a jogada feita será aleatoria
                        if(opt==0 && opd==0){
                            printf("calculando..\n");
                            la=aleatorio();
                            ka=aleatorio();
                            while (la<0||la>3||ka<0||ka>3||tabu[la][ka]=='X'||tabu[la][ka]=='O'){
                                la=aleatorio();
                                ka=aleatorio();
                            }
                            system("clear");
                            desenho();
                        }
                        else{
                            //Grava a quantidade de 9s linha que representa vitória
                            // EXEMPLO: possibilidade[0]= 23 (linha do banco de dados)// nove[0]=6 (a linha 23 do banco de dados possui 6 '9s')
                            for(beta=0;beta<p;beta++){
                                for(alfa=17;(alfa>cont*2-2);alfa--){
                                    if(dados[possibilidade[beta]][alfa]==9){
                                    nove[beta]++;
                                    }
                                    else{
                                        continue;
                                    }
                                }
                            }
                            //Vê qual dessas linhas de vitoria possui mais 9s (ou seja, acaba mais rapido e leva pra uma vitoria mais rapida)
                            //Grava a quantidade de noves da linha com mais nove em 'maior' e a respectiva linha em 'maiorl'
                            for(zeta=0; zeta<p;zeta++){
                                if(nove[zeta]>maior){
                                    maior=nove[zeta];
                                    maiorl=zeta;
                                }
                            }
                            //Vê a linha derrota com mais 9s
                            //MESMA COISA DO QUE ACONTECEU ACIMA PORÉM SERVE PARA DERROTAS(Variaves possuem um 'D' na frente)
                            for(ichi=0;ichi<der;ichi++){
                                for(nii=0;nii<21;nii++){
                                    if(dados[possibilidadeD[ichi]][nii] == 9){
                                    noveD[ichi]++;
                                    }
                                    else{
                                    continue;
                                    }
                                }
                            }
                            for(san=0; san<der;san++){
                                if(noveD[san]>maiorD){
                                    maiorD=noveD[san];
                                    maiorlD=san;
                                }
                                else{
                                    continue;
                                }
                            }          
                    
                            //Verifica se a quantidade de 9s da linha com derrota é maior que a da linha de vitória 
                            //Ou seja, se a derrota chega mais rapido que a vitória na sequencia de jogadas escolhida
                            if(maiorD>maior){
                                if(dados[possibilidadeD[maiorlD]][cont*2+2]==9){
                                    la=dados[possibilidadeD[maiorlD]][cont*2+0];
                                    ka=dados[possibilidadeD[maiorlD]][cont*2+1];
                                }
                                else{
                                    //caso não exista possibilidade de derrota (opd==0) nessa sequencia de jogadas, ele continua com ela
                                    if(opd==0){
                                        la=dados[possibilidade[maiorl]][cont*2-2];
                                        ka=dados[possibilidade[maiorl]][cont*2-1];
                                    }
                                    //mudar
                                    else{
                                        while (la<0||la>3||ka<0||ka>3||tabu[la][ka]=='X'||tabu[la][ka]=='O'){
                                            la=aleatorio();
                                            ka=aleatorio();
                                        }
                                    }
                                }
                            }
                            //Só continua com a sequencia que leva a vitória mais rapido caso nada do acima tenha acontecido
                            else{
                                //Se a quantidade 9s de uma derrota for 0, o bot irá perder por causa da ultima jogada da 0
                                //Portanto aqui ele irá copiar esse jogada antes do bot faze-la
                                if(maiorD == 0){
                                    la=dados[possibilidadeD[maiorlD]][16];
                                    ka=dados[possibilidadeD[maiorlD]][17];
                                }
                                else{   
                                    la=dados[possibilidade[maiorl]][cont*2-2];
                                    ka=dados[possibilidade[maiorl]][cont*2-1];
                                }  
                                
                            }
                        }
                         if(la<0||la>3||ka<0||ka>3||tabu[la][ka]=='X'||tabu[la][ka]=='O'){
                                //Medida preventiva pro bot não roubar
                                printf("Woopsy\n");
                            //Medida preventiva pro bot não roubar
                            while (la<0||la>3||ka<0||ka>3||tabu[la][ka]=='X'||tabu[la][ka]=='O'){
                                la=aleatorio();
                                ka=aleatorio();
                        }
                         }
                        //Realiza a jogada de verdade a jogada escolhida
                        tabu[la][ka]='O';
                        system("clear");
                        desenho();
                        //Guarda o logo atual em 'patida[]'
                        partida[C]=la;
                        partida[C+1]=ka;
                        C=C+2;
                    }
                }
            }
            //Confere se a partida acabou
            v=acabouO();
            if(v==0){
                o++;
                fprintf(esc, "\n");
                for(m=0; m<18;m++){
                    fprintf(esc, "%d " , partida[m]);
                }
                fprintf(esc,"%d %d %d", x, o, e);
                fclose(esc);
                fclose(stream);
                return ;
            }
            else{}
        }
    }
    e++;
    fprintf(esc, "\n");
    for(m=0; m<18;m++){
        fprintf(esc, "%d " , partida[m]);
    }
    fprintf(esc,"%d %d %d", x, o, e);
    fclose(esc);
    fclose(stream);
    return ;
}
int main(){
    int woop, viz=1, lupbot=1, escolha,zong;
    Inic_Random();
    for(woop=0;woop<lupbot;woop++){
        printf("Bem vindo\n");
        printf("Para jogar como X, digite 1\n");
        printf("Para jogar como O, digite 2\n");
        printf("OPÇÔES DE CRIADOR: \n");
        printf("3 para IaXIaB\n5 IaX\n6 IaB\n");
        scanf("%d", &viz);
        switch(viz){
            case 1:
            BotO_contrahumano();
            break;
            case 2:
            BotX_contrahumano();
            break;
            case 3:
            printf("Digite quantos jogos serão feitos: ");
            scanf("%d",&zong);
            while(zong>0){
                BotbotIA();
                zong--;
            }
            printf("Tchau\n");
            break;
            case 5:
            printf("Digite quantos jogos serão feitos: ");
            scanf("%d",&zong);
            while(zong>0){
                IaX();
                zong--;
            }
            break;
            case 6:
            printf("Digite quantos jogos serão feitos: ");
            scanf("%d",&zong);
            while(zong>0){
                IaO();
                zong--;
            }
            return 0; 
        }
        printf("Até a próxima!\n");
    }
    return 0;
}