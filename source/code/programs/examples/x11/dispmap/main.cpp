  /****************************************************
   *
   *                dispmap.c
   *
   *  This program allows the user to view all the
   *  bitmaps in the /usr/include/X11/bitmaps directory
   *  A list widget is used to display the names of
   *  all the bitmaps in this directory.  When the
   *  user selects one of these bitmaps it is read in
   *  and displayed in a label widget.
   *
   ****************************************************/

  #include  <X11/StringDefs.h> 
  #include  <X11/Intrinsic.h> 
  #include  <X11/Xaw/Box.h> 
  #include  <X11/Xaw/Label.h> 
  #include  <X11/Xaw/List.h> 
  #include  <dirent.h> 

  /*
   *  base is the name of the directory containing
   *  the bitmaps
   */

  char base[] = "/usr/include/X11/bitmaps";

  /*
   *  show_bitmap is the callback procedure for
   *  the list widget.  The procedure is called
   *  when the user selects a filename from
   *  the widget.  This procedure constructs
   *  the complete pathname for the bitmap,
   *  reads it, and then makes it the icon
   *  for the label widget.
   */

  void show_bitmap(w,label,file)
  Widget w;
  Widget label;
  XawListReturnStruct file; {
       char filename[100];
       unsigned int width, height;
       Pixmap    bitmap;
       int x_hot, y_hot;
       Arg wargs[5];
       int n;

       strcpy(filename,base);
       strcat(filename,"/");
       strcat(filename,file.string);

       XReadBitmapFile(XtDisplay(w),
        RootWindowOfScreen(XtScreen(w)),
        filename, &width, &height, &bitmap,
        &x_hot, &y_hot);

       n = 0;
       XtSetArg(wargs[n], XtNbitmap, bitmap); n++;

       XtSetValues(label, wargs, n);

  }


  /*
   *  The make_list procedure builds the list widget
   *  that is used in this program.  It makes two
   *  passes through the directory.  The firs pass
   *  counts the number of files in the directory,
   *  the is used to dynamically allocate the list
   *  of file names.  The second pass actually
   *  constructs the list of file names.  After
   *  that the list is added to the list widget.
   */

  Widget make_list(box,label)
  Widget box;
  Widget label; {
       Widget list;
       char **labels;
       int n;
       int len;
       DIR *dir;
       struct dirent *entry;
       int i;

       list = XtCreateManagedWidget("bitmaps",listWidgetClass,
         box, NULL, 0);

       dir = opendir(base);

       n = 0;
       while(readdir(dir) != NULL) n++;

       rewinddir(dir);

       labels = (char **) malloc((n+1) * (sizeof *labels));

       i = 0;
       while((entry = readdir(dir)) != NULL) {
        /*
         *  don't include . and .. in the list
         */
        if(strcmp(entry->d_name,".") == 0)
         continue;
        if(strcmp(entry->d_name,"..") == 0)
         continue;

        len = entry->d_namlen + 1;
        labels[i] = (char *) malloc(len+1);
        strcpy(labels[i],entry->d_name);
        i++;
       }
       labels[i] = 0;

       closedir(dir);

       XawListChange(list,labels,0, 0, 1);

       XtAddCallback(list, XtNcallback, show_bitmap, label);

       return(list);

  }

  main(argc,argv)
  int argc;
  char **argv; {
       Widget toplevel;
       Widget box;
       Widget list;
       Widget label;
       Widget quit;

       toplevel = XtInitialize(argv[0],"display", NULL, 0,
         &argc,argv);

       box = XtCreateManagedWidget("box",boxWidgetClass,
         toplevel, NULL, 0);

       label = XtCreateManagedWidget("icon",labelWidgetClass,
         box, NULL, 0);

       quit = quit_button(box);

       list = make_list(box,label);

       XtRealizeWidget(toplevel);

       XtMainLoop();

  }