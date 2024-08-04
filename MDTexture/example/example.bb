
; TextureBlend Example
; --------------------

Graphics3D 640,480
SetBuffer BackBuffer()

camera=CreateCamera()

; Choose a background colour which isn't the same colour as anything else, to avoid confusion
CameraClsColor camera,255,0,0

light=CreateLight()
RotateEntity light,90,0,0

cube=CreateCube()
PositionEntity cube,0,0,5

; Load textures
tex0=LoadTexture( "b3dlogo.jpg" )

t$ = LoadTexture( "b3dlogo.jpg" )

; Texture cube with textures
EntityTexture cube,tex0,0,0

tex0_blend_info$="no texture"

While Not KeyDown( 1 )

; Change texture 0 blending mode
If KeyHit( 11 )=True
tex0_blend=tex0_blend+1
If tex0_blend=4 Then tex0_blend=0
If tex0_blend=0 Then tex0_blend_info$="no texture"
If tex0_blend=1 Then tex0_blend_info$="no blend"
If tex0_blend=2 Then tex0_blend_info$="multiply"
If tex0_blend=3 Then tex0_blend_info$="add"
EndIf



; Set texture blend modes
;TextureBlend tex0,tex0_blend

TextureBumpEnvMat tex0,0,0,-0.012
TextureBumpEnvMat tex0,0,0,-0.012
TextureBumpEnvMat tex0,1,0,0.012
TextureBumpEnvMat tex0,1,0,0.012
TextureBumpEnvScale tex0,0.5
TextureBumpEnvOffset tex0,1.0

TurnEntity cube,0.1,0.1,0.1

RenderWorld

Text 0,0,"Press 0 to change texture 0's blending mode"
Text 0,20,"TextureBlend tex0,"+tex0_blend+" ("+tex0_blend_info$+")"

Flip

Wend

End