#include <stdio.h>
#include <stdlib.h>

void sayHi() {
	printf("Hi!\n");
}

void hablarHolla() {
	printf("Holla!\n");
}

void dizerOi() {
	printf("OI!\n");
}

void parlareCiao() {
	printf("Ciao!\n");
}

void greetings(void (*greetingFunction)(void)) {
	greetingFunction();
}

enum {EN = 1, ES, PT_BR, IT};

int main() {
	void (*greetingFunCollection[])(void) = {sayHi, hablarHolla, 
										dizerOi, parlareCiao};
    const char msg[] = "Type a language:\n\t1. English\n\t2. Spanish\n\t3. Portuguese-BR\n\t4. Italian\n";
    printf("%s\n>>> ", msg);
	int languageCode;
	scanf("%d", &languageCode);
	getchar();
	switch(languageCode) {
		case EN:
			greetings((*greetingFunCollection[EN - 1]));
			break;
		case ES:
			greetings((*greetingFunCollection[ES - 1]));
			break;
		case PT_BR:
			greetings((*greetingFunCollection[PT_BR - 1]));
			break;
		case IT:
			greetings((*greetingFunCollection[IT - 1]));
			break;
		default:
			printf("Given language is not supported.\n");
			break;
	} 
	return 0;
}
