#include <iostream>
#include <json/json.h>
#include <fstream>
#include <string>
#include "json.hpp"
using namespace std;
 
void readFileJson()
{
        Json::Reader reader;
        Json::Value root;
 
        //从文件中读取，保证当前文件有demo.json文件  
        ifstream in("demo.json", ios::binary);
 
        if (!in.is_open())
        {
                cout << "Error opening file\n";
                return;
        }
 
        if (reader.parse(in, root))
        {
                //读取根节点信息  
                string name = root["name"].asString();
                int age = root["age"].asInt();
                string sex = root["sex"].asString();
 
                cout << "My name is " << name << endl;
                cout << "I'm " << age << " years old" << endl;
                cout << "I'm a " << sex << endl;
				
				//读取子节点信息  
                string friend_name = root["friends"]["friend_name"].asString();
                int friend_age = root["friends"]["friend_age"].asInt();
                string friend_sex = root["friends"]["friend_sex"].asString();
 
                cout << "My friend's name is " << friend_name << endl;
                cout << "My friend's sex is "<<friend_sex << endl;
                cout << "My friend is " << friend_age << " years old" << endl;
 
                //读取数组信息  
                cout << "Here's my hobby:" << endl;
                for (unsigned int i = 0; i < root["hobby"].size(); i++)
                {
                        string ach = root["hobby"][i].asString();
                        cout << ach << '\t';
                }
                cout << endl;
 
                cout << "Reading Complete!" << endl;
        }
        else
        {
                cout << "parse error\n" << endl;
        }
 
        in.close();
}
 
int main(void)
{
        readFileJson();
        return 0;
}