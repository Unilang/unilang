#include <iostream>
#include "code/utilities/github/user_forked_repos_getter.hpp"
#include "code/utilities/github/repo_deleter.hpp"


int main(){
    
    std::string user = "luxe";
    
    auto repos = User_Forked_Repos_Getter::Get(user);
    
    for (auto it: repos){
        std::cout << Repo_Deleter::Delete(user,it["name"]).dump(1) << std::endl;;
    }
}