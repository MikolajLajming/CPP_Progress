#include "main.h"

using namespace std;

int* apply_all(const int* const first_array, const size_t first_array_size, const int* const second_array, const size_t second_array_size);
void print(const int* const array, const size_t array_size);

int main() 
{
    int array_1[]{1,2,3,4,5};
    int array_2[]{10,20,30};

    constexpr size_t array_1_size{sizeof(array_1)/ sizeof(int)};
    constexpr size_t array_2_size{sizeof(array_2)/ sizeof(int)};

    print(array_1, array_1_size);
    print(array_2, array_2_size);

    int* result{apply_all(array_1, array_1_size, array_2, array_2_size)};
    constexpr size_t result_size{array_1_size * array_2_size};
    print(result, result_size);

    return 0;
} 

int* apply_all(const int* const first_array, const size_t first_array_size, const int* const second_array, const size_t second_array_size){
    int* ptr{nullptr};
    ptr = new int[first_array_size*second_array_size];
    int n{0};
    for(size_t i{0}; i < second_array_size; ++i){
        for(size_t j{0}; j < first_array_size; ++j){
            // ptr[(i*first_array_size)+j] = first_array[j] * second_array[i];
            ptr[n] = first_array[j] * second_array[i];
            ++n;
        }
    }
    return ptr;
}

void print(const int* const array, const size_t array_size){
    cout << "[ ";
    for(size_t i{0}; i < array_size; ++i)
        cout << array[i] << ' ';
    cout << "]\n" << endl;
}