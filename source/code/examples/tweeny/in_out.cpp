#include "tweeny.h"
#include <iostream>

int main(){

    auto tween = tweeny::from(0).to(100).during(1000).via(tweeny::easing::circularInOut);
    tween.onStep([](int v) { printf("%d\n", v); return false;});
    for (int i = 0; i < 1000; i++) tween.step(1);
}