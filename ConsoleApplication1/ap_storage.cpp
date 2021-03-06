#include "ap_storage.h"
#include "string.h"

#include "Models/profiles.h"
#include "storage_map.h"


uint8_t RamStorage::buf[8182] = {};

static const Profile_t prof[15] =
{
	{{'p','r','o','f','i','l','e','_','1'}, {{31, 4},{120, 20},{170, 35},{230, 46},{260, 51},{180, 58}, {110, 66},{41, 79},{31, 82}}},
	{{'p','r','o','f','i','l','e','_','2'}, {{32, 4},{120, 7},{170, 13},{240, 16},{261, 17},{180, 23}, {110, 26},{42, 28}}},
	{{'p','r','o','f','i','l','e','_','3'}, {{33, 4},{120, 7},{170, 13},{240, 16},{262, 17},{180, 23}, {110, 26},{42, 29}}},
	{{'p','r','o','f','i','l','e','_','4'}, {{34, 4},{120, 7},{170, 13},{240, 16},{263, 17},{180, 23}, {110, 26},{42, 30}}},
	{{'p','r','o','f','i','l','e','_','5'}, {{35, 4},{120, 15},{120, 20},{120, 26},{264, 30},{180, 43}, {110, 56},{42, 61}}},
	{{'p','r','o','f','i','l','e','_','6'}, {{36, 4},{120, 20},{170, 35},{230, 46},{265, 51},{180, 58}, {110, 66},{41, 79},{31, 82}}},
	{{'p','r','o','f','i','l','e','_','7'}, {{37, 4},{120, 7},{170, 13},{240, 16},{266, 17},{180, 23}, {110, 26},{42, 28}}},
	{{'p','r','o','f','i','l','e','_','8'}, {{38, 4},{120, 7},{170, 13},{240, 16},{267, 17},{180, 23}, {110, 26},{42, 29}}},
	{{'p','r','o','f','i','l','e','_','9'}, {{39, 4},{120, 7},{170, 13},{240, 16},{268, 17},{180, 23}, {110, 26},{42, 30}}},
	{{'p','r','o','f','i','l','e','_','1','0'}, {{40, 4},{120, 7},{170, 13},{240, 16},{269, 17},{180, 23}, {110, 26},{42, 31}}},
	{{'p','r','o','f','i','l','e','_','1','1'}, {{41, 4},{120, 20},{170, 35},{230, 46},{270, 51},{180, 58}, {110, 66},{41, 79},{31, 82}}},
	{{'p','r','o','f','i','l','e','_','1','2'}, {{42, 4},{120, 7},{170, 13},{240, 16},{271, 17},{180, 23}, {110, 26},{42, 28}}},
	{{'p','r','o','f','i','l','e','_','1','3'}, {{43, 4},{120, 7},{170, 13},{240, 16},{272, 17},{180, 23}, {110, 26},{42, 29}}},
	{{'p','r','o','f','i','l','e','_','1','4'}, {{44, 4},{120, 7},{170, 13},{240, 16},{273, 17},{180, 23}, {110, 26},{42, 30}}},


	//debug default
	{{'p','r','o','f','i','l','e','_','1','5'}, {{/*debug default*/-450, 4},{120, 7},{170, 13},{240, 16},{274, 17},{180, 23}, {110, 26},{42, 31}}}
};

typedef struct 
{
	char ssid[20];
	char psw[20];
	uint8_t securityIdx;
}WiFi;

WiFi wifi = { {'t','e','s','t'}, {'1','2','3','4'}, 4};

typedef struct
{
	float kp;
	float ki;
	float kd;
	uint32_t dt;
}Pid;

Pid pid = {3.2f, 1.7f, 0.3f, 200};

RamStorage::RamStorage()
{
	//debug start
	memcpy(buf + StrorageMap::PROFILES, prof, sizeof(prof));
	memcpy(buf + StrorageMap::WIFI, &wifi, sizeof(wifi));
	memcpy(buf + StrorageMap::PID, &pid, sizeof(pid));
	//debug end
}

bool RamStorage::Read(uint32_t addr, void* buf, uint32_t len)
{
	memcpy(buf, this->buf + addr, len);
	return true;
}

bool RamStorage::Write(uint32_t addr, void* data, uint32_t len)
{
	memcpy(this->buf + addr, data, len);
	return true;
}

bool RamStorage::Remove(uint32_t addr, uint32_t len)
{
	memset(buf + addr, 0xFF, len);
	return true;
}

