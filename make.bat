cls

del *.exe

windres TemplateDialog.rc -o TemplateDialog.o

g++ -mwindows -m64 -static -Wall -Wextra Dialog.cpp TemplateDialog.cpp TemplateDialog.o -o Dialog.exe
