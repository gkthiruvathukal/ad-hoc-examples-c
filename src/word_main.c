#include "word_entry.h"

int main(int argc, char* argv) {
  word_entry_t* word_entry1 = new_word_entry_t("comp310", 0);
  word_entry_t* word_entry2 = new_word_entry_t("comp410", 0);
  print_word_entry(word_entry1);
  print_word_entry(word_entry2);
}
