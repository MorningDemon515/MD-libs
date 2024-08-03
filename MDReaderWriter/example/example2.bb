Global H$,W$

WriteJSONstring("example.json","H","Hello")
WriteJSONstring("example.json","W","World")

H = ReadJSONstring("example.json","H")
W = ReadJSONstring("example.json","W")

Print H+", "+W