/* test cases */

#include <gtest/gtest.h>

#include "word_entry.h"
 
TEST(WordEntry, Allocate) { 
    word_entry_t* word_entry1 = word_entry_new("comp310", 0);
    word_entry_t* word_entry2 = word_entry_new("comp410", 0);
    ASSERT_TRUE(word_entry1 != NULL);
    ASSERT_TRUE(word_entry2 != NULL);
    ASSERT_EQ(word_entry1->count, 0);
    ASSERT_EQ(word_entry2->count, 0);
}
 
TEST(WordEntry, Bump) {
    word_entry_t* word_entry1 = word_entry_new("comp310", 0);
    word_entry_t* word_entry2 = word_entry_new("comp410", 0);

    word_entry_bump(word_entry1);
    word_entry_bump(word_entry2);
    word_entry_bump(word_entry2);
    ASSERT_EQ(1, word_entry_count(word_entry1));
    ASSERT_EQ(2, word_entry_count(word_entry2));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
