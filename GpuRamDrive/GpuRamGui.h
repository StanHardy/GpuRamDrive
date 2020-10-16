#pragma once
#include "GpuRamTrayIcon.h"


class GpuRamGui
{
private:
	GPURamDrive m_RamDrive;
	HWND m_hWnd;
	HINSTANCE m_Instance;
	GpuRamTrayIcon m_Tray;

	HICON m_Icon;
	HWND m_CtlGpuList;
	HWND m_CtlMountBtn;
	HWND m_CtlMemSize;
	HWND m_CtlDriveLetter;
	HWND m_CtlDriveType;
	HWND m_CtlDriveRemovable;
	HWND m_CtlLabel;
	HWND m_CtlFormatParam;
	HWND m_CtlTempFolder;
	HWND m_CtlStartOnWindows;
	bool m_UpdateState;

	LPCWSTR wszTaskJobName;

public:
	GpuRamGui();
	~GpuRamGui();

	bool Create(HINSTANCE hInst, const std::wstring& title, int nCmdShow);
	int Loop();
	void Mount(const std::wstring& device, size_t size, const std::wstring& driveLetter, const std::wstring& formatParam, const std::wstring& labelParam, const std::wstring& driveType, bool removable, bool tempFolderParam);
	void RestoreWindow();

private:
	void OnCreate();
	void OnDestroy();
	void OnEndSession();
	void OnResize(WORD width, WORD height, bool minimized);
	void OnMountClicked();
	void OnTrayInteraction(LPARAM lParam);
	void UpdateState();

	ATOM MyRegisterClass();
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

