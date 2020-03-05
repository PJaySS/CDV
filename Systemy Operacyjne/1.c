#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
	int input_fd, output_fd; 
	ssize_t ret_in, ret_out;
	char buffer[BUF_SIZE];
	
		if(argc != 3){
			printf("Usage: %s file_orgin file_destination\n", argv[0]);
		return 1;
		}

	input_fd = open (argv[1], O_RDONLY);
		if(input_fd == -1) {
			fprintf(stderr, "Couldn't open file %s\n", argv[1]);
		return 2;
		}

	output_fd = open(argv[2], O_CREAT | O_WRONLY, 0644);
		if(output_fd == -1) {
			fprintf(stderr, "Couldn't open file %s\n", argv[2]);
		return 3;
	}
	
	while((ret_in = read(input_fd, &buffer, BUF_SIZE))>0)
	{
		ret_out = write(output_fd, &buffer, (ssize_t) ret_in);
		if(ret_in != ret_out) 
		{
			fprintf(stderr, "Copy failed\n");
			return 5;
	}
	}
	close(input_fd);
	close(output_fd);
	
	return 0;
	
}