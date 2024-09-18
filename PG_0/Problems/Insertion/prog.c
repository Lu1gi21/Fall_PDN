// insetrion Sort
#include <stdio.h>
#include <stdlib.h>

// insertion sort algorythm inspired by geeks for geeks.
void insertionSort(float arr[], int n){
    for(int i = 1; i < n; i++){
        float key = arr[i];
        int j = i -1;

        while (j >=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j= j-1;
        }
        arr[j+1] = key;
    }
}

int main(int argc, char *argv[]){
	// checks if arguments are correct
	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	
	
	int size = getc(in_file) - '0';
	
	float* nums = (float*)malloc(size * sizeof(float));
	// fills array with numbers in the file
	char text[100];
	fgets(text,100,in_file);
	for(int i = 0; i < size; i++){
		fgets(text,100,in_file);
		nums[i]= atof(text);
	}
	
	
	fclose(in_file);

    int n = size ;
	// sorts the numbers
	insertionSort(nums,n);

	//builds the out file
	fprintf(out_file,"%i\n",size );
	for(int i = 0; i < size; i++){
		fprintf(out_file, "%f\n", nums[i]);
	}


	fclose(out_file);
	free(nums);
	
	return 0;



}