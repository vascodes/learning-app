#include <stdio.h>
#include <stdlib.h>
#include "questionmanager/questionmanager.h"

int main() {			
	question q;
	char str[] = "what is german for one?|eins|2";
	qm_get_question_from_str(str, &q);
	
	printf("\nThe question is: %s", q.question);
	printf("\nThe answer is: %s", q.answer);
	printf("\nThe freq is: %d", q.frequency);
	
	return 0;
}
