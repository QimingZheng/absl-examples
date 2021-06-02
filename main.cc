#include <iostream>
#include <string>
#include <vector>

#include "absl/strings/str_join.h"
#include "absl/container/btree_map.h"
#include "absl/container/btree_set.h"

int main() {
    absl::btree_set<std::string> str_set;
    std::string str = "a";
    str_set.insert(str);
    str_set.find(str);
    return 0;
}