11. 障害物回避
================================

このプロジェクトでは、Zeus車は自動的に前進し、2つの障害物回避モジュールと超音波モジュールが障害物にぶつからないようにします。

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html

    <br/> 

**操作方法**

#. ESP32-CAMとArduinoボードは、RX（受信）およびTX（送信）のピンが共有されています。コードをアップロードする際は、まずESP32-CAMを切断して、コンフリクトや潜在的な問題を避けてください。

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. ``zeus-car-main\examples\11_obstacle_avoid`` のパスから ``11_obstacle_avoid.ino`` ファイルを開きます。

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/520af1d6-4ef2-4804-a4a9-f6aa92985258/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. コードが正常にアップロードされたら、電源スイッチをONにしてZeus Carを起動します。

    * Zeus車は前進します。
    * 超音波モジュールが前方の障害物を検出すると、車は左に曲がります。
    * 左の障害物回避モジュールが障害物を検出すると、車は右に曲がり、右の障害物回避モジュールが障害物を検出すると、車は左に曲がります。

.. note::
    使用する前に、2つの障害物回避モジュールの検出距離を15CMに調整する必要があります。手順は次のとおりです

    * IR障害物回避モジュールから約15cm離れた場所に障害物を置きます。
    * モジュールには2つのポテンショメーターがあり、1つは送信電力を調整し、もう1つは送信周波数を調整するためのものです。これらのポテンショメーターを調整することで、検出距離を調整できます。
    * 次に、ポテンショメーターを調整します。15cmでモジュールの信号ランプが点灯する場合、調整が成功しています。そうでない場合は、もう1つのポテンショメーターを調整します。

        .. image:: img/zeus_ir_avoid.jpg

    * 同様にして、もう1つの障害物回避モジュールをキャリブレートします。