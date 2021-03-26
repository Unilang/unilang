#include "csv/reader.hpp"
#include "code/utilities/formats/csv/csv_extractor.hpp"
#include "code/utilities/program/call/lib.hpp"
#include <iostream>

std::string Get_Hostname_Of_Ip_With_Host_Program(std::string const& ip){
    auto x = execute("host " + ip);
    return x;
}

std::string Get_Hostname_Of_Ip_With_Dig_Program(std::string const& ip){
    auto x = execute("dig +short -x " + ip);
    return x;
}

int main(){
    
    
    auto ips = Csv_Extractor::Get_Column_Values_Of_Double_Quoted("/home/thickey/Desktop/wireshark.csv", "Address");
    for (auto const& it: ips){
        auto host = Get_Hostname_Of_Ip_With_Dig_Program(it);
        std::cout << it << " " << host << std::endl;
    }
    // exit(0);
    
    // csv::Reader foo;
    // foo.read("/home/thickey/Desktop/wireshark.csv");

    // //foo.configure_dialect("my fancy dialect")
    //   //.delimiter(",")
    //   //.quote_character('"')
    //   //.double_quote(true)
    //   //.skip_initial_space(false)
    //   //.trim_characters(' ', '\t')
    //   //.ignore_columns("foo", "bar")
    //   //.header(true)
    //   //.skip_empty_rows(false);
    
    // auto rows = foo.rows();
    
    // for (auto & row: rows){
    //     auto data = row["\"Address\""];
    //     std::cout << data << std::endl.hpp;
    // }
}