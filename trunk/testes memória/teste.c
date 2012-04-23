#include <stdlib.h>
#include <stdio.h>

int main(){
	int **array;
	int i=0;
	array=(int**)malloc(350000*sizeof(int*));
	while((i<350000)&&(array[i-1]!=NULL)){
		array[i]=(int*)malloc(1000*sizeof(int));
		if(i==1230){
			array[1230][56]=678;
		}
		i++;
	}
	printf("%d - %d",i,array[1230][56]);
	system("pause");
	return 0;
}