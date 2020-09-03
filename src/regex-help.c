#include "regex-help.h"

#include <stdio.h>
#include <stdlib.h>


matchinfo_t* get_matches (regex_t *r, char * to_match, int n_matches)
{
    char * p = to_match;
    regmatch_t* m = (regmatch_t*) malloc(n_matches * sizeof(regmatch_t));
    matchinfo_t* results = (matchinfo_t*) calloc(n_matches,  sizeof(matchinfo_t)); 

    while (1) {
        int i = 0;
        int nomatch = regexec (r, p, n_matches, m, 0);
        if (nomatch) {
           break;
        }
        for (i = 0; i < n_matches; i++) {
            int start;
            int finish;
            if (m[i].rm_so == -1) {
                break;
            }
            // Users want to have an easy way of knowing the positions
            // start, finish, and be able to copy the substring.
            results[i].start = m[i].rm_so + (p - to_match);
            results[i].finish = m[i].rm_eo + (p - to_match);
            results[i].location = p;
            results[i].is_match = 1;
        }
        p += m[0].rm_eo;
    }
    free(m);
    return results;
}


int compile_regex (regex_t * r, const char * regex_text)
{
    //int status = regcomp (r, regex_text, REG_EXTENDED|REG_ENHANCED|REG_NEWLINE);
    //
#ifdef WITH_APPLE
    int status = regcomp (r, regex_text, REG_EXTENDED|REG_ENHANCED|REG_NEWLINE);
#endif
#ifdef WITH_LINUX
    int status = regcomp (r, regex_text, REG_EXTENDED|REG_NEWLINE);
#endif
    if (status != 0) {
        char error_message[MAX_ERROR_MSG];
        regerror (status, r, error_message, MAX_ERROR_MSG);
        printf ("Regex error compiling '%s': %s\n", regex_text, error_message);
        return 1;
    }
    return 0;
}

