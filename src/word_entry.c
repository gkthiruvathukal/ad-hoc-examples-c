#include <stdio.h>
#include <stdlib.h>

struct word_entry {
  char *word;
  int count;
};

typedef struct word_entry word_entry_t;


word_entry_t* new_word_entry_t(char* word, int count) {
  word_entry_t* new_entry = (word_entry_t*)malloc(sizeof(word_entry_t));
  new_entry->word = word; /* todo: consider strdup() to copy the string here */
  new_entry->count = count;
  return new_entry;
}

void print_word_entry(word_entry_t* word_entry) {
  printf("word %s; word count %d\n", word_entry->word, word_entry->count);
}

int main(int argc, char* argv) {
  word_entry_t* word_entry1 = new_word_entry_t("comp310", 0);
  word_entry_t* word_entry2 = new_word_entry_t("comp410", 0);
  print_word_entry(word_entry1);
  print_word_entry(word_entry2);
}




