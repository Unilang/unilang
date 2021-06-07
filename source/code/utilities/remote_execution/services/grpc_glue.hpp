#pragma once
#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include "build/bazel/remote/execution/v2/remote_execution.grpc.pb.h"
#include "code/utilities/formats/serialization/protobuf.hpp"
#include "google/bytestream/bytestream.grpc.pb.h"

//This code is essntially GRPC glue for the generated service code.
//I don't want to force an OO design when deciding what these services should do.
//The functions have to be overridden, but I can specify all the implementations when constructing the service
//You can imagine a constructor that takes all lambdas.
//This will allow me to put all the implementations in a single function/scope and further abstract the GRPC-related code
//to a re-usable place here.

template <
typename ExecuteFunImpl,
typename WaitExecutionFunImpl
>
class ExecutionService final : public build::bazel::remote::execution::v2::Execution::Service {

    //functions to implement
    public:
    ExecuteFunImpl ExecuteFun;
    WaitExecutionFunImpl WaitExecutionFun;
    
    //constructor
    ExecutionService(ExecuteFunImpl ExecuteFun,
    WaitExecutionFunImpl WaitExecutionFun):
    ExecuteFun(ExecuteFun),
    WaitExecutionFun(WaitExecutionFun)
    {}
    
    //function forwarding
    grpc::Status Execute(grpc::ServerContext* context, const build::bazel::remote::execution::v2::ExecuteRequest* request, grpc::ServerWriter<google::longrunning::Operation>* writer) override{
        return ExecuteFun(context,request,writer);
    }
    
    grpc::Status WaitExecution(grpc::ServerContext* context, const build::bazel::remote::execution::v2::WaitExecutionRequest* request, grpc::ServerWriter<google::longrunning::Operation>* writer) override{
        return WaitExecutionFun(context,request,writer);
    }
};


template <
typename GetActionResultFunImpl,
typename UpdateActionResultFunImpl
>
class ActionCacheService final : public build::bazel::remote::execution::v2::ActionCache::Service {
  
    //functions to implement
    public:
    GetActionResultFunImpl GetActionResultFun;
    UpdateActionResultFunImpl UpdateActionResultFun;
    
    //constructor
    ActionCacheService(GetActionResultFunImpl GetActionResultFun,
    UpdateActionResultFunImpl UpdateActionResultFun):
    GetActionResultFun(GetActionResultFun),
    UpdateActionResultFun(UpdateActionResultFun)
    {}
    
    //function forwarding
    grpc::Status GetActionResult(grpc::ServerContext* context, const build::bazel::remote::execution::v2::GetActionResultRequest* request, build::bazel::remote::execution::v2::ActionResult* response) override{
        return GetActionResultFun(context,request,response);
    }
    
    grpc::Status UpdateActionResult(grpc::ServerContext* context, const build::bazel::remote::execution::v2::UpdateActionResultRequest* request, build::bazel::remote::execution::v2::ActionResult* response) override{
        return UpdateActionResultFun(context,request,response);
    }
};

template <
typename FindMissingBlobsFunImpl,
typename BatchUpdateBlobsFunImpl,
typename BatchReadBlobsFunImpl,
typename GetTreeFunImpl
>
class ContentAddressableStorageService final : public build::bazel::remote::execution::v2::ContentAddressableStorage::Service {
  
    //functions to implement
    public:
    FindMissingBlobsFunImpl FindMissingBlobsFun;
    BatchUpdateBlobsFunImpl BatchUpdateBlobsFun;
    BatchReadBlobsFunImpl BatchReadBlobsFun;
    GetTreeFunImpl GetTreeFun;
    
    //constructor
    ContentAddressableStorageService(FindMissingBlobsFunImpl FindMissingBlobsFun,
    BatchUpdateBlobsFunImpl BatchUpdateBlobsFun,
    BatchReadBlobsFunImpl BatchReadBlobsFun,
    GetTreeFunImpl GetTreeFun):
    FindMissingBlobsFun(FindMissingBlobsFun),
    BatchUpdateBlobsFun(BatchUpdateBlobsFun),
    BatchReadBlobsFun(BatchReadBlobsFun),
    GetTreeFun(GetTreeFun)
    {}
    
    //function forwarding
    grpc::Status FindMissingBlobs(grpc::ServerContext* context, const build::bazel::remote::execution::v2::FindMissingBlobsRequest* request, build::bazel::remote::execution::v2::FindMissingBlobsResponse* response) override{
        return FindMissingBlobsFun(context,request,response);
    }
    
    grpc::Status BatchUpdateBlobs(grpc::ServerContext* context, const build::bazel::remote::execution::v2::BatchUpdateBlobsRequest* request, build::bazel::remote::execution::v2::BatchUpdateBlobsResponse* response) override{
        return BatchUpdateBlobsFun(context,request,response);
    }
    
    grpc::Status BatchReadBlobs(grpc::ServerContext* context, const build::bazel::remote::execution::v2::BatchReadBlobsRequest* request, build::bazel::remote::execution::v2::BatchReadBlobsResponse* response) override{
        return BatchReadBlobsFun(context,request,response);
    }

    grpc::Status GetTree(grpc::ServerContext* context, const build::bazel::remote::execution::v2::GetTreeRequest* request, grpc::ServerWriter< build::bazel::remote::execution::v2::GetTreeResponse>* writer) override{
        return GetTreeFun(context,request,writer);
    }
};

template <typename GetCapabilitiesFunImpl>
class CapabilitiesService final : public build::bazel::remote::execution::v2::Capabilities::Service {
  
    //functions to implement
    public:
    GetCapabilitiesFunImpl GetCapabilitiesFun;
    
    //constructor
    CapabilitiesService(GetCapabilitiesFunImpl GetCapabilitiesFun):
    GetCapabilitiesFun(GetCapabilitiesFun)
    {}
    
    //function forwarding
    grpc::Status GetCapabilities(grpc::ServerContext* context, const build::bazel::remote::execution::v2::GetCapabilitiesRequest* request, build::bazel::remote::execution::v2::ServerCapabilities* response) override {
        return GetCapabilitiesFun(context,request,response);
    }
};

template <
    typename ReadFunImpl,
    typename WriteFunImpl,
    typename QueryWriteStatusFunImpl
>
class BytestreamService final : public google::bytestream::ByteStream::Service {

    //functions to implement
    public:
    ReadFunImpl ReadFun;
    WriteFunImpl WriteFun;
    QueryWriteStatusFunImpl QueryWriteStatusFun;
    
    //constructor
    BytestreamService(ReadFunImpl ReadFun,
    WriteFunImpl WriteFun,
    QueryWriteStatusFunImpl QueryWriteStatusFun):
    ReadFun(ReadFun),
    WriteFun(WriteFun),
    QueryWriteStatusFun(QueryWriteStatusFun)
    {}
    
    //function forwarding
    grpc::Status Read(grpc::ServerContext* context, const google::bytestream::ReadRequest* request, grpc::ServerWriter< google::bytestream::ReadResponse>* writer) override {
        return ReadFun(context,request,writer);
    }
    grpc::Status Write(grpc::ServerContext* context, grpc::ServerReader< google::bytestream::WriteRequest>* reader, google::bytestream::WriteResponse* response) override {
        return WriteFun(context,reader,response);
    }
    grpc::Status QueryWriteStatus(grpc::ServerContext* context, const google::bytestream::QueryWriteStatusRequest* request, google::bytestream::QueryWriteStatusResponse* response) override {
        return QueryWriteStatusFun(context,request,response);
    }
};
