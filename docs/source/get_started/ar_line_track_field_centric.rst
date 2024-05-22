.. note::

    こんにちは、SunFounderのRaspberry Pi & Arduino & ESP32愛好家コミュニティへようこそ！Facebook上でRaspberry Pi、Arduino、ESP32についてもっと深く掘り下げ、他の愛好家と交流しましょう。

    **参加する理由は？**

    - **エキスパートサポート**：コミュニティやチームの助けを借りて、販売後の問題や技術的な課題を解決します。
    - **学び＆共有**：ヒントやチュートリアルを交換してスキルを向上させましょう。
    - **独占的なプレビュー**：新製品の発表や先行プレビューに早期アクセスしましょう。
    - **特別割引**：最新製品の独占割引をお楽しみください。
    - **祭りのプロモーションとギフト**：ギフトや祝日のプロモーションに参加しましょう。

    👉 私たちと一緒に探索し、創造する準備はできていますか？[|link_sf_facebook|]をクリックして今すぐ参加しましょう！


15. 線追跡 - フィールド中心の制御システム
===========================================================

このプロジェクトでは、新しいトレーサーモードを探求します - コンパスを使用したトレーサー移動。

実験結果は :ref:`ar_line_track` とほぼ同じですが、Zeus Carの頭部は常に固定の方向を向いています。前のプロジェクトでは、それが線の方向とともに変わりました。

.. image:: img/line_track_compass.gif

**やり方は？**

#. ESP32-CAMとArduinoボードは同じRX（受信）およびTX（送信）ピンを共有しています。そのため、コードをアップロードするときには、ESP32-CAMを一度切断して、競合や潜在的な問題を避ける必要があります。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. ``zeus-car-main\examples\15_line_track_field_centric`` のパスの下にある ``15_line_track_field_centric.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/6b6734cb-38c9-4a5b-81b7-3decced20326/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードが正常にアップロードされたら、電源スイッチをONにしてZeus Carを起動します。

#. 次に、Zeus Carは線に沿って移動しますが、その頭部は一つの方向を向き続けます。Zeus Carが線から外れてしまう場合は、 :ref:`ar_grayscale` を再校正するか、スピードを下げる必要があるかもしれません。




