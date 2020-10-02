#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include "build/bazel/remote/execution/v2/remote_execution.grpc.pb.h"

// Logic and data behind the server's behavior.
class ExecutionService final : public build::bazel::remote::execution::v2::Execution::Service {

    grpc::Status Execute(grpc::ServerContext* context, const build::bazel::remote::execution::v2::ExecuteRequest* request, grpc::ServerWriter<google::longrunning::Operation>* writer){
        return grpc::Status::OK;
    }
    
    grpc::Status WaitExecution(grpc::ServerContext* context, const build::bazel::remote::execution::v2::WaitExecutionRequest* request, grpc::ServerWriter<google::longrunning::Operation>* writer){
        return grpc::Status::OK;
    }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  ExecutionService service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  grpc::ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}