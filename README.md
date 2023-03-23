# PikoKeyBeta

## About this page
- MIDIキーボード PikoKey β版 組み立てキットの情報ページです。

- 随時更新中

- Arduino Nano Everyは別売ですので、別途入手しておいてください。

## Parts List

| リファレンス番号 | 個数 | 部品名 |
| ---------------- | ---- | -------|
| BT1 | 1 | バッテリーケース |
| CN1 | 1 | DINコネクタ | 
| D1, D2, D3, D4 | 4 | LED | 
| D5 | 1 | ショットキーダイオード SBM245L| 
| J1 | 1 | 3.5mmステレオジャック | 
| R1, R2 | 2 | 抵抗 220Ω | 
| R3, R4, R5, R6 | 4 | 抵抗 1kΩ | 
| SW1, SW2, SW3, SW4, SW5, SW6, SW7, SW8, SW9, SW10, SW11, SW12, SW13, SW14, SW15, SW16, SW17 | 17 | タクトスイッチ | 
| SW18 | 1 | スライドスイッチ | 
| U1 | 1 | Arduino Nano Every(別売) | 
| U2 | 1 | 5V出力昇圧DC/DCコンバーターキット | 
| - | 1	| 基板| 
| - | 3	| スペーサー| 
| - | 3 | 	ネジ| 

## 回路図

[Schematics](/Hardware/PikoKeyBeta_schematic.pdf)

## 基板パターン図

[PCB Pattern](/Hardware/PikoKeyBeta_patten.pdf)

## 部品配置図

![PartsPlacementChart](/image/PikoKeyBeta_parts_place.PNG)
![PartsPlacementImage](/image/IMG_5642.JPG)

## 部品実装上の注意
### ダイオード
- ダイオードは極性があります。方向に注意してください。
- D5は線が付いている方向がカソード(K)です。

![PartsPlacementImage](/image/IMG_5644.JPG)


- LED(D1～D4)はリード線の短い方がカソード(K)です。以下の図を参考にしてください。

![PartsPlacementImage](/image/diode.PNG)

### U1 Arduino Nano Every

- U1 Arduino Nano Every はUSBコネクタが外側になるように取り付けてください。部品配置図を参考にしてください。

### U2 5V出力昇圧DC/DCコンバーターキット

- U2 5V出力昇圧DC/DCコンバーターキットは以下の写真の方向で取り付けてください。

![PartsPlacementImage](/image/IMG_5643.JPG)

## 修正点

- 追加で抵抗(100Ω)を以下の図に従って取り付けてください。100Ω抵抗は一部のキットでは付属していない場合がありますので、お手持ちのものをお使いいただくか、ご希望の場合はお手数ですが Twitter @PikoPiko_F までご連絡ください。送付対応させていただきます。この抵抗を取り付けない場合、一番低いキー（SW1）の打鍵情報が取得できません。

![PartsPlacementImage](/image/IMG_5645.JPG)
![PartsPlacementImage](/image/IMG_5646.JPG)


## ソフトウェア
- Arduino IDEベースです。
- MIDIライブラリが必要です。MIDIライブラリは多種リリースされていますが、https://github.com/FortySevenEffects/arduino_midi_library を使用しています。

### サンプルコード
- Arduino Nano Every用です。
- 鍵盤を押すと、相当するNote on/offをMIDI outから送出します。チャンネルは1です。SW16,17,18の機能はまだインプリしていません。SW16,17でオクターブアップ、ダウン、SW18+鍵盤キーのコンビネーションでMIDI CH変更と、プログラムチェンジの送出を行う予定で、近日中にアップデート予定です。

[Code/Software/PikoKey.ino](/Software/PikoKey.ino)

