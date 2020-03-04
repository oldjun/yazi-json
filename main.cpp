#include <iostream>
using namespace std;

#include "Json.h"
using namespace yazi::json;

int main()
{
    // the null json value
    Json null;
    std::cout << null.toString() << std::endl;
    
    
    // 3 ways to set a int value
    Json int1 = 1;         // #1 set a int value
    Json int2(2);          // #2 set a int value
    Json int3;
    int3.set(3);            // #3 set a int value
    
    // 3 ways to get a int value
    int i1 = int1;          // #1 get a int value
    int i2 = (int)int2;     // #2 get a int value
    int i3 = int3.asInt();  // #3 get a int value
    
    
    // 3 ways to set a double value
    Json real1 = 1.0;      // #1 set a double value
    Json real2(2.0);       // #2 set a double value
    Json real3;
    real3.set(3.0);         // #3 set a double value
    
    // 3 ways to get a double value
    double d1 = real1;              // #1 get a double value
    double d2 = (double)real2;      // #2 get a double value
    double d3 = real3.asDouble();   // #3 get a double value
    
    
    // 3 ways to set a string value
    Json str1("this is a json string");                    // #1 set a string value
    const string & str = "this is another json string";
    Json str2 = str;                                       // #2 set a string value
    Json str3;
    str3.set("this is the third json string");              // #3 set a string value
    
    // 3 ways to get a string value
    const string & s1 = str1;               // #1 get a string value
    const string & s2 = (string)str2;       // #2 get a string value
    const string & s3 = str3.asString();    // #3 get a string value
    
    
    // 3 ways to set a boolean value
    Json bool1 = true;                     // #1 set a bool value
    Json bool2(false);                     // #2 set a bool value
    Json bool3;
    bool3.set(true);                        // #3 set a bool value
    
    // 3 ways to get a boolean value
    bool b1 = bool1;                        // #1 get a bool value
    bool b2 = (bool)bool2;                  // #2 get a bool value
    bool b3 = bool3.asBool();               // #3 get a bool value
    

    // manipulate an array value
    Json arr1;                             // #1 set an array value
    arr1[0] = "th0 item";
    arr1[1] = "th1 item";
    arr1[2] = "th2 item";
    
    Json arr2;                             // #2 set an array value
    arr2.append("th0 item");
    arr2.append("th1 item");
    arr2.append("th2 item");

    // 3 ways to get an array value
    const string & s4 = arr1[0];
    const string & s5 = (string)arr1[0];
    const string & s6 = arr1[0].asString();

    // 3 ways to loop over each item in array
    int len = arr1.size();
    for (int i = 0; i < len; i++)
    {
        std::cout << "arr1[" << i << "] = " << arr1[i].asString() << std::endl;
    }

    for (Json::iterator it = arr1.begin(); it != arr1.end(); it++)
    {
        std::cout << (*it).asString() << std::endl;
    }

    for (Json::const_iterator it = arr1.begin(); it != arr1.end(); it++)
    {
        std::cout << (*it).asString() << std::endl;
    }

    // manipulate an object value
    Json obj;
    obj["name"] = "junping";
    obj["sex"] = "man";
    obj["age"] = 30;
    obj["country"] = "china";
    obj["work"]["type"] = "c++,php,js";
    obj["work"]["time"] = "10 years";
    obj["phone"] = "189****5599";
    obj["single"] = true;

    if (obj["name"] == "junping")
    {
        std::cout << "the author's name is junping" << std::endl;
    }
    if (obj["age"] == 30)
    {
        std::cout << "the author's age is 30" << std::endl;
    }

    // if obj is object type value
    if (obj.isObject())
    {
        std::cout << "the obj is a json object type value" << std::endl;
    }

    // if the object has key work
    if (obj.has("work"))
    {
        std::cout << "the obj has key work" << std::endl;
    }

    if (obj.has("work"))
    {
        std::cout << "the obj's work is " << (string)obj["work"]["type"] << std::endl;
    }

    // object remove the key
    obj.remove("single");

    // serialize the json value to string;
    std::cout << obj.toString() << std::endl;

    try {

        // parse a string to json null value;
        Json null;
        null.parse("null");

        // parse a string to json bool value;
        Json boolean;
        boolean.parse("true");

        // parse a string to json int value;
        Json integer;
        integer.parse("123");

        // parse a string to json double value;
        Json real;
        real.parse("123.01");

        // parse a string to json string value;
        Json str;
        str.parse("\"this is a string\"");

        // parse a string to json array value;
        const string & str1 = "[0, 1, 2, null, true, false, \"hello json\"]";
        Json arr;
        arr.parse(str1);

        // parse a string to json object value;
        const string & str2 = "{\"name\":\"junping\",\"age\":30,\"sex\":\"man\"}";
        Json obj;
        obj.parse(str2);
        
    } catch (std::exception & e) {
        std::cout << "catch exception: " << e.what() << std::endl;
    }

    return 0;
}
