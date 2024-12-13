#include <iostream>
#include "CustomMemoryResource.h"
#include "Queue.h"

struct ComplexType {
    int a;
    double b;
};

int main() {
    // Создаем пользовательский ресурс памяти
    CustomMemoryResource custom_memory_resource;

    // Создаем аллокаторы для int и ComplexType
    std::pmr::polymorphic_allocator<int> int_allocator(&custom_memory_resource);
    std::pmr::polymorphic_allocator<ComplexType> complex_allocator(&custom_memory_resource);

    // Создаем очереди с использованием пользовательского ресурса памяти
    Queue<int> int_queue(int_allocator);
    Queue<ComplexType> complex_queue(complex_allocator);

    // Добавляем элементы в очередь int_queue
    int_queue.push(1);
    int_queue.push(2);
    int_queue.push(3);

    // Выводим элементы из очереди int_queue
    std::cout << "Elements in int_queue:" << std::endl;
    while (!int_queue.empty()) {
        std::cout << int_queue.front() << std::endl;
        int_queue.pop();
    }

    // Создаем элементы ComplexType
    ComplexType ct1{1, 2.0};
    ComplexType ct2{3, 4.0};
    ComplexType ct3{5, 6.0};

    // Добавляем элементы в очередь complex_queue
    complex_queue.push(ct1);
    complex_queue.push(ct2);
    complex_queue.push(ct3);

    // Выводим элементы из очереди complex_queue
    std::cout << "Elements in complex_queue:" << std::endl;
    while (!complex_queue.empty()) {
        std::cout << complex_queue.front().a << " " << complex_queue.front().b << std::endl;
        complex_queue.pop();
    }

    return 0;
}
