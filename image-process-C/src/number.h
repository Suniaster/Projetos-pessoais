#ifndef dadwdaw
#define dadwdaw
typedef struct Imagem{
    char *name;
    char modo[2];
    int chns;
    int Vertical,Horizontal;
    int Cor;
    int ***matriz;
    float ilum_mean;
}IMG_PGM;

typedef struct Matriz_2dims{
    float **data;
    int linhas,colunas;
}Matriz2D;
/* Reading and Writing Images */

void read_image_name(char Nome_imagem[]);
void read_image_pgm_B(char nome[],IMG_PGM *N);
void create_image(IMG_PGM Base,IMG_PGM *N);
void write_image(IMG_PGM N);
void cpyhead_image(IMG_PGM N, IMG_PGM *Dest);
void convert_img_pgm(IMG_PGM *N);

/* Processing images */

void whiting_image(IMG_PGM N, IMG_PGM *Dest);
void normalize_image(IMG_PGM N, IMG_PGM *Dest);
void invertBW_image(IMG_PGM N,IMG_PGM *Dest);
void cut_image(IMG_PGM N, IMG_PGM *Dest);
void find_corner(IMG_PGM N, IMG_PGM *Dest);
void blur_image(IMG_PGM N, IMG_PGM *Dest);
void finding_structures(IMG_PGM N,IMG_PGM *Dest);
void separating_structures(IMG_PGM N, IMG_PGM *Dest);
void find_otherimg(IMG_PGM N ,IMG_PGM *Dest);


/* Processing Metodes */

void process_1(IMG_PGM N, IMG_PGM *Dest);
void process_2(IMG_PGM N, IMG_PGM *Dest);

/* Free Data Allocated */

void free_img_struct(IMG_PGM *N);
void free_Matriz2D(Matriz2D* N);

/* Other */

int partic(int V[],int idx[],int inic, int fim);
void quicksort(int vetor[], int idx[],int inic, int fim);
int positivo(int i);
int modulo(int i);
void ilumination_mean(IMG_PGM *Dest);
Matriz2D* create_blur_matriz(int blur);

#endif