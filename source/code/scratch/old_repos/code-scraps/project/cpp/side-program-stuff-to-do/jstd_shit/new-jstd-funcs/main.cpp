#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

void Gobble_First_Line_Of_Input();
std::vector<std::vector<int>> From_Std_Input_Get_Each_Line_As_A_Vector_Of_Numbers();
bool Test_For_Duplicate_At_Kth_Index_Distance(std::vector<std::vector<int>> const& numbered_input, int const& kth_index);
bool Element_Passes(std::vector<std::vector<int>> const& numbered_input, size_t x, size_t y, int const& kth_index);
void Print_Answer(bool passes_test);

int main(){

  //The amount of rows is irrelevant if the data ends at the kth data value
  Gobble_First_Line_Of_Input();
  
  //get the rest of the numbers
  auto numbered_input = From_Std_Input_Get_Each_Line_As_A_Vector_Of_Numbers();
  
  //get the kth value
  auto kth_index = numbered_input.back()[0];
  numbered_input.pop_back();
  
  auto passing_test = Test_For_Duplicate_At_Kth_Index_Distance(numbered_input,kth_index);
  
  //print the problem's expected output
  Print_Answer(passing_test);
  
  return EXIT_SUCCESS;
}
void Gobble_First_Line_Of_Input(){
  std::string garbage;
  std::getline(std::cin,garbage);
}

std::vector<std::vector<int>> From_Std_Input_Get_Each_Line_As_A_Vector_Of_Numbers(){
   std::string line;
   std::vector< std::vector<int> > all_integers;
   while ( getline( std::cin, line ) ) {
      std::istringstream is( line );
      all_integers.push_back( 
            std::vector<int>( std::istream_iterator<int>(is),
                              std::istream_iterator<int>() ) );
   }
   
   return all_integers;
}
bool Test_For_Duplicate_At_Kth_Index_Distance(std::vector<std::vector<int>> const& numbered_input, int const& kth_index){

  for (int i = 0; i < numbered_input.size(); ++i){
    for (int j = 0; j < numbered_input[i].size(); ++j){
    
      if (!Element_Passes(numbered_input, i, j, kth_index)){
        return false;
      }
    }
  }
  
  return true;
}

bool Element_Passes(std::vector<std::vector<int>> const& numbered_input, size_t x, size_t y, int const& kth_index){

  //direction adjustments
  y--; if (y < 0){ y = 0;}
  y++; if (y > numbered_input.size()){ y = numbered_input.size();}
  x--; if (y < 0){ y = 0;}
  x++; if (y > numbered_input[0].size()){ y = numbered_input[0].size();}
  
  return true;
}

void Print_Answer(bool passes_test){

  if (passes_test){
      std::cout << "YES\n";
  }else{
     std::cout << "NO\n";
  }
}
