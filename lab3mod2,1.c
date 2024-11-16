#include <stdio.h>
#include <stdlib.h>
#include "lab3mod2.h"

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
    *len = ae;
    free(arr);
    return 0;
}
