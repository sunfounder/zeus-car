4. ドリフト
======================

このプロジェクトでは、Zeus Carをドリフトさせる方法を学びます。

.. image:: img/zeus_drift_left.jpg

**どのように実行するか？**

#. ESP32-CAMとArduinoボードは、同じRX（受信）およびTX（送信）ピンを共有しています。そのため、コードをアップロードする際は、ESP32-CAMの接続を一度切断して、衝突や潜在的な問題を避ける必要があります。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. ``zeus-car-main\examples\4_drift`` のパスの下にある ``4_drift.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/9ca66dad-7258-4868-a8a4-3bd512bacd72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードが正常にアップロードされた後、電源スイッチをONにしてZeus Carを起動します。
#. Zeus Carは0.5秒間前進し、その後90度左にドリフトします。45(rot)を別の値や負の数に変更して、ドリフトの角度と方向がどのように変わるかを試してみてください。

**動作原理は？**

Zeus Carのドリフトは、移動関数 ``carMove()`` にドリフトパラメータ ``drift`` を追加することで実現されます。

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot)

* ``angle``: 車を移動させたい方向。車の前方を0度として、反時計回りに角度を増やします。
* ``power``: 移動のパワー、範囲は-100% ~ 100%です。 ``power`` が正の場合、車は前進し、その逆の場合は後退します。
* ``rot``: 回転力、範囲は-100% ~ 100%です。 ``rot`` が正の場合、車は反時計回りに回転し、その逆も同様です。
* ``drift``: デフォルトはfalseですが、trueに設定するとドリフトモードが有効になります。

したがって、異なる ``power`` と ``rot`` の値は、Zeus Carのドリフト角度と方向を変更します。
