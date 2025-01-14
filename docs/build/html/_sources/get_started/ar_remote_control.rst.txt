.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

5. リモートコントロール
============================

このプロジェクトでは、リモートコントロールを使用してZeus Carを制御する方法を学びます。

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/> 


**どのように実行するか？**

#. ESP32-CAMとArduinoボードは、同じRX（受信）およびTX（送信）ピンを共有しています。そのため、コードをアップロードする際は、ESP32-CAMの接続を一度切断して、衝突や潜在的な問題を避ける必要があります。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. ``zeus-car-main\examples\5_remote_control`` のパスの下にある ``5_remote_control.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/8e74cf1b-9100-4e4d-ab63-f21ae40232a5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードが正常にアップロードされた後、電源スイッチをONにしてZeus Carを起動します。

#. 次に、リモートコントロールの1〜9の数字を使用して、車を8つの方向に制御します。

    .. image:: img/ar_remote_control.png
        :width: 600
        :align: center

#. キーを押すと、Zeus Carは |ir_power| キーまたは数字キー5を押すまで移動し続けます。

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center

#. |ir_return| を一度押すと、車は本体を中心に反時計回りに回転し、 |ir_power| キーまたは数字キー5を押すまで停止します。

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. 同様に、 |ir_usd| を一度押すと、車は時計回りに回転し、その後 |ir_power| キーまたは数字キー5を押すまで停止します。

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center
