#include <iostream>
#include <iomanip>
#include "code/utilities/data_structures/graph/unique_str_vertex_graph/lib.hpp"
#include "code/utilities/program/wrappers/graphviz/graphviz_image_maker.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"


int main()
{
    Unique_Str_Vertex_Graph g;
    g.Connect("A","B");
    g.Connect("B","C");
    g.Connect("B","D");
    g.Connect("D","E");
    g.Connect("C","E");
    g.Connect("E","F");
    std::cout << g.As_Graphviz() << std::endl;
    Graphviz_Image_Maker::Make(g.As_Graphviz(),Full_Path_To_Desktop(),"graph_example");
}