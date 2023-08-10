8. 移動 - フィールドセントリック制御システム
===============================================================

このプロジェクトは、前のプロジェクトに基づいて、Zeus Carの動きにコンパス機能を組み合わせます。
リモートコントロールでZeus Carの動きを制御している間、外部の力（例：犬に蹴られる）で逸らされた場合、自動的に元の方向に戻します。

**操作方法**

#. ESP32-CAMとArduinoボードは、RX（受信）およびTX（送信）のピンが共有されています。コードをアップロードする際は、まずESP32-CAMを切断して、コンフリクトや潜在的な問題を避けてください。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. ``zeus-car-main\examples\8_move_field_centric`` のパスから ``8_move_field_centric.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a0ac96b3-47a9-4eab-8d8a-d1ca16c7fcda/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードが正常にアップロードされたら、電源スイッチをONにしてZeus Carを起動します。

#. その後、リモートコントロールの数字1〜9を使用して、車を8つの方向に制御します。キーを押した後、Zeus Carは |ir_power| または数字キー5を押すまで移動し続けます。

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center

#. |ir_return| を一度押すと、車は車体を中心に反時計回りに回転し、 |ir_power| または数字キー5を押すまで停止します。

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. 同様に、 |ir_usd| を一度押すと、車は時計回りに回転し、その後 |ir_power| または数字キー5を押すまで停止します。

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center

#. |ir_minus| キーを押すと、車は左にドリフトします。

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

#. |ir_plus| キーを押すと、車は右にドリフトします。

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center

.. note::

    * Zeus Carがうまく動かない場合、コンパスが正しくキャリブレートされていない可能性があります。その場合は |ir_mute| を押してキャリブレートしてください。
    * 車を地面からテーブルに持ち上げると、磁場が変わるため、再キャリブレーションが必要です。
