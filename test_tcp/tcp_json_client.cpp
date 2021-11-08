#include <iostream>
#include <json/json.h>
#include <fstream>
#include <string>
#include <typeinfo>
#include "tcp_session.h"
#include "json.hpp"

Json::Value json_init(void);
int main(void)
{
    auto trays = nlohmann::json::array();
    trays.push_back(nlohmann::json({
                {"id", 1},
                {"type", 2},
                {"state", 3},
                {"binId", "789"}
            }));
    nlohmann::json report_info = nlohmann::json{
        {"trays", trays}
    };
    trays[0]["num"] = 199;
    std::string msg_data = report_info.dump();

    std::cout << msg_data << std::endl;

    //Json::Value send_date = json_init();
    char server_ip[] = "127.0.0.1";
    tcp_client_init(msg_data, server_ip);
    /* parse json object */
    nlohmann::json msg_json;
    try {
        msg_json = nlohmann::json::parse(msg_data);
    } catch (std::exception& e) {
    }

    auto tray_read = msg_json["trays"];
    auto binId = tray_read[0]["binId"];

    std::cout << "binId: " << binId << std::endl;
    //std::cout << "type: " << (int)(typeid(tray_read) << std::endl;
    return 0;
}

Json::Value json_init(void)
{
    Json::Value root; 
    Json::Value arrayObj;
    Json::Value item; 

    root["key"] = "value1"; 
    for (int i=0; i<3; i++)
    { 
        item["arraykey"] = i; 
        arrayObj.append(item);  //添加新的数组成员
    } 
    root["array"] = arrayObj; 
    std::string out = root.toStyledString();  //将Json对象序列化为字符串
    std::cout << out << std::endl;

    return root;
}