#define MAX_PROD 100
#define MAX_N 100
#define MAX_DESCRIP 100

void inputProducto(char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int* cantidad);
void editProducto(char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int cantidad);
void showProductos(char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int cantidad);
void eliminarProducto(char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int* cantidad, int indice);
int loadProductos(FILE* archivo, char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[]);
void storeProductos(FILE* archivo, char prod[][MAX_N], char descrip[][MAX_DESCRIP], float precios[], int cantidad);
