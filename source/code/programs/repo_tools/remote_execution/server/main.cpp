#include <iostream>
#include <memory>
#include <string>

#include "code/programs/repo_tools/remote_execution/server/settings/server_settings.hpp"
#include "code/programs/repo_tools/remote_execution/server/server.hpp"


int main(int argc, char** argv) {
  
  Server_Settings x;
  
  //grpc settings
  x.enable_default_health_check_service = true;
  
  //make sure clients do:
  //grpc://localhost:8980
  //or they might see errors like:
  //ERROR: io.netty.handler.ssl.NotSslRecordException: not an SSL/TLS record
  x.address = "localhost:8980";
  
  //x.log_pattern = "[%c] [%s:%!:%#] %v";
  x.log_pattern = "[%c] [%s:%!:%#]";
  
  Server::BuildAndRun(x);
}
