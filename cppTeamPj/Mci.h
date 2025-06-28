#pragma once
#include<Windows.h>
#include<string>
// ����
bool OpenMciDevice(LPCWSTR _deviceType, LPCWSTR _name, UINT& _deviceid);

// �ݱ�
void CloseMciDevice(UINT& _deviceid);

// ���
void PlayMciDevice(UINT _deviceid, bool repeat = false);

enum class SOUNDID
{
	TitleBGM, GameBGM, Dead, ShieldHit, ShieldDamage,PlayerHit, PlayerDamage, END
};

struct SoundEntry
{
	//LPCWSTR path;     // ���� ���
	std::wstring path; // ���� ���
	int     volume;  // ���� (0~1000)  
	UINT    deviceId; // MCI ��ġ ID (�ʱⰪ 0)
};
// �ʱ�ȭ
bool InitAllSounds();
// ���
void PlaySoundID(SOUNDID _id, bool _repeat = false);
// ����
void StopSoundID(SOUNDID _id);
// ������ 
void ReleaseAllSounds();
