#ifndef _BLE_Peripheral_H_
#define _BLE_Peripheral_H_

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <Arduino.h>

class BLE_Peripheral {
   public:
    BLE_Peripheral(const char* deviceName);

    void init();
    void enableDebugMode();
    bool checkConnection();

    int available();
    char read();
    void write(char* data, size_t length);

    void uuidGenerate(const char* tag);

   private:
    // デバイスの接続状態
    bool _isDeviceConnected;
    bool _wasDeviceConnected;
    bool _isDebugMode;

    char _serviceUuid[38];
    char _characteristicUuid[38];
    const char* _deviceName;

    // BLEサーバー
    BLEServer* _pServer;

    // BLE特性
    BLECharacteristic* _pCharacteristic;

    // 受信データ
    std::string _rxValue;
    class MyServerCallbacks : public BLEServerCallbacks {
        BLE_Peripheral* peripheral;

       public:
        MyServerCallbacks(BLE_Peripheral* peripheral);
        void onConnect(BLEServer* pServer);
        void onDisconnect(BLEServer* pServer);
    };

    class MyCallbacks : public BLECharacteristicCallbacks {
        BLE_Peripheral* peripheral;

       public:
        MyCallbacks(BLE_Peripheral* peripheral);
        void onWrite(BLECharacteristic* pCharacteristic);
    };
};

#endif