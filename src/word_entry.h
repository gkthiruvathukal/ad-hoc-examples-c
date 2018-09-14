/* This is called an include guard,
 * to protect the user from multiple
 * #include"word_entry.h" occurrences.
 */

#ifndef WORD_ENTRY_H
#define WORD_ENTRY_H

struct word_entry {
  char *word;
  int count;
};

typedef struct word_entry word_entry_t;

extern word_entry_t* new_word_entry_t(char* word, int count);
extern void print_word_entry(word_entry_t* word_entry);



#endif

