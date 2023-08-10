.. _ar_play_mode:


実際の操作モード
======================

実際の操作モードとは、工場でArduinoボードにコードを事前にアップロードし、Zeus CarはオンにするだけでAPPやリモコンでリモート制御できるモードのことです。

* :ref:`play_app_control` : あなたの携帯やタブレットにSunFounder Controllerをインストールする必要があります。これにより、ジョイスティックウィジェットを使用してZeus Carを全方向に制御したり、音声制御を行ったりすることができます。そして、何よりも、APP上でZeus Carによって撮影されたリアルタイムの映像ストリームを見ることができます。

* :ref:`play_remote_control` : 簡単なリモコンも装備しています。Zeus Carをオンにするだけで、リモコンで制御することができます。これは、Zeus Carの制御の楽しさをできるだけ早く体験したいユーザーにとって良い選択です。

.. note::

    このキットのコードパッケージはこちらです。

    * :download:`SunFounder Zeus Car Kit for Arduino <https://github.com/sunfounder/zeus-car/archive/refs/heads/main.zip>`

    他のコードをArduinoにアップロードした後、再び実際の操作モードに戻したい場合は、 ``zeus-car-main\zeus_car`` のパスの下にある ``zeus_car.ino`` をArduinoボードにアップロードするだけでOKです。


.. toctree::
    :maxdepth: 2

    app_control
    remote_control
