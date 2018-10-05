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

extern word_entry_t* word_entry_new(const char* word, const int count);
extern void word_entry_print(word_entry_t* word_entry);
extern void word_entry_dispose(word_entry_t* word_entry);
extern void word_entry_bump(word_entry_t* word_entry);
extern int word_entry_count(word_entry_t* word_entry);
extern char* word_entry_get_word(word_entry_t* word_entry);

#endif

