#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_join.h"
#include "absl/container/btree_map.h"
#include "absl/container/btree_set.h"
#include "absl/meta/type_traits.h"

template <typename T>
T byte_swap(T value) {
    unsigned char *bytes = reinterpret_cast<unsigned char *>(&value);
    for (size_t i = 0; i < sizeof(T); i += 2) {
        unsigned char v = bytes[i];
        bytes[i] = bytes[i + 1];
        bytes[i + 1] = v;
    }
    return value;
}

int main() {
    int x = 0xff11ff11;
    std::cout << byte_swap(x) << std::endl;
    return 0;
}