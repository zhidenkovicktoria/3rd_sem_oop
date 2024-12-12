#ifndef QUEUE_H
#define QUEUE_H

#include <memory_resource>
#include <deque>
#include <queue>

template <typename T>
class Queue {
public:
    using value_type = T;
    using allocator_type = std::pmr::polymorphic_allocator<T>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using iterator = typename std::deque<T, allocator_type>::iterator;
    using const_iterator = typename std::deque<T, allocator_type>::const_iterator;

    explicit Queue(const allocator_type& alloc = allocator_type())
        : data(alloc) {}

    void push(const_reference value) {
        data.push_back(value);
    }

    void pop() {
        data.pop_front();
    }

    reference front() {
        return data.front();
    }

    const_reference front() const {
        return data.front();
    }

    bool empty() const {
        return data.empty();
    }

    iterator begin() {
        return data.begin();
    }

    const_iterator begin() const {
        return data.begin();
    }

    iterator end() {
        return data.end();
    }

    const_iterator end() const {
        return data.end();
    }

private:
    std::deque<T, allocator_type> data;
};

#endif // QUEUE_H
