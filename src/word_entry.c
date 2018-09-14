#include <stdio.h>
#include <stdlib.h>

#include "word_entry.h"

word_entry_t* new_word_entry_t(char* word, int count) {
  word_entry_t* new_entry = (word_entry_t*)malloc(sizeof(word_entry_t));
  new_entry->word = word; /* todo: consider strdup() to copy the string here */
  new_entry->count = count;
  return new_entry;
}

void print_word_entry(word_entry_t* word_entry) {
  printf("word %s; word count %d\n", word_entry->word, word_entry->count);
}

