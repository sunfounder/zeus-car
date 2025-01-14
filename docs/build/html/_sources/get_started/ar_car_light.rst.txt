.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！

6. 車のライト
==========================

このプロジェクトでは、リモートコントロールを使用して、車の下部に取り付けられたRGBライトストリップを制御し、さまざまな色を表示させることができます。

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/car_light.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**操作方法**

#. ESP32-CAMとArduinoボードは、RX（受信）およびTX（送信）のピンが共有されています。コードをアップロードする際は、まずESP32-CAMを切断して、コンフリクトや潜在的な問題を避けてください。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. ``zeus-car-main\examples\6_car_light`` のパスから ``6_car_light.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/79b6c0e5-a788-4d67-bb44-7e7122c521ab/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードが正常にアップロードされたら、電源スイッチをONにしてZeus Carを起動します。

#. 1から9までの数字のリモートコントロールを使用して、車のライトの色を変更することができます。0を押すとオフになり、 |ir_return| を押すと色が順番に変わります。1から9のキーはそれぞれ次の色に対応しています：赤、オレンジ、黄色、緑、水色、青、紫、ピンク、白。
