#include <stdio.h>
#include <stdlib.h>
#include "lab3mod2.h"
//#include <lab3mod2,1.c>

int main(){
    int r = 0;
    int *numbs = malloc(sizeof(int));
    numbs[0] = 0;
    int len=0;
    int *new_numbs = malloc(sizeof(int));
    new_numbs[0] = 0; 
    while (r != -1){
	int numb;
	printf("1 - инициализация массива\n2 - добавление элемента по индексу\n3 - удаление элемента по индексу\n4 - индивидуальное задание\n");
	int rnumb = vvod(&numb);
	while (rnumb != 0){
	    if (rnumb == -1){
	        r = -1;
		free(numbs);
		free(new_numbs);
		return 0;
	    }
            rnumb = vvod(&numb);
	}
	if (numb == 1){
            int n=0;
            printf("введите длину массива: ");
            int r1 = vvod(&n);
	    while (r1 != 0){
	        if (r1 == -1){
	            r = -1;
		    free(numbs);
		    free(new_numbs);
		    return 0;
	        }
	        r1 = vvod(&n);
	    }
	    //free(numbs);
	    //int *numbs = malloc(n*sizeof(int));
            //numbs  = my_realloc(numbs, len, n*sizeof(int));
	    numbs = realloc(numbs, n*sizeof(int));
            initial(numbs, n, &len);
            printf("массив: ");
            out(numbs, len);
            printf("\n");
	}
	if (numb == 2){
            //int *new_array = malloc((len+1)*sizeof(int));
	    //numbs = my_realloc(numbs, len, (len+1)*sizeof(int));
	    numbs = realloc(numbs, (len+1)*sizeof(int));
	    //out(numbs, len+1);
	    int el = 0, poz = 0;
	    printf("введите элемент: "); if(scanf("%d", &el) != 1) return 1;
	    printf("введите индекс: "); if(scanf("%d", &poz) != 1) return 1;
            if (add_num(numbs, len, numbs, &len, el, poz) == 1){
	        //numbs = my_realloc(numbs, (len-1), (len)*sizeof(int));
		numbs = realloc(numbs, len*sizeof(int));
	    }
	    //numbs = realloc(numbs, (len)*sizeof(int));
	    //numbs = new_array;
            printf("массив: ");
            out(numbs, len);
            printf("\n");
	}
	if (numb == 3){
            //int *del_array = malloc((len-1)*sizeof(int));
	    int poz = 0;
	    printf("введите индекс: "); if(scanf("%d", &poz) != 1) return 1;
            if (delete(numbs, len, numbs, &len, poz) == 0){
	        //numbs = my_realloc(numbs, (len+1), (len)*sizeof(int));
		numbs = realloc(numbs, len*sizeof(int));
                printf("массив: ");
                out(numbs, len);
                printf("\n");
	    }
	    else{
	        printf("ошибка ввода индекса\n");
	    }
	}
	if (numb == 4){
	    //int *uniq_array = malloc(len*sizeof(int));
	    //int *new_numbs = malloc(0);
	    int zero = 0, dub=0;
	    new_numbs = realloc(new_numbs, len*sizeof(int));
	    //new_numbs = my_realloc(new_numbs, 0, len*sizeof(int));
            uniq(numbs, len, numbs, new_numbs, &len, &zero, &dub);
	    numbs = realloc(numbs, (zero)*sizeof(int));
	    new_numbs = realloc(new_numbs, (dub)*sizeof(int));
	    printf("исходный массив: ");
	    out(numbs, zero);
	    printf("\n");
	    printf("новый массив: ");
	    out(new_numbs, dub);
	    printf("\n");

	}
    }
    free(new_numbs);
    free(numbs);
    return 0;
}
