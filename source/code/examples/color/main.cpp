#include "src/color/color.hpp"

int main(){
    
    // Initialize with constant.
    color::bgr<std::uint8_t>  b( ::color::constant::aqua_t{} );

    //!< Use x11 green.
    color::yiq<std::uint8_t>  y( ::color::constant::x11::green_t{} );

    // Use intuitive/natural values for initialization.
    // hue goes from 0 to 360, saturation and value from 0 to 100.
    color::hsv<double>        h( { 120.0, 50.0, 60.0 } );

    // Lightens will goes from 0 to 100. a and b from -127 to 127.
    color::lab<float>         l( { 50.0, -10, 90 } );

    // Well known rgb. Values are between 0 and 1.
    color::rgb<float>         l2( { 0.5, 0, 0.9 } );
}