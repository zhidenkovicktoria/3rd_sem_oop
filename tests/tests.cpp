#include <gtest/gtest.h>
#include "CustomMemoryResource.h"
#include "Queue.h"

struct ComplexType {
    int a;
    double b;
};

TEST(QueueTest, IntQueue) {
    CustomMemoryResource custom_memory_resource;
    std::pmr::polymorphic_allocator<int> int_allocator(&custom_memory_resource);
    Queue<int> int_queue(int_allocator);

    int_queue.push(1);
    int_queue.push(2);
    int_queue.push(3);

    ASSERT_FALSE(int_queue.empty());
    ASSERT_EQ(int_queue.front(), 1);
    int_queue.pop();
    ASSERT_EQ(int_queue.front(), 2);
    int_queue.pop();
    ASSERT_EQ(int_queue.front(), 3);
    int_queue.pop();
    ASSERT_TRUE(int_queue.empty());
}

TEST(QueueTest, ComplexTypeQueue) {
    CustomMemoryResource custom_memory_resource;
    std::pmr::polymorphic_allocator<ComplexType> complex_allocator(&custom_memory_resource);
    Queue<ComplexType> complex_queue(complex_allocator);

    ComplexType ct1{1, 2.0};
    ComplexType ct2{3, 4.0};
    ComplexType ct3{5, 6.0};

    complex_queue.push(ct1);
    complex_queue.push(ct2);
    complex_queue.push(ct3);

    ASSERT_FALSE(complex_queue.empty());
    ASSERT_EQ(complex_queue.front().a, 1);
    ASSERT_EQ(complex_queue.front().b, 2.0);
    complex_queue.pop();
    ASSERT_EQ(complex_queue.front().a, 3);
    ASSERT_EQ(complex_queue.front().b, 4.0);
    complex_queue.pop();
    ASSERT_EQ(complex_queue.front().a, 5);
    ASSERT_EQ(complex_queue.front().b, 6.0);
    complex_queue.pop();
    ASSERT_TRUE(complex_queue.empty());
}

TEST(QueueTest, IntQueueMultipleElements) {
    CustomMemoryResource custom_memory_resource;
    std::pmr::polymorphic_allocator<int> int_allocator(&custom_memory_resource);
    Queue<int> int_queue(int_allocator);

    for (int i = 1; i <= 10; ++i) {
        int_queue.push(i);
    }

    for (int i = 1; i <= 10; ++i) {
        ASSERT_EQ(int_queue.front(), i);
        int_queue.pop();
    }

    ASSERT_TRUE(int_queue.empty());
}

TEST(QueueTest, ComplexTypeQueueMultipleElements) {
    CustomMemoryResource custom_memory_resource;
    std::pmr::polymorphic_allocator<ComplexType> complex_allocator(&custom_memory_resource);
    Queue<ComplexType> complex_queue(complex_allocator);

    for (int i = 1; i <= 10; ++i) {
        ComplexType ct{i, static_cast<double>(i * 2.0)};
        complex_queue.push(ct);
    }

    for (int i = 1; i <= 10; ++i) {
        ASSERT_EQ(complex_queue.front().a, i);
        ASSERT_EQ(complex_queue.front().b, static_cast<double>(i * 2.0));
        complex_queue.pop();
    }

    ASSERT_TRUE(complex_queue.empty());
}

TEST(QueueTest, IntQueueIterator) {
    CustomMemoryResource custom_memory_resource;
    std::pmr::polymorphic_allocator<int> int_allocator(&custom_memory_resource);
    Queue<int> int_queue(int_allocator);

    for (int i = 1; i <= 5; ++i) {
        int_queue.push(i);
    }

    int index = 1;
    for (auto it = int_queue.begin(); it != int_queue.end(); ++it) {
        ASSERT_EQ(*it, index);
        ++index;
    }
}

TEST(QueueTest, ComplexTypeQueueIterator) {
    CustomMemoryResource custom_memory_resource;
    std::pmr::polymorphic_allocator<ComplexType> complex_allocator(&custom_memory_resource);
    Queue<ComplexType> complex_queue(complex_allocator);

    for (int i = 1; i <= 5; ++i) {
        ComplexType ct{i, static_cast<double>(i * 2.0)};
        complex_queue.push(ct);
    }

    int index = 1;
    for (auto it = complex_queue.begin(); it != complex_queue.end(); ++it) {
        ASSERT_EQ(it->a, index);
        ASSERT_EQ(it->b, static_cast<double>(index * 2.0));
        ++index;
    }
}
