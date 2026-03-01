#include "communication.hpp"

CommManager::CommManager() : _index(0) {}

bool CommManager::ParseByte(uint8_t byte) {
    _buffer[_index++] = byte;

    if (_buffer[0] != 0xA5) {
        _index = 0;
        return false;
    }

    if (_index == sizeof(RobotCommand)) {
        RobotCommand* potential_cmd = (RobotCommand*)_buffer;
        
        if (potential_cmd->footer == 0x5A) {
            _last_cmd = *potential_cmd;
            _index = 0;
            return true;
        }
        _index = 0;
    }
    return false;
}