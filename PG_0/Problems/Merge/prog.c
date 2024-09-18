// Merge Sort
#include <stdio.h>
#include <stdlib.h>

// merges two arrays
void merge(float arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l +1;
    int n2 = r-m;

    //temp arrays
    float L[n1], R[n2];

    //coppy data to temp arrays
    for(i = 0; i <n1; i++){
        L[i]= arr[l +i];
    }
    for(j = 0; j <n2; j++){
        R[j] = arr[m+1+j];
    }

    //merge back
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // coppy remaining if any
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

//sorting algorythm, inspired by geeks for geeks.
void mergeSort(float arr[], int l, int r){
    if(l < r){
        int m = l + (r-l) /2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);

        merge(arr,l,m,r);
    }
}

int main(int argc, char *argv[]){

    //checks if missing arguments
	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	
	
	int size = getc(in_file) - '0';
	
	float* nums = (float*)malloc(size * sizeof(float));
    // fills the array from what is in the files
	char text[100];
	fgets(text,100,in_file);
	for(int i = 0; i < size; i++){
		fgets(text,100,in_file);
		nums[i]= atof(text);
	}
	
	
	fclose(in_file);

    int n = size ;
    // sorts the numbers
	mergeSort(nums,0,n-1);

    //makes the out file.
	fprintf(out_file,"%i\n",size );
	for(int i = 0; i < size; i++){
		fprintf(out_file, "%f\n", nums[i]);
	}


	fclose(out_file);
	free(nums);
	
	return 0;



}