#include <iostream>
#include <memory>
#include "Index.h"

void test1() {
    std::shared_ptr<std::string> str1 = std::make_shared<std::string>("hello");
    std::shared_ptr<std::string> str2 = std::make_shared<std::string>("yakity");
    std::shared_ptr<std::string> str3 = std::make_shared<std::string>("shmakity");
    std::shared_ptr<std::string> str4 = std::make_shared<std::string>("world");
    Index index;
    index.Insert(str1, 3);
    index.Insert(str4, 6);
}

int main() {
    test1();
    return 0;
}
