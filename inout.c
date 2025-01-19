#include <stdio.h>
#include <stdlib.h>

#include "common.h"

void dataInput(int count, struct student *s) {
	if(count<1)
		printf("Nothing to show\n");
		return;
	if(count > MAX_STUDENTS){
		printf("Too much data for input\n");
		return;
	}
	for (int i = 0; i < count; i++){
		printf("Please enter data for student %d:\n", i + 1);
		scanf("%s %s %d %d", (s+i)->name, (s+1)->lastname,
					&(s+i)->group_id, &(s+i)->course );
	}
	return;
}

void dataOutput( int count, struct student *s){
	if (count < 1){
		printf("No data to show\n");
		goto exit;
	}
	if (count > MAX_STUDENTS) {
		printf("Too much data to show\n");
		goto exit;
	}
	printf("User entered data:\n");
	for ( int i = 0; i < count; i++){
		printf("%s\t%s\t%d\t%d\n", (s+i)->name, (s+i)->lastname,
					(s+i)->group_id, (s+i)->course);
	}
	
exit:
	return;
}
