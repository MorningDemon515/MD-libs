;By MorningDemon(https://github.com/MorningDemon515)
;MDGAME
;Blitz3D libs
;This lib can handle the conversion between ANSI encoding and UTF8 encoding

Graphics 800,600,32,2
;print the text, centered horizontally at x=400, y=0
Text 400,0,GfxDriverName(1),1,0
Text 600,100,ANSIToUTF8(GfxDriverName(1))
; wait for ESC key before ending
While Not KeyHit(1)
Wend