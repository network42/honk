#include <stdio.h>
#include <stdlib.h>

#include "honk_list.h"

#define BASH_OK 0
#define BASH_FAIL 1

typedef FILE *bash;

//Execute a shell command
int bash_exec(bash* bash_fp, const char* command) {
	*bash_fp = popen(command, "r");
	if (*bash_fp == NULL) { return BASH_FAIL; }
	return BASH_OK;
}

//Store bash command output in a linked list
struct llist* bash_tolist(bash* bash_fp) {
	struct llist* list = llist_create();
	char* line = NULL;
	size_t length = 0;
	ssize_t read;

	while ((read = getline(&line, &length, *bash_fp)) != -1) {
		llist_insert(list, line);
		length = 0;
		line = NULL;
	}
	return list;
}

//Close and clean the bash command
void bash_close(bash* bash_fp) {
	pclose(*bash_fp);
}

//Helper function to print a node
int printstring(void *s)
{
        printf("%s", (char *)s);
        return 0;
}

