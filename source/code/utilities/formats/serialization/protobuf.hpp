#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "code/utilities/formats/json/converters/lib.hpp"
#include "code/utilities/formats/json/converters/json_file_io.hpp"
#include <google/protobuf/util/json_util.h>
#include <google/protobuf/util/delimited_message_util.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/util/delimited_message_util.h>
#include <google/protobuf/text_format.h>
#include "code/utilities/streams/filestreams/read_all/lib.hpp"



template <typename T>
T Deserialize_Plain_Text_File(std::string const& path){
    auto str = Read_Entire_File_Into_String(path);
    
    T t;
    google::protobuf::TextFormat::ParseFromString(str,&t);
    return t;
}

template <typename T>
void Serialize(T const& t, std::string const& path){
    std::ofstream ofs(path, std::ios_base::out | std::ios_base::binary);
    bool was_successful = t.SerializeToOstream(&ofs);
    if (!was_successful){
        std::cerr << "failed to serialize" << std::endl;
    }
}

template <typename T>
T Deserialize(std::string const& path){
    T t;
    std::ifstream ifs(path, std::ios_base::binary);
    bool was_successful = t.ParseFromIstream(&ifs);
    //bool was_successful = t.ParsePartialFromIstream(&ifs);
    if (!was_successful){
        std::cerr << "failed to deserialize" << std::endl;
    }
    return t;
}


template <typename T>
std::string Protobuf_Message_To_Json(T const& t){
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = true;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    std::string str;
    MessageToJsonString(t, &str, options);
    return str;
}

template <typename T>
std::string Protobuf_Message_To_Inline_Json(T const& t){
    google::protobuf::util::JsonPrintOptions options;
    options.add_whitespace = false;
    options.always_print_primitive_fields = true;
    options.preserve_proto_field_names = true;
    std::string str;
    MessageToJsonString(t, &str, options);
    return str;
}

template <typename T>
T Deserialize_From_Json_File(std::string const& path){
    auto j_blob = Json_File_Io::Read_Json_From_File(path);
    T x;
    google::protobuf::util::JsonParseOptions options;
    JsonStringToMessage(j_blob, &x, options);
    
    return x;
}

template <typename T>
std::vector<T> Deserialize_Multiple_From_Json_File(std::string const& path){
    auto j_blobs = Json_File_Io::Read_Jsons_From_File(path);
    std::vector<T> results;
    for (auto const& it: j_blobs){
        T x;
        google::protobuf::util::JsonParseOptions options;
        JsonStringToMessage(it, &x, options);
        results.emplace_back(x);
    }
    
    return results;
}

template <typename T>
std::vector<T> Deserialize_Multiple_Protos_From_Bin_File(std::string const& filename){
    int infd = open(filename.c_str(), O_RDONLY);

    google::protobuf::io::FileInputStream fin(infd);
    bool keep = true;
    std::vector<T> out;

    while (keep) {
        T msg;
        keep = google::protobuf::util::ParseDelimitedFromZeroCopyStream(
            &msg, &fin, nullptr);
        if (keep)
            out.push_back(msg);
    }
    fin.Close();
    close(infd);
    return out;
}

template <typename T>
bool Serialize_Multiple_Protos_To_Bin_File(std::vector<T> messages, std::string filename) {
    int outfd = open(filename.c_str(), O_WRONLY | O_CREAT | O_TRUNC);
    google::protobuf::io::FileOutputStream fout(outfd);

    bool success;
    for (auto msg: messages) {
        success = google::protobuf::util::SerializeDelimitedToZeroCopyStream(
            msg, &fout);
        if (! success) {
            std::cout << "Writing Failed" << std::endl;
            break;
        }
    }
    fout.Close();
    close(outfd);
    return success;
}
