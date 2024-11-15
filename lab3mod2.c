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

int add_num(int *array, int n, int *new_array, int *len){
    int el, poz;
    printf("введите элемент "); scanf("%d", &el);
    printf("введите позицию "); scanf("%d", &poz);
    if (poz >(n+1)){
        for (int i=0; i<=n; i++){
	    new_array[i] = array[i];
	}
	new_array[n] = el;
    }
    else{
        for (int i=0; i<=n; i++){
            if (i<poz){
	        new_array[i] = array[i];
	    }
	    if (i==poz){
	        new_array[i] = el;
	    }
	    if (i>poz){
	        new_array[i] = array[i-1];
	    }
        }
    }
    *len = n+1;
    return 0;
}

int delete(int *array, int n, int *new_array, int *len){
    int poz;
    printf("введите индекс элемента "); scanf("%d", &poz);
    if (poz > n-1){
        return 1;
    }
    for (int i=0; i<n; i++){
        if (i<poz){
	    new_array[i]=array[i];
	}
	if (i>poz){
	    new_array[i-1] = array[i];
	}
    }
    *len = n-1;
    return 0;
}

int del(int *array, int n, int *new_array, int poz){
    for (int i=0; i<=n; i++){
        if (i<poz){
	    new_array[i] = array[i];
	}
	if (i>poz){
	    new_array[i-1] = array[i];
	}
    }
    return 0;
}

int uniq(int *array, int n, int *new_array, int *len, int *del_array, int *zer){
    int coun;
    int dubl=0;
    for (int i=0; i<n; i++){
	coun = 0;
        for (int j=0; j<n; j++){
	    if (array[i] == array[j]){
	        coun+=1;
	    }
	}
	if (coun == 1){
	    new_array[dubl] = array[i];
	    dubl +=1;
	}
    }
    int zero = 0;
    for (int k=0; k<=n; k++){
         if (new_array[k] == 0){
	    zero += 1;
	}
    }
    *zer = zero;
    return 0;
}

int main(){
    int r = 0;
    int *numbs = malloc(sizeof(int));
    int len;
    while (r != -1){
	int numb;
	printf("1 - инициализация массива\n2 - добавление элемента по индексу\n3 - удаление элемента по индексу\n4 - индивидуальное задание\n");
	int rnumb = vvod(&numb);
	while (rnumb != 0){
	    if (rnumb == -1){
	        r = -1;
		return 0;
	    }
            rnumb = vvod(&numb);
	}
	if (numb == 1){
            int n;
            printf("введите длину массива: ");
            int r1 = vvod(&n);
	    while (r1 != 0){
	        if (r1 == -1){
	            r = -1;
		    return 0;
	        }
	        r1 = vvod(&n);
	    }
            numbs  = realloc(numbs, n*sizeof(int));
            initial(numbs, n, &len);
            printf("массив: ");
            out(numbs, n);
            printf("\n");
	}
	if (numb == 2){
            int *new_array = malloc((len+1)*sizeof(int));
            add_num(numbs, len, new_array, &len);
	    numbs = realloc(numbs, (len)*sizeof(int));
	    numbs = new_array;
            printf("массив: ");
            out(numbs, len);
            printf("\n");
	}
	if (numb == 3){
            int *del_array = malloc((len-1)*sizeof(int));
            if (delete(numbs, len, del_array, &len) == 0){
	        numbs = realloc(numbs, (len)*sizeof(int));
	        numbs = del_array;
                printf("массив: ");
                out(numbs, len);
                printf("\n");
	    }
	    else{
	        printf("ошибка ввода индекса\n");
	    }
	}
	if (numb == 4){
	    int *uniq_array = malloc(len*sizeof(int));
	    int *new_numbs = malloc(0);
	    int zero;
            uniq(numbs, len, uniq_array, &len, new_numbs, &zero);
	    uniq_array = realloc(uniq_array, (len-zero+1)*sizeof(int));
	    printf("исходный массив: ");
	    out(numbs, len);
	    printf("\n");
	    printf("новый массив: ");
	    out(uniq_array, len-zero+1);
	    printf("\n");

	}
    }
    free(numbs);
    return 0;
}
