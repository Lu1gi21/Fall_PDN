// transpose

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    // checks if arguments are complete
	if(argc < 3){
		printf("need more contents in command line");
		exit(0);
	}
	
    //opens files
	FILE *in_file = fopen(argv[1], "r");
	FILE *out_file = fopen(argv[2], "w");

	
	// get size of array
	int row = getc(in_file) - '0';
    getc(in_file);
    int column = getc(in_file) - '0';

    // finds size of 2Darray
	int size = row*column;
	float* nums = (float*)malloc(size* sizeof(float));

    // fills 2D array
	char text[100];
    char* pend;
	fgets(text,100,in_file);
	for(int i = 0; i < row; i++){
		fgets(text,100,in_file);
        char* temp = &text[0];
		for(int j = 0; j < column; j++){
            nums[i * column + j] = strtof(temp, &pend);
            temp = pend;
            pend = 0;
            
        }

	}
    fclose(in_file);
    // makes transposed outfile
    fprintf(out_file,"%i %i\n", column, row);
    for(int i = 0; i < column; i++){
        for(int j = 0; j <row; j++){
            fprintf(out_file, "%.0f ", nums[j * column + i]);
        }
        fprintf(out_file, "\n");
    }
    fclose(out_file);
    free(nums);


	



}