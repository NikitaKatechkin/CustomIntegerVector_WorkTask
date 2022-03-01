#include "pch.h"

#include "../CustomIntegerVector/CustomIntegerVector.h"
#include "../CustomIntegerVector/CustomIntegerVector.cpp"

#include "gtest/gtest.h"
#include "gtest/gtest-spi.h"

namespace CustomIntegerVectorTests
{
    TEST(CustomIntegerVectorTest, InitializationTest)
    {
        CustomIntegerVector test_vector;

        EXPECT_EQ(1, test_vector.GetCapacity());
        EXPECT_EQ(0, test_vector.GetSize());
        
        ASSERT_DEATH({ test_vector.Front(); }, "");
        ASSERT_DEATH({ test_vector.Back(); }, "");
    }

    TEST(CustomIntegerVectorTest, CapacityIncreaseTest)
    {
        CustomIntegerVector test_vector;

        test_vector.PushBack(1);

        EXPECT_EQ(1, test_vector.GetCapacity());
        EXPECT_EQ(1, test_vector.GetSize());

        test_vector.PushBack(2);

        EXPECT_EQ(2, test_vector.GetCapacity());
        EXPECT_EQ(2, test_vector.GetSize());

        test_vector.PushBack(3);

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(3, test_vector.GetSize());
    }

    TEST(CustomIntegerVectorTest, SizeDecreaseTest)
    {
        CustomIntegerVector test_vector;

        test_vector.PushBack(1);
        test_vector.PushBack(2);
        test_vector.PushBack(3);

        test_vector.PopBack();

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(2, test_vector.GetSize());

        EXPECT_EQ(1, test_vector.Front());
        EXPECT_EQ(2, test_vector.Back());

        test_vector.PopBack();

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(1, test_vector.GetSize());

        EXPECT_EQ(1, test_vector.Front());
        EXPECT_EQ(1, test_vector.Back());

        test_vector.PopBack();

        EXPECT_EQ(2, test_vector.GetCapacity());
        EXPECT_EQ(0, test_vector.GetSize());

        ASSERT_DEATH({ test_vector.Front(); }, "");
        ASSERT_DEATH({ test_vector.Back(); }, "");
    }
    
    TEST(CustomIntegerVectorTest, PushFrontTest)
    {
        CustomIntegerVector test_vector;

        test_vector.PushFront(1);

        EXPECT_EQ(1, test_vector.GetCapacity());
        EXPECT_EQ(1, test_vector.GetSize());

        test_vector.PushFront(2);

        EXPECT_EQ(2, test_vector.GetCapacity());
        EXPECT_EQ(2, test_vector.GetSize());

        test_vector.PushFront(3);

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(3, test_vector.GetSize());
    }
    
    TEST(CustomIntegerVectorTest, PopFrontTest)
    {
        CustomIntegerVector test_vector;

        test_vector.PushBack(1);
        test_vector.PushBack(2);
        test_vector.PushBack(3);

        test_vector.PopFront();

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(2, test_vector.GetSize());

        EXPECT_EQ(2, test_vector.Front());
        EXPECT_EQ(3, test_vector.Back());

        test_vector.PopFront();

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(1, test_vector.GetSize());

        EXPECT_EQ(3, test_vector.Front());
        EXPECT_EQ(3, test_vector.Back());

        test_vector.PopFront();

        EXPECT_EQ(2, test_vector.GetCapacity());
        EXPECT_EQ(0, test_vector.GetSize());

        ASSERT_DEATH({ test_vector.Front(); }, "");
        ASSERT_DEATH({ test_vector.Back(); }, "");
    }
    
    TEST(CustomIntegerVectorTest, ClearTest)
    {
        CustomIntegerVector test_vector;

        test_vector.PushFront(1);
        test_vector.PushFront(2);
        test_vector.PushFront(3);

        ASSERT_NO_THROW({ test_vector.Clear(); }, "");

        EXPECT_EQ(1, test_vector.GetCapacity());
        EXPECT_EQ(0, test_vector.GetSize());

        ASSERT_DEATH({ test_vector.Front(); }, "");
        ASSERT_DEATH({ test_vector.Back(); }, "");

        ASSERT_NO_THROW({ test_vector.Clear(); }, "");

        EXPECT_EQ(1, test_vector.GetCapacity());
        EXPECT_EQ(0, test_vector.GetSize());

        ASSERT_DEATH({ test_vector.Front(); }, "");
        ASSERT_DEATH({ test_vector.Back(); }, "");
    }

    TEST(CustomIntegerVectorTest, InsertTest)
    {
        CustomIntegerVector test_vector;

        test_vector.Insert(0, 1);

        EXPECT_EQ(1, test_vector.GetCapacity());
        EXPECT_EQ(1, test_vector.GetSize());

        EXPECT_EQ(1, test_vector.Front());
        EXPECT_EQ(1, test_vector.Back());

        test_vector.Insert(1, 2);

        EXPECT_EQ(2, test_vector.GetCapacity());
        EXPECT_EQ(2, test_vector.GetSize());

        EXPECT_EQ(1, test_vector.Front());
        EXPECT_EQ(2, test_vector.Back());

        test_vector.Insert(1, 3);

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(3, test_vector.GetSize());

        EXPECT_EQ(1, test_vector.Front());
        EXPECT_EQ(2, test_vector.Back());
    }

    TEST(CustomIntegerVectorTest, EraseTest)
    {
        CustomIntegerVector test_vector;

        test_vector.Insert(0, 1);

        test_vector.Insert(1, 2);

        test_vector.Insert(1, 3);

        test_vector.Erase(1);

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(2, test_vector.GetSize());

        EXPECT_EQ(1, test_vector.Front());
        EXPECT_EQ(2, test_vector.Back());

        test_vector.Erase(0);

        EXPECT_EQ(4, test_vector.GetCapacity());
        EXPECT_EQ(1, test_vector.GetSize());

        EXPECT_EQ(2, test_vector.Front());
        EXPECT_EQ(2, test_vector.Back());

        test_vector.Erase(test_vector.GetSize());

        EXPECT_EQ(2, test_vector.GetCapacity());
        EXPECT_EQ(0, test_vector.GetSize());

        ASSERT_DEATH({ test_vector.Front(); }, "");
        ASSERT_DEATH({ test_vector.Back(); }, "");

    }
}
