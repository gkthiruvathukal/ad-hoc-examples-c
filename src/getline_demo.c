#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>

#define WITH_LINUX
#define MAX_ERROR_MSG 80
/*
 * This example shows a strbuffer_t-enabled getline() like function
 * and how to use strtok() to separate text with whitespace delimiters.
 */

#include "strbuffer.h"

#define DELIMS " \n\r\t"


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

void print_words (regex_t *r, char * to_match, int max_matches)
{
    char * p = to_match;
    const int n_matches = 1;
    regmatch_t m[n_matches];

    for(;;) {
        int nomatch = regexec (r, p, n_matches, m, 0);
        if (nomatch) break;
        for (int i = 0; i < n_matches; i++) {
            char* word = strndup(p+m[i].rm_so, m[i].rm_eo - m[i].rm_so);
            printf("Match at start %d, end %d, word %s\n", m[i].rm_so, m[i].rm_eo, word);
        }
        p += m[0].rm_eo;
    }
}

int main(int argc, char* argv[]) {
    
    strbuffer_t buffer;
    strbuffer_init(&buffer, 80, 10);
    regex_t r;
    compile_regex(&r, "(\\w+)");
    for (;;) {
        int eof;
        char* line = strbuffer_getline(&buffer, &eof);
        if (eof) break;
        print_words(&r, line, 100);
        free(line);
    }
}
