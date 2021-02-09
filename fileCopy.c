#include <stdio.h>
#include <stdlib.h>
/*

	This little program copies the binary content of any file to a new file designated by the command line

	Syntax:
		.\copyFile originalFile.extension newFile.extension

*/

void main (int argc, char*argv[])
{
	FILE *fileIn, *fileOut;
	int ch;
	
	
	/* 
		- argv[] is a vector of arguments
		- argv[0] is the aplication dir
		- argv[1] the first argument (original file)
		- argv[2] the second argumento (new file to be created)
	*/
	
	
	// Case the program receive one or more than three arguments, an error message are display.
	if (argc!=3)
		{
			printf("\n\nTWO ARGUMENTS ARE NECESSARY!\n\nSintax:  .\\fileCopy originalFile.extension newFile.extension\n\n");
		}
	else
		{
			fileIn = fopen(argv[1], "rb");
			
			if(fileIn==NULL)
				{
					printf("Fail to open %s\n", argv[1]);
					exit(2);
				}
			
			fileOut = fopen(argv[2], "wb");
			
			if (fileOut==NULL)
				{
					printf("Fail to create the file %s\n", argv[2]);
					exit(3);
				}
			
			while ((ch=fgetc(fileIn))!=EOF)
				{
					fputc(ch, fileOut);
				}
				
			fclose(fileIn);
			fclose(fileOut);
		}
	
	//Success message
	printf("\n\n##############################\n\n%s successfully copied to %s\n\n##############################", argv[1], argv[2]);
		
	
}
