#include "CustomMemoryResource.h"
#include <cstdlib>

void* CustomMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    if (!free_blocks.empty()) {
        void* ptr = free_blocks.front();
        free_blocks.pop_front();
        return ptr;
    }
    void* ptr = std::malloc(bytes);
    if (ptr) {
        allocated_blocks.push_back(ptr);
    }
    return ptr;
}

void CustomMemoryResource::do_deallocate(void* ptr, std::size_t bytes, std::size_t alignment) {
    free_blocks.push_back(ptr);
}

bool CustomMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}

CustomMemoryResource::~CustomMemoryResource() {
    for (void* ptr : allocated_blocks) {
        std::free(ptr);
    }
}
