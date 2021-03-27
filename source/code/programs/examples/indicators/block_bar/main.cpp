#include "single_include/indicators/indicators.hpp"
#include <thread>
#include <chrono>

int main() {

  using namespace indicators;

  // Hide cursor
  show_console_cursor(false);

  BlockProgressBar bar{
    option::BarWidth{80},
    option::Start{"["},
    option::End{"]"},
    option::ForegroundColor{Color::white}  ,
    option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
  };
  
  // Update bar state
  auto progress = 0.0f;
  while (true) {
    bar.set_progress(progress);
    progress += 0.25f;
    if (bar.is_completed())
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }

  // Show cursor
  show_console_cursor(true);

  return 0;
}