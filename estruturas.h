typedef struct Celula {
    int valor;
    struct Celula *proximo;
} Celula;

typedef struct {
    Celula *primeiro;
    int qtd;
} LDE;

Celula *criar_celula(int valor);
LDE *criar_lista();
void inserir(LDE *lista, int valor);
void remover(LDE *lista, int valor);
void mostrar(LDE *lista);

