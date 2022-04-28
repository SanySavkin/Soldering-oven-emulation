#include "ap_storage.h"
#include "string.h"

#include "Common/Model/profiles.h"


uint8_t RamStorage::buf[2048] = {};

Profile_t prof[5] =
{
	{{'p','r','o','f','i','l','e','_','1'}, {{31, 4},{120, 20},{170, 35},{230, 46},{265, 51},{180, 58}, {110, 66},{41, 79},{31, 82}}},
	{{'p','r','o','f','i','l','e','_','2'}, {{32, 4},{120, 7},{170, 13},{240, 16},{272, 17},{180, 23}, {110, 26},{42, 28},}},
	{{'p','r','o','f','i','l','e','_','3'}, {{32, 4},{120, 7},{170, 13},{240, 16},{273, 17},{180, 23}, {110, 26},{42, 29},}},
	{{'p','r','o','f','i','l','e','_','4'}, {{32, 4},{120, 7},{170, 13},{240, 16},{274, 17},{180, 23}, {110, 26},{42, 30},}},
	{{'p','r','o','f','i','l','e','_','5'}, {{32, 4},{120, 7},{170, 13},{240, 16},{275, 17},{180, 23}, {110, 26},{42, 31},}}
};


RamStorage::RamStorage()
{
	//debug start
	memcpy(buf, prof, sizeof(prof));
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

bool RamStorage::Erase(uint32_t addr, uint32_t len)
{
	memset(buf + addr, 0xFF, len);
	return true;
}

