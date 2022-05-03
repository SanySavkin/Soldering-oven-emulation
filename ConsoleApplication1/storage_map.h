#ifndef STORAGE_MAP_H
#define STORAGE_MAP_H



namespace StrorageMap {
	enum AddrMapEnum
	{
		PROFILES = 0,
		WIFI = PROFILES + 4096,
		PID = WIFI + 1024,
	};
}


#endif // STORAGE_MAP_H


