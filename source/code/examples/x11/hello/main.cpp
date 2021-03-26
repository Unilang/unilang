/*
 *  This is a sample X11 program using Xt and the Athena widget set that
 *  simply puts up a main window with the text "hello" in it.
 */

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>
#include <X11/Xaw/Label.h>

int main(int argc, char* argv[])
{
    XtAppContext app_context;
    Widget toplevel, hello;

    toplevel = XtVaAppInitialize(
        &app_context,
        "XHello",
        NULL, 0,
        &argc, argv,
        NULL,
        NULL);

    hello = XtVaCreateManagedWidget("hello", labelWidgetClass, toplevel, NULL);

    XtRealizeWidget(toplevel);
    XtAppMainLoop(app_context);
}