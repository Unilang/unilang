# CodeLang-font
a modifed version of ProFont that adds glyphs for the unicode characters of the language

##File Types
.sfd - Font Forge save file(not sure if needed)  
.bdf - Font Forge generated front file(delete this before re-saving)  
.pcf - Original Linux ProFont found online(was modified in FontForge to create the .bdf)  

##How to modify:  
Edit the .bdf in FontForge, and while you're editing it, delete that .bdf, before re-saving it.  
I've had trouble with the program actually rewriting the file-- so just be sure to delete it first.

##Tools used
FontForge

##Installing
On Linux, first delete the file if it already exists:  
`~/.local/share/fonts`  
Then install the .bdf file.  

##Issues when modifying the font
Make sure the font is encoded full (NOT BMP full)
Changes don't take effect right away, and I've seen changing the font like this crash applications. Computer restarts may be needed-- like it screwed up firefox, but that's probably because I was installing/deleting the font over and over again.  I probably never did a proper uninstall of the font.  I just rm'd ~.local/font/..  

##Expansion note:  
The private area ended at:  u10FD50 / U+10fd50  
So I started filling in the glyph name, and unicode value myself.  
Ok, that suddenly went away a different time I encoded into to FULL UNICODE.  
Hopefully we can ignore his expansion note now.
