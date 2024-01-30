## BLE-Kit For C3

![アートボード 1](https://github.com/shirokuma89dev/BLE-Kit4C3/assets/47915291/e91d2c99-5d00-4bb9-b6f4-cabe41392532)

## Support

個人のモチベーションのみで成り立っているプロジェクトです。作業用のカフェ代奢ってくれると嬉しいです☺️

<a href="https://www.buymeacoffee.com/shirokuma89dev" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>

## 概要

ESP32C3で簡単にBluetooth通信を扱えるようにしたライブラリです。ペリフェラル側とコントローラー側のうち、**現在はペリフェラル側のみ対応**しています。（コントローラー側は現在動作済み→リファクタリング中）

[動作イメージ（Youtube）](https://youtu.be/WkrFvnKTLFU)

## インストール方法

2つのインストール方法があります。

### 1. PlatformIO Library（推奨）

PlatformIOのLibrariesタブでBLE-Kit4C3と検索してAdd to projectからインストールしてください。

### 2. 手動インストール

このリポジトリをダウンロードして、src内のヘッダーファイル、.cppファイル一式をあなたのプロジェクトに追加して利用してください。

## 現在用意されている関数（Peripheral only）

```cpp
void init();
void enableDebugMode();
bool checkConnection();
int available();
char read();
void write(char* data, size_t length);
```

### BLE_Peripheral:BLE_Peripheral(const char* deviceName)

コンストラクタです。デバイスの名前を文字列リテラルで指定してください。UUIDはこのデバイス名から適当に生成されます。（これは完全にユニークではないので、ちゃんと指定したい方はBLE_Peripehral.cppを改造してください。）

### void init()

BLE関係をもろもろ初期化する関数です.`void setup()`とかで実行するのが良いと思います。

### enableDebugMode()

BLE関係の詳細情報を`Serial.print()`します。`init()`時に以下のようにデバッグ情報が送られてきます。`init()`の前に実行することに注意してください。

```
BLE Device created
Device name: XIAOC3 PeripheralB
BLE Server created
BLE Service created
Service UUID: 00000293-0586-0879-1172-000000001465
BLE Characteristic created
Characteristic UUID: 00001172-2344-3516-4688-000000005860
Descriptor added to the characteristic
Callbacks set for the characteristic
Service started
Service UUID added to the advertising
Advertising settings updated
Advertising started
```

### bool checkConnection()

コントローラーに接続しているかどうかを返します。この時同時にコントローラと接続できるか再試行を行います。

### int available()

コントローラから送られてきたデータが何byte利用可能かを返します。`Serial.available()`と使用方法は同一です。

### char read()

コントローラから送られてきたデータをバッファから順に取得します。`Serial.read()`と使用方法は同一です。

### void write(char* data, size_t length);

コントローラへデータを送信します。`char* data`には先頭アドレスを、`size_t length`には送信するバイト数を指定します。

### Example

ペリフェラルは1秒おきにコントローラへHello world!を出力します。コントローラから送信されたデータを受け取ったら、Serial.writeでシリアルモニタに出力します。

```cpp
#include <Arduino.h>

#include <BLE_Kit4C3.h>

BLE_Peripheral ble("BLE_Kit4C3 Peripheral");

void setup() {
    ble.enableDebugMode();
    ble.init();
}

void loop() {
    if (ble.checkConnection()) {
        static unsigned long flagTimer = millis();
        if (millis() - flagTimer > 1000) {
            char sendDataArr[] = "Hello world!";
            int dataSize = sizeof(sendDataArr) / sizeof(sendDataArr[0]);

            ble.write(sendDataArr, dataSize);

            flagTimer = millis();
        }

        while (ble.available() != 0) {
            char data = ble.read();
            Serial.write(data);
        }
    }
}
```

## おすすめアプリ

動作確認におすすめのアプリを勝手にご紹介します。

- LightBlue(iOS, macOS, Android)
- BLE Discover(iOS)

どちらのアプリもあまり操作方法は変わりません。ペリフェラルに接続した後にサービスにアクセスして、Notificationをオンにしてください。各アプリの操作方法は制作者が私ではないのでサポートしかねます。

### BLE Discover

![image](https://github.com/shirokuma89dev/BLE-Kit4C3/assets/47915291/f25a25be-ec34-4c71-b616-77323233c9cc)

### LightBlue

![image](https://github.com/shirokuma89dev/BLE-Kit4C3/assets/47915291/150ae54d-c7ee-4ea3-828e-28fe95a8d034)


