#include <string>
#include <memory>
#include "sqlite_orm/sqlite_orm.h"

struct User{
    int id;
    std::string firstName;
    std::string lastName;
    int birthDate;
    std::unique_ptr<std::string> imageUrl;
    int typeId;
};

struct UserType {
    int id;
    std::string name;
};

int main(){

  using namespace sqlite_orm;
  auto storage = make_storage("/home/laptop/Desktop/db.sqlite",
                              make_table("users",
                                         make_column("id", &User::id, autoincrement(), primary_key()),
                                         make_column("first_name", &User::firstName),
                                         make_column("last_name", &User::lastName),
                                         make_column("birth_date", &User::birthDate),
                                         make_column("image_url", &User::imageUrl),
                                         make_column("type_id", &User::typeId)),
                              make_table("user_types",
                                         make_column("id", &UserType::id, autoincrement(), primary_key()),
                                         make_column("name", &UserType::name, default_value("name_placeholder"))));
  //storage.sync_schema();
}