#include <stdio.h>
#include "questionmanager/questionmanager.h"

int main() {				
	int i;
	question questions[100];
	qm_create_questions();
	qm_set_questions_arr();
	int n = qm_get_all_questions(questions);
	printf("\n");
	for(i = 0; i < n; i++){
		printf("Question: %s\n", questions[i].question);
		printf("Answer: %s\n", questions[i].answer);
		printf("Frequency: %d\n\n", questions[i].frequency);
	}
	
	return 0;
}
