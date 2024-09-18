// Selection Sort
#include <stdio.h>
#include <stdlib.h>

// sorting algorythm, 
void selectionSort(float arr[], int n){
    int i, j;
	float min, max;

    //move bounds
    for(i=0;i<n-1; i++){

        

        for (j = i+1; j < n; j++){
			// delete conditionals
			min = !(arr[i] > arr[j])*arr[i] + (arr[i] > arr[j])*arr[j] ;
        	max = (arr[i] > arr[j])*arr[i] + !(arr[i] > arr[j])*arr[j] ;
			arr[i] = min;
			arr[j] = max;
        }

        

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

	
	
	int size = 4;
	
	float* nums = (float*)malloc(size * sizeof(float));
	// fills the array whit the contents of the file
	char text[100];
	
	for(int i = 0; i < size; i++){
		fgets(text,100,in_file);
		nums[i]= atof(text);
	}
	
	
	fclose(in_file);

    int n = size ;
	// sorts the array
	selectionSort(nums,n);
	// makes the outfile

	for(int i = 0; i < size; i++){
		fprintf(out_file, "%.1f\n", nums[i]);
	}


	fclose(out_file);
	free(nums);
	
	return 0;



}