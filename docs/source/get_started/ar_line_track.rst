.. _ar_line_track:

14. 線追跡
==============

このプロジェクトでは、Omni Grayscaleモジュールを使用して線の追跡方法を学びます。

プロジェクトに取り組む前に、黒の電気テープを使ってトラックの線を貼り付ける必要があります。これは円、直線、または不規則な形状にすることができます。

ただ、注意するべき点が2つあります。

1. このラインは3cmの幅が必要です（電気テープの厚さは1.5cmです）。
2. 曲がり角の角度は90°未満であってはなりません。

.. image:: img/map.png

**やり方は？**

#. ESP32-CAMとArduinoボードは同じRX（受信）およびTX（送信）ピンを共有しています。そのため、コードをアップロードするときには、ESP32-CAMを一度切断して、競合や潜在的な問題を避ける必要があります。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. ``zeus-car-main\examples\14_line_track`` のパスの下にある ``14_line_track.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/f1bfb9ad-8bfa-417e-a4c0-10dbdcdc4298/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードが正常にアップロードされたら、電源スイッチをONにしてZeus Carを起動します。

#. 次に、Zeus Carは線に沿って移動します。Zeus Carが線から外れてしまう場合は、 :ref:`ar_grayscale` を再校正するか、スピードを下げる必要があるかもしれません。
