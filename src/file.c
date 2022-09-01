#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX (1024 * 1024 * 5)

int main(int argc, char** argv) {
	char* path = argv[1];
	char* hexstring = argv[2];
	int hex = strtol(hexstring, NULL, 16);

	FILE *fptr;
	fptr = fopen(path, "rb");

	char buffer[MAX];
	int i = 0;

	while (!feof(fptr)) 
		buffer[i++] = fgetc(fptr) ^ hex;
	
	fclose(fptr);

	fptr = fopen(path, "wb");

	for (int j = 0; j < i - 1; j++) {
		fputc(buffer[j], fptr);
	}

	fclose(fptr);
	return 0;
}

