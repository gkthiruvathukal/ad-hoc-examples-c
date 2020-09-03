#include "regex-help.h"

#include <stdio.h>

int main (int argc, char ** argv)
  {
      regex_t r;
      matchinfo_t* results = NULL;

      const char * regex_text;
      const char * find_text;
      if (argc != 3) {
          //regex_text = "([[:digit:]]+)[^[:digit:]]+([[:digit:]]+)";
          regex_text = "(\\w+)";
          find_text = "This 1 is nice 2 so 33 for 4254";
      }
      else {
          regex_text = argv[1];
          find_text = argv[2];
      }
      printf ("Trying to find '%s' in '%s'\n", regex_text, find_text);
      compile_regex (& r, regex_text);
      results = get_matches(&r, find_text, 1000);
      for (int i=0; i < 1000 && results[i].is_match; i++) {
        printf("match result %s, start=%d, finish=%d\n", 
            results[i].location, results[i].start, results[i].finish);
      }
      return 0;
  }

