1. 基本動き
========================

このプロジェクトで、Zeus Carをすべての方向に動かす方法を学びます。

    .. image:: img/zeus_move.jpg
        :width: 600

**どのように実行するか？**

#. ESP32-CAMとArduinoボードは、同じRX（受信）およびTX（送信）ピンを共有しています。そのため、コードをアップロードする際は、ESP32-CAMの接続を一度切断して、衝突や潜在的な問題を避ける必要があります。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. 青いUSBケーブルを使用してZeus Carをコンピュータに接続します。Arduinoボードを接続すると、コンピュータは自動的にそれを認識し、Device Managerで確認できるCOMポートを割り当てます。

#. ``zeus-car-main\examples\1_basic_move`` のパスの下にある ``1_basic_move.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/cedd4eb2-3283-48ae-8851-c932eb2098ea/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. ここからボードとポートをすぐに選択できます。

    .. image:: img/ar_board.png

    .. note::
        COMxxが表示されない場合は、左側からボードマネージャを開き、「Arduino AVR Boards」のコアがインストールされていることを確認してください。

        .. image:: img/ar_other_board.png

#. 今度は **アップロード** ボタンをクリックして、コードをArduinoボードにアップロードします。完了すると、IDEウィンドウの右下に通知が表示されます。もちろん、アップロード時にいくつかの問題が発生することがあり、これらのエラーもここにリストされます。

    .. note::
        * ``Compilation error: SoftPWM.h: No such file or directory`` というプロンプトが表示される場合、 ``SoftPWM`` ライブラリがインストールされていないことを意味します。
        * 必要なライブラリ ``SoftPWM`` と ``IRLremote`` のインストールについては、 :ref:`ar_install_library` を参照してください。

    .. image:: img/ar_upload.png

#. Zeus Carを起動しましょう。

    * 初めて使用する場合やバッテリーケーブルが抜かれている場合、Zeus Car Shieldは過放電保護回路を活性化します。
    * そのため、Type-Cケーブルを約5秒間接続する必要があります。

            .. image:: img/zeus_charge.jpg

    * 電源インジケータが点灯すると、保護状態が解除されたことを意味します。この時、バッテリーインジケータを確認し、両方のバッテリーインジケータがオフの場合は、Type-Cケーブルを接続してバッテリーを充電してください。

        .. image:: img/zeus_power.jpg

#. Zeus Carが各方向に1秒間移動するのを見ることができます。

    .. image:: img/zeus_move.jpg
        :width: 600

**動作原理は？**

これらの動きは、4つのメカナムホイールが協力して得られるもので、例えば、4つのホイールが同時に前進または後退することで、車も前進または後退でき、2つのホイールが前進し、2つのホイールが後退することで、車が左右にパンまたは回転する原因となります。

これらの動きがどのように具体的に達成されるのかを見てみましょう。

* 前進と後退、左右のパンニング

    .. image:: img/ar_fwlr.jpg
        :width: 600

* 対角線上のパンニング

    .. image:: img/ar_fblr.jpg
        :width: 600

* 左右の回転

    .. image:: img/ar_turn_lr.jpg
        :width: 600
