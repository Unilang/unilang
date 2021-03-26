#include <string>
#include <iostream>
#include <SFML/Window/Joystick.hpp>
#include "code/utilities/peripheral/keyboard/F310_gamepad/functions/f310_gamepads_state_getter.hpp"
#include "code/utilities/formats/json/converters/lib.hpp"
#include "code/utilities/formats/json/converters/type_to_json_string.hpp",

int main()
{
    // i bought two Logitech Gamepad F310 controllers
    //this dumps their state in json
    while (true){
        auto controllers = F310_Gamepads_State_Getter::Get();
        std::cout << Type_To_Json_String::As_JSON_String(controllers) << std::endl;
    }

    return 0;
}