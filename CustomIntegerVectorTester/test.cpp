#include "pch.h"

#include "../CustomIntegerVector/CustomIntegerVector.h"
#include "../CustomIntegerVector/CustomIntegerVector.cpp"

#include "gtest/gtest.h"
#include "gtest/gtest-spi.h"


TEST(CustomIntegerVectorTest, InitializationTest)
{
    CustomIntegerVector test_vector;

    EXPECT_EQ(1, test_vector.GetCapacity());
    EXPECT_EQ(0, test_vector.GetSize());

    CustomIntegerVector test_vector_1({1, 2, 3 ,4});

    EXPECT_EQ(4, test_vector_1.GetCapacity());
    EXPECT_EQ(4, test_vector_1.GetSize());
    EXPECT_EQ(test_vector_1, CustomIntegerVector({ 1, 2, 3 ,4 }));

    CustomIntegerVector test_vector_2(test_vector_1);

    EXPECT_EQ(4, test_vector_2.GetCapacity());
    EXPECT_EQ(4, test_vector_2.GetSize());
    EXPECT_EQ(test_vector_2, CustomIntegerVector({ 1, 2, 3 ,4 }));

    EXPECT_EQ(test_vector_2, test_vector_1);
}

TEST(CustomIntegerVectorTest, BackTest)
{
    CustomIntegerVector test_vector;

    try
    {
        test_vector.Back();
        FAIL() << "Back() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), 
                  "Access to the back element of an empty vector exception.");
    }

    test_vector = CustomIntegerVector({ 1, 2, 3 });
    
    EXPECT_EQ(test_vector.Back(), 3);
}

TEST(CustomIntegerVectorTest, FrontTest)
{
    CustomIntegerVector test_vector;

    try
    {
        test_vector.Front();
        FAIL() << "Back() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()),
            "Access to the front element of an empty vector exception.");
    }

    test_vector = CustomIntegerVector({ 1, 2, 3 });

    EXPECT_EQ(test_vector.Front(), 1);
}

TEST(CustomIntegerVectorTest, PushBackTest)
{
    CustomIntegerVector test_vector;

    test_vector.PushBack(1);

    EXPECT_EQ(1, test_vector.GetCapacity());
    EXPECT_EQ(1, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({1}));

    test_vector.PushBack(2);

    EXPECT_EQ(2, test_vector.GetCapacity());
    EXPECT_EQ(2, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({ 1, 2 }));

    test_vector.PushBack(3);

    EXPECT_EQ(4, test_vector.GetCapacity());
    EXPECT_EQ(3, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({ 1, 2, 3 }));
}

TEST(CustomIntegerVectorTest, PushFrontTest)
{
    CustomIntegerVector test_vector;

    test_vector.PushFront(1);

    EXPECT_EQ(1, test_vector.GetCapacity());
    EXPECT_EQ(1, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({ 1 }));

    test_vector.PushFront(2);

    EXPECT_EQ(2, test_vector.GetCapacity());
    EXPECT_EQ(2, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({ 2, 1 }));

    test_vector.PushFront(3);

    EXPECT_EQ(4, test_vector.GetCapacity());
    EXPECT_EQ(3, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({ 3, 2, 1 }));
}

TEST(CustomIntegerVectorTest, PopBackTest)
{
    CustomIntegerVector test_vector;

    try
    {
        test_vector.PopBack();
        FAIL() << "PopBack() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Erasing of an empty vector exception.");
    }

    test_vector = CustomIntegerVector({1, 2, 3});

    test_vector.PopBack();

    EXPECT_EQ(3, test_vector.GetCapacity());
    EXPECT_EQ(2, test_vector.GetSize());

    EXPECT_EQ(test_vector, CustomIntegerVector({ 1, 2 }));

    test_vector.PopBack();

    EXPECT_EQ(3, test_vector.GetCapacity());
    EXPECT_EQ(1, test_vector.GetSize());

    EXPECT_EQ(test_vector, CustomIntegerVector({ 1 }));

    test_vector.PopBack();

    try
    {
        test_vector.PopBack();
        FAIL() << "PopBack() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Erasing of an empty vector exception.");
    }
}
    
TEST(CustomIntegerVectorTest, PopFrontTest)
{
    CustomIntegerVector test_vector;

    try
    {
        test_vector.PopFront();
        FAIL() << "PopBack() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Erasing of an empty vector exception.");
    }

    test_vector = CustomIntegerVector({ 1, 2, 3 });

    test_vector.PopFront();

    EXPECT_EQ(3, test_vector.GetCapacity());
    EXPECT_EQ(2, test_vector.GetSize());

    EXPECT_EQ(test_vector, CustomIntegerVector({ 2, 3 }));

    test_vector.PopFront();

    EXPECT_EQ(3, test_vector.GetCapacity());
    EXPECT_EQ(1, test_vector.GetSize());

    EXPECT_EQ(test_vector, CustomIntegerVector({ 3 }));

    test_vector.PopFront();

    try
    {
        test_vector.PopFront();
        FAIL() << "PopBack() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Erasing of an empty vector exception.");
    }
}

TEST(CustomIntegerVectorTest, InsertTest)
{
    CustomIntegerVector test_vector;

    try
    {
        test_vector.Insert(1, 0);
        FAIL() << "Insert() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Out of bounds insertion index exception.");
    }

    test_vector.Insert(0, 1);

    EXPECT_EQ(1, test_vector.GetCapacity());
    EXPECT_EQ(1, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({ 1 }));

    test_vector.Insert(test_vector.GetSize(), 2);

    EXPECT_EQ(2, test_vector.GetCapacity());
    EXPECT_EQ(2, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({ 1, 2 }));

    test_vector.Insert(test_vector.GetSize() - 1, 3);

    EXPECT_EQ(4, test_vector.GetCapacity());
    EXPECT_EQ(3, test_vector.GetSize());
    EXPECT_EQ(test_vector, CustomIntegerVector({ 1, 3, 2 }));

    try
    {
        test_vector.Insert(test_vector.GetSize() + 1, 0);
        FAIL() << "Insert() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Out of bounds insertion index exception.");
    }
}

TEST(CustomIntegerVectorTest, EraseTest)
{
    CustomIntegerVector test_vector;

    try
    {
        test_vector.Erase(0);
        FAIL() << "Erase() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Erasing of an empty vector exception.");
    }

    test_vector = CustomIntegerVector({ 1, 2, 3, 4 });

    test_vector.Erase(0);

    EXPECT_EQ(4, test_vector.GetCapacity());
    EXPECT_EQ(3, test_vector.GetSize());

    EXPECT_EQ(test_vector, CustomIntegerVector({ 2, 3, 4 }));

    test_vector.Erase(test_vector.GetSize() - 2);

    EXPECT_EQ(4, test_vector.GetCapacity());
    EXPECT_EQ(2, test_vector.GetSize());

    EXPECT_EQ(test_vector, CustomIntegerVector({ 2, 4 }));

    test_vector.Erase(test_vector.GetSize() - 1);

    EXPECT_EQ(4, test_vector.GetCapacity());
    EXPECT_EQ(1, test_vector.GetSize());

    EXPECT_EQ(test_vector, CustomIntegerVector({ 2 }));

    try
    {
        test_vector.Erase(test_vector.GetSize());
        FAIL() << "Erase() should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Out of bounds erasing index exception.");
    }

    test_vector.Erase(test_vector.GetSize() - 1);

    EXPECT_EQ(2, test_vector.GetCapacity());
    EXPECT_EQ(0, test_vector.GetSize());

    EXPECT_EQ(test_vector, CustomIntegerVector({ }));
}

TEST(CustomIntegerVectorTest, ClearTest)
{
    CustomIntegerVector test_vector;

    test_vector.Clear();

    test_vector = CustomIntegerVector({ 1, 2, 3 });

    test_vector.Clear();

    EXPECT_EQ(1, test_vector.GetCapacity());
    EXPECT_EQ(0, test_vector.GetSize());

    test_vector.Clear();
}

TEST(CustomIntegerVectorTest, AccessToElementTest)
{
    CustomIntegerVector test_vector;

    try
    {
        test_vector[0];
        FAIL() << "[] should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Out of bounds access index exception.");
    }

    test_vector = CustomIntegerVector({ 1, 2, 3, 4 });

    test_vector[0];
    test_vector[test_vector.GetSize() - 1];
    test_vector[test_vector.GetSize() - 2];

    try
    {
        test_vector[test_vector.GetSize()];
        FAIL() << "[] should be failed.";
    }
    catch (const std::exception& e)
    {
        EXPECT_EQ(std::string(e.what()), "Out of bounds access index exception.");
    }
}
