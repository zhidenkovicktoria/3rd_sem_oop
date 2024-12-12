#ifndef CUSTOM_MEMORY_RESOURCE_H
#define CUSTOM_MEMORY_RESOURCE_H

#include <memory_resource>
#include <list>

class CustomMemoryResource : public std::pmr::memory_resource {
public:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* ptr, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;
    ~CustomMemoryResource();

private:
    std::list<void*> allocated_blocks;
    std::list<void*> free_blocks;
};

#endif // CUSTOM_MEMORY_RESOURCE_H
