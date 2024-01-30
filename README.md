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
