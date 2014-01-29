#include <gtest/gtest.h>
#include "linked_list.h"

TEST(PushElements, One) {
    doubly_list *list = NULL;
    insert(&list, 1);
    ASSERT_EQ(list->value, 1);
}
