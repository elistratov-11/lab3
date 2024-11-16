#include <stdio.h>
#include <stdlib.h>

int initial(int *array, int len, int *n){
    for (int i=0; i<len; i++){
	printf("введите число ");
	int a;
        scanf("%d", &a);
	array[i] = a;
    }
    *n = len;
    return 0;
}

int out(int *array, int n){
    for (int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    return 0;
}

int vvod(int *numb){
    char t = '0';
    int a = scanf("%d%c", numb, &t);
    if (a == -1){
        return -1;
    }
    if ((a!=2) || (t!='\n')){
        printf("введено не число\n");
	scanf("%*[^\n]");
	return 1;
    }
    return 0;
}

int add_num(int *array, int n, int *new_array, int *len, int el, int poz){
    //int el, poz;
    //printf("введите элемент "); scanf("%d", &el);
    //printf("введите позицию "); scanf("%d", &poz);
    //*array = realloc(*array, (*len+1)*sizeof(int));
    int *arr = malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        arr[i] = array[i];
    }
    if (poz <0){
        return 1;
    }
    if (poz >n){
        poz = n;
    }
    for (int i=0; i<=n; i++){
        if (i<poz){
	    new_array[i] = arr[i];
	}
	if (i==poz){
	    new_array[i] = el;
	}
	if (i>poz){
	    new_array[i] = arr[i-1];
	}
    }
    free(arr);
    *len = n + 1;
    return 0;
}

int delete(int *array, int n, int *new_array, int *len, int poz){
    //int poz;
    //printf("введите индекс элемента "); scanf("%d", &poz);
    int *arr = malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        arr[i] = array[i];
    }
    if (poz > n-1){
        return 1;
    }
    for (int i=0; i<n; i++){
        if (i<poz){
	    new_array[i]=arr[i];
	}
	if (i>poz){
	    new_array[i-1] = arr[i];
	}
    }
    free(arr);
    *len = n-1;
    return 0;
}

int uniq(int *array, int n, int *new_array, int *uniq, int *len, int *zer, int *dub){
    int coun = 0;
    int dubl = 0, ae = 0;
    int *arr = malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        arr[i] = array[i];
    }
    for (int i=0; i<n; i++){
	coun = 0;
        for (int j=0; j<n; j++){
	    if (arr[i] == arr[j]){
	        coun+=1;
	    }
	}
	if (coun == 1){
	    uniq[dubl] = arr[i];
	    dubl +=1;
	}
	else{
	    new_array[ae] = arr[i];
	    ae +=1;
	}
    }
    *dub = dubl;
    //out(uniq, dubl);
    //out(new_array, ae);
    *zer = ae;
    free(arr);
    return 0;
}

void *my_realloc(char *arr, int ex_size, int size)
{
	int *new = malloc(size);
	for (int i=0; i<ex_size; i++){
		new[i] = arr[i];
	}
	free(arr);
	return new;
}

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
	    printf("введите элемент: "); scanf("%d", &el);
	    printf("введите индекс: "); scanf("%d", &poz);
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
	    printf("введите индекс: "); scanf("%d", &poz);
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
