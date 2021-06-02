#include <iostream>
#include <string>
#include <vector>

#include "absl/status/status.h"

absl::Status Division(int dividend, int divisor) {
    if (divisor == 0)
        return absl::InvalidArgumentError("invalid divisor\n");
    else
        return absl::OkStatus();
}

int main() {
    absl::Status status = Division(1, 0);
    status.Update(Division(2, 0));
    if (status.ok()) {
        std::cout << "all pass\n";
    } else if (absl::IsInvalidArgument(status)) {
        std::cout << status.message();
    }
    return 0;
}