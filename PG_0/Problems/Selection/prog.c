// Selection Sort
#include <stdio.h>
#include <stdlib.h>

// swaps two numbers
void swap(float* arr, int i, int j){
	float temp = arr[i];
	arr[i] = arr[j];
	arr[j]= temp;
}

// sorting algorythm, inspired by geeks for geeks
void selectionSort(float arr[], int n){
    int i, j, min_idx;

    //move bounds
    for(i=0;i<n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i)
            swap(arr,min_idx,i);

    }
}


int main(int argc, char *argv[]){
	// checks if missing arguments
	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	// opens files
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	
	
	int size = getc(in_file) - '0';
	
	float* nums = (float*)malloc(size * sizeof(float));
	// fills the array whit the contents of the file
	char text[100];
	fgets(text,100,in_file);
	for(int i = 0; i < size; i++){
		fgets(text,100,in_file);
		nums[i]= atof(text);
	}
	
	
	fclose(in_file);

    int n = size ;
	// sorts the array
	selectionSort(nums,n);
	// makes the outfile
	fprintf(out_file,"%i\n",size );
	for(int i = 0; i < size; i++){
		fprintf(out_file, "%f\n", nums[i]);
	}


	fclose(out_file);
	free(nums);
	
	return 0;



}