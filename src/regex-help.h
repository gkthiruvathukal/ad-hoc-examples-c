#ifndef _REGEX_HELP_
#define _REGEX_HELP_

#define WITH_LINUX

#define MAX_ERROR_MSG 100

#include <regex.h>

typedef struct _matchinfo_t {
  char* location;
  int start, finish;
  int is_match;
} matchinfo_t;


matchinfo_t* get_matches(regex_t* r, char* to_match, int n_matches);
int compile_regex (regex_t * r, const char * regex_text);

#endif
