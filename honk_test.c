//#!/usr/local/bin/honk -run -g

#include "honk.h"

int main(void) 
{

	bash ls;
	struct llist *ls_list;

	bash_exec(&ls, "cat /var/log/syslog");
	ls_list = bash_tolist(&ls);
	llist_foreach(ls_list, printstring);
	llist_free(ls_list);
	bash_close(&ls);
	return 0;
}

