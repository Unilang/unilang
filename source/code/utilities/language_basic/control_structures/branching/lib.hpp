#pragma once

template <typename Boolean_Expression, typename Function>
bool If(Boolean_Expression b, Function f){
    if (b){f();return true;}
    return false;
}
template <typename Boolean_Expression, typename Function>
bool If_Not(Boolean_Expression b, Function f){
    if (!b){f();return true;}
    return false;
}

template <typename  Boolean_Expression, typename Function1, typename Function2>
bool If_Else(Boolean_Expression b, Function1 f1, Function2 f2){
    if (b){f1();return true;}
    f2(); return false;
}

template <typename Boolean_Expression, typename Function>
void Configurable_If(bool enable, Boolean_Expression b, Function f){
    if (enable){
        if (b){f();}
    }
}
