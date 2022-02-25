#include <iostream>
#include <memory>
#include "Index.h"

void test1() {
    std::shared_ptr<std::string> str1 = std::make_shared<std::string>("alpha");
    std::shared_ptr<std::string> str2 = std::make_shared<std::string>("bravo");
    std::shared_ptr<std::string> str3 = std::make_shared<std::string>("charlie");
    std::shared_ptr<std::string> str4 = std::make_shared<std::string>("delta");
    std::shared_ptr<std::string> str5 = std::make_shared<std::string>("echo");
    std::shared_ptr<std::string> str6 = std::make_shared<std::string>("foxtrot");
    std::shared_ptr<std::string> str7 = std::make_shared<std::string>("golf");
    std::shared_ptr<std::string> str8 = std::make_shared<std::string>("hotel");
    std::shared_ptr<std::string> str9 = std::make_shared<std::string>("india");
    std::shared_ptr<std::string> str10 = std::make_shared<std::string>("juliet");
    std::shared_ptr<std::string> str11 = std::make_shared<std::string>("kilo");
    std::shared_ptr<std::string> str12 = std::make_shared<std::string>("lima");
    std::shared_ptr<std::string> str13 = std::make_shared<std::string>("mike");


    Index index;
    index.Insert(str7, 7);
    index.Insert(str3, 3);
    index.Insert(str11, 11);
    index.Insert(str5, 5);
    index.Insert(str8, 8);
    index.Insert(str2, 2);
    index.Insert(str12, 12);
    index.Insert(str4, 4);
    index.Insert(str6, 6);
    //index.Insert(str9, 9);
    //index.Insert(str10, 10);



}

int main() {
    test1();
    return 0;
}
