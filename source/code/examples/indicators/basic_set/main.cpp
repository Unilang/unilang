#include "single_include/indicators/indicators.hpp"
#include <thread>
#include <chrono>

int main() {
  using namespace indicators;

  // Hide cursor
  show_console_cursor(false);

  ProgressBar bar{
    option::BarWidth{50},
    option::Start{"["},
    option::Fill{"■"},
    option::Lead{"■"},
    option::Remainder{"-"},
    option::End{" ]"},
    option::PostfixText{"Loading dependency 1/4"},
    option::ForegroundColor{Color::cyan},
    option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
  };

  // Update bar state
  bar.set_progress(10); // 10% done

  // do some work
  std::this_thread::sleep_for(std::chrono::milliseconds(800));

  bar.set_option(option::PostfixText{"Loading dependency 2/4"});  

  bar.set_progress(30); // 30% done

  // do some more work
  std::this_thread::sleep_for(std::chrono::milliseconds(700));

  bar.set_option(option::PostfixText{"Loading dependency 3/4"});  

  bar.set_progress(65); // 65% done

  // do final bit of work
  std::this_thread::sleep_for(std::chrono::milliseconds(900));

  bar.set_option(option::PostfixText{"Loaded dependencies!"});

  bar.set_progress(100); // all done

  // Show cursor
  show_console_cursor(true);

  return 0;
}