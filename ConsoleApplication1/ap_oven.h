#ifndef AP_OVEN_H
#define AP_OVEN_H


#include "Models/oven_processor.h"


class OvenControl : public IOvenProcessor
{
public:
    OvenControl();
    uint32_t GetMs() override;
    int32_t GetTemp() override;
    void SetOutput(int32_t) override;
};


#endif //AP_OVEN_H
