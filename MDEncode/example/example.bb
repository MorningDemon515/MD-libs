
Graphics 800,600,32,2
;print the text, centered horizontally at x=400, y=0
SetFont LoadFont("C:\Windows\Fonts\simfang.ttf",16)
Text 600,100,GfxDriverName(1),1,0
Text 600,100,ANSIToUTF8(GfxDriverName(1))
; wait for ESC key before ending
While Not KeyHit(1)
Wend