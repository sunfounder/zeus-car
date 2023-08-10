12. ついてきて
====================

このプロジェクトでは、以前のプロジェクトと同じ2つの障害物回避モジュールと超音波モジュールを使用しますが、今回の目的は障害物を避けることではなく、ユーザーについてくることです。

**どうやって行うか？**

#. ESP32-CAMとArduinoボードは、RX（受信）およびTX（送信）のピンが共有されています。したがって、コードをアップロードする際には、先にESP32-CAMを切断して、トラブルや潜在的な問題を回避してください。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. ``zeus-car-main\examples\12_follow`` のパスから ``12_follow.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3fd83bdc-5457-4532-9da1-126fb7092a11/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードのアップロードが成功したら、電源スイッチをONにしてZeus Carを起動します。

#. この設定では、Zeus Carは前方に何もない場合は動きません。しかし、20cmの距離で前方に立つと、車はあなたについてきます。

