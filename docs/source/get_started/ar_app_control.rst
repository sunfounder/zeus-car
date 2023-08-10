.. _ar_app_control:

17. APP制御
=====================

前回のプロジェクトでは、カメラで撮影された映像を単純に表示し、SunFounderコントローラのAI検出機能を使用しました。

このプロジェクトでは、アプリのジョイスティックウィジェットを使用してZeus Carの動きや方向を制御する方法を試みます。それでは、その動作方法を見てみましょう。

.. note::
    **APP Store(iOS)** または **Google Play(Android)** から `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ をインストールしてください。

**やり方**

#. ESP32-CAMとArduinoボードは、RX（受信）およびTX（送信）ピンを共有します。そのため、コードをアップロードする際は、ESP32-CAMの接続を解除して、競合や潜在的な問題を回避する必要があります。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. ``zeus-car-main\examples\17_app_control`` のパスの下の ``17_app_control.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5d65d2b4-5ed7-4d21-ba3b-02529ee8dd6c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードのアップロードが成功したら、電源スイッチをONにしてZeus Carを起動します。

#. アップロードスイッチをRunの側(この図では右側)に切り替えて、ESP32 CAMを起動します。

    .. image:: img/zeus_run.jpg

#. リセットボタンを押して、Arduinoボードのプログラムを再度実行します。

    .. image:: img/zeus_reset_button.jpg

#. ``Zeus_Car`` WLANに接続します。

    * 携帯電話(タブレット)のWLANで ``Zeus_Car`` を見つけ、パスワード ``12345678`` を入力して接続します。

    .. image:: img/app_wlan.png

    * デフォルトの接続モードはAPモードです。接続後、このWLANネットワークにインターネットアクセスがないというプロンプトが表示されますが、接続を続行してください。

    .. image:: img/app_no_internet.png

#. コントローラを作成します。

    * SunFounderコントローラでコントローラを追加するには、**+** アイコンをクリックします。

        .. image:: img/app1.png

    * プリセットセクションには、一部の製品用のプリセットコントローラがあります。しかし、ここでは **空白** および **デュアルスティック** テンプレートを選択します。

        .. image:: img/app_blank.PNG

    * Jエリアの+アイコンをクリックし、スイッチウィジェットを選択します。ウィジェットを見るために左にスライドする必要があるかもしれません。

        .. image:: img/app_switch_wid.png

        .. note::
            間違ったウィジェットを選択したと思う場合は、再度クリックして削除ボタンを使用して削除することができます。

            .. image:: img/app_delete.png

    * 右上の設定アイコンをクリックして名前を付けます。

        .. image:: img/app_name_dirft.png

    * KエリアとQエリアでジョイスティックウィジェットを選択し、両方のウィジェットに名前を付けます。次に、|app_save| ボタンを使用してコントローラを保存します。

    .. image:: img/app_joystick_wid.png

    * 次のステップは、|app_connect| ボタンを使用してZeus Carをデバイスに接続することです。数秒待ち、``Zeus_Car(IP)`` が表示されるのを待ち、クリックして接続します。

        .. image:: img/app_connect.png

        .. note::
            Wi-Fiが ``Zeus_Car`` に接続されていることを確認してください。上記のメッセージが長い間表示されない場合。

#. コントローラを実行します。

    "正常に接続されました"というメッセージが表示された後、|app_run| ボタンをクリックすると、カメラの映像がアプリに表示され、これらのウィジェットを使用してZeus Carを制御することができます。

    3つのウィジェットの機能は以下のように参照されます。

    **全方向の移動(K)**

    |app_move_k| ウィジェットをスワイプすると、Zeus Carは適切な方向に移動します。

    .. image:: img/joystick_move.png
        :align: center

    スライドするたびに車が一度移動しますので、常に手を離さない限り、車は移動し続けます。

    .. image:: img/zeus_move.jpg

    **ドリフト機能の有効化(J)**

    |app_drift_j| ボタンをクリックして、ドリフト機能を有効にします。

    * |app_rotate_q| ウィジェットを反時計回りにスライドすると、Zeus Carは右にドリフトします。手を離すと、車はその場所で停止します。

        .. image:: img/zeus_drift_left.jpg
            :width: 600
            :align: center

    * 同様に、|app_rotate_q| ウィジェットを時計回りにスライドすると、Zeus Carは左にドリフトし、現在の位置で停止します。

        .. image:: img/zeus_drift_right.jpg
            :width: 600
            :align: center

    **方向の制御(Q)**

    * |app_drift_j| ボタンがオンのとき、|app_rotate_q| ウィジェットはZeus Carを左右にドリフトさせるために使用されます。

    * |app_drift_j| ウィジェットがオフのとき、|app_rotate_q| ウィジェットは車の先端の方向を制御するために使用されます。

        * |app_rotate_q| ウィジェットを反時計回りにスライドすると、車も反時計回りに回転します。手を放すと、車の先端は元の方向に戻ります。

            .. image:: img/zeus_turn_left.jpg
                :width: 600
                :align: center

        * 同様に、|app_rotate_q| ウィジェットを使用して車を時計回りに回転させると、手を放すと元の方向に戻ります。

            .. image:: img/zeus_turn_right.jpg
                :width: 600
                :align: center
