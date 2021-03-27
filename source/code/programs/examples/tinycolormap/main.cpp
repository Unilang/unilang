#include <iostream>
#include "include/tinycolormap.hpp"

int main()
{
  // Define a target value. This value should be in [0, 1]; otherwise, it will be cropped to 0 or 1.
  const double value = 0.5;

  // Get the mapped color. Here, Viridis is specified as the colormap.
  const tinycolormap::Color color = tinycolormap::GetColor(value, tinycolormap::ColormapType::Viridis);

  // Print the RGB values. Each value is in [0, 1].
  std::cout << "r = " << color.r() << ", g = " << color.g() << ", b = " << color.b() << std::endl;

  return 0;
}