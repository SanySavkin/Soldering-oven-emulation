#ifndef AP_STORAGE_H
#define AP_STORAGE_H


#include "Storage/istorage.h"


class RamStorage : public DStorage::IStorage
{
private:
    static uint8_t buf[8182];
public:
    RamStorage();
    bool Read(uint32_t addr, void* buf, uint32_t len) override;
    bool Write(uint32_t addr, void* data, uint32_t len) override;
    bool Remove(uint32_t address, uint32_t len) override;
};



#endif // AP_STORAGE_H

