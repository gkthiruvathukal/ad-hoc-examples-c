#include "word_entry.h"

int main(int argc, char* argv[]) {
    word_entry_t* word_entry1 = word_entry_new("comp310", 0);
    word_entry_t* word_entry2 = word_entry_new("comp410", 0);
    word_entry_print(word_entry1);
    word_entry_print(word_entry2);
    word_entry_bump(word_entry1);
    word_entry_bump(word_entry1);
    word_entry_bump(word_entry2);
    word_entry_print(word_entry1);
    word_entry_print(word_entry2);
    word_entry_dispose(word_entry1);
    word_entry_dispose(word_entry2);
}
