#ifndef SENSEBOXBLE_H
#define SENSEBOXBLE_H

#include <cstddef>

#include "Arduino.h"
#include "NINAB31serial.h"

class CharacteristicProperties
{
private:
    static uint8_t BROADCAST;
    static uint8_t READ;
    static uint8_t WRITE_NO_RESPONSE;
    static uint8_t WRITE;
    static uint8_t NOTIFY;
    static uint8_t INDICATE;
    static uint8_t AUTH_SIGNED_WRITE;
    const bool broadcast;
    const bool read;
    const bool write_no_response;
    const bool write;
    const bool notify;
    const bool indicate;
    const bool auth_signed_write;
public:
    CharacteristicProperties(
        bool broadcast, bool read, bool write_no_response, bool write,
        bool notify, bool indicate, bool auth_signed_write);
    String asHexString() const;
};

class SenseBoxBLE
{
    private:

        static uint8_t data_package[20];

        static NINAB31Serial port;

        static void configCharacteristicWritten();

        static int h_configCharacteristic;

        static uint8_t* data; //this pointer points to the data the user wants to write in the characteristic

        static uint8_t configCharValue[21];


    public:

        static void start(const char* DEVICE_NAME, uint8_t* p, size_t n = 0);
        static void start(const char* DEVICE_NAME);
        static void start(uint8_t* p, size_t n = 0);
        static void start();

        static bool advertise();
        static bool stopAdvertise();

        static int addService(const char* serviceUUID);
        static int addCharacteristic(
            const char* characteristicUUID,
            const CharacteristicProperties& properties);
        static int addCharacteristic(const char* characteristicUUID);
        static int setConfigCharacteristic(const char* serviceUUID, const char* characteristicUUID);
        static void setName(String name);
        static String getMCUId();

        static bool write(
            int characteristic, uint8_t const *data, std::size_t len);
        static bool write(int, float&);
        static bool write(int, float&, float&);
        static bool write(int, float&, float&, float&);
        static bool write(int, float&, float&, float&, float&);
        static bool write(int, float&, float&, float&, float&, float&);

        static void read(uint8_t*, unsigned int);
        static void read(float&);

        static void poll();
        static void poll(int timeout);

        static void(*configHandler)();
        static uint16_t minConInterval;
        static uint16_t maxConInterval;
        static uint16_t slaveLatency;
        static uint16_t timeout;

};

#endif
