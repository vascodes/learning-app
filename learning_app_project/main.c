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
	
	get_str_from_question(q, str);
	printf("\nstr is: %s", str);
	
	printf("\nis ans correct: %d", qm_is_correct_answer(q, "eins"));
	
	return 0;
}
