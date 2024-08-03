.lib "MDReaderWriter.dll"

ReadINIstring$(file$,section$, key$):"_ReadINIstring@12"
ReadINIint%(file$,section$, key$):"_ReadINIint@12"
ReadINIfloat#(file$,section$, key$):"_ReadINIfloat@12"

WriteINIstring(file$,section$, key$, value$):"_WriteINIstring@16"
WriteINIint(file$,section$,key$, value%):"_WriteINIint@16"
WriteINIfloat(file$,section$, key$, value#):"_WriteINIfloat@16"

ReadJSONstring$(file$,key$):"_ReadJSONstring@8"
ReadJSONint%(file$,key$):"_ReadJSONint@8"
ReadJSONfloat#(file$,key$):"_ReadJSONfloat@8"

WriteJSONstring(file$,key$,value$):"_WriteJSONstring@12"
WriteJSONint(file$,key$,value%):"_WriteJSONint@12"
WriteJSONfloat(file$,key$,value#):"_WriteJSONfloat@12"