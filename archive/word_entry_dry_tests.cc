#include <gtest/gtest.h>
#include "word_entry.h"

// To use text fixture (SetUp/TearDown) requires a C++ class and TEST_F (below)
// protected: required because this class acts as a base class for generated
// class in TEST_F.

class WordEntryTest : public ::testing::Test {
protected:
    void SetUp() override {
        word_entry1 = word_entry_new("comp310", 0);
        word_entry2 = word_entry_new("comp410", 0);
    }

    void TearDown() override {
        word_entry_dispose(word_entry1);
        word_entry_dispose(word_entry2);
    }

    word_entry_t* word_entry1;
    word_entry_t* word_entry2;
};

TEST_F(WordEntryTest, Allocation) {
    // word_entry1
    ASSERT_TRUE(word_entry1 != NULL);
    ASSERT_EQ(word_entry1->count, 0);

    // word_entry2
    ASSERT_TRUE(word_entry2 != NULL);
    ASSERT_EQ(word_entry2->count, 0);
}

TEST_F(WordEntryTest, Mutators) {
    // word_entry1
    word_entry_bump(word_entry1);
    ASSERT_EQ(1, word_entry_count(word_entry1));

    // word_entry2
    word_entry_bump(word_entry2);
    word_entry_bump(word_entry2);
    ASSERT_EQ(2, word_entry_count(word_entry2));
}

TEST_F(WordEntryTest, Accessors) {
    // word_entry1
    ASSERT_STREQ(word_entry_get_word(word_entry1), "comp310");
    ASSERT_EQ(0, word_entry_count(word_entry1));

    // word_entry2
    ASSERT_STREQ(word_entry_get_word(word_entry2), "comp410");
    ASSERT_EQ(0, word_entry_count(word_entry2));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
