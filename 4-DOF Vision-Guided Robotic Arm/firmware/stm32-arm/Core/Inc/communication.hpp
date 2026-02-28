#ifndef COMMUNICATION_HPP
#define COMMUNICATION_HPP

#include <cstdint>

#pragma pack(push, 1)
struct RobotCommand {
    uint8_t  header;   
    uint8_t  command;  
    float    x;
    float    y;
    float    z;
    uint8_t  crc;      
    uint8_t  footer;   
};
#pragma pack(pop)

class CommManager {
public:
    CommManager();
    bool ParseByte(uint8_t byte); 
    RobotCommand GetLatestCommand() { return _last_cmd; }

private:
    RobotCommand _last_cmd;
    uint8_t _buffer[sizeof(RobotCommand)];
    uint8_t _index;
    uint8_t CalculateCRC(RobotCommand cmd);
};

#endif