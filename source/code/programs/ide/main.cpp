#include "code/programs/ide/unilang_ide.hpp"
#include "code/programs/ide/program_options/program_options.hpp"
#include "code/utilities/program/common_actions/main/catching_main.hpp"

//other programming editors for inspiration:
// fructure (racket): https://github.com/disconcision/fructure
// lambdu: https://www.lamdu.org/
//https://en.wikipedia.org/wiki/DRAKON
//https://www.jetbrains.com/mps/

//similarity to other projects:
// Haxe
// OneLang
// Felleisen's A Programmable Programming Language
//http://andescotia.com/products/marten/
//https://divan.dev/posts/visual_programming_go/

//community:
//https://www.reddit.com/r/nosyntax/

//https://github.com/enso-org/enso
//(previously luna)

//unity & bolt visual scripting



//ideas:
//optional thread pool on drawing grid
//label button
//use it set growth bool
//maybe reorganize all draw things (functions with the objects / mouse under label)

//menu selection:
//change label
//color
//muli-level

//drag functionality to reformat tree
int main(int argc, char** argv)
{
    return Catching_Main::Run([&](){
        Program_Options po(argc,argv);
        return Unilang_Ide::Run(po);
    });
}
