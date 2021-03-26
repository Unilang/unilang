#include "single_include/indicators/indicators.hpp"
#include <thread>
#include <chrono>

int main() {
  using namespace indicators;
  indicators::ProgressSpinner spinner{
    option::PostfixText{"Checking credentials"},
    option::ForegroundColor{Color::yellow},
    option::SpinnerStates{std::vector<std::string>{"⠈", "⠐", "⠠", "⢀", "⡀", "⠄", "⠂", "⠁"}},
    option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
  };
 
  // Update spinner state
  auto job = [&spinner]() {
    while (true) {
      if (spinner.is_completed()) {
        spinner.set_option(option::ForegroundColor{Color::green});
        spinner.set_option(option::PrefixText{"✔"});
        spinner.set_option(option::ShowSpinner{false});
        spinner.set_option(option::ShowPercentage{false});
        spinner.set_option(option::PostfixText{"Authenticated!"});
        spinner.mark_as_completed();	
        break;
      } else
        spinner.tick();
      std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
  };
  std::thread thread(job);
  thread.join();  

  return 0;
}