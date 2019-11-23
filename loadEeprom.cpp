#include <exception>
#include <string>
#include <regex>
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include "cpu.hpp"
#include "sys.hpp"
#include "state.hpp"

bool loadEeprom( const std::string &fileName ){
    FILE *fp = fopen( fileName.c_str(), "rb" );
    if( !fp ) return false;

    u32 count = fread( MMU::eeprom, sizeof(MMU::eeprom), 1, fp );
    fclose(fp);
    return count == sizeof(MMU::eeprom);
}

void writeEeprom( const std::string &fileName ){
    if( !MMU::eepromDirty )
        return;

    FILE *fp = fopen( fileName.c_str(), "wb" );
    if( !fp )
        return;

    fwrite( MMU::eeprom, sizeof(MMU::eeprom), 1, fp );
    fclose(fp);

    MMU::eepromDirty = false;
}
