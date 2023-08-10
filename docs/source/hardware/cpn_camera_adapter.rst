カメラアダプターボード
========================================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: ESP32-CAMをリセットするために使用します。
* **SCL**: QMC6310のシリアルデータピン
* **SDA**: QMC6310のシリアルクロックピン
* **RXD**: ESP32-CAMのRXD、このRXDおよびTXDの2つのシリアルピンを使用してESP32-CAMにコードをアップロードします。
* **TXD**: ESP32-CAMのTXD
* **5V**: 5V DCの供給入力
* **GND**: 接地入力

カメラアダプターボードは、その名の通り、ESP-32 CAMの拡張ボードで、ロボットに固定するため、また簡単に配線するためのESP32-CAMを拡張するために使用されます。

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

また、地磁気チップQMC6310はモーターからの干渉を受けやすいため、モーターからできるだけ遠くに保つためにこのカメラアダプターボードに配置しました。

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**特徴**

* 動作電圧: 5V
* インターフェースモデル: ZH1.5, 7P
* サイズ: 40mm x 27mm x 15mm
* 通信プロトコル: UART および I2C

**関連ドキュメント**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* 回路図

.. image:: img/cam_adapter_sche.png


**QMC6310について**

QMC6310は、磁気センサーと信号条件ASICを一つのシリコンチップに統合した3軸の磁気センサーです。このLGAパッケージは、モバイルやウェアラブルデバイスのe-コンパス、地図回転、ゲーム、個人ナビゲーションなどのアプリケーションを対象としています。

QMC6310は、最先端の高解像度磁気抵抗技術をベースにしています。カスタム設計された16ビットADC ASICとともに、低ノイズ、高精度、低消費電力、オフセットキャンセル、温度補償の利点を提供します。QMC6310は1°から2°のコンパス方位精度を実現します。I²Cシリアルバスは、簡単なインターフェースを可能にします。

QMC6310は、1.2x1.2x0.53mm3のサーフェスマウント8ピンLGAパッケージに収められています。

* |link_qmc6310_datasheet|
