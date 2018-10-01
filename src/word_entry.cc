#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "word_entry.h"

word_entry_t* word_entry_new(const char* word, const int count) {
    word_entry_t* new_entry = (word_entry_t*)malloc(sizeof(word_entry_t));
    new_entry->word = strdup(word);  /* strdup() uses dynamic allocation */
    new_entry->count = count;
    return new_entry;
}

void word_entry_print(word_entry_t* word_entry) {
    assert (word_entry != NULL);
    printf("word %s; word count %d\n", word_entry->word, word_entry->count);
}

void word_entry_dispose(word_entry_t* word_entry) {
    assert (word_entry != NULL);
    free(word_entry->word);
    free(word_entry);
}

void word_entry_bump(word_entry_t* word_entry) {
    assert (word_entry != NULL);
    word_entry->count++;
}

int word_entry_count(word_entry_t* word_entry) {
    assert (word_entry != NULL);
    return word_entry->count;
}
