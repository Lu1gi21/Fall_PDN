// Bubble Sort
#include <stdio.h>
#include <stdlib.h>


// Swaps the identified numbers
void swap(float* arr, int i, int j){
	float temp = arr[i];
	arr[i] = arr[j];
	arr[j]= temp;
}

//Bubble Sort algorithm inspired on geeksforgeeks algorithm
void bubbleSort(float arr[], int n)
{
	int i,j;
	
	for (i = 0; i < n -1; i++){

		for(j = 0; j < n-i -1; j++){

			if (arr[j] > arr[j +1]){
				swap(arr, j, j +1);
			}
		}
	}
}

int main(int argc, char *argv[]){

	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	
	//opens files
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	
	
	int size = getc(in_file) - '0';
	
	float* nums = (float*)malloc(size * sizeof(float));
	// fills the array
	char text[100];
	fgets(text,100,in_file);
	for(int i = 0; i < size; i++){
		fgets(text,100,in_file);
		nums[i]= atof(text);
	}
	
	
	fclose(in_file);

	//sorts the numbers
	bubbleSort(nums,size);

	// makes the outfile
	fprintf(out_file,"%i\n",size );
	for(int i = 0; i < size; i++){
		fprintf(out_file, "%f\n", nums[i]);
	}


	fclose(out_file);
	free(nums);
	
	return 0;



}
