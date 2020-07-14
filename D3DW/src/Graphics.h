#pragma once
#include "AdapterReader.h"

class Graphics
{
public:
	bool Initialize(HWND hwnd, int width, int height);
	Microsoft::WRL::ComPtr<ID3D11Device> GetDevice();
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> GetContext();
	Microsoft::WRL::ComPtr<IDXGISwapChain> GetSwapChain();
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> GetTarget();
private:
	Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> pContext;
	Microsoft::WRL::ComPtr<IDXGISwapChain> pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> pTarget;
	bool InitializeDirectX(HWND hwnd, int width, int height);
};