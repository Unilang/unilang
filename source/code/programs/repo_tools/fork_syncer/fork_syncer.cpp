#include <iostream>
#include <string>
#include "code/utilities/program/wrappers/git/sync_fork/fork_syncer.hpp"
#include "code/utilities/program/wrappers/git/latest_commit_getter.hpp"
#include "code/utilities/web/url/github_url_getter.hpp"
#include "code/utilities/formats/compression/lib.hpp"

//If you are maintaining a fork of a repository,
//this tool will automatically catch that fork up to latest master of the upstream repository.
//this is useful for all of the third party dependencies that are forked to ensure we have control over them.
int main(int const argc, char** const argv){
    
    //update the fork
    std::string dev_name = argv[1];
    std::string dev_proj_name = argv[2];
    std::string fork_name = argv[3];
    Fork_Syncer::Sync(dev_name,dev_proj_name,fork_name);
    
    //provide the new info for updating internally:
    auto commit = Latest_Commit_Getter::Get();
    std::cout << "latest commit: " << commit << std::endl;
    auto url = Github_Url_Getter::Common_Http_Archive_Url(dev_name,dev_proj_name,commit,"tar.gz");
    
    auto sha = Sha256sum_Of_Url_Artifact(url);
    std::cout << "SHA: " << sha<< std::endl;
}