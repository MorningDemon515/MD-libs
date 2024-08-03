Global w$,h$

WriteINIstring("example.ini","HelloWorld","w","world")
WriteINIstring("example.ini","HelloWorld","h","hello")

w = ReadINIstring("example.ini","HelloWorld","w")
h = ReadINIstring("example.ini","HelloWorld","h")

Print h+", "+w