
#include "main.h"

#pragma comment(lib, "ddraw.lib")

IDirect3DDevice7* device = nullptr;//D3DDevice
IDirect3D7* d3d = nullptr;
D3DDEVICEDESC7 dir3dDevDesc;

LPDIRECTDRAW7 g_pDD = nullptr;//ddraw
LPDIRECTDRAWSURFACE7 g_pPrimarySurface = nullptr;//Front Surface
LPDIRECTDRAWSURFACE7 g_pBackBuffer = nullptr;//Back Surface

HWND hwnd;

int d3d_tss[8][32] = { 0 };

DWORD bumpEnvMat[2][2] = { 0 };
DWORD bumpEnvScale = 0;
DWORD bumpEnvOffset = 0;

void InitDirectDraw()
{
    if (g_pDD == nullptr) {
        //Get Window HWND
        hwnd = GetActiveWindow();
        
        //Create Draw
        if (FAILED(DirectDrawCreateEx(NULL, (void**)&g_pDD, IID_IDirectDraw7, NULL))) {
            // Handle error
            return;
        }

        if (FAILED(g_pDD->SetCooperativeLevel(hwnd, DDSCL_NORMAL))) {
            // Handle error
            return;
        }

        DDSURFACEDESC2 ddsd = { 0 };
        ddsd.dwSize = sizeof(ddsd);
        ddsd.dwFlags = DDSD_CAPS | DDSD_BACKBUFFERCOUNT;
        ddsd.ddsCaps.dwCaps = DDSCAPS_PRIMARYSURFACE | DDSCAPS_FLIP;
        ddsd.dwBackBufferCount = 1;

        if (FAILED(g_pDD->CreateSurface(&ddsd, &g_pPrimarySurface, NULL))) {
            // Handle error
            return;
        }

        ddsd.ddsCaps.dwCaps = DDSCAPS_BACKBUFFER;

        if (FAILED(g_pPrimarySurface->GetAttachedSurface(&ddsd.ddsCaps, &g_pBackBuffer))) {
            // Handle error
            return;
        }
    }
}

HRESULT LoadImageToSurface(LPDIRECTDRAW7 pDD, LPDIRECTDRAWSURFACE7* ppSurface, const char* filePath) {
    HBITMAP hBitmap = (HBITMAP)LoadImage(NULL, filePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    if (hBitmap == NULL) return E_FAIL;

    HDC hdcBitmap = CreateCompatibleDC(NULL);
    SelectObject(hdcBitmap, hBitmap);

    BITMAP bitmap;
    GetObject(hBitmap, sizeof(BITMAP), &bitmap);

    DDSURFACEDESC2 ddsd = { 0 };
    ddsd.dwSize = sizeof(ddsd);
    ddsd.dwFlags = DDSD_WIDTH | DDSD_HEIGHT | DDSD_PIXELFORMAT;
    ddsd.dwWidth = bitmap.bmWidth;
    ddsd.dwHeight = bitmap.bmHeight;
    ddsd.ddpfPixelFormat.dwSize = sizeof(DDPIXELFORMAT);
    ddsd.ddpfPixelFormat.dwFlags = DDPF_RGB;
    ddsd.ddpfPixelFormat.dwRGBBitCount = 24;
    ddsd.ddpfPixelFormat.dwRBitMask = 0x00FF0000;
    ddsd.ddpfPixelFormat.dwGBitMask = 0x0000FF00;
    ddsd.ddpfPixelFormat.dwBBitMask = 0x000000FF;

    HRESULT hr = pDD->CreateSurface(&ddsd, ppSurface, NULL);
    if (FAILED(hr)) {
        DeleteDC(hdcBitmap);
        DeleteObject(hBitmap);
        return hr;
    }

    HDC hdcSurface;
    hr = (*ppSurface)->GetDC(&hdcSurface);
    if (FAILED(hr)) {
        (*ppSurface)->Release();
        DeleteDC(hdcBitmap);
        DeleteObject(hBitmap);
        return hr;
    }

    BitBlt(hdcSurface, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hdcBitmap, 0, 0, SRCCOPY);
    (*ppSurface)->ReleaseDC(hdcSurface);

    DeleteDC(hdcBitmap);
    DeleteObject(hBitmap);

    return S_OK;
}

void setTSS(int n, int s, int t)
{
    if (d3d_tss[n][s] == t) return;
    device->SetTextureStageState(n, (D3DTEXTURESTAGESTATETYPE)s, t);
    d3d_tss[n][s] = t;
}

void D3DInit()
{
    if (device == nullptr && g_pPrimarySurface != nullptr) {
        if (FAILED(d3d->CreateDevice(dir3dDevDesc.deviceGUID, g_pPrimarySurface, &device))) {//Create D3DE
            // Handle error
            return;
        }
        device->SetTexture(0, g_pPrimarySurface);
        setTSS(0, D3DTSS_COLOROP, D3DTOP_BUMPENVMAP);
    }
}

void setBumpEnvMat(const char* file, int x, int y, float envmat)
{
    InitDirectDraw();
    if (FAILED(LoadImageToSurface(g_pDD, &g_pPrimarySurface, file))) {
        // Handle error
        return;
    }
    D3DInit();

    bumpEnvMat[x][y] = *((DWORD*)&envmat);
    
    setTSS(0, D3DTSS_BUMPENVMAT00, bumpEnvMat[0][0]);
    setTSS(0, D3DTSS_BUMPENVMAT01, bumpEnvMat[0][1]);
    setTSS(0, D3DTSS_BUMPENVMAT10, bumpEnvMat[1][0]);
    setTSS(0, D3DTSS_BUMPENVMAT11, bumpEnvMat[1][1]);
}

void setBumpEnvScale(const char* file, float envscale)
{
    InitDirectDraw();
    if (FAILED(LoadImageToSurface(g_pDD, &g_pPrimarySurface, file))) {
        // Handle error
        return;
    }
    D3DInit();

    bumpEnvScale = *((DWORD*)&envscale);

    setTSS(0, D3DTSS_BUMPENVLSCALE, bumpEnvScale);
}

void setBumpEnvOffset(const char* file, float envoffset)
{
    InitDirectDraw();
    if (FAILED(LoadImageToSurface(g_pDD, &g_pPrimarySurface, file))) {
        // Handle error
        return;
    }
    D3DInit();

    bumpEnvOffset = *((DWORD*)&envoffset);

    setTSS(0, D3DTSS_BUMPENVLOFFSET, bumpEnvOffset);
}

BLITZ3D(void) TextureBumpEnvMat(const char* file,int x,int y,float envmat)
{
    setBumpEnvMat(file,x,y,envmat);
}

BLITZ3D(void) TextureBumpEnvScale(const char* file,float envscale)
{
    setBumpEnvScale(file,envscale);
}

BLITZ3D(void) TextureBumpEnvOffset(const char* file,float envoffset)
{
    setBumpEnvOffset(file,envoffset);
}






