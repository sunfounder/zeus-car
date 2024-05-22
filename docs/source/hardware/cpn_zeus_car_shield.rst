.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

Zeus Car Shield
=========================

.. image:: img/zeus_car_shield.png
    :width: 500
    :align: center

SunFounder社がArduino向けに設計したオールインワンの拡張ボードです。モーターやライトバー、障害物回避、グレースケール、ESP32 CAM、超音波モジュールなど、さまざまなモジュールポートが含まれています。HS0038B IRレシーバーも内蔵されており、リモートコントロールが可能です。

この拡張ボードには充電回路も内蔵されており、PH2.0-5Pインターフェースのバッテリーを充電でき、推定充電時間は130分です。

**Zeus Car Shield ピンアウト**

.. image:: img/zeus_car_shield_pinout.png

* リセットボタン
    * このボタンを押すとArduinoボード上のプログラムがリセットされます。

* 充電ポート
    * 5V/2AのUSB-Cポートに接続すると、バッテリーを130分で充電できます。

* :ref:`shield_battry_pin`：
    * 6.6V~8.4V PH2.0-5P電源入力。
    * Zeus Car ShieldとArduinoボードの両方に電源を供給します。

* 電源スイッチ
    * ONの位置にスライドするとZeus Car Shieldの電源が入ります。

* IRレシーバー
    * これはHS0038B IRレシーバーで、Arduinoボードのピン2に信号ピンが接続されています。

* :ref:`shield_grayscale_pin`
    * グレースケール調整用のポテンショメーター：オムニグレースケールモジュールの基準電圧を設定するために使用
    * グレースケールポート：オムニグレースケールモジュールの接続に使用。

* インジケータ
    * **充電インジケータ**: USB-Cポートからの充電中に赤く点灯します。
    * **電源インジケータ**: 電源スイッチが"ON"の位置にあるとき緑色に点灯します。
    * **バッテリーインジケータ**: 2つのオレンジ色のインジケータは、異なるバッテリーレベルを示しています。充電中は点滅し、バッテリーの充電が必要なときは消灯します。

* :ref:`shield_ultrasonic_pin`
    * 超音波モジュールを接続するために、TrigとEchoのピンはArduinoボードのピン10に接続されます。

* :ref:`shield_camera_pin`
    * カメラアダプターボードポート。

* :ref:`shield_avoid_pin`
    * 2つのIR障害物回避モジュールを接続するために使用され、2つのポートの信号ピンは74HC165のQ0とQ1に接続されています。

* :ref:`shield_strip_pin`
    * 2つのRGB LEDストリップを接続するために使用され、ストリップの3つのピンはそれぞれ12, 13, 11に接続されています。

* 実行スイッチ
   * カメラを使用する必要がある場合、このスイッチを反対側に切り替えることで、ESP32-CAMがArduinoボードと通信できるようになります。

* :ref:`shield_motor_pin`
    * モーターポートの4組。

.. _shield_battry_pin:

バッテリーポート
----------------

こちらはバッテリーインターフェースのピン配置図です。タイプはPH2.0-5Pで、電力入力範囲は6.6V〜8.4Vです。

.. image:: img/shield_battery_pin.png
    :width: 400
    :align: center

.. _shield_grayscale_pin:

グレースケールモジュール関連
-----------------------------

Zeus Car Shield上の青いポテンショメーターは、グレースケールモジュールの参照電圧を設定することで、異なる環境への感度を調整するために使用されます。VREFピンを通じて、グレースケールモジュールは設定された参照電圧を受け取ります。

.. image:: img/shield_grayscale_pin.png

これは回路図です。グレースケールモジュールの値は、74HC165チップからArduinoボードに転送されます。グレースケールモジュール自体に74HC165チップが組み込まれているため、これら2つのチップのカスケードは、Arduinoボードに16ビットのデータを転送します。最初の8ビットはグレースケールセンサーデータであり、残りの2ビットはIR障害回避データです。

.. image:: img/shield_grayscale1.png
.. image:: img/shield_grayscale2.png
    :width: 400

Arduinoボード上のこのポートのピンマッピングは以下の通りです。

.. list-table::
    :widths: 25 50

    * - Arduino Board
      - Zeus Car Shield
    * - 7
      - 74HC165 Q7
    * - 8
      - 74HC165 CP
    * - ~9
      - 74HC165 PL

.. _shield_ultrasonic_pin:

超音波ポート
--------------------

これはZH1.5-4P超音波ポートのピン配置で、Trig & EchoピンはArduinoボードのピン10に接続されています。

.. image:: img/shield_ultrasonic_pin.png

.. _shield_camera_pin:

カメラアダプターポート
----------------------

カメラアダプターインターフェースのピン図は、タイプはZH1.5-7Pです。

* TXとRXはESP32 CAM用です。
* SDAとSCLはQMC6310用です。

.. image:: img/shield_camera_pin.png

.. _shield_avoid_pin:

障害回避ポート
----------------------------

以下は、2つのZH1.5-3P障害回避ポートのピン配置図です。

.. image:: img/shield_avoid_pin.png

回路図に示されているように、S1およびS0は74HC165チップ上のQ0およびQ1を参照します。2つの74HC165カスケードは、2つのIR障害回避モジュールおよびグレースケールセンサーのデータをArduinoボードに転送します。最初の8ビットはグレースケールセンサーデータであり、最後の2ビットはIR障害回避データを示します。

.. image:: img/shield_avoid_sche.png
.. image:: img/shield_avoid_sche1.png

.. _shield_strip_pin:

RGB LEDストリップポート
-------------------------

以下は、2つのRGB LEDストリップのピン配置図で、並列接続されており、ピンアウトは同じです。

.. image:: img/shield_strip_pin.png

これはその回路図です。

.. image:: img/shield_strip_sche.png
.. image:: img/shield_strip_sche1.png

.. _shield_motor_pin:

モーターポート
---------------

これは、4セットのモーターポートのピン配置です。

.. image:: img/shield_motor_pin.png
    :width: 400
    :align: center

これら4セットのモーターは、最大1.8A/チャンネルの連続出力電流を持つデュアルチャンネルモータードライバーチップである2つのTC1508Sチップによって駆動されます。

こちらがその回路図です。

.. image:: img/shield_motor_sche.png

したがって、4つのモーターポートの対応する制御ピンは以下の通りです。

.. list-table::
    :widths: 25 50

    * - Arduino Board
      - Zeus Car Shield
    * - ~3
      - OUTA1
    * - 4
      - OUTB1
    * - ~5
      - OUTA2
    * - ~6
      - OUTB2
    * - A0
      - OUTB4
    * - A1
      - OUTA4
    * - A2
      - OUTB3
    * - A3
      - OUTA3



