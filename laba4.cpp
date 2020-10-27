#include<cstdlib>
#include<stdio.h>
#include<locale>

using namespace std;


int main(){
    setlocale(LC_ALL, "rus");
    int *a, n, index = 1, pr = 0, max = 0;
    printf("¬ведите размер массива: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("a[%d]: ", i);
        scanf("%d", &*(a+i));
    }
    for(int i = 1; i < n; i++){
        if(*(a + i) * *(a + i -1) > max){
            max = *(a + i) * *(a + i -1);
            index = i;
        }
    }
    printf("Index максимального - %d", index);
    /*for(int i = 0; i < n; i++){
        printf("%3d", *(a+i));
    }*/
    return 0;
}
