#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "common.h"

void dataInput ( int count, struct student *s);
void dataOutput (int count, struct student *s);
int dataSave(int count, struct student *s, const char *file);
struct student *dataRead(const char *file, int *count);

int main(){
	int c = 0;
	int yn=0;
	char *file = "data.bin";
	struct student *s;
	struct student *data;
	int err = 0;

	printf("Do you want to see existing student data?\n");
	scanf("%d", &yn);
	if( yn == 1){
		data = dataRead(file, &c);
		if( !data){
			printf("Error reading database: %m\n");
		}
		else{
			printf("There are %d students in databas: \n", c);
			dataOutput(c, data);
		}
	}

	printf("Please enter number of students: ");
	scanf("%d", &c);

	s = (struct student *)malloc( sizeof(struct student) * c);

	dataInput(c, s);
	dataOutput(c, s);
	
	printf("Do you want to save the data(1/0)?");
	scanf("%d", &yn);
	if (yn == 1){
		printf("Saving data to %s...\n", file);
		err = dataSave(c,s,file);
		if (err){
			printf("Error saving data: %d(%m)\n", err);
		}
	}
	
	free(s);
	return 0;
}